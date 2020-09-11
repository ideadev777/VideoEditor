#ifndef CXTEXTPOPUPDLG_H
#define CXTEXTPOPUPDLG_H

#include <QDialog>
#include <QProcess>
#include <QTime>
#include <QMediaPlayer>
#include <QBasicTimer>
#include <QTimerEvent>

#include "cxgraphicsscene.h"
#include "ui_dlg_text_select.h"
#include "cxtextitem.h"
#include "cxprogressdlg.h"

#define CREATENEWMP4 0
#define INSERTINSIDEVIDEO 1
#define ADDIMAGETOSCENE 2
#define SINGLEVIDEOMODE 3
#define FREEVIDEOMODE 4

#define CALCDURATIONSTATE 0
#define CREATEAUDIOSTATE 1

class CxTextPopupDlg : public QDialog
{
	Q_OBJECT

public:
	CxTextPopupDlg(QWidget *parent);
	~CxTextPopupDlg();
	Ui::Dialog_Text_Popup form(){ return ui ;}
	void initMe( int role ) ;
	void setParentScene(CxGraphicsScene* sc) ;
	void setCurrentScene(int sceneId) ;
	CxTextItem* textItem(){ return m_item ; }
	int state(){ return m_addState ; }
	bool isNewMovie(){ return m_addState == CREATENEWMP4 ; }
	QString audioPath(){ return m_audioPath ; }
	QString singleVideoAudioPath(){ return m_singleAudioPath ; }
	QString singleVideoImagePath(){ return m_singleImagePath ; }
	int audioDuration(){ return m_audioEn - m_audioSt ; }
	int textDuration(){ return m_itemDur ; }
	QPixmap getImage() ;
	QPixmap getFreezeImage() ;
	void setSceneExist( bool on ) ;
	QList<CxGraphicsScene*> sceneList(){ return m_sceneList ; }
	CxGraphicsScene* parentScene(){ return m_parentScene ; }
	int insertTimeMSec() ;
	void setSceneSize( QSize sz ) ;
	int freezeTime(){ return ui.lbl_seek->freezeTime() ; }
protected:
	void closeEvent(QCloseEvent* event) ;
	void mouseMoveEvent(QMouseEvent *event) ;
	void timerEvent(QTimerEvent* event) ;
private slots:
	void onCreateAction() ;
	void onSelectAudio() ;
	void onCreateVideo(int role=CREATENEWMP4) ;
	void onInsertIntoVideo() ;
	void onBold() ;
	void onItalic() ;
	void onUnderline() ;
	void onLeft() ;
	void onRight() ;
	void onCenter() ;
	void onJustify() ;
	void onSelectTextColor() ;
	void onSelectBackColor() ;
	void currentCharFormatChanged(const QTextCharFormat &format);
	void cursorPositionChanged();
	void mergeFormatOnWordOrSelection(const QTextCharFormat &format) ;
	void alignmentChanged(Qt::Alignment a) ;
	void textFamily(const QString &f) ;
	void textSize(const QString &p) ;
	void onInsertText(int) ;
	void onProcessStandardOutput() ;
	void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus) ;
	void onTextColorClicked(QAbstractButton* ) ;
	void onBackColorClicked(QAbstractButton* ) ;

	void onDrawRect() ;
	void onDrawCircle() ;
	void onDrawLine() ;
	void onDrawMark() ;
	void onAddImage(bool isFullScreen=false) ;
	void onAddFullScreenImage() ;
	void draw( int role ) ;
	void onItemSelectionChanged() ;
	void onAddImageToScene() ;
	void onSave() ;

	void onShowFlexMenu(bool on=true) ;
	void onWhiteTextClicked() ;
	void onFlexTextClicked() ;
	void onImageFullScreen() ;
	void onFill() ;

	void onLeftArrow() ;
	void onRightArrow() ;
	void onUpArrow() ;
	void onDownArrow() ;

	void onMovementMode() ;
	void onSelectSingleImageAudio() ;
	void onSelectSingleImage() ;
	void onCreateSingleVideo() ;

	void onNextVideo() ;
	void onPrevVideo() ;
	void onAddNewScene() ;
	void onDeleteScene() ;
	void onSceneDurationChanged( double val ) ;

	void onPlay() ;
	void onDeleteItem() ;
	void onShowAddImagePanel() ;

	void onCreateFreezeVideo() ;
	void onAddBlackCircle() ;
	void onInitDrawRole() ;
	void onScenePreview(int msec,bool isPressed) ;
private:
	Ui::Dialog_Text_Popup ui ;
	CxTextItem* m_item ;
	void initConnection() ;
	void setItemData() ;
	void setTextItemAlignment( Qt::Alignment val ) ;
	void startPlay( bool on ) ;
	void setDurationToSeekBar() ;
	void freeze( bool on ) ;
	int m_addState ;
	int m_processState ;
	QString m_audioPath ;
	QString m_audioTmp ;
	QProcess* m_process ;
	int m_audioSt, m_audioEn, m_itemDur ;
	CxGraphicsScene* m_scene ;
	CxGraphicsScene* m_parentScene ;
	CxTextItem* m_curSelectedTextItem ;
	bool m_close ;
	QWidget* m_flexbuttonWidget ;
	QToolButton* m_flexTextBtn ;
	QString m_singleAudioPath ;
	QString m_singleImagePath ;
	QList<CxGraphicsScene*> m_sceneList ;
	int m_curSceneId ;

	bool m_isPlaying ;
	bool m_audioSeeked ;
	int m_playStartTime, m_currentPlayingTime ;
	int m_SeekStartTime ;
	QMediaPlayer* m_audioTrack ;
	QBasicTimer m_timer ;
	int m_curSceneElapsed ;
	int m_dlgRole ;
	bool m_isFreezeState ;
	CxProgressDlg* m_progressBar ;
};

#endif // CXTEXTPOPUPDLG_H
