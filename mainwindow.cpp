#include "mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QFile>
#include <QCloseEvent>

#include <QTextStream>
#include <QDesktopWidget>
#include <QSplitter>
#include <QResizeEvent>
#include <QByteArray>
#include <QAudioBuffer>
#include <QAudioFormat>
#include <QColorDialog>

#define MARKPANELWIDTH 185
#define MARKPANELHEIGHT 144
#define TITLEHEIGHT 50

#include <QMediaPlayer>
#include "videoplayer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),m_fullScreenBtn(NULL),m_showCategoryBtn(NULL),m_lockScreen(NULL)
{
    ui->setupUi(this);
	m_lockScreen = new QLabel(this) ;
	m_lockScreen->setStyleSheet("QLabel{background:#1A477B;}") ;
	m_lockScreen->hide() ;
    initUI() ;
    initVar() ;
    initConnection() ;
	m_state = 0 ;
	
	m_audioTrack = new QMediaPlayer(this) ;
	connect( m_audioTrack, SIGNAL(stateChanged(QMediaPlayer::State)),
		this, SLOT(onAudioStateChanged(QMediaPlayer::State))) ;


	m_isMaximized = false ;
	saveCurrentPosition() ;
	maximize() ;
//	onAddContentScene() ;
//	m_trimmer->hide() ;
	ui->tb_scene_color->hide() ;
	ui->tb_paint->hide() ;
	ui->tb_show_editvideowidget->setRole(EDITVIDEOBTN) ;
	ui->w_top_painter->hide() ;

	ui->tb_single_image_video->setRole(SINGLEGRAPHICVID) ;
	ui->tb_create_new_video->setRole(CREATENEWVIDEOBTN) ;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint );

	ui->btn_item_mode->addButton( ui->rb_flex, 0 ) ;
	ui->btn_item_mode->addButton( ui->rb_black_line, 1 ) ;
	ui->btn_item_mode->addButton( ui->rb_white_line, 2 ) ;

	m_sceneList = ui->lw_layer ;
	m_view = ui->graphicsView ;
	m_videoPanel = ui->w_control ;
	m_itemList = ui->lw_item_layer ;
	m_trimmer = ui->lbl_trimmer ;
	ui->tb_delete_video->setEnabled(false) ;
	m_videoPanel->setEnabled(false) ;
	ui->w_title->setStyleSheet("background-color:#535353;color:white;") ;

	ui->tb_preview->setEnabled(false) ;

	setButtonTransparent( ui->tb_add_video ) ;
	setButtonTransparent( ui->tb_preview ) ;
	setButtonTransparent( ui->tb_delete_video ) ;
	setButtonTransparent( ui->tb_add_video ) ;

	//53 26 4D

	ui->cb_theme->addItem("Grey Theme") ;
	ui->cb_theme->addItem("Dark Theme") ;
	ui->cb_theme->addItem("Blue Theme") ;
	ui->cb_theme->addItem("Light Theme") ;

	QFile file("setting.dat") ;
	QDataStream in(&file) ;
	if( file.open(QIODevice::ReadOnly) )
	{
		int val ;
		in >> val ;
		ui->cb_theme->setCurrentIndex(val) ;
		onThemeChanged(val) ;
	}
	else onThemeChanged(0) ;

	m_trimmer->setEnabled(false) ;
	onExpandTrimmer(true) ;

	ui->w_control_button->hide() ;

	ui->w_footer->hide() ;
//	setVisibleItemMode(false) ;
	ui->w_text_del->hide() ;
	ui->w_image_del->hide() ;
	ui->w_mark_del->hide() ;
	ui->w_text_dropdown->hide() ;	
}

void MainWindow::initVar()
{
	m_process = new QProcess() ;
	m_process->setProcessChannelMode(QProcess::MergedChannels);
	m_markPanel = new CxMarkPanel ;
    m_markPanel->hide() ;
	m_isPressing = false ;

	m_fullScreenBtn = new CxCustomButton(this) ;
	m_showCategoryBtn = new CxCustomButton(this) ;
	m_playBtn = new CxCustomButton(this) ;
	m_fullScreenBtn->setRole(SHOWFULLSCREENBTN) ;
	m_showCategoryBtn->setRole(SHOWCATEGORYBTN) ;
	m_playBtn->setRole(PLAYBTN) ;
	m_fullScreenBtn->show() ;
	m_showCategoryBtn->hide() ;
	m_playBtn->hide() ;
	m_playBtn->setEnabled(false) ;

	connect( m_playBtn, SIGNAL(clicked()), ui->tb_preview, SLOT(click())) ;
	m_progressBar = new CxProgressDlg(this) ;
}

void MainWindow::initConnection()
{
	connect( m_process, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(onProcessFinished(int,QProcess::ExitStatus))) ;

	connect (m_process, SIGNAL(readyReadStandardOutput()), this, SLOT(onProcessStandardOutput()));

	connect( ui->w_text_dropdown, SIGNAL(__addText(int)), this, SLOT(onAddTextItem(int))); 
	connect( ui->graphicsView, SIGNAL(__mouseHover(bool)), m_videoPanel->form().w_ani, SLOT(onStartAnimation(bool))) ;
    connect( m_markPanel, SIGNAL(__drawMark(int,QColor)), m_view, SLOT(onDrawMark(int,QColor))) ;
	connect( m_trimmer, SIGNAL(__fade(bool)), m_sceneList, SLOT(onChangeCurFade(bool))) ;
	connect( ui->tb_preview, SIGNAL(clicked()), this, SLOT(onPreview())) ;
	connect( m_videoPanel, SIGNAL(__preview(int)), this, SLOT(onRangePreview(int))) ;
	connect( m_trimmer, SIGNAL(__preview(int)), this, SLOT(onRangePreview(int))) ;
	connect( m_trimmer, SIGNAL(__onRangeChanged(qreal,qreal,bool)), m_videoPanel, SLOT(setSegment(qreal,qreal,bool)) ) ;
	connect( m_videoPanel, SIGNAL(__curPosChanged(qreal)), m_trimmer, SLOT(onRemoteSeek(qreal))) ;
	connect( m_trimmer, SIGNAL(__curSeekPosChanged(qreal)), m_videoPanel, SLOT(onSeek(qreal))) ;

	
	connect( ui->tb_exit, SIGNAL(clicked()), this, SLOT(onClose())) ;
	connect( ui->tb_maximize, SIGNAL(clicked()), this, SLOT(onMaximize())) ;
	connect( ui->tb_minimize, SIGNAL(clicked()), this, SLOT(showMinimized())) ;

	connect( ui->tb_show_logo_widget, SIGNAL(clicked()), this, SLOT(onShowLogoWidget())) ;
	connect( ui->tb_add_logo, SIGNAL(clicked()), this, SLOT(onAddLogo())); 
	connect( ui->tb_delete_logo, SIGNAL(clicked()), ui->lw_logo_list, SLOT(onRemoveLogo())) ;
    connect( ui->tb_image, SIGNAL(clicked()), this, SLOT(onAddImage())) ;
	connect( ui->tb_paint, SIGNAL(clicked()), this, SLOT(onPaint())) ;
    connect( ui->tb_text, SIGNAL(clicked()), this, SLOT(onAddText())) ;
    connect( ui->tb_mark, SIGNAL(clicked()), this, SLOT(onMark())) ;
    connect( ui->tb_add_video, SIGNAL(clicked()), this, SLOT(onAddVideo())) ;
	connect( ui->tb_upload_video, SIGNAL(clicked()), this, SLOT(onAddVideo())) ;
	
//	connect( ui->tb_add_contentscene, SIGNAL(clicked()), this, SLOT(onAddContentScene())) ;

	connect( ui->tb_render, SIGNAL(clicked()), this, SLOT(onRecord())) ;

	connect( m_sceneList, SIGNAL(__currentItemChanged(CxLayerItem*)), m_videoPanel, SLOT(setCurrentLayerItem(CxLayerItem*))) ;
	connect( m_sceneList, SIGNAL(__currentItemChanged(CxLayerItem*)), this, SLOT(onCurrentItemChanged(CxLayerItem*))) ;
	connect( ui->tb_delete_video, SIGNAL(clicked()), ui->lw_layer, SLOT(deleteCurItem())) ;
	connect( m_videoPanel, SIGNAL(__rangeChanged(qreal,qreal)), ui->lw_layer, SLOT(onSeekRangeChanged(qreal,qreal))) ;
	connect( m_videoPanel, SIGNAL(__rangeChanged(qreal,qreal)), m_trimmer, SLOT(onSetSegment(qreal,qreal))) ;

	connect( ui->cb_theme, SIGNAL(currentIndexChanged(int)), this, SLOT(onThemeChanged(int))) ;

	connect( m_videoPanel, SIGNAL(__curPosChanged(qreal)), m_itemList, SLOT(onCurPosChanged(qreal))) ;

	connect( ui->tb_expand_trimmer, SIGNAL(clicked(bool)), this, SLOT(onExpandTrimmer(bool))) ;

	connect( ui->btn_item_mode, SIGNAL(buttonClicked(int)), this, SLOT(onItemModeChanged(int))) ;
	connect( ui->tb_delete, SIGNAL(clicked()), this, SLOT(onDeleteCxItem())) ;
	connect( ui->tb_delete_2, SIGNAL(clicked()), this, SLOT(onDeleteCxItem())) ;
	connect( ui->tb_delete_3, SIGNAL(clicked()), this, SLOT(onDeleteCxItem())) ;
//	connect( ui->tb_delete_all, SIGNAL(clicked()), this, SLOT(onRemoveAllItems())) ;
//	connect( ui->tb_copy_to_all, SIGNAL(clicked()), this, SLOT(copyToGlobal())) ;
	connect( ui->tb_scene_color, SIGNAL(clicked()), this, SLOT(onChangeSceneColor())) ;

	connect( ui->tb_create_new_video, SIGNAL(clicked()), this, SLOT(onCreateNewVideo())) ;
	connect( ui->tb_edit_video_image, SIGNAL(clicked()), this, SLOT(onEditVideo())) ;
	connect( ui->tb_edit_video_freeze, SIGNAL(clicked()), this, SLOT(onFreezeVideo())) ;
	connect( ui->tb_single_image_video, SIGNAL(clicked()), this, SLOT(onCreateSingleImageVideo())) ;

	connect( ui->tb_single_video_audio, SIGNAL(clicked()), this, SLOT(onSingleVideoAudioSelect()) ) ;
	connect( ui->tb_single_video_image, SIGNAL(clicked()), this, SLOT(onSingleVideoImageSelect()) ) ;
	connect( ui->tb_single_video_mp4, SIGNAL(clicked()), this, SLOT(onSingleVideoMp4Select()) ) ;
	connect( ui->tb_save_single_video, SIGNAL(clicked()), this, SLOT(onSingleVideoCreate()) ) ;

	connect( m_fullScreenBtn, SIGNAL(clicked()), this, SLOT(onHideCategory())) ;
	connect( m_showCategoryBtn, SIGNAL(clicked()), this, SLOT(onShowCategory())) ;

	connect( ui->tb_add_intro, SIGNAL(clicked()), this, SLOT(onAddIntroVideo())) ;
	connect( ui->tb_remove_intro, SIGNAL(clicked()), this, SLOT(onRemoveIntroVideo())) ;
	connect( ui->lw_intro_layer, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onInsertIntroItem(QListWidgetItem*))) ;

/*
	connect( ui->tb_logo_topleft, SIGNAL(clicked()), this, SLOT(onAddTopLeftLogo())) ;
	connect( ui->tb_logo_topright, SIGNAL(clicked()), this, SLOT(onAddTopRightLogo())) ;
	connect( ui->tb_logo_bottomleft, SIGNAL(clicked()), this, SLOT(onAddBottomLeftLogo())) ;
	connect( ui->tb_logo_bottomright, SIGNAL(clicked()), this, SLOT(onAddBottomRightLogo())) ;
*/
	connect( ui->lw_logo_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onAddLogo(QListWidgetItem*))) ;
	connect( ui->tb_logo_save, SIGNAL(clicked()), this, SLOT(onLogoSave())) ;
	connect( ui->tb_show_editvideowidget, SIGNAL(clicked()), this, SLOT(onShowEditVideoWidget())) ;
}

void MainWindow::onExpandTrimmer(bool on)
{
	m_trimmer->setVisible(on) ;
	m_itemList->setVisible(!on) ;
//	refitTrimmerRect() ;
}

void MainWindow::onClose()
{
    close() ;
}

void MainWindow::onMaximize()
{
	if( m_isMaximized ){
		normalize() ;
	}
	else
	{
		maximize() ;
	}
}

void MainWindow::onLogoSave()
{
	CxGraphicsScene* sc = ui->graphicsView->currentScene() ;
	if( !sc )
	{
		QMessageBox::information(this,"Error","Please select video first.") ;
		return ;
	}
	QList<CxGraphicsItem*> itemList = sc->availableItems() ;
	bool selected = false ;
	foreach( CxGraphicsItem* item, itemList )
	{
		if( item->isSelected() && item->myType() == PIXITEM && item->isLogo() )
		{
			ui->lw_logo_list->addMyItem((CxImageItem*)item) ;
			return ;
		}
	}
	QMessageBox::information(this,"Error","Please select Logo image first.") ;
}

void MainWindow::onAddLogo()
{
	addLogo(5) ;
}

void MainWindow::onAddLogo(QListWidgetItem* item)
{
	CxGraphicsScene* sc = ui->graphicsView->currentScene() ;	
	if( !sc )
	{
		QMessageBox::information(this,"Error","Please select video first.") ;
		return ;
	}
	LogoItem* logo = (LogoItem*) item ;
	sc->addLogo(logo->imagePath(), logo->myPos(), logo->mySize() ) ;
}

void MainWindow::onShowLogoWidget()
{
	/*
	if( !m_view->currentScene() ) 
	{
		QMessageBox::information(this,"Error","Please select video first.") ;
		return ;
	}
	if( ui->w_logo_pos->isVisible() )
	{
		ui->w_logo_pos->hide() ;
		return ;
	}
//	ui->w_inside_single_image_video->hide() ;
	ui->w_logo_pos->show() ;
	*/
	return ;
}

void MainWindow::onAddImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png *.xpm *.jpg)"));
    if( fileName.length() == 0 )    return ;
    QPixmap pix(fileName) ;
    if( pix.isNull() )
    {
        QMessageBox::information(NULL,"Error", "Invalid File Format") ;
        return ;
    }
	if( m_view->currentScene() ) m_view->currentScene()->addImageItem(fileName) ;
}

void MainWindow::onAddText()
{
	if( ui->w_text_dropdown->isVisible()) 
	{
		ui->w_text_dropdown->hide() ;
		return ;
	}
	CxGraphicsScene* sc = m_view->currentScene() ;
	if( sc ) sc->clearSelection() ;
	ui->w_text_dropdown->show() ;
	return ;
}

void MainWindow::onPaint(int role)
{

	CxTextPopupDlg* dlg = new CxTextPopupDlg(0) ;
	CxGraphicsScene* sc = m_view->currentScene() ;
	dlg->form().tb_inside_video->setEnabled(sc) ;
	dlg->initMe(role) ;
	dlg->setParentScene(sc) ;
	if( role == FREEVIDEOMODE )
	{
		dlg->setSceneSize(m_sceneList->itemAt(m_sceneList->currentRow())->videoSize()) ;
	}
	if( dlg->exec() == QDialog::Accepted )
	{
		int ret = dlg->state() ;

		if( ret == ADDIMAGETOSCENE )
		{
			if( sc ) sc->addImageItem(dlg->getImage(),0.5) ;
			return ;
		}
		QString videouuid = QString("tmp/%1.mp4").arg(createSimpleUuid()) ;
		QStringList args ;
		if( ret == SINGLEVIDEOMODE )
		{
			QApplication::setOverrideCursor(Qt::WaitCursor) ;
			args << "-loop" <<"1" << "-i"<< dlg->singleVideoImagePath() <<"-i"<<
				dlg->singleVideoAudioPath()<<"-shortest"<<"-acodec"<<"copy"<<"-c:v"<< "libx264"<< "-pix_fmt"
				<<"yuv420p"<< "-r" <<"29.7"<<videouuid ;

			m_progressBar->startProgress(args,-1,"Creating Single Video ...") ;
			CxLayerItem* item = ui->lw_layer->onAddVideoLayer(videouuid) ;
			createSceneConnection( item->myScene() ) ;
			QApplication::restoreOverrideCursor() ;
			return ;
		}
		int curSc = m_sceneList->currentRow() ;
		if( ret == FREEVIDEOMODE )
		{
			QApplication::setOverrideCursor(Qt::WaitCursor) ;
			QString pix = QString("tmp/%1.png").arg(createSimpleUuid()) ;
			dlg->getFreezeImage().save(pix) ;
			int freezeDur = dlg->form().sp_freeze_duration->value() ;
			args <<"-loop" <<"1" <<"-i" <<pix<<"-i"<<"silence.wav"<<"-c:v" <<"libx264"<<"-t" <<QString("%1").arg(freezeDur)<<"-pix_fmt" <<"yuv420p" <<videouuid ;
			m_progressBar->startProgress(args,freezeDur*1000, "Initializing ...") ;
			QFile::remove(pix) ;

			args.clear() ;
			CxGraphicsScene* sc = m_sceneList->itemAt(curSc)->myScene() ;
			qreal insertPos = dlg->freezeTime()/1000.0 ;
			qreal newVideoLength = freezeDur ;
			qreal prevVideoLength = sc->totalMSec()/1000.0 ;
			args << "-i" << sc->videoPath() << "-i" << videouuid << "-i" << sc->videoPath() << "-filter_complex" ;
			args << QString("[0:v]trim=0:%1,setpts=PTS-STARTPTS[v0];[1:v]trim=0:%2,setpts=PTS-STARTPTS[v1];[2:v]trim=%3:%4,setpts=PTS-STARTPTS[v2];[0:a]atrim=0:%5,asetpts=PTS-STARTPTS[a0];[1:a]atrim=0:%6,asetpts=PTS-STARTPTS[a1];[2:a]atrim=%7:%8,asetpts=PTS-STARTPTS[a2];[v0][a0][v1][a1][v2][a2]concat=n=3:v=1:a=1") 
				.arg(insertPos).arg(newVideoLength).arg(insertPos).arg(prevVideoLength).arg(insertPos).arg(newVideoLength).arg(insertPos).arg(prevVideoLength) ;
			QString newvideouuid = QString("tmp/%1.mp4").arg(createSimpleUuid()) ;
			args << "-r" <<"29.7" << newvideouuid ;			
			m_progressBar->startProgress(args,freezeDur*1000+sc->totalMSec(), "Saving ...") ;
			m_sceneList->deleteCurItem() ;
			CxLayerItem* item = ui->lw_layer->onAddVideoLayer(newvideouuid,curSc) ;
			createSceneConnection( item->myScene() ) ;
			m_sceneList->setCurrentRow(curSc) ;

			QApplication::restoreOverrideCursor() ;
			return ;
		}
		QList<CxGraphicsScene*> scList = dlg->sceneList() ;
		QStringList pixUuidList ;
		int sceneCnt = scList.count() ;

		args << "-y" ;
		QSize videoSz(-1,-1) ;
		int imageSeqDur = 0 ;
		if( curSc < 0 || curSc >= m_sceneList->count() ) curSc = 0 ;
		if( ret == INSERTINSIDEVIDEO ){
			videoSz = m_sceneList->itemAt(curSc)->videoSize() ;
		}
		for( int i = 0; i < sceneCnt; i++ )
		{
			QString pix = QString("tmp/%1.png").arg(createSimpleUuid()) ;
			pixUuidList << pix ;
			scList.at(i)->renderToPix(videoSz).save(pix) ;
			imageSeqDur += scList.at(i)->totalMSec() ;
			args <<"-loop" <<"1" ;
			if( i != sceneCnt-1 ) 
			{
				args <<"-t"<<QString("%1").arg(scList.at(i)->totalMSec()/1000.0) ;
			}
			args <<"-i"<<pix ;
		}
		args << "-i" << dlg->audioPath() << "-acodec" <<"copy"<<"-shortest"<<"-filter_complex"
			<<QString("concat=n=%1").arg(sceneCnt)<<"-c:v"<<"libx264"<<"-pix_fmt"<<"yuv420p"<<"-r"<<"29.7"<<videouuid ;

		m_progressBar->startProgress(args,imageSeqDur, "Creating Image Sequence...") ;
		if( ret == CREATENEWMP4 )
		{
			CxLayerItem* item = ui->lw_layer->onAddVideoLayer(videouuid) ;
			createSceneConnection( item->myScene() ) ;
		}
		if( ret == INSERTINSIDEVIDEO )
		{
			args.clear() ;
			CxGraphicsScene* sc = m_sceneList->itemAt(curSc)->myScene() ;
			qreal insertPos = dlg->insertTimeMSec()/1000.0 ;
			qreal newVideoLength = dlg->audioDuration()/1000.0 ;
			qreal prevVideoLength = sc->totalMSec()/1000.0 ;
			args << "-i" << sc->videoPath() << "-i" << videouuid << "-i" << sc->videoPath() << "-filter_complex" ;
			args << QString("[0:v]trim=0:%1,setpts=PTS-STARTPTS[v0];[1:v]trim=0:%2,setpts=PTS-STARTPTS[v1];[2:v]trim=%3:%4,setpts=PTS-STARTPTS[v2];[0:a]atrim=0:%5,asetpts=PTS-STARTPTS[a0];[1:a]atrim=0:%6,asetpts=PTS-STARTPTS[a1];[2:a]atrim=%7:%8,asetpts=PTS-STARTPTS[a2];[v0][a0][v1][a1][v2][a2]concat=n=3:v=1:a=1") 
				.arg(insertPos).arg(newVideoLength).arg(insertPos).arg(prevVideoLength).arg(insertPos).arg(newVideoLength).arg(insertPos).arg(prevVideoLength) ;

			QString newvideouuid = QString("tmp/%1.mp4").arg(createSimpleUuid()) ;

			args << "-r" <<"29.7" << newvideouuid ;

			m_progressBar->startProgress(args,1000*(newVideoLength+prevVideoLength),"Saving...") ;
			m_sceneList->deleteCurItem() ;
			CxLayerItem* item = ui->lw_layer->onAddVideoLayer(newvideouuid,curSc) ;
			createSceneConnection( item->myScene() ) ;
			m_sceneList->setCurrentRow(curSc) ;
			QApplication::restoreOverrideCursor() ;
		}
		foreach( QString path, pixUuidList ) QFile::remove(path) ;
	}
	return ;
}
void MainWindow::onAddTextItem(int id)
{
	ui->w_text_dropdown->hide() ;
	CxGraphicsScene* sc = m_view->currentScene() ;
	if( sc ) {

		CxTextItem* item = sc->addTextItem() ;
		sc->setItemState(item,id) ;
		item->showEditor() ;
	}
}

void MainWindow::onFade()
{
	//Un-necessary
}

void MainWindow::onMark()
{
    QPoint pnt = QCursor::pos()-QPoint(MARKPANELWIDTH,0) ;
    QRect rc( pnt, QSize(MARKPANELWIDTH,MARKPANELHEIGHT)) ;
    m_markPanel->setGeometry(rc);
    m_markPanel->show();
}

void MainWindow::createSceneConnection( CxGraphicsScene* sc ) 
{
	connect( sc, SIGNAL(__currentTimeChanged(int)), m_videoPanel, SLOT(setCurrentTime(int))) ;
	connect( sc, SIGNAL(__itemAdded(CxGraphicsItem*)), this, SLOT(onGraphicsItemAdded(CxGraphicsItem*))) ;
	connect( sc, SIGNAL(__itemDeleted(CxGraphicsItem*)), 
		m_itemList, SLOT(onItemDelete(CxGraphicsItem*))) ;
	connect( sc, SIGNAL(selectionChanged()), m_itemList, SLOT(onSelectionChanged())) ;
	connect( sc, SIGNAL(selectionChanged()), this, SLOT(onCxItemSelectionChanged())) ;
	connect( sc, SIGNAL(__screenClicked()), this, SLOT(onScreenClicked())) ;
	//	connect( item->myScene(), SIGNAL(__currentTimeChanged(int)), this, SLOT(onVideoCurTimeChanged(int))) ;
}

void MainWindow::onAddVideo()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
		"",tr("Mp4 files (*.mp4 *.wmv *.avi)"));
    if( fileName.length() == 0 ) return ;
	CxLayerItem* item = ui->lw_layer->onAddVideoLayer(fileName) ;
	createSceneConnection( item->myScene() ) ;
}

void MainWindow::onAddContentScene()
{
	m_addAudioFileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Audio files (*.mp3 *.wmv *.wav)"));
	if( m_addAudioFileName.length() == 0 ) return ;
	m_addAudioDuration = -1 ;
	QStringList args ;
	args << "-i" << m_addAudioFileName ;//<<"-vn"<<"-ac"<<"2"<<"-ar"<<"44100"<<"-ab"<<"320k"<<"-f"<<"mp3"<<"output.mp3" ;
	//-vn -ac 2 -ar 44100 -ab 320k -f mp3 output.mp3
//	QApplication::setOverrideCursor(Qt::WaitCursor) ;
	m_process->start("ffmpeg.exe", args) ;
}

void MainWindow::onProcessStandardOutput()
{
	QString str = m_process->readAllStandardOutput();
	m_addAudioDuration =  1 ;
	if( str.contains("Duration:")) 
	{
		int pos = str.indexOf("Duration:") ;
		m_addAudioDuration = getMSec(QTime::fromString(str.mid(pos+10,11),"hh:mm:ss.z")) ;
		if( m_addAudioDuration <= 0 ) return ;
//		QMessageBox::information(NULL,"",QString("%1  %2").arg(str.mid(pos+10,11)).arg(m_addAudioDuration)) ;
		CxLayerItem* item = ui->lw_layer->onAddVideoLayer(m_addAudioFileName, m_addAudioDuration) ;
		item->myScene()->setSceneType(AUDIOSCENE) ;
		createSceneConnection( item->myScene() ) ;
	}
}

void MainWindow::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
	QApplication::restoreOverrideCursor() ;
	if( m_addAudioDuration <= 0 )
	{
//		QMessageBox::information(NULL,"","Invalid Audio File") ;
		return ;
	}
}

void MainWindow::onGraphicsItemAdded(CxGraphicsItem* item)
{
	item->setStart(item->isLogo() ? 0 : m_videoPanel->currentSeekPos()) ;
	item->setEnd(m_videoPanel->endPos() ) ;
	m_itemList->onAddItem(item) ;
}

void MainWindow::onVideoCurTimeChanged( int cur )
{
}

void MainWindow::onCurrentItemChanged(CxLayerItem* item)
{
	ui->tb_delete_video->setEnabled(item?true:false) ;
	m_videoPanel->setEnabled(item?true:false) ;
	m_trimmer->setEnabled(item?true:false) ;
	if( !m_state )
	{
		m_playBtn->setEnabled(item?true:false) ;
		ui->tb_preview->setEnabled(item?true:false) ;
	}
	if( item ){
		CxGraphicsScene* sc = item->myScene() ;
		m_view->setMyScene(sc) ;
		m_itemList->setMyScene(sc) ;
		m_trimmer->setFileName(sc->videoPath()) ;
		m_trimmer->setTotMSec(sc->totalMSec()) ;
//		QMessageBox::information(NULL,"", QString("%1  %2").arg(sc->videoPath()).arg(sc->totalMSec())) ;
		m_trimmer->onSetSegment(1.0*sc->startTime()/sc->totalMSec(),1.0*sc->endTime()/sc->totalMSec()) ;
		m_trimmer->setFade(item->myScene()->hasFadeEffect()) ;
	}
	else{
		m_view->setMyScene(NULL) ;
		m_itemList->setMyScene(NULL) ;
		m_trimmer->setFileName("") ;
	}
}

//////////////////////////////////////////////////////////////////////////

void MainWindow::mousePressEvent(QMouseEvent *event)
{
	if( m_isMaximized ) return ;
	m_oriRect = geometry() ;
	m_oriPnt = event->globalPos() ;
	if( event->pos().y() < 0 || event->pos().y() > TITLEHEIGHT ) return ;
	m_isPressing = true ;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
	if( !m_isPressing ) return ;
	QPoint tmp = event->globalPos()-m_oriPnt ;
	QRect geo = m_oriRect.translated(tmp.x(),tmp.y()) ;
	setGeometry(geo);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
	m_isPressing = false ;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
	if( event->pos().y() < 0 || event->pos().y() > TITLEHEIGHT ) return ;
	onMaximize() ;
}

void MainWindow::onPreview()
{
	m_state = ui->tb_preview->isChecked() ;
	if( m_state ) {
		m_audioTrack->setMedia(QUrl::fromLocalFile(m_view->currentScene()->videoPath()));
		m_audioTrack->play(); // music can be heard
		m_audioTrack->setVolume(0);
		startPlaying(m_state) ;
	}
	else{
		startPlaying(m_state) ;
	}
}

void MainWindow::startPlaying( bool on )
{
	m_playBtn->setChecked(on) ;
	ui->w_create_video_panel->setEnabled(!on) ;
	ui->tb_upload_video->setEnabled(!on) ;
	ui->tb_add_video->setEnabled(!on) ;
	ui->tb_delete_video->setEnabled(!on) ;
	ui->lw_layer->setEnabled(!on) ;

	ui->tb_preview->setChecked(on) ;
	m_videoPanel->play(on) ;

	if( !on )
	{
		stopPlayingAudio() ;
		m_timer.stop() ;
		if( m_view->currentScene() ) m_view->currentScene()->setRunningVideo(false) ;
		if( m_state == 2 )
		{
			finalizeRecording() ;
		}
//		QMessageBox::information(NULL,"","A") ;
		m_state = 0 ;
		return ;
	}
	int cnt = m_sceneList->count() ;
	for( int i = 0; i < cnt ; i++ )
	{
		CxLayerItem* item = m_sceneList->itemAt(i) ;
		if( i == cnt-1 || m_state == 1 )
		{
			item->myScene()->setNextVideoFrame(QImage()) ;
			break ;
		}
		CxLayerItem* nxt = m_sceneList->itemAt(i+1) ;
		item->myScene()->setNextVideoFrame(nxt->thumnail()) ;
	}
	if( m_state == 2 ) m_timer.start(5,this) ;
	else m_timer.start(25,this) ;
}

void MainWindow::stopPlayingAudio()
{
	m_audioTrack->stop() ;
	return ;
	if( m_audioTrack->state() == QMediaPlayer::PlayingState )
	{
		m_audioTrack->stop() ;
	}
}
void MainWindow::timerEvent(QTimerEvent* event)
{
	if( event->timerId() != m_timer.timerId() ) return ;
	if( !m_state ) return ;
	CxGraphicsScene* sc = m_view->currentScene() ;
	if( sc ) {
		if( m_state == 1 && !m_audioTrack->isSeekable()  ) return ;
		if( m_state == 1 && !sc->isRunningVideo() )
		{
			m_sceneStartTime = QTime::currentTime().addMSecs(-m_videoPanel->currentSeekMSec()) ;
			m_audioTrack->setPosition(m_videoPanel->currentSeekMSec()); // music can be heard
			m_audioTrack->setVolume(100) ;
		}
		int flg = -1 ;
		if( !sc->isRunningVideo() )
		{
			sc->setRunningVideo(true,m_state==1?m_videoPanel->currentSeekMSec():-1) ;
		}
		if( m_state == 1 ) flg = m_sceneStartTime.msecsTo(QTime::currentTime()) ;
		int ret = sc->showNextFrame(flg) ;
		if( ret == PLAYFINISHED )
		{
			sc->setRunningVideo(false) ;
			int id = m_sceneList->currentRow()+1 ;
			if( id < m_sceneList->count() && m_state == 2 )// when Recording...switch to next Scene
			{
				m_sceneList->setCurrentRow(id) ;
			}
			else {
				startPlaying(false) ;
			}
		}
		else if(m_state==2){
			QPixmap pix = sc->renderToPix() ;
			m_recorder.write(QImage2Mat(pix.toImage())) ;
			m_videoPanel->form().progressBar->setValue(m_videoPanel->form().progressBar->value()+1) ;
			m_progressBar->setValue(m_videoPanel->form().progressBar->value()+1) ;
		}
	}
}

void MainWindow::onRangePreview( int msec )
{
	CxGraphicsScene* sc = m_view->currentScene() ;
	if( sc ) {
		if( sc->isRunningVideo() )
		{
			m_audioTrack->setPosition(msec) ;
			m_sceneStartTime = QTime::currentTime().addMSecs(-msec) ;
//			ui->lbl_title->setText(QString("%1").arg(msec)) ;
		}
		sc->preview(msec) ;
	}
}

void MainWindow::closeEvent(QCloseEvent* event)
{
	if( m_state == 1 ) startPlaying(false) ;
	if( m_state == 2 )
	{
		cancelRecording() ;
	}
	QFile file("setting.dat") ;
	QDataStream out(&file) ;
	if( file.open(QIODevice::WriteOnly) )
	{
		out << ui->cb_theme->currentIndex() ;
	}
	file.close() ;
	event->accept() ;
}

void MainWindow::cancelRecording()
{
	ui->tb_render->setText("Finalize") ;
	m_videoPanel->form().progressBar->hide() ;
	ui->tb_preview->setEnabled(true) ;
	m_state = 0 ;
	QFile::remove(m_tmpRecordingPath) ;
	startPlaying(false) ;
}

void MainWindow::onRecord()
{
	if( !m_sceneList->count() )
	{
		QMessageBox::information(NULL,"","No movie exist!") ;
		return ;
	}
	m_videoPanel->form().progressBar->setValue(0) ;
	if( m_state == 1 ) {
		startPlaying(false) ;
		releaseRecordinig() ;
// 		m_progressBar->close() ;
// 		m_lockScreen->hide() ;
	}
	if( m_state == 2 )
	{
		releaseRecordinig() ;
		cancelRecording() ;
// 		m_progressBar->close() ;
// 		m_lockScreen->hide() ;
	}
	else{
		QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"",tr("Mp4 files (*.mp4)"));
		if( fileName.length() == 0 ) return ;
		ui->tb_preview->setEnabled(false) ;
		ui->tb_render->setText("Cancel") ;
		m_savePath = fileName ;
		m_tmpRecordingPath = QString("tmp/%1.avi").arg(createSimpleUuid()) ;
		m_recorder.open(m_tmpRecordingPath.toStdString(), CV_FOURCC('D','I','V','X'), 29.7, Size(SCENEWIDTH,SCENEHEIGHT), true);
		m_state = 2 ;
		m_sceneList->setCurrentRow(0) ;
		int maxVal = 0 ;
		for( int i = m_sceneList->count()-1; i >= 0; i-- )
		{
			CxLayerItem* item = m_sceneList->itemAt(i) ;
			item->myScene()->setRecordingState(true) ;
			maxVal += item->totalPlayTime() ;
		}
		m_videoPanel->form().progressBar->show() ;
		m_videoPanel->form().progressBar->setMaximum(maxVal*29.7/1000) ;
		startPlaying(true) ;
		m_progressBar->startProgress(maxVal*29.7/1000, "Rendering...") ;
		m_progressBar->show() ;
		m_lockScreen->show() ;
		setEnabled(false) ;
		ui->tb_render->setEnabled(true) ;
		m_tmp = getMSec(QTime::currentTime()) ;
	}
	return ;
}

void MainWindow::releaseRecordinig()
{
	for( int i = m_sceneList->count()-1; i >= 0; i-- )
	{
		m_sceneList->sceneAt(i)->setRecordingState(false) ;
	}
	m_progressBar->close() ;
	m_lockScreen->hide() ;
}

void MainWindow::finalizeRecording()
{
	releaseRecordinig() ;
	m_videoPanel->form().progressBar->hide() ;
	ui->tb_preview->setEnabled(true) ;
	ui->tb_render->setText("Finalize") ;
	m_state = 0 ;
	m_recorder.release() ;
	int cnt = m_sceneList->count() ;
	QStringList uuidList ;
	int audioDur = 0 ;
	for( int i = 0 ; i < cnt; i++ )
	{
		CxLayerItem* item = m_sceneList->itemAt(i) ;
		QString uuid = QString("tmp/%1.mp3").arg(createSimpleUuid()) ;
		uuidList << uuid ;
		QStringList argu ;
		int dur = getMSec(item->endTime())-getMSec(item->startTime()) ;
		audioDur += dur ;
		argu << "-i" <<  item->myScene()->audioPath() << "-ss" << item->startTime().toString("hh:mm:ss.zzz")
			<< "-t" << item->endTime().toString("hh:mm:ss.zzz")
			<< "-vn" << "-ac" << "2" << "-ar" << "44100" << "-ab" << "320k"
			<< "-f" << "mp3" << uuid ;
		m_progressBar->startProgress(argu,dur, QString("Audio Initializing %1/%2").arg(i+1).arg(cnt)) ;
	}
	QFile data("audiolist.txt") ;
	if (data.open(QFile::WriteOnly | QFile::Truncate)) {
		QTextStream out(&data);
		for( int i = 0; i < cnt; i++ ) {
			out << "file '" ;
			out << uuidList.at(i) ;
			out << "'" ;
			out << '\n' ;
		}
		data.close() ;
		QStringList argu ;
		QString targetfile = QString("tmp/%1.wav").arg(createSimpleUuid()) ;
		argu << "-f" <<"concat" <<"-i" << "audiolist.txt" <<"-c"<<"copy"<<targetfile ;
		m_progressBar->startProgress(argu,audioDur,"Merge Audio ...") ;
		argu.clear() ;
		argu << "-i" << m_tmpRecordingPath << "-i" << targetfile << "-codec" <<"copy"
			<<"-shortest" << m_savePath << "-y" ;
		m_progressBar->startProgress(argu,audioDur,"Finalizing ...") ;
		for( int i = 0; i < cnt; i++ ) {
			QFile::remove(uuidList.at(i)) ;
		}
		QFile::remove(m_tmpRecordingPath) ;
		QFile::remove(targetfile) ;
		m_tmp = getMSec(QTime::currentTime())-m_tmp ;
//		QMessageBox::information(NULL,"",QString::number(m_tmp)) ;
		QMessageBox::information(NULL,"","Success") ;
		setEnabled(true) ;
		return ;
	}
	QMessageBox::information(NULL,"","Failed") ;
	setEnabled(true) ;

//	ffmpeg -i video.avi -i output.mp3 -codec copy -shortest output.avi
	//ffmpeg -f concat -i mylist.txt -c copy output.wav
}

void MainWindow::onThemeChanged( int id )
{
	if( id < 0 || id >= ui->cb_theme->count() ) id = 0 ;
	QFile styleSheet(QString(":/res/qss/%1.qss").arg(id+1));
	if (!styleSheet.open(QIODevice::ReadOnly)) {
	}

	else setStyleSheet(styleSheet.readAll());
}


//////////////////////////////////////////////////////////////////////////
void MainWindow::maximize()
{
	m_isMaximized = true ;
	saveCurrentPosition();
	move(QApplication::desktop()->mapToGlobal(QApplication::desktop()->availableGeometry().topLeft()));
	resize(QApplication::desktop()->availableGeometry().size());
}
void MainWindow::normalize()
{
	m_isMaximized = false ;
	move(lastGlobalPosition);
	resize(lastSize);
}
void MainWindow::saveCurrentPosition()
{
	lastGlobalPosition = mapToGlobal(rect().topLeft());
	lastSize = size();
}

void MainWindow::onAudioStateChanged(QMediaPlayer::State state)
{
	return ;
	if( state == QMediaPlayer::PlayingState )
	{
		m_audioTrack->setPosition(m_audioTrack->duration()/2) ;
		return ;
		startPlaying(m_state) ;
	}
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event) ;
	refitTrimmerRect() ;
}

void MainWindow::showEvent(QShowEvent *event)
{
	QMainWindow::showEvent(event) ;
	refitTrimmerRect() ;
}

void MainWindow::refitTrimmerRect()
{
	m_trimmer->fit(QRect(ui->graphicsView->mapToGlobal(QPoint(0,0)),ui->graphicsView->size())) ;
	QPoint pnt = ui->graphicsView->mapToGlobal(QPoint(0,0)) ;
//	ui->lbl_title->setText(QString("%1 %2").arg(pnt.x()).arg(pnt.y())) ;
	if(m_fullScreenBtn) 
		m_fullScreenBtn->setGeometry(pnt.x()+30,pnt.y()+ui->graphicsView->height()-45,60,30) ;


	if(m_showCategoryBtn) 
		m_showCategoryBtn->setGeometry(pnt.x()-20,pnt.y()+ui->graphicsView->height()/2-30,30,60) ;
	if(m_playBtn) 
		m_playBtn->setGeometry(pnt.x()+20,pnt.y()+ui->graphicsView->height()-80,60,60) ;
	if( m_lockScreen )
	{
		QPoint pnt = ui->graphicsView->mapTo(this,QPoint(0,0)) ;
		m_lockScreen->setGeometry(pnt.x(),pnt.y(),ui->graphicsView->width(),ui->graphicsView->height()) ;
	}
	update() ;
	repaint() ;
}

void MainWindow::onShowCategory()
{
	m_fullScreenBtn->show() ;
	m_showCategoryBtn->hide() ;
	m_playBtn->hide() ;
	ui->w_left->show() ;
	int w = width() ;
	int h = height() ;
	ui->w_bottom_left->show() ;
	resize(w+1,h+1) ;
	resize(w,h) ;
//	refitTrimmerRect() ;
}

void MainWindow::onHideCategory()
{
	m_playBtn->show() ;
	m_fullScreenBtn->hide() ;
	m_showCategoryBtn->show() ;
	ui->w_left->hide() ;
	int w = width() ;
	int h = height() ;
	ui->w_bottom_left->hide() ;
	resize(w+1,h+1) ;
	resize(w,h) ;
//	refitTrimmerRect() ;
//	QMessageBox::information(NULL,"","A") ;
}

void MainWindow::onItemModeChanged( int id )
{
//	QMessageBox::information(NULL,"",QString::number(id)) ;
	CxGraphicsScene* sc = ui->graphicsView->currentScene() ;
	if( !sc ) return ;
	sc->setCurrentItemState(id) ;
}

void MainWindow::onDeleteCxItem()
{
	CxGraphicsScene* sc = ui->graphicsView->currentScene() ;
	if( !sc ) return ;
	sc->onRemoveCurItem() ;
}

void MainWindow::onRemoveAllItems()
{
	CxGraphicsScene* sc = ui->graphicsView->currentScene() ;
	if( !sc ) return ;
	sc->onRemoveAllItems() ;
}
void MainWindow::onCxItemSelectionChanged()
{
	setVisibleItemMode(false) ;
	ui->w_text_del->hide() ;
	ui->w_image_del->hide() ;
	ui->w_mark_del->hide() ;

	CxGraphicsScene* sc = ui->graphicsView->currentScene() ;
	if( !sc ) return ;
	QList<CxGraphicsItem*> itemList = sc->availableItems() ;
	for( int i = itemList.count()-1; i >= 0; i-- )
	{
		CxGraphicsItem* item = itemList.at(i) ;
		if( item->isSelected() && item->myType() == TEXTITEM )
		{
			setVisibleItemMode(true,item->itemState()) ;
			ui->w_text_del->show() ;
			return ;
		}
		if( item->isSelected() && item->myType() == PIXITEM )
		{
			ui->w_image_del->show() ;
			return ;
		}
		if( item->isSelected() && item->myType() == MARKITEM )
		{
			ui->w_mark_del->show() ;
			return ;
		}
	}
}

void MainWindow::setVisibleItemMode( bool on, int id )
{
	ui->rb_black_line->setVisible(on) ;
	ui->rb_white_line->setVisible(on) ;
	ui->rb_flex->setVisible(on) ;
	if( on && id == 2 ) ui->rb_white_line->setChecked(true) ;
	if( on && id == 1 ) ui->rb_black_line->setChecked(true) ;
	if( on && id == 0 ) ui->rb_flex->setChecked(true) ;
}

void MainWindow::copyToGlobal()
{
	CxGraphicsScene* sc = ui->graphicsView->currentScene() ;
	if( !sc ) return ;
	QList<CxGraphicsItem*> itemList = sc->availableItems() ;
	CxGraphicsItem* curItem = NULL ;
	for( int i = itemList.count()-1; i >= 0; i-- )
	{
		CxGraphicsItem* item = itemList.at(i) ;
		if( item->isSelected() ) curItem = item ;
	}
	if( !curItem ) return ;
	for( int i = m_sceneList->count()-1 ; i >= 0; i-- )
	{
		CxGraphicsScene* s = m_sceneList->sceneAt(i) ;
		if( s->sceneName() == sc->sceneName() ) continue ;
		s->pasteItem(curItem) ;
	}
}

void MainWindow::onScreenClicked()
{
	if( ui->tb_preview->isEnabled() ) {
		ui->tb_preview->click() ;
		if( !ui->w_left->isVisible() ) onShowCategory() ;
	}
}

void MainWindow::setButtonTransparent(QToolButton* btn)
{
	return ;
	btn->setPalette(Qt::transparent);
	btn->setAttribute( Qt::WA_TranslucentBackground, true );
	btn->setAttribute( Qt::WA_OpaquePaintEvent, true );
	btn->setAutoFillBackground(false);
	btn->setStyleSheet("QWidget{background-color: transparent;}");
	btn->setAttribute(Qt::WA_NoSystemBackground);
}

void MainWindow::onChangeSceneColor()
{
	CxGraphicsScene* sc = ui->graphicsView->currentScene() ;
	if( !sc ) return ;
	QColor col = QColorDialog::getColor(sc->bgBrush().color(),this) ;
	if( col.isValid() ) sc->setBgBrush(QBrush(col)) ;
}

void MainWindow::onCreateNewVideo()
{
//	ui->w_inside_single_image_video->hide() ;
	onPaint(CREATENEWMP4) ;
}

void MainWindow::onShowEditVideoWidget()
{
	if( ui->w_edit_video->isVisible() )
	{
		ui->w_edit_video->hide() ;
		return ;
	}
	ui->w_edit_video->show() ;
}

void MainWindow::onFreezeVideo()
{
	CxGraphicsScene* sc = ui->graphicsView->currentScene() ;	
	if( !sc )
	{
		QMessageBox::information(this,"Error","Please select video first.") ;
		return ;
	}
	onPaint(FREEVIDEOMODE) ;
	return ;
}

void MainWindow::onEditVideo()
{
	if( !ui->graphicsView->currentScene() )
	{
		QMessageBox::information(NULL,"", "You have to select video to edit.") ;
		return ;
	}
//	ui->w_inside_single_image_video->hide() ;
	onPaint(INSERTINSIDEVIDEO) ;
}

void MainWindow::onCreateSingleImageVideo()
{
/*
	if( ui->w_inside_single_image_video->isVisible() )
	{
		ui->w_inside_single_image_video->hide() ;
	}
	else
	{
		ui->w_inside_single_image_video->show() ;
		ui->w_logo_pos->hide() ;
	}
*/
//	onPaint(2) ;
}

void MainWindow::onSingleVideoAudioSelect()
{
	QString file = QFileDialog::getOpenFileName(this, tr("Select audio File"),"",tr("Audio files (*.mp3 *.wmv *.wav)"));
	if( !file.length() ) return ;
	ui->tb_single_video_audio->setText(file) ;
	m_singleVideoAudioPath = file ;
}

void MainWindow::onSingleVideoMp4Select()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Mp4 File"),"",tr("Videos (*.mp4 *.avi *.wmv)"));
	if( fileName.length() == 0 )    return ;
	m_singleVideoImagePath = "" ;
	m_singleVideoMp4Path = fileName ;
}

void MainWindow::onSingleVideoImageSelect()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Images (*.png *.xpm *.jpg)"));
	if( fileName.length() == 0 )    return ;
	QPixmap pix(fileName) ;
	if( pix.isNull() )
	{
		QMessageBox::information(NULL,"Error", "Invalid File Format") ;
		return ;
	}
	m_singleVideoImagePath = fileName ;
	m_singleVideoMp4Path = "" ;
}

void MainWindow::onSingleVideoCreate()
{
	if( !m_singleVideoAudioPath.length() )
	{
		QMessageBox::information(NULL,"","Audio is not choosen.") ;
		return ;
	}
	if( !m_singleVideoImagePath.length() && !m_singleVideoMp4Path.length() )
	{
		QMessageBox::information(NULL,"","Image or Mp4 file is not choosen.") ;
		return ;
	}
	QStringList args ;
	QString videouuid = QString("tmp/%1.mp4").arg(createSimpleUuid()) ;
	if( m_singleVideoMp4Path.length() )
	{
		args <<"-i"<< m_singleVideoMp4Path<<"-i" <<m_singleVideoAudioPath<< "-shortest" 
			<<"-c:v" <<"copy" <<"-map" <<"0:v:0" <<"-map"<< "1:a:0"<<"-r"<<"29.7"<< videouuid ;
	}
	else
	{
		args << "-loop" <<"1" << "-i"<< m_singleVideoImagePath <<"-i"<<
			m_singleVideoAudioPath<<"-shortest"<<"-acodec"<<"copy"<<"-c:v"<< "libx264"<< "-pix_fmt"
			<<"yuv420p"<< "-r" <<"29.7"<<videouuid ;
	}
	m_progressBar->setSingleAudioPath(m_singleVideoAudioPath) ;
	m_progressBar->startProgress(args,-1, "Creating Single Video...") ;
	CxLayerItem* item = ui->lw_layer->onAddVideoLayer(videouuid) ;
	createSceneConnection( item->myScene() ) ;
	return ;
}

void MainWindow::onAddIntroVideo()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Import videos into Intro library"),
		"",tr("Mp4 files (*.mp4 *.wmv *.avi)"));
	if( fileName.length() == 0 ) return ;
	CxLayerItem* item = ui->lw_intro_layer->onAddVideoLayer(fileName) ;
}

void MainWindow::onRemoveIntroVideo()
{
	ui->lw_intro_layer->deleteCurItem() ;
}

void MainWindow::onInsertIntroItem(QListWidgetItem* item)
{
	CxLayerItem* movie = (CxLayerItem*)item;
	CxLayerItem* newOne = ui->lw_layer->onAddVideoLayer(movie->filePath()) ;
	createSceneConnection( newOne->myScene() ) ;
}

void MainWindow::onAddTopLeftLogo()
{
	addLogo(1) ;
}

void MainWindow::onAddTopRightLogo()
{
	addLogo(2) ;
}

void MainWindow::onAddBottomLeftLogo()
{
	addLogo(3) ;
}

void MainWindow::onAddBottomRightLogo()
{
	addLogo(4) ;
}

void MainWindow::addLogo( int dir )
{
	CxGraphicsScene* sc = ui->graphicsView->currentScene() ;	
	if( !sc )
	{
		QMessageBox::information(this,"Error","Please select video first.") ;
		return ;
	}
	QString fileName = QFileDialog::getOpenFileName(this, tr("Add logo"),
		"/home",
		tr("Images (*.png *.xpm *.jpg)"));
	if( fileName.length() == 0 )    return ;
	QPixmap pix(fileName) ;
	if( pix.isNull() )
	{
		QMessageBox::information(NULL,"Error", "Invalid File Format") ;
		return ;
	}
	sc->addImageItem(fileName,0.2,dir) ;
}