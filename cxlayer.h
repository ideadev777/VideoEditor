#ifndef CXLAYER_H
#define CXLAYER_H

#include <QListWidget>
#include <QTime>
#include "ui_form_layer_item_widget.h"
#include "cxgraphicsscene.h"

//////////////////////////////////////////////////////////////////////////

class CxLayerItemWidget : public QWidget
{
public:
	CxLayerItemWidget() ;
	Ui::Form_Layer_Item_Widget form(){ return ui; }
	void setRank( int id ) ;
	void onSelect( bool on ) ;
private:
	Ui::Form_Layer_Item_Widget ui ;
};

//////////////////////////////////////////////////////////////////////////
class CxLayerItem : public QObject, public QListWidgetItem
{
	Q_OBJECT
public:
	CxLayerItem(QString str, int dur) ;
	QPointF segmentPos(){ return QPointF(m_st, m_en); }
	void setSegmentPos( qreal st, qreal en ) ;
	QTime totalTime(){ return m_totTime ; }
	QTime startTime(){ return m_startTime ; }
	QTime endTime(){ return m_endTime ; }
	int totalPlayTime() ;
	//	bool isFade(){ return m_w->form().tb_fade->isChecked() ; }
	CxLayerItemWidget* widget(){ return m_w ; }
	CxGraphicsScene* myScene(){ return m_scene ; }
	QImage thumnail(){ return m_thumbnail ; }
	QSize videoSize(){ return m_videoSize ; }
	QString filePath(){ return m_fileName ; }
	public slots:
		void setFade( bool on ) ;
private:
	void initVar(int dur) ;
	QString m_fileName ;
	qreal m_st, m_en ;
	CxLayerItemWidget* m_w ;
	QTime m_totTime, m_startTime, m_endTime ;
	CxGraphicsScene* m_scene ;
	QImage m_thumbnail ;
	QSize m_videoSize ;
};

//////////////////////////////////////////////////////////////////////////

class CxLayer : public QListWidget
{
	Q_OBJECT
public:
	explicit CxLayer(QWidget *parent = 0);
	CxLayerItem* itemAt(int id){ return m_itemList.at(id); }
	CxGraphicsScene* sceneAt( int id ){ return itemAt(id)->myScene() ; }
signals:
	void __currentItemChanged( CxLayerItem* cur ) ;
	private slots:
		void onSelectionChanged() ;
protected:
	void dropEvent(QDropEvent* event) ;
public slots:
	CxLayerItem* onAddVideoLayer(QString fileName, int pos = -1, int dur = -1 ) ;
	void deleteCurItem() ;
	void onSeekRangeChanged( qreal st, qreal en ) ;
	void onChangeCurFade( bool on ) ;
private:
	QList<CxLayerItem*> m_itemList ;
};


#endif // CXLAYER_H
