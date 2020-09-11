#include "cxprogressdlg.h"
#include <QTime>
#include <QCloseEvent>

#include <QMovie>
CxProgressDlg::CxProgressDlg(QWidget *parent)
	: QDialog(parent)
{
	setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
	ui.setupUi(this) ;
	m_process = new QProcess(this) ;
	m_process->setProcessChannelMode(QProcess::MergedChannels);
	connect( m_process, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(onProcessFinished(int,QProcess::ExitStatus))) ;
	connect (m_process, SIGNAL(readyReadStandardOutput()), this, SLOT(onProcessStandardOutput()));
	setFixedHeight(80) ;

	ui.lbl_banner->setScaledContents(true) ;
	QMovie *movie = new QMovie(":/res/loading.gif");
	ui.lbl_banner->setMovie(movie);
	movie->start();
//	setStyleSheet("QDialog{border:3px;border-color:#2D2D2D; border-style:solid;}") ;
}

CxProgressDlg::~CxProgressDlg()
{

}

void CxProgressDlg::setSingleAudioPath(QString str)
{
	m_singleAudioPath = str ;
	m_state = SINGLEVIDEOCREATE ;
}

void CxProgressDlg::startProgress( int dur, QString str )
{
	setDuration(dur) ;
	ui.progressBar->setValue(0) ;
	ui.lbl_status->setText(str) ;
}

void CxProgressDlg::startProgress(QStringList arg, int dur, QString str)
{
	if( dur != -1 ) setDuration(dur) ;
	else setDuration(0) ;
	ui.lbl_status->setText(str) ;
	ui.progressBar->setValue(0) ;
	m_process->start("ffmpeg",arg) ;
	exec() ;
}

void CxProgressDlg::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
	accept() ;
}

void CxProgressDlg::onProcessStandardOutput()
{
	QString str = m_process->readAllStandardOutput();
	if( !str.length() ) return ;
	QString token = "Duration: " ;
	int pos ;
	if( str.contains(token) && !ui.progressBar->maximum() && str.contains("kb/s"))
	{
		pos = str.indexOf(token) ;
		QTime tt = QTime::fromString(str.mid(pos+token.length(),11),"hh:mm:ss.z") ;
		int dur = getMSec(tt) ;
		if( dur < 0 ) return ;
		ui.progressBar->setMaximum(dur) ;
		return ;
	}
	token = "kB time=" ;
	if( !str.contains(token) ) return ;
	pos = str.indexOf(token) ;
	ui.progressBar->setValue(getMSec(QTime::fromString(str.mid(pos+token.length(),11),"hh:mm:ss.z"))) ;
}

void CxProgressDlg::closeEvent(QCloseEvent* event)
{
	if( m_process->state() == QProcess::Running ) m_process->terminate() ;
	event->accept() ;
}
