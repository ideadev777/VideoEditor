#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBasicTimer>
#include <QProcess>

#include "cxprogressdlg.h"
#include "cxgraphicsview.h"
#include "cxgraphicsscene.h"
#include "cxmarkpanel.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include "cxtextpopupdlg.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onClose() ;
	void onScreenClicked() ;
    void onAddText() ;
	void onPaint( int role ) ;
	void onAddTextItem(int) ;
    void onAddImage() ;
	void onShowLogoWidget() ;
	void onAddLogo() ;
	void onAddLogo(QListWidgetItem* item) ;
	void onAddTopLeftLogo() ;
	void onAddTopRightLogo() ;
	void onAddBottomLeftLogo() ;
	void onAddBottomRightLogo() ;

	void onFade() ;
    void onMark() ;
    void onAddVideo() ;
	void onAddContentScene() ;
	void onCurrentItemChanged(CxLayerItem* item) ;
	void onMaximize() ;
	void onPreview() ;
	void onRecord() ;
	void onRangePreview( int msec ) ;
	void onThemeChanged( int ) ;
	void onVideoCurTimeChanged(int) ;// milisec
	void onGraphicsItemAdded(CxGraphicsItem* item) ;
	void onAudioStateChanged(QMediaPlayer::State state) ;
	void onExpandTrimmer(bool on) ;
	void onItemModeChanged( int id ) ;
	void onCxItemSelectionChanged() ;
	void onDeleteCxItem() ;
	void onRemoveAllItems() ;
	void copyToGlobal() ;
	void onProcessStandardOutput() ;
	void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus) ;
	void onChangeSceneColor() ;

	void onCreateNewVideo() ;
	void onEditVideo() ;
	void onFreezeVideo() ;
	void onCreateSingleImageVideo() ;

	void onSingleVideoAudioSelect() ;
	void onSingleVideoImageSelect() ;
	void onSingleVideoMp4Select() ;
	void onSingleVideoCreate() ;

	void onHideCategory() ;
	void onShowCategory() ;

	void onAddIntroVideo() ;
	void onRemoveIntroVideo() ;
	void onInsertIntroItem(QListWidgetItem* item) ;

	void onLogoSave() ;
	void onShowEditVideoWidget() ;
protected:
	void showEvent(QShowEvent *event) ;
	void resizeEvent(QResizeEvent* event) ;
	void mousePressEvent(QMouseEvent* event) ;
	void mouseMoveEvent(QMouseEvent* event) ;
	void mouseReleaseEvent(QMouseEvent *event) ;
	void mouseDoubleClickEvent(QMouseEvent *event) ;
	void timerEvent(QTimerEvent* event) ;
	void closeEvent(QCloseEvent* event) ;
private:
    void initUI() ;
    void initVar() ;
    void initConnection() ;
	void finalizeRecording() ;
	void cancelRecording() ;
	void stopPlayingAudio() ;
	void startPlaying( bool on ) ;
	void maximize() ;
	void normalize() ;
	void saveCurrentPosition() ;
	void refitTrimmerRect() ;
	void setVisibleItemMode( bool on, int id = -1 ) ;
	void setButtonTransparent( QToolButton* btn ) ;
	void createSceneConnection( CxGraphicsScene* sc ) ;
	void addLogo( int dir ) ;
	void releaseRecordinig() ;
    Ui::MainWindow *ui;

	CxMarkPanel* m_markPanel ;

	QRect m_oriRect;
	QPoint m_oriPnt ;
	bool m_isPressing ;
	QString m_tmpRecordingPath ;
	QString m_savePath ;
	QBasicTimer m_timer ;
	QTime m_playStartTime ;
	CxLayer* m_sceneList ;
	CxGraphicsView* m_view ;
	CxVideoPanel* m_videoPanel ;
	CxItemLayer* m_itemList ;
	CxTrimmerPanel* m_trimmer ;
	VideoWriter m_recorder ;
	int m_state ;
	QMediaPlayer* m_audioTrack ;
	QTime m_sceneStartTime ;
	QProcess* m_process ;
	bool m_isMaximized ;
	QPoint lastGlobalPosition ;
	QSize lastSize ;
	int m_addAudioDuration ;
	QString m_addAudioFileName ;
	QString m_singleVideoAudioPath, m_singleVideoImagePath, m_singleVideoMp4Path ;

	CxCustomButton* m_fullScreenBtn ;
	CxCustomButton* m_showCategoryBtn ;
	CxCustomButton* m_playBtn ;
	CxProgressDlg* m_progressBar ;
	QLabel* m_lockScreen ;
	int m_tmp ;
};

#endif // MAINWINDOW_H
