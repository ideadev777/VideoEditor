#include "cxtextpopupdlg.h"
#include <QFile>
#include <QColorDialog>
#include <QFontDatabase>
#include <QMessageBox>
#include <QFileDialog>
#include <QApplication>
#include <QCloseEvent>
#include "common.h"
#include <QFileInfo>

#define FLEXWIDGETHEIGHT 50

CxTextPopupDlg::CxTextPopupDlg(QWidget *parent)
	: QDialog(parent){
	ui.setupUi(this) ;
	ui.w_inside_video->hide() ;
	setMouseTracking(true) ;
	QFile styleSheet(QString(":/res/qss/%1.qss").arg(4));
	if (!styleSheet.open(QIODevice::ReadOnly)) {
	}
//	else setStyleSheet(styleSheet.readAll());
	styleSheet.close() ;
	QFontDatabase db;
	foreach(int size, db.standardSizes()){
		ui.comboBox->addItem(QString::number(size));
	}
	ui.comboBox->setCurrentIndex(ui.comboBox->findText(QString::number(QApplication::font().pointSize())));

	m_process = new QProcess(this) ;
	m_process->setProcessChannelMode(QProcess::MergedChannels);

	ui.btn_text_group->setId(ui.tb_text_col_1, 0) ;
	ui.btn_text_group->setId(ui.tb_text_col_2, 1) ;
	ui.btn_text_group->setId(ui.tb_text_col_3, 2) ;
	ui.btn_text_group->setId(ui.tb_text_col_4, 3) ;
	ui.btn_text_group->setId(ui.tb_text_col_5, 4) ;

	m_flexbuttonWidget = new QWidget(this) ;
	m_flexbuttonWidget->setStyleSheet("QWidget{background-color:#C3C3C3;}");
	m_flexbuttonWidget->hide() ;
	m_flexTextBtn = new QToolButton(m_flexbuttonWidget) ;
	m_flexTextBtn->setStyleSheet("QWidget{background-color:#E1E1E1;}");
	m_flexTextBtn->setText("FLEX MODE") ;
	m_flexTextBtn->setFont(ui.tb_white_mode->font()) ;

	ui.tb_text_col_1->setColor(Qt::black) ;
	ui.tb_text_col_2->setColor(Qt::white) ;
	ui.tb_text_col_3->setColor(Qt::red) ;
	ui.tb_text_col_4->setColor(Qt::yellow) ;
	ui.tb_text_col_5->setColor(Qt::blue) ;

	initConnection() ;

	m_progressBar = new CxProgressDlg ;

	ui.textEdit->hide() ;

//	ui.w_item_duration_2->hide() ;
//	ui.w_item_duration->hide() ;
	ui.w_inside_video->show() ;
	m_curSelectedTextItem = NULL ;
	m_parentScene = NULL ;
	m_singleAudioPath = m_singleImagePath = "" ;

	ui.tb_image_fullscreen->setRole(FULLSCREENIMAGEBTN) ;
	ui.tb_image->setRole(INPUTIMAGEBTN) ;
	ui.tb_change_audio->setRole(ADDAUDIOBTN) ;
	ui.tb_movement->hide() ;
	ui.w_add_image->hide() ;
	ui.tb_justify->hide() ;
	ui.tb_right->hide() ;

	QStringList fontList ;
	fontList << "HoloLens MDL2 Assets"<<"Impact"<<"Arial Black"
		<<"Bahnschrift SemiCondensed"<<"Franklin Gothic Medium" ;
	for( int i = ui.fontComboBox->count()-1 ; i >= 0; i-- )
	{
		bool del = true ;
		for( int j = fontList.count()-1; j >= 0; j-- )
		{
			if( ui.fontComboBox->itemText(i)==fontList[j] ) del = false ;
		}
		if( del ) ui.fontComboBox->removeItem(i) ;
	}
}

void CxTextPopupDlg::initConnection()
{
	connect( ui.tb_freeze_save, SIGNAL(clicked()), this, SLOT(onCreateFreezeVideo())) ;
//	connect( ui.tb_dur_dec, SIGNAL(clicked()), ui.dsp_dur, SLOT(stepDown())) ;
//	connect( ui.tb_dur_inc, SIGNAL(clicked()), ui.dsp_dur, SLOT(stepUp())) ;
//	connect( ui.tb_dur_dec_2, SIGNAL(clicked()), ui.dsp_dur_2, SLOT(stepDown())) ;
//	connect( ui.tb_dur_inc_2, SIGNAL(clicked()), ui.dsp_dur_2, SLOT(stepUp())) ;

//	connect( ui.tb_new_video, SIGNAL(clicked()), this, SLOT(onCreateAction())) ;
	connect( ui.tb_create, SIGNAL(clicked()), this, SLOT(onCreateVideo())) ;
	connect( ui.tb_change_audio, SIGNAL(clicked()), this, SLOT(onSelectAudio())) ;
	connect( ui.tb_bold, SIGNAL(clicked()), this, SLOT(onBold())) ;
	connect( ui.tb_italic, SIGNAL(clicked()), this, SLOT(onItalic())) ;
	connect( ui.tb_underline, SIGNAL(clicked()), this, SLOT(onUnderline())) ;
	connect( ui.tb_left, SIGNAL(clicked()), this, SLOT(onLeft())) ;
	connect( ui.tb_right, SIGNAL(clicked()), this, SLOT(onRight())) ;
	connect( ui.tb_center, SIGNAL(clicked()), this, SLOT(onCenter())) ;
	connect( ui.tb_justify, SIGNAL(clicked()), this, SLOT(onJustify())) ;
//	connect( ui.tb_text_color, SIGNAL(clicked()), this, SLOT(onSelectTextColor())) ;
//	connect( ui.tb_background, SIGNAL(clicked()), this, SLOT(onSelectBackColor())) ;

	connect(ui.textEdit, SIGNAL(currentCharFormatChanged(QTextCharFormat)),
		this, SLOT(currentCharFormatChanged(QTextCharFormat)));
	connect(ui.textEdit, SIGNAL(cursorPositionChanged()),
		this, SLOT(cursorPositionChanged()));
	connect(ui.fontComboBox, SIGNAL(activated(QString)), this, SLOT(textFamily(QString)));
	connect(ui.comboBox, SIGNAL(activated(QString)), this, SLOT(textSize(QString)));
//	connect( ui.w_text_dropdown, SIGNAL(__addText(int)), this, SLOT(onInsertText(int))); 

	connect( m_process, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(onProcessFinished(int,QProcess::ExitStatus))) ;
	connect (m_process, SIGNAL(readyReadStandardOutput()), this, SLOT(onProcessStandardOutput()));

//	connect( ui.btn_back_group, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onBackColorClicked(QAbstractButton*))) ;
	connect( ui.btn_text_group, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onTextColorClicked(QAbstractButton*))) ;

	//////////////////////////////////////////////////////////////////////////
	connect( ui.tb_rect, SIGNAL(clicked()), this, SLOT(onDrawRect())) ;
	connect( ui.tb_circle, SIGNAL(clicked()), this, SLOT(onDrawCircle())) ;
	connect( ui.tb_line, SIGNAL(clicked()), this, SLOT(onDrawLine())) ;
	connect( ui.tb_mark, SIGNAL(clicked()), this, SLOT(onDrawMark())) ;
	connect( ui.tb_image, SIGNAL(clicked()), this, SLOT(onAddImage())) ;
	connect( ui.tb_image_fullscreen, SIGNAL(clicked()), this, SLOT(onAddFullScreenImage())) ;

	connect( ui.dsp_item_dur, SIGNAL(valueChanged(double)), this, SLOT(onSceneDurationChanged(double))) ;
	connect( ui.tb_item_dur_dec, SIGNAL(clicked()), ui.dsp_item_dur, SLOT(stepDown())) ;
	connect( ui.tb_item_dur_inc, SIGNAL(clicked()), ui.dsp_item_dur, SLOT(stepUp())) ;

//	connect( ui.tb_add_new_image, SIGNAL(clicked()), this, SLOT(onAddImageToScene())) ;
	connect( ui.tb_insert_into_video, SIGNAL(clicked()), this, SLOT(onInsertIntoVideo()) ) ;
	connect( ui.tb_white_mode, SIGNAL(__showFlexMenu()), this, SLOT(onShowFlexMenu())) ;
	connect( ui.tb_white_mode, SIGNAL(clicked()), this, SLOT(onWhiteTextClicked())) ;
	connect( m_flexTextBtn, SIGNAL(clicked()), this, SLOT(onFlexTextClicked())) ;
//	connect( ui.tb_image_fullscreen, SIGNAL(clicked()), this, SLOT(onImageFullScreen())) ;
	connect( ui.tb_fill, SIGNAL(clicked()), this, SLOT(onFill()) ) ;
	connect( ui.tb_arrow_left, SIGNAL(clicked()), this, SLOT(onLeftArrow())) ;
	connect( ui.tb_arrow_right, SIGNAL(clicked()), this, SLOT(onRightArrow())) ;
	connect( ui.tb_arrow_up, SIGNAL(clicked()), this, SLOT(onUpArrow())) ;
	connect( ui.tb_arrow_down, SIGNAL(clicked()), this, SLOT(onDownArrow())) ;
	connect( ui.tb_movement, SIGNAL(clicked()), this, SLOT(onMovementMode())) ;
// 	connect( ui.tb_single_video_audio, SIGNAL(clicked()), this, SLOT(onSelectSingleImageAudio())) ;
// 	connect( ui.tb_single_video_image, SIGNAL(clicked()), this, SLOT(onSelectSingleImage())) ;
// 	connect( ui.tb_save_single_video, SIGNAL(clicked()), this, SLOT(onCreateSingleVideo())) ;

	connect( ui.tb_next_video, SIGNAL(clicked()), this, SLOT(onNextVideo())) ;
	connect( ui.tb_prev_video, SIGNAL(clicked()), this, SLOT(onPrevVideo())) ;
	connect( ui.tb_add_new_scene, SIGNAL(clicked()), this, SLOT(onAddNewScene())) ;
	connect( ui.tb_delete_scene, SIGNAL(clicked()), this, SLOT(onDeleteScene())) ;

	connect( ui.tb_play, SIGNAL(clicked()), this, SLOT(onPlay())) ;
	connect( ui.tb_delete_item, SIGNAL(clicked()), this, SLOT(onDeleteItem())) ;

	connect( ui.tb_show_image_panel, SIGNAL(clicked()), this, SLOT(onShowAddImagePanel()) ) ;
	connect( ui.tb_insert_black_circle_mark,SIGNAL(clicked()), this, SLOT(onAddBlackCircle())) ;
}

CxTextPopupDlg::~CxTextPopupDlg()
{

}

void CxTextPopupDlg::onShowAddImagePanel()
{
	if( ui.w_add_image->isVisible() ) ui.w_add_image->hide() ;
	else ui.w_add_image->show() ;
}

void CxTextPopupDlg::onCreateAction()
{
}

void CxTextPopupDlg::onCreateVideo(int role)
{
	m_audioSt = getMSec(ui.te_start->time()) ;
	m_audioEn = getMSec(ui.te_end->time()) ;
	if( ui.te_end->time() != ui.te_end->maximumTime() ) 
	{
		m_audioEn -= m_audioEn%1000 ;
	}
	m_itemDur = 0;
	foreach( CxGraphicsScene* sc, m_sceneList ) m_itemDur += sc->totalMSec() ;
	if( m_audioPath.length() == 0 ) {
		m_audioPath = "silence.wav" ;
		m_audioSt = 0 ;
		m_audioEn = m_itemDur ;
	}
	if( m_audioEn <= m_audioSt ) 
	{
		QMessageBox::information(NULL,"this","Invalid duration!") ;
		return ;
	}
	if( m_audioEn-m_audioSt < m_itemDur )
	{
		QMessageBox::information(NULL,"this", "Audio duration is smaller than text's duration") ;
		return ;
	}
	QString uuid = QString("tmp/%1.mp3").arg(createSimpleUuid()) ;
	QStringList argu ;
	argu << "-i" <<  m_audioPath << "-ss" << 
		getTime(m_audioSt).toString("hh:mm:ss.zzz")
		<< "-t" << getTime(m_audioEn-m_audioSt).toString("hh:mm:ss.zzz")
		<< "-vn" << "-ac" << "2" << "-ar" << "44100" << "-ab" << "320k"
		<< "-f" << "mp3" << uuid ;

	m_progressBar->startProgress(argu,m_audioEn-m_audioSt,"Audio Initializing ...") ;

	m_audioPath = uuid ;
	m_addState = role ;
	setItemData() ;
	accept() ;
}

void CxTextPopupDlg::onInsertIntoVideo()
{
	onCreateVideo(INSERTINSIDEVIDEO) ;
}

void CxTextPopupDlg::setItemData()
{
	m_item->textItem()->setHtml(ui.textEdit->toHtml()) ;
	m_item->setItemState(0) ;
//	CxColorButton* btn = (CxColorButton*) ui.btn_back_group->checkedButton() ;
//	if( btn ) m_item->setBrush(QBrush(btn->color())) ;
}

void CxTextPopupDlg::onInsertText( int id )
{
	onMovementMode() ;
	CxTextItem* item = m_scene->addTextItem() ;
	item->setEditorVisible(false) ;
	m_scene->setItemState(item,id) ;
	return ;
}

void CxTextPopupDlg::initMe( int role )
{
	m_dlgRole = role ;
	ui.groupBox_audio->hide() ;
	m_close = false ;
	m_item = new CxTextItem ;
	m_audioTmp = m_audioPath = "" ;
	ui.textEdit->setHtml(m_item->textItem()->toHtml()) ;
	m_curSceneId = 0 ;
	m_scene = NULL ;
	onAddNewScene() ;
	m_isPlaying = false ;
	m_audioTrack = new QMediaPlayer(this) ;
	ui.tb_new_video->setVisible(role==CREATENEWMP4) ;
	ui.tb_inside_video->setVisible(role==INSERTINSIDEVIDEO) ;
	ui.tb_create->setVisible(role==CREATENEWMP4) ;
	ui.w_inside_video->setVisible(role==INSERTINSIDEVIDEO) ;

	ui.w_freeze->setVisible(role==FREEVIDEOMODE) ;
	ui.tb_freeze->setVisible(role==FREEVIDEOMODE) ;
	ui.tb_freeze_save->setVisible(role==FREEVIDEOMODE) ;
//	QMessageBox::information(NULL,"","AAAA") ;
//	ui.w_draw_panel->setVisible(role<2) ;
//	ui.tb_single_image_vid->setVisible(role==2) ;
//	ui.w_inside_single_image_video->setVisible(role==2) ;
	ui.lbl_seek->showFreezeSeekBar(role==FREEVIDEOMODE) ;
	ui.w_scene_control->setVisible(role!=FREEVIDEOMODE) ;

	ui.groupBox_audio->setVisible(role!=FREEVIDEOMODE) ;
	ui.w_audio_dur->setVisible(role!=FREEVIDEOMODE) ;
	ui.tb_change_audio->setVisible(role!=FREEVIDEOMODE) ;
}

void CxTextPopupDlg::setParentScene(CxGraphicsScene* sc)
{
	m_parentScene = sc ;
	if( m_dlgRole == FREEVIDEOMODE )
	{
		m_scene->setVideoPath(sc->videoPath()) ;
		

		VideoCapture cap(sc->videoPath().toStdString()) ;
		Mat img ;
		int totMSec = 0 ;
		if( cap.isOpened() ) {
			totMSec = 1000*cap.get(CV_CAP_PROP_FRAME_COUNT)/cap.get(CV_CAP_PROP_FPS) ;
			cap.release() ;
		}
		m_scene->setTotalMSec(totMSec) ;
		ui.lbl_seek->setDuration(totMSec) ;
		m_scene->setVideoRange(0,totMSec) ;
		m_scene->preview(100) ;
		connect( ui.lbl_seek, SIGNAL(__scenePreview(int,bool)), this, SLOT(onScenePreview(int,bool))) ;
	}
	ui.w_inside_video->setEnabled(sc) ;
	if( sc )
	{
		ui.te_insert_pos->setMaximumTime(getTime(sc->totalMSec())) ;
	}
}

void CxTextPopupDlg::setTextItemAlignment( Qt::Alignment val )
{
	if( !m_curSelectedTextItem ) return ;
	QTextCursor cursor = m_curSelectedTextItem->textItem()->textCursor() ;
	QTextBlockFormat bfmt = cursor.blockFormat() ;
	bfmt.setAlignment(val) ;
	cursor.mergeBlockFormat(bfmt) ;
}

void CxTextPopupDlg::onLeft()
{
	ui.tb_right->setChecked(false) ;
	ui.tb_center->setChecked(false) ;
	ui.tb_justify->setChecked(false) ;
	setTextItemAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
}

void CxTextPopupDlg::onRight()
{
	ui.tb_left->setChecked(false) ;
	ui.tb_center->setChecked(false) ;
	ui.tb_justify->setChecked(false) ;
	setTextItemAlignment(Qt::AlignRight | Qt::AlignAbsolute);
}

void CxTextPopupDlg::onCenter()
{
	ui.tb_left->setChecked(false) ;
	ui.tb_right->setChecked(false) ;
	ui.tb_justify->setChecked(false) ;
	setTextItemAlignment(Qt::AlignHCenter);
}

void CxTextPopupDlg::onJustify()
{
	ui.tb_left->setChecked(false) ;
	ui.tb_right->setChecked(false) ;
	ui.tb_center->setChecked(false) ;
	setTextItemAlignment(Qt::AlignJustify);
}

void CxTextPopupDlg::onBold()
{
	QTextCharFormat fmt;
	fmt.setFontWeight(ui.tb_bold->isChecked() ? QFont::Bold : QFont::Normal);
	mergeFormatOnWordOrSelection(fmt);
}

void CxTextPopupDlg::onItalic()
{
	QTextCharFormat fmt;
	fmt.setFontItalic(ui.tb_italic->isChecked()) ;
	mergeFormatOnWordOrSelection(fmt);
}

void CxTextPopupDlg::onUnderline()
{
	QTextCharFormat fmt;
	fmt.setFontUnderline(ui.tb_underline->isChecked()) ;
	mergeFormatOnWordOrSelection(fmt);
}

void CxTextPopupDlg::onSelectBackColor()
{
	QColor col = QColorDialog::getColor(ui.textEdit->textColor(), this);
	if (!col.isValid())
		return;
//	ui.tb_background->setColor(col) ;
	ui.textEdit->setStyleSheet(QString("QTextEdit{background-color:%1;}").arg(col.name()));
}

void CxTextPopupDlg::onSelectTextColor()
{
	QColor col = QColorDialog::getColor(ui.textEdit->textColor(), this);
	if (!col.isValid())
		return;
	QTextCharFormat fmt;
	fmt.setForeground(col);
	mergeFormatOnWordOrSelection(fmt);
//	ui.tb_text_color->setColor(col) ;
}

void CxTextPopupDlg::currentCharFormatChanged(const QTextCharFormat &format)
{
	QFont f = format.font() ;
	ui.fontComboBox->setCurrentIndex(ui.fontComboBox->findText(QFontInfo(f).family()));
	ui.comboBox->setCurrentIndex(ui.comboBox->findText(QString::number(f.pointSize())));
	ui.tb_bold->setChecked(f.bold());
	ui.tb_italic->setChecked(f.italic());
	ui.tb_underline->setChecked(f.underline());
//	ui.tb_text_color->setColor(format.foreground().color()) ;
	QColor col = format.foreground().color() ;
	for( int i = 0; i < 5; i++ )
	{
		CxColorButton* btn = (CxColorButton*)ui.btn_text_group->button(i) ;
		if( btn->color() == col ) btn->setChecked(true) ;
	}
}

void CxTextPopupDlg::cursorPositionChanged()
{
	alignmentChanged(ui.textEdit->alignment());
}

void CxTextPopupDlg::textFamily(const QString &f)
{
	QTextCharFormat fmt;
	fmt.setFontFamily(f);
	mergeFormatOnWordOrSelection(fmt);
}

void CxTextPopupDlg::textSize(const QString &p)
{
	qreal pointSize = p.toFloat();
	if (p.toFloat() > 0) {
		QTextCharFormat fmt;
		fmt.setFontPointSize(pointSize);
		mergeFormatOnWordOrSelection(fmt);
	}
}


void CxTextPopupDlg::alignmentChanged(Qt::Alignment a)
{
	ui.tb_left->setChecked(a & Qt::AlignLeft) ;
	ui.tb_center->setChecked(a & Qt::AlignHCenter) ;
	ui.tb_justify->setChecked(a & Qt::AlignJustify) ;
	ui.tb_right->setChecked(a & Qt::AlignRight) ;
}

void CxTextPopupDlg::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
	if( !m_curSelectedTextItem ) return ;
	QTextCursor cursor = m_curSelectedTextItem->textItem()->textCursor() ;
	if (!cursor.hasSelection())
		cursor.select(QTextCursor::Document);
	cursor.mergeCharFormat(format) ;
	/*
	QTextCursor cursor = ui.textEdit->textCursor();
	if (!cursor.hasSelection())
		cursor.select(QTextCursor::WordUnderCursor);
	cursor.mergeCharFormat(format);
	ui.textEdit->mergeCurrentCharFormat(format);
	*/
}

void CxTextPopupDlg::onSelectAudio()
{
	QString file = QFileDialog::getOpenFileName(this, tr("Select audio File"),"",tr("Audio files (*.mp3 *.wmv *.wav)"));
	if( !file.length() ) return ;
	m_audioTmp = file ;
	QApplication::setOverrideCursor(Qt::WaitCursor) ;
	QStringList args ;
	args << "-i" << file ;//<<"-vn"<<"-ac"<<"2"<<"-ar"<<"44100"<<"-ab"<<"320k"<<"-f"<<"mp3"<<"output.mp3" ;
	//-vn -ac 2 -ar 44100 -ab 320k -f mp3 output.mp3
	//	QApplication::setOverrideCursor(Qt::WaitCursor) ;
	m_processState = CALCDURATIONSTATE ;
	m_process->start("ffmpeg.exe", args) ;
}

void CxTextPopupDlg::onProcessStandardOutput()
{
	QString str = m_process->readAllStandardOutput();
	if( str.contains("Duration:")) 
	{
		int pos = str.indexOf("Duration:") ;
		int dur = getMSec(QTime::fromString(str.mid(pos+10,11),"hh:mm:ss.z")) ;
		if( dur <= 0 ) return ;
		QTime t(0,0,0) ;
		t = t.addMSecs(dur) ;
		ui.te_total->setTime(t) ;
		ui.te_start->setMaximumTime(t) ;
		ui.te_start->setTime(QTime(0,0,0)) ;
		ui.te_end->setMaximumTime(t) ;
		ui.te_end->setTime(t) ;
		m_audioPath = m_audioTmp ;
		ui.tb_change_audio->setText(QFileInfo(m_audioPath).fileName()) ;
		ui.tb_change_audio->repaint();
	}
}

void CxTextPopupDlg::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
	QApplication::restoreOverrideCursor() ;
}

void CxTextPopupDlg::onTextColorClicked(QAbstractButton* btn)
{
	CxColorButton* b = (CxColorButton*) btn ;
	QList<CxGraphicsItem*> itemList = m_scene->availableItems() ;
	m_scene->setDrawColor(b->color()) ;
	if( !m_curSelectedTextItem ){
		for( int i = itemList.count()-1; i >= 0; i-- )
		{
			CxGraphicsItem* item = itemList[i] ;
			if( !item->isSelected() ) continue ;
			if( item->myType() == MARKITEM ) item->setPen(QPen(QBrush(b->color()),5)) ;
		}
		return ;
	}

	QTextCharFormat fmt;
	fmt.setForeground(b->color());
	mergeFormatOnWordOrSelection(fmt);

}

void CxTextPopupDlg::onBackColorClicked(QAbstractButton* btn)
{
	CxColorButton* b = (CxColorButton*) btn ;
	ui.textEdit->setStyleSheet(QString("QTextEdit{background-color:%1;}").arg(b->color().name()));
}

//////////////////////////////////////////////////////////////////////////

void CxTextPopupDlg::onAddFullScreenImage()
{
	onAddImage(true) ;
}

void CxTextPopupDlg::onAddImage(bool isFullScreen)
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Images (*.png *.xpm *.jpg)"));
	if( fileName.length() == 0 )    return ;
	QPixmap pix(fileName) ;
	if( pix.isNull() )
	{
		QMessageBox::information(NULL,"Error", "Invalid File Format") ;
		return ;
	}
	CxImageItem* item = m_scene->addImageItem(fileName) ;
	if( isFullScreen ) item->fitToScene() ;
	onMovementMode() ;
	ui.w_add_image->hide() ;
}

void CxTextPopupDlg::onDeleteItem()
{
	m_scene->onRemoveCurItem() ;
}

void CxTextPopupDlg::onDrawRect()
{
	draw(RECTMARKROLE) ;
}

void CxTextPopupDlg::onDrawMark()
{
	draw(NUMBERMARKROLE) ;
}

void CxTextPopupDlg::onDrawLine()
{
	draw(LINEMARKROLE) ;
}

void CxTextPopupDlg::onDrawCircle()
{
	draw(CIRCLEMARKROLE) ;
}

void CxTextPopupDlg::draw( int role )
{
	QColor col(Qt::black) ;
	CxColorButton* btn = (CxColorButton*) ui.btn_text_group->checkedButton() ;
	if( btn ) col = btn->color() ;
//	if( btn ) m_item->setBrush(QBrush(btn->color())) ;
	ui.graphicsView->onDrawMark(role,col) ;
}

void CxTextPopupDlg::onItemSelectionChanged()
{
	QList<CxGraphicsItem*> itemList = m_scene->availableItems() ;
	m_curSelectedTextItem = NULL ;
	foreach( CxGraphicsItem* item, itemList )
	{
		if( item->isSelected() && item->myType() == TEXTITEM ) 
		{
			m_curSelectedTextItem = (CxTextItem*)item ;
			QTextCursor cursor = m_curSelectedTextItem->textItem()->textCursor() ;
			if (!cursor.hasSelection())
				cursor.select(QTextCursor::Document);
			alignmentChanged(cursor.blockFormat().alignment());
			currentCharFormatChanged(cursor.charFormat()) ;
		}
	}
}

void CxTextPopupDlg::onAddImageToScene()
{
	if( !m_parentScene )
	{
		QMessageBox::information(NULL, "Error", "No scene exists to add image.") ;
		return ;
	}
	m_close = true ;
	m_addState = ADDIMAGETOSCENE ;
	accept() ;
}

void CxTextPopupDlg::onSave()
{
}

void CxTextPopupDlg::closeEvent(QCloseEvent* event)
{
	if( m_close ) {
		startPlay(false) ;
		event->accept() ;
		return ;
	}
	startPlay(false) ;
	event->accept() ;
	return ;
	int ret = QMessageBox::question(this, "Confirm" , "Save changes?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel ) ;
	if( ret == QMessageBox::Yes )
	{
		onSave() ;
		return ;
	}
	if( ret == QMessageBox::No ) {
		startPlay(false) ;
		event->accept() ;
	}
	else event->ignore() ;
}

QPixmap CxTextPopupDlg::getImage()
{
	m_scene->clearSelection() ;
	return m_scene->renderToPix() ;
}

void CxTextPopupDlg::onShowFlexMenu(bool on/* =true */)
{
//	setMouseTracking(on) ;
	if( on )
	{
		QPoint pnt = ui.tb_white_mode->mapTo(this,QPoint(0,ui.tb_white_mode->height())) ;
		m_flexbuttonWidget->setGeometry(QRect(pnt,QSize(ui.tb_white_mode->width(),FLEXWIDGETHEIGHT))) ;
		int delta = 4;
		m_flexTextBtn->setGeometry(delta,delta,ui.tb_white_mode->width()-2*delta,FLEXWIDGETHEIGHT-2*delta) ;
	}

	m_flexbuttonWidget->setVisible(on) ;
}

void CxTextPopupDlg::mouseMoveEvent(QMouseEvent *event)
{
	QDialog::mouseMoveEvent(event) ;
	QPoint pnt = event->pos() ;
//	ui.tb_new_video->setText(QString("%1 %2").arg(pnt.x()).arg(pnt.y())) ;
	if( !m_flexbuttonWidget->isVisible() ) return ;
	bool flg = false ;
	if( ui.tb_white_mode->geometry().contains(pnt) )  flg = true ;
	if( m_flexbuttonWidget->geometry().contains(pnt) ) flg = true ;
	if( !flg ) onShowFlexMenu(false) ;
}

void CxTextPopupDlg::onWhiteTextClicked()
{
	onShowFlexMenu(false) ;
	onInsertText(2) ;
}

void CxTextPopupDlg::onFlexTextClicked()
{
	onShowFlexMenu(false) ;
	onInsertText(0) ;
}

void CxTextPopupDlg::onImageFullScreen()
{
	QList<CxGraphicsItem*> itemList = m_scene->availableItems() ;
	foreach( CxGraphicsItem* item, itemList )
	{
		if( !item->isSelected() || item->myType() != PIXITEM ) continue ;
		item->fitToScene() ;
		m_scene->rearrangeCtrlList() ;
	}
}

void CxTextPopupDlg::onFill()
{
	//
	CxColorButton* btn = (CxColorButton*) ui.btn_text_group->checkedButton() ;
//	m_scene->setBgBrush(QBrush(btn->color())) ;
	m_scene->setFillMode() ;
}

void CxTextPopupDlg::onLeftArrow()
{
	draw(LEFTARROWROLE) ;
}

void CxTextPopupDlg::onRightArrow()
{
	draw(RIGHTARROWROLE) ;
}

void CxTextPopupDlg::onUpArrow()
{
	draw(UPARROWROLE) ;
}

void CxTextPopupDlg::onDownArrow()
{
	draw(DOWNARROWROLE) ;
}

void CxTextPopupDlg::onMovementMode()
{
	m_scene->setMovementMode() ;
}

void CxTextPopupDlg::onSelectSingleImageAudio()
{
	QString file = QFileDialog::getOpenFileName(this, tr("Select audio File"),"",tr("Audio files (*.mp3 *.wmv *.wav)"));
	if( !file.length() ) return ;
//	ui.lb_single_video_audio->setText(file) ;
	m_singleAudioPath = file ;
}

void CxTextPopupDlg::onSelectSingleImage()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Images (*.png *.xpm *.jpg)"));
	if( fileName.length() == 0 )    return ;
	QPixmap pix(fileName) ;
	if( pix.isNull() )
	{
		QMessageBox::information(NULL,"Error", "Invalid File Format") ;
		return ;
	}
	m_singleImagePath = fileName ;
}

void CxTextPopupDlg::onCreateSingleVideo()
{
	if( !m_singleImagePath.length() )
	{
		QMessageBox::information(NULL,"Error", "Please choose image file.") ;
		return ;
	}
	if( !m_singleAudioPath.length() )
	{
		QMessageBox::information(NULL,"Error", "Please choose audio file.") ;
		return ;
	}
	m_addState = SINGLEVIDEOMODE ;
	accept() ;
}

QPixmap CxTextPopupDlg::getFreezeImage()
{
	m_scene->preview(ui.lbl_seek->freezeTime()) ;
	return m_scene->renderToPix() ;
}

void CxTextPopupDlg::onCreateFreezeVideo()
{
	m_addState = FREEVIDEOMODE ;
	accept() ;
}

void CxTextPopupDlg::onNextVideo()
{
	if( m_curSceneId >= m_sceneList.count()-1 ) return ;
	m_curSceneId++ ;
	setCurrentScene(m_curSceneId) ;
}

void CxTextPopupDlg::onPrevVideo()
{
	if( !m_curSceneId ) return ;
	m_curSceneId-- ;
	setCurrentScene(m_curSceneId) ;
}

void CxTextPopupDlg::setCurrentScene(int id)
{
	if( m_scene ){
		m_scene->setMovementMode() ;
	}
	m_curSceneId = id ;
	m_scene = m_sceneList.at(id) ;
	ui.graphicsView->setMyScene(m_sceneList[id]) ;
	ui.lbl_video_index->setText(QString(" %1 / %2 ").arg(id+1).arg(m_sceneList.count())) ;
	ui.dsp_item_dur->setValue(m_scene->totalMSec()/1000.0) ;
}

void CxTextPopupDlg::onAddNewScene()
{
	CxGraphicsScene* sc = new CxGraphicsScene(NULL) ;
	sc->setBgBrush(QBrush(Qt::white)) ;
	connect( sc, SIGNAL(__initDrawRole()), this, SLOT(onInitDrawRole())) ;
	connect( sc, SIGNAL(selectionChanged()), this, SLOT(onItemSelectionChanged())) ;
	m_sceneList.insert(m_curSceneId+1,sc) ;
	setCurrentScene(m_curSceneId+!!(m_sceneList.count()-1)) ;
//	setDurationToSeekBar() ;
}

void CxTextPopupDlg::onDeleteScene()
{
	if( m_sceneList.count() == 1 )
	{
		QMessageBox::information(NULL,"Error","There is only one image so you can't delete this.") ;
		return ;
	}
	if( m_curSceneId < m_sceneList.count()-1 )
	{
		m_sceneList.takeAt(m_curSceneId) ;
		setCurrentScene(m_curSceneId) ;
	}
	else
	{
		m_sceneList.takeAt(m_curSceneId) ;
		setCurrentScene(m_curSceneId-1) ;
	}
//	setDurationToSeekBar() ;
}

void CxTextPopupDlg::onSceneDurationChanged( double val )
{
	int msec = val * 1000 ;
	m_scene->setTotalMSec(msec) ;
	m_scene->setVideoRange(0,msec) ;
//	setDurationToSeekBar() ;
}

int CxTextPopupDlg::insertTimeMSec()
{
	return getMSec( ui.te_insert_pos->time() ) ;
}

void CxTextPopupDlg::onPlay()
{
	startPlay(!m_isPlaying) ;
}

void CxTextPopupDlg::startPlay( bool on )
{
	if( on ) freeze(false) ;
	else freeze(true) ;
	ui.lbl_seek->setPlayState(on) ;
	ui.sp_freeze_duration->setEnabled(!on) ;
	ui.w_scene_control->setEnabled(!on) ;
	ui.tb_play->setChecked(on) ;
	m_isPlaying = on ;
	m_audioSeeked = false ;
//	QMessageBox::information(NULL,"",QString("%1 %2").arg(m_audioPath).arg(on)) ;
	if( on ) {
		setCurrentScene(0) ;
		if( m_dlgRole == FREEVIDEOMODE ) m_audioPath = m_scene->videoPath() ;
		if( m_audioPath.length() )
		{
			m_audioSt = getMSec(ui.te_start->time()) ;
			m_audioEn = getMSec(ui.te_end->time()) ;
			if( m_dlgRole == FREEVIDEOMODE )
			{
				m_audioSt = 0 ;
				m_audioEn = m_scene->totalMSec() ;
			}
			if( m_audioEn <= m_audioSt )
			{
				QMessageBox::information(NULL,"Error", "Audio duration is invalid") ;
				startPlay(false) ;
				return ;
			}
			if( m_dlgRole != FREEVIDEOMODE ) ui.lbl_seek->setDuration(m_audioEn-m_audioSt) ;
			m_timer.start(50,this) ;
			m_audioTrack->setMedia(QUrl::fromLocalFile(m_audioPath));
			m_audioTrack->setVolume(0);
			m_audioTrack->play(); // music can be heard
		}
		else
		{
			int dur = 0 ;
			foreach( CxGraphicsScene* sc, m_sceneList ) dur += sc->totalMSec() ;
			ui.lbl_seek->setDuration(dur) ;
			m_playStartTime = getMSec(QTime::currentTime()) ;
			m_timer.start(50,this) ;
		}
	}
	else
	{
		ui.lbl_seek->init() ;
		m_timer.stop() ;
		m_audioTrack->stop() ;
	}
}


void CxTextPopupDlg::timerEvent(QTimerEvent* event)
{
	if( event->timerId() != m_timer.timerId() ) return ;
	if( !m_isPlaying ) return ;
	if( !m_audioPath.length() )
	{
		int elapsed = getMSec(QTime::currentTime())-m_playStartTime ;
		int cnt = m_sceneList.count() ;
		int s = 0 ;
		for( int i = 0 ; i < cnt; i++ )
		{
			s += m_sceneList.at(i)->totalMSec() ;
			if( s >= elapsed || i == cnt-1 )
			{
				setCurrentScene(i) ;
				break ;
			}
		}
		ui.lbl_seek->setCurrentSeek(elapsed) ;
		if( elapsed >= s ) startPlay(false) ;
		return ;
	}
	if( !m_audioTrack->isSeekable() ) return ;
	qint64 cur = m_audioTrack->position() ;
	int curTime = getMSec(QTime::currentTime()) ;
	int elapsed = cur-m_audioSt ;
	if( cur >= m_audioEn )
	{
		startPlay(false) ;
		return ;
	}
	if( m_dlgRole == FREEVIDEOMODE )
	{
		if( !m_audioSeeked )
		{
			m_audioSeeked = true ;
			m_SeekStartTime = ui.lbl_seek->currentSeek() ;
			m_audioTrack->setPosition(m_SeekStartTime) ;
			m_audioTrack->setVolume(100) ;
			m_curSceneElapsed = m_SeekStartTime ;
			m_playStartTime = getMSec(QTime::currentTime()) ;
		}
		int freezetime = ui.lbl_seek->freezeTime() ;
		int freezeDur = ui.sp_freeze_duration->value()*1000 ;
		elapsed = curTime-m_playStartTime+m_SeekStartTime ;
		if(  elapsed >= freezetime && freezetime+freezeDur >= elapsed )
		{
			freeze(true) ;
			m_audioTrack->pause() ;
			return ;
		}
		if( m_isFreezeState )
		{
			freeze(false) ;
			m_audioTrack->setPosition(freezetime) ;
			m_audioTrack->play() ;
		}
//		if( m_audioTrack->state() == QMediaPlayer::PlayingState )
		ui.lbl_seek->setCurrentSeek(cur) ;
		return ;
	}
	if( !m_audioSeeked )
	{
		m_audioSeeked = true ;
		m_audioTrack->setPosition(m_audioSt) ;
		m_audioTrack->setVolume(100) ;
		m_curSceneElapsed = 0 ;
		m_playStartTime = getMSec(QTime::currentTime()) ;
	}
	int cnt = m_sceneList.count() ;
	int s = 0 ;
	for( int i = 0 ; i < cnt; i++ )
	{
		s += m_sceneList.at(i)->totalMSec() ;
		if( s >= elapsed || i == cnt-1 )
		{
			setCurrentScene(i) ;
			break ;
		}
	}
	ui.lbl_seek->setCurrentSeek(cur-m_audioSt) ;
}

void CxTextPopupDlg::setDurationToSeekBar() 
{
	int dur = 0 ;
	for( int i = m_sceneList.count()-1; i >= 0; i-- ) dur += m_sceneList.at(i)->totalMSec() ;
	ui.lbl_seek->setDuration(dur) ;
}

void CxTextPopupDlg::onAddBlackCircle()
{
	if( ui.tb_insert_black_circle_mark->isChecked() )
	{
		draw(BLACKCIRCLEROLE) ;
	}
	else
	{
		m_scene->setMovementMode() ;		
	}
}

void CxTextPopupDlg::onInitDrawRole()
{
	ui.tb_insert_black_circle_mark->setChecked(false) ;
}


void CxTextPopupDlg::onScenePreview(int msec, bool isPressed)
{
	if( m_isPlaying && isPressed )
	{
		m_SeekStartTime = ui.lbl_seek->currentSeek() ;
		m_audioTrack->setPosition(m_SeekStartTime) ;
		m_audioTrack->setVolume(100) ;
		m_curSceneElapsed = m_SeekStartTime ;
		m_playStartTime = getMSec(QTime::currentTime()) ;
	}
	m_scene->preview(msec) ;
}

void CxTextPopupDlg::freeze( bool on )
{
	m_isFreezeState = on ;
	QList<CxGraphicsItem*> itemList = m_scene->allItems() ;
	foreach( CxGraphicsItem* item, itemList ) item->setVisible(on) ;
}

void CxTextPopupDlg::setSceneSize( QSize sz )
{
	ui.graphicsView->setSceneRect( 0, 0, sz.width(), sz.height() );
	m_scene->setSceneRect(0,0,sz.width(),sz.height()) ;
}