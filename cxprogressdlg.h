#ifndef CXPROGRESSDLG_H
#define CXPROGRESSDLG_H

#include <QDialog>
#include <QProcess>
#include "ui_dlg_progress.h"
#include "common.h"

#define SINGLEVIDEOCREATE 0

class CxProgressDlg : public QDialog
{
	Q_OBJECT

public:
	CxProgressDlg(QWidget *parent=0);
	~CxProgressDlg();
	void setSingleAudioPath(QString str);
	void startProgress(QStringList arg,  int dur=-1,QString str="Processing ...") ;
	void setDuration( int dur ) { ui.progressBar->setMaximum(dur) ; }
	void setValue( int val ){ ui.progressBar->setValue(val); }
	void startProgress( int dur, QString str ) ;
private slots:
	void onProcessFinished(int,QProcess::ExitStatus) ;
	void onProcessStandardOutput() ;
protected:
	void closeEvent(QCloseEvent* event) ;
private:
	QProcess* m_process ;
	int m_state ;
	QString m_singleAudioPath ;
	Ui::Dialog_Progress ui ;
};

#endif // CXPROGRESSDLG_H
