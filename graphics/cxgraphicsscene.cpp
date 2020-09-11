#include "cxgraphicsscene.h"
#include <QPainter>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlaylist>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QEvent>

#define MARKZVALUE 1000
#define CTRLSIZE 20

#define NUMBERMARKITEMSIZE 50

#define FADELENGTH 1000

CxGraphicsScene::CxGraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
	m_audioPath = "silence.wav" ;
	m_sceneType = VIDEOSCENE ;
	m_sceneName = createUuid() ;
    setSceneRect( 0, 0, SCENEWIDTH, SCENEHEIGHT ) ;
    for( int i = 0; i < 8; i++ )
    {
        QGraphicsRectItem* item = new QGraphicsRectItem ;
        item->setFlags(QGraphicsItem::ItemIsMovable|
                 QGraphicsItem::ItemIsSelectable|
                 QGraphicsItem::ItemIsFocusable|
                 QGraphicsItem::ItemSendsGeometryChanges) ;
        item->setRect( 0, 0, CTRLSIZE, CTRLSIZE);
        item->setZValue(100000);
        item->setBrush(Qt::red);
        item->setPen(QPen(Qt::white,2));
        addItem(item) ;
        m_ctrlList << item ;
        item->hide() ;
    }
    connect( this, SIGNAL(selectionChanged()), this, SLOT(onSelectionChanged())) ;
    m_curItem = NULL ;
    m_markPenWidth = 5 ;
    m_resizeState = NORESIZESTATE ;
    m_drawRole = NOMARKROLE ;
	m_isPressed = false ;
//	m_timer.start(50,this) ;
	m_isRunningVideo = false ;
	m_isFade = true ;
	m_fadeValue = 1 ;
	m_hasNextVideo = false ;
	m_bgBrush = QBrush(Qt::black) ;
	m_totalDurMSec = 2000 ;
	m_startFrame = 0 ; m_endFrame = m_totalDurMSec ;
	m_isRecording = false ;
//	m_videoFrame = QImage("D://1.png") ;
}

void CxGraphicsScene::setVideoFrame( QImage img )
{
	m_videoFrame = img ;
	setBackgroundBrush(Qt::black) ;
}
void CxGraphicsScene::drawBackground(QPainter *painter, const QRectF &rect)
{
	painter->setBrush(m_bgBrush) ;
	if( !m_isRunningVideo && m_sceneType != VIDEOSCENE )
	{
		painter->setPen(Qt::white) ;
		painter->setBrush(Qt::blue) ;
		return ;
	}
	int w = width() ;
	int h = height() ;
	painter->setRenderHints(QPainter::SmoothPixmapTransform|QPainter::HighQualityAntialiasing) ;
	if( m_isRunningVideo || 1 )
	{
		painter->drawRect(0,0,width(),height()) ;
		if( m_isFade && m_fadeValue < 1 && m_hasNextVideo ) 
		{
			painter->setOpacity(1-m_fadeValue) ; 
			painter->drawImage(0, 0, m_nextVideoFrame.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)) ;
			painter->setOpacity(m_fadeValue) ; 
		}
		painter->drawImage(0, 0, m_videoFrame.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)) ;
		return ;
	}
    painter->setBrush(Qt::green);
	painter->setPen(Qt::NoPen) ;
	painter->drawRect( 0, 0, width(), height() ) ;
}

void CxGraphicsScene::keyPressEvent(QKeyEvent *event)
{
	if( event->key() == Qt::Key_Delete ) onRemoveCurItem() ;
	QGraphicsScene::keyPressEvent(event) ;
	if( event->key() == Qt::Key_5 ) 
	{
		foreach(CxGraphicsItem* item, availableItems() )
		{
			QMessageBox::information(NULL,"","A") ;
			item->startAnimation() ;
		}
	}
}

void CxGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsScene::mouseDoubleClickEvent(event) ;
	QList<CxGraphicsItem*> itemList = availableItems() ;
	foreach( CxGraphicsItem* item, itemList )
	{
		if( item->myType() == TEXTITEM && item->isSelected() ) {
			CxTextItem* tItem = (CxTextItem*) item ;
			if( m_curItem && m_curItem->itemName() == tItem->itemName() ) return ;
		}
	}
}

void CxGraphicsScene::onItemClicked( CxGraphicsItem* item )
{
	m_curClickedItem = item ;
}

void CxGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if( event->buttons()&Qt::RightButton ) {
		setMovementMode() ;
		return ;
	}

	if( m_drawRole == FILLROLE )
	{
		m_curClickedItem = NULL ;
		QGraphicsScene::mousePressEvent(event) ;
		if( m_curClickedItem == NULL ) setBgBrush(QBrush(m_drawColor)) ;
		return ;
	}
	m_isPressed = true ;
	if( m_drawRole == BLACKCIRCLEROLE )
	{
		CxMarkItem* item = new CxMarkItem(BLACKCIRCLEROLE) ;
		item->setBrush(Qt::black) ;
		item->setPos(event->scenePos()-QPoint(NUMBERMARKITEMSIZE/2,NUMBERMARKITEMSIZE/2)) ;
		item->setRect(0 ,0, NUMBERMARKITEMSIZE,NUMBERMARKITEMSIZE ) ;
		item->setZValue(m_itemList.count()+1) ;
		addMyItem(item) ;
		return ;
	}
	if( m_drawRole == NUMBERMARKROLE  )
	{
		if( event->buttons()&Qt::RightButton ) {
			m_drawRole = NOMARKROLE ;
			views().first()->setCursor(Qt::ArrowCursor) ;
		}
		else{
			CxMarkItem* item = new CxMarkItem(NUMBERMARKROLE, m_numberCount++) ;
			item->setPen(QPen(QBrush(m_drawColor),m_markPenWidth));
			item->setBrush(Qt::NoBrush) ;
			item->setPos(event->scenePos()-QPoint(NUMBERMARKITEMSIZE/2,NUMBERMARKITEMSIZE/2)) ;
			item->setRect(0 ,0, NUMBERMARKITEMSIZE,NUMBERMARKITEMSIZE ) ;
			item->setZValue(m_itemList.count()+1) ;
			addMyItem(item) ;
		}
		return ;
	}
	if( event->buttons()&Qt::RightButton ) return ;
    if( m_drawRole != NOMARKROLE )
    {
        m_drawStartPoint = event->scenePos() ;
        m_curDrawItem = new CxMarkItem(m_drawRole) ;
        m_curDrawItem->setPen(QPen(QBrush(m_drawColor),m_markPenWidth));
        m_curDrawItem->setRect(0,0,0,0);
        m_curDrawItem->setPos(m_drawStartPoint);
        m_curDrawItem->setZValue(m_itemList.count()+1) ;
        addMyItem(m_curDrawItem) ;
        return ;
    }
	bool hasSel = selectedItems().count() ;
    QGraphicsScene::mousePressEvent(event) ;
	if( !selectedItems().count() && !hasSel )
	{
		emit __screenClicked() ;
		return ;
	}
    int i ;

    for( i = 0; i < 8; i++ )
    {
        QGraphicsRectItem* item = m_ctrlList.at(i) ;
        if( item->isSelected() && m_curItem  ) {
			if( m_curItem->itemState() ){
				if( i != 3 && i != 7 ) continue ;
			}
            m_resizeStartPoint = event->scenePos() ;
            m_oriPos = m_curItem->pos() ;
            m_oriSize = m_curItem->rect().size() ;
            m_resizeState = i ;
        }
    }
}

void CxGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event) ;
	if( !m_isPressed ) return ;
	if( m_drawRole == NUMBERMARKROLE || m_drawRole == BLACKCIRCLEROLE ) return ;
    if( m_drawRole != NOMARKROLE )
    {
//        m_curDrawItem->setRect(QRectF(m_drawStartPoint,event->scenePos()));
		QPointF pnt = event->scenePos() ;
        m_curDrawItem->setRect(0,0,abs(event->scenePos().x()-m_drawStartPoint.x()),abs(event->scenePos().y()-m_drawStartPoint.y()));
		m_curDrawItem->setPos( qMin(pnt.x(),m_drawStartPoint.x()), qMin(pnt.y(),m_drawStartPoint.y()) ) ;
        update() ;
        return ;
    }
    if( m_resizeState != NORESIZESTATE )
    {
    }
    QPointF delta = event->scenePos()-m_resizeStartPoint ;
	if( m_curItem && (m_curItem->itemState()&&m_resizeState!=3&&m_resizeState!=7) ) return ;
    if( m_resizeState == TOPLEFTSTATE )
    {
        m_curItem->setRect(0, 0, m_oriSize.width()-delta.x(), m_oriSize.height()-delta.y());
        m_curItem->setPos(m_oriPos+delta);
//        m_oriPos += QPoint(1,1);
    }
    if( m_resizeState == TOPMIDDLESTATE )
    {
        m_curItem->setPos(m_oriPos.x(),m_oriPos.y()+delta.y());
        m_curItem->setRect( 0, 0, m_oriSize.width(), m_oriSize.height()-delta.y()) ;
    }
    if( m_resizeState == TOPRIGHTSTATE )
    {
        m_curItem->setRect(0, 0, m_oriSize.width()+delta.x(), m_oriSize.height()-delta.y());
        m_curItem->setPos(m_oriPos.x(), m_oriPos.y()+delta.y());
    }
    if( m_resizeState == MIDDLERIGHTSTATE )
    {
        m_curItem->setRect( 0, 0, m_oriSize.width()+delta.x(), m_oriSize.height() ) ;
    }
    if( m_resizeState == BOTTOMRIGHTSTATE )
    {
        m_curItem->setRect(0, 0, m_oriSize.width()+delta.x(), m_oriSize.height()+delta.y());
    }
    if( m_resizeState == BOTTOMMIDDLESTATE )
    {
        m_curItem->setRect( 0, 0, m_oriSize.width(),m_oriSize.height()+delta.y() );
    }
    if( m_resizeState == BOTTOMLEFTSTATE )
    {
        m_curItem->setRect( 0, 0, m_oriSize.width()-delta.x(), m_oriSize.height()+delta.y() ) ;
        m_curItem->setPos(m_oriPos.x()+delta.x(),m_oriPos.y()) ;
    }
    if( m_resizeState == MIDDLELEFTSTATE )
    {
        m_curItem->setRect( 0, 0, m_oriSize.width()-delta.x(), m_oriSize.height() ) ;
        m_curItem->setPos(m_oriPos.x()+delta.x(),m_oriPos.y()) ;
    }
    if( m_curItem ) {
        rearrangeCtrlList() ;
//        QMessageBox::information(NULL,"a",QString::number(m_curItem->type())) ;
        if( m_curItem->myType() == TEXTITEM ) {
            ((CxTextItem*)m_curItem)->updateMe() ;
        }
    }
    update() ;
}

void CxGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	m_isPressed = false ;
	if( m_drawRole == NUMBERMARKROLE || m_drawRole == BLACKCIRCLEROLE )
	{
		return ;
	}
    QGraphicsScene::mouseReleaseEvent(event) ;
    if( m_drawRole != NOMARKROLE && m_drawRole != FILLROLE )
    {
		if( m_curDrawItem )
		{
			QRectF rc = m_curDrawItem->rect() ;
			qreal r = rc.width() ;
			qreal c = rc.height() ;
			if( r < 10 || c < 10 )
			{
				m_curDrawItem->setRect( 0, 0, qMax(r,10.0), qMax(c,10.0) ) ;
			}
		}
		setMovementMode() ;
        clearSelection() ;
		if( m_curDrawItem ) m_curDrawItem->setSelected(true) ;
		rearrangeCtrlList() ;
    }
    m_resizeState = NORESIZESTATE ;
}

void CxGraphicsScene::setMovementMode()
{
	views().first()->setCursor(Qt::ArrowCursor) ;
	m_drawRole = NOMARKROLE ;
	emit __initDrawRole() ;
}

void CxGraphicsScene::setFillMode()
{
	int curSz = 30 ;
	QCursor cur(QPixmap(":/res/bucket.png").scaled(curSz,curSz, Qt::IgnoreAspectRatio,Qt::SmoothTransformation),curSz,curSz/2) ; 
	views().first()->setCursor(cur) ;
	m_drawRole = FILLROLE ;
}

CxImageItem* CxGraphicsScene::addImageItem(QPixmap pix, qreal ratio, int logostate )
{
	int w = width()*ratio ;
	int h = height()*ratio ;
	if( pix.width() > w || pix.height() > h )
	{
		pix = pix.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation) ;
	}
	CxImageItem* item = new CxImageItem ;
	item->setPixmap(pix) ;
	item->setRect( 0, 0, pix.width(),pix.height() ) ;
	item->setZValue(m_itemList.count()+1) ;
	if( logostate ) 
	{
			item->setLogo(true) ;
	}
	else item->setPos((width()-pix.width())/2,(height()-pix.height())/2 );
	addMyItem(item) ;
	clearSelection() ;

	item->setSelected(true) ;

	return item ;
}

CxImageItem* CxGraphicsScene::addImageItem(QString filePath, qreal ratio, int logostate )
{
	int w = width()*ratio ;
	int h = height()*ratio ;
    CxImageItem* item = new CxImageItem ;
    item->setImageSource(filePath);
	QPixmap pix(filePath) ;
	if( pix.width() > w || pix.height() > h )
	{
		pix = pix.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation) ;
	}
    item->setRect( 0, 0, pix.width(),pix.height() ) ;
    item->setZValue(m_itemList.count()+1) ;
	if( logostate ) 
	{
		item->setLogo(true) ;
		if( logostate == 1 ) item->setPos(0,0) ;
		if( logostate == 2 ) item->setPos(width()-pix.width(),0) ;
		if( logostate == 3 ) item->setPos(0,height()-pix.height()) ;
		if( logostate == 4 ) item->setPos(width()-pix.width(),height()-pix.height()) ;
		if( logostate == 5 ) item->setPos((width()-pix.width())/2,(height()-pix.height())/2 );
	}
	else item->setPos((width()-pix.width())/2,(height()-pix.height())/2 );
	addMyItem(item) ;
	clearSelection() ;
	item->setSelected(true) ;
    return item ;
}

CxImageItem* CxGraphicsScene::addLogo( QString filePath, QPointF pos, QSizeF sz )
{
	CxImageItem* item = new CxImageItem ;
	item->setImageSource(filePath);
	QPixmap pix(filePath) ;
	pix = pix.scaled(sz.width(),sz.height(),Qt::KeepAspectRatio,Qt::SmoothTransformation) ;
	item->setRect( 0, 0, pix.width(),pix.height() ) ;
	item->setZValue(m_itemList.count()+1) ;
	item->setLogo(true) ;
	item->setPos(pos) ;
	addMyItem(item) ; 
	clearSelection() ;
	item->setSelected(true) ;
	return item ;
}

void CxGraphicsScene::insertTextItem( CxTextItem* item )
{
	QSize sz = item->textItem()->document()->size().toSize()+QSize(10,10) ;
	int dif = 10 ;
	if( sz.height() > height()-dif ) sz.setHeight(height()-dif) ;
	if( sz.width() > width()-dif ) sz.setWidth(width()-dif) ;
	item->setRect( 0, 0, sz.width(),sz.height() ) ;
	item->setZValue(m_itemList.count()+1) ;
	item->setPos( (width()-sz.width())/2, (height()-sz.height())/2 );
	addMyItem(item) ;
	clearSelection() ;
	item->setSelected(true) ;
}

CxTextItem* CxGraphicsScene::addTextItem(QString str)
{
	int w = 400;
	int h = 90;
    CxTextItem* item = new CxTextItem("TEXT") ;
//	item->textItem()->setAl
    item->setRect( 0, 0, w, h ) ;
    item->setZValue(m_itemList.count()+1) ;
    item->setPos( (width()-w)/2, (height()-h)/2 );
	addMyItem(item) ;
    return item ;
}

void CxGraphicsScene::onSelectionChanged()
{
    update() ;
    int cnt = selectedItems().count() ;
    if( !cnt )
    {
        for( int i = m_ctrlList.count()-1; i >= 0; i-- ) m_ctrlList.at(i)->hide();
        m_curItem = NULL ;
        return ;
    }
	if( m_drawRole != NOMARKROLE ) return ;
    for( int i = m_itemList.count()-1; i >= 0; i-- )
    {
        CxGraphicsItem* item = m_itemList.at(i) ;
        if( item->isSelected() )
        {
            m_curItem = item ;
            rearrangeCtrlList();
//            m_oriPos = m_curItem->pos() ;
  //          m_oriSize = m_curItem->rect().size();
        }
    }
}

void CxGraphicsScene::removeMyItem(CxGraphicsItem* item)
{
	item->setSelected(false) ;
	item->setFlags(0) ;
	item->setEnabled(false) ;
	item->hide() ;
	emit __itemDeleted(item) ;
}
void CxGraphicsScene::onRemoveAllItems()
{
	int cnt = m_itemList.count() ;
	for( int i = 0 ; i < cnt; i++ )
	{
		CxGraphicsItem* item = m_itemList.at(i) ;
		if( item->isVisible() ) removeMyItem(item) ;
	}
}

void CxGraphicsScene::onRemoveCurItem()
{
	QList<CxGraphicsItem*> itemList = availableItems() ;
	for( int i = itemList.count()-1; i >= 0; i-- )
	{
		CxGraphicsItem*item = itemList.at(i) ;
		if( item->isSelected() )
		{
			removeMyItem(item) ;
			return ;
		}
	}
}

void CxGraphicsScene::rearrangeCtrlList()
{
    if( m_curItem )
    {
        QList<QPointF> pntList ;
        QPointF st = m_curItem->pos() - QPoint(CTRLSIZE/2,CTRLSIZE/2);
        int w = m_curItem->rect().width() ;
        int h = m_curItem->rect().height() ;
        pntList << st << st+QPoint(w/2,0) << st+QPoint(w,0) << st+QPoint(w,h/2) << st+QPoint(w,h)
                   << st+QPoint(w/2,h) << st+QPoint(0,h) << st+QPoint(0,h/2)  ;
        for( int i = 0; i < 8; i++ )
        {
            QGraphicsRectItem* item = m_ctrlList.at(i) ;
			item->setBrush(!m_curItem->itemState()?(Qt::red):(Qt::blue)) ;
			item->setFlag(QGraphicsItem::ItemIsMovable,!m_curItem->itemState()) ;
            item->show();
            item->setPos(pntList[i]) ;
        }
    }
}

void CxGraphicsScene::setDrawColor( QColor col )
{
	m_drawColor = col ;
}

void CxGraphicsScene::onDrawMark(int role, QColor col)
{
	clearSelection() ;
	if( m_drawRole == role ) {
		m_drawColor = col ;
		return ;
	}
    m_drawRole = role ;
    m_drawColor = col ;
	m_numberCount = 1 ;
	if( m_drawRole == NUMBERMARKROLE || m_drawRole == BLACKCIRCLEROLE ) views().first()->setCursor(Qt::PointingHandCursor) ;
	else views().first()->setCursor(Qt::CrossCursor) ;
}

void CxGraphicsScene::addMyItem( CxGraphicsItem* item )
{
	addItem(item) ;
	m_itemList << item ;
	emit __itemAdded(item) ;
	connect( item, SIGNAL(__itemClicked(CxGraphicsItem*)), this, SLOT(onItemClicked(CxGraphicsItem*))) ;
}

void CxGraphicsScene::timerEvent(QTimerEvent *event)
{
	if( event->timerId() != m_timer.timerId() ) return ;
}

void CxGraphicsScene::setRunningVideo( bool on, int startMSec )
{
//	if( on == m_isRunningVideo ) return ;
	for( int i = m_itemList.count()-1; i >= 0 ; i-- )
	{
		CxGraphicsItem* item = m_itemList.at(i) ;
		if( !item->isEnabled() ) continue ;
		item->setVisible(!on) ;
	}

	m_isRunningVideo = on ;
	if( on )
	{
		if( m_sceneType == VIDEOSCENE )
		{
			m_capture.open(m_mediaPath.toStdString()) ;
			m_capture.set(CV_CAP_PROP_POS_MSEC,startMSec<0?m_startFrame:startMSec) ;
		}
//		if( startMSec != -1 )
//		if( startMSec != -1 ) QMessageBox::information(NULL,"",QString("%1 %2").arg(startMSec).arg(m_endFrame)) ;
		m_curFrameTime = (startMSec<0?m_startFrame:startMSec) ;
//		QMessageBox::information(NULL,"", QString("%1 %2 %3").arg(startMSec).arg(m_startFrame).arg(m_endFrame)) ;
	}
	else
	{
		if( m_sceneType == VIDEOSCENE ) m_capture.release() ;
	}
}

void CxGraphicsScene::setVideoPath( QString str )
{
	m_mediaPath = str ;
	m_audioPath = str ;
//	m_videoItem->setVideoPath(str) ;
}

int CxGraphicsScene::showNextFrame(int val)
{
	if( !m_isRunningVideo ) return PLAYFINISHED;
	if( !m_capture.isOpened() && m_sceneType == VIDEOSCENE ) return NOOPENED ;
	int curTime = ( (m_sceneType == VIDEOSCENE) ? m_capture.get(CV_CAP_PROP_POS_MSEC) : m_curFrameTime) ;
	m_curFrameTime += 1000/DEFAULTFRAMERATE;
	if( val != -1 ) {
		if( m_sceneType == VIDEOSCENE ) m_capture.set(CV_CAP_PROP_POS_MSEC,val+m_startFrame) ;
		curTime = val+m_startFrame ;
	}
	qreal curPos = 1.0*curTime/m_totalDurMSec ;

	for( int i = m_itemList.count()-1; i >= 0 ; i-- )
	{
		CxGraphicsItem* item = m_itemList.at(i) ;
		if( !item->isEnabled() ) continue ;
		item->setVisible(item->startValue()<=curPos&&item->endValue()>=curPos) ;
	}

	emit __currentTimeChanged(curTime) ;
	int remain = m_endFrame-curTime ;
	if( remain < 0 ) return PLAYFINISHED ;
	if( remain < FADELENGTH )
	{
		m_fadeValue = 1-0.7*(FADELENGTH-remain)/FADELENGTH ;
	}
	else m_fadeValue = 1 ;
	if( m_sceneType == VIDEOSCENE )
	{
		Mat img ;
		m_capture.read(img) ;
		if( img.empty() ) return PLAYFINISHED ;
		m_videoFrame = Mat2QImage(img) ;
		if( !m_isRecording )
		{
			setBackgroundBrush(Qt::red) ;
			update() ;
		}
	}
	else if( m_curFrameTime >= m_endFrame ) return PLAYFINISHED ;
	return PLAYINGNOW ;
}

void CxGraphicsScene::setVideoRange( int st, int en )
{
	m_startFrame = st ;
	m_endFrame = en ;
}

void CxGraphicsScene::preview(int msec)
{
	if ( m_isRunningVideo )
	{
		if( m_sceneType == VIDEOSCENE ) m_capture.set(CV_CAP_PROP_POS_MSEC,msec ) ;
		else m_curFrameTime = msec ;
		return ;
	}
	if( m_sceneType != VIDEOSCENE )
	{
		return ;
	}
	m_capture.open(m_mediaPath.toStdString()) ;
	if( m_capture.isOpened() )
	{
		m_capture.set(CV_CAP_PROP_POS_MSEC,msec ) ;
//		QMessageBox::information(NULL,"",QString::number(msec)) ;
//		m_capture.set(CV_CAP_PROP_POS_MSEC,seekId == 0 ? m_startFrame : m_endFrame ) ;
		Mat img ;
		m_capture.read(img) ;
		if( !img.empty() ) {
//			m_isRunningVideo = true ;
			m_videoFrame = Mat2QImage(img) ;
			setBackgroundBrush(Qt::red) ;
//			m_isRunningVideo = false ;
			update() ;
		}
		m_capture.release() ;
	}
}

void CxGraphicsScene::setNextVideoFrame( QImage img )
{
	m_nextVideoFrame = img ; 
	m_hasNextVideo = (!img.isNull()) ; 
}

QPixmap CxGraphicsScene::renderToPix(QSize sz)
{
	clearSelection() ;
	QPixmap ret(width(),height());
	QPainter painter(&ret);
	painter.setRenderHints(QPainter::SmoothPixmapTransform|QPainter::HighQualityAntialiasing) ;
	render(&painter);
	painter.end();
	if( sz.width() != -1 )
	{
		ret = ret.scaled(sz,Qt::IgnoreAspectRatio,Qt::SmoothTransformation) ;
	}
	return ret ;
}

QList<CxGraphicsItem*> CxGraphicsScene::availableItems()
{
	QList<CxGraphicsItem*> ret ;
	int cnt = m_itemList.count() ;
	for( int i = 0 ; i < cnt; i++ )
	{
		CxGraphicsItem* item = m_itemList.at(i) ;
		if( item->isVisible() ) ret << item ;
	}
	return ret ;
}

void CxGraphicsScene::setCurrentItemState(int state)
{
	int cnt = m_itemList.count() ;
	for( int i = 0 ; i < cnt; i++ )
	{
		CxGraphicsItem* item = m_itemList.at(i) ;
		if( item->isVisible() && item->isSelected() )
		{
			setItemState(item,state) ;
		}
	}
}

void CxGraphicsScene::setItemState( CxGraphicsItem* item, int state )
{
	item->setItemState(state) ;
	for( int j = 0; j < m_ctrlList.count(); j++ )
	{
		m_ctrlList.at(j)->setBrush(!state?(Qt::red):(Qt::blue)) ;
		m_ctrlList.at(j)->setFlag(QGraphicsItem::ItemIsMovable,!state) ;
	}
	if( item->myType() == TEXTITEM )
	{
		CxTextItem* tItem = (CxTextItem*) item ;
		MyGraphicsTextItem* child = tItem->textItem() ;
		if( state == 1 )//black
		{
			tItem->setRect(0,0,width()*0.7, height()*0.05) ;
			tItem->setBrush(Qt::black) ;
			child->setTextColor(Qt::white) ;
			tItem->setPos(width()*0.15, height()*0.73) ;
		}
		if( state == 2 )
		{
			tItem->setRect(0,0,width()*0.7, height()*0.15) ;
			tItem->setBrush(Qt::white) ;
			child->setTextColor(Qt::black) ;
			tItem->setPos(width()*0.15, height()*0.78) ;
		}
		rearrangeCtrlList() ;
	}

}
void CxGraphicsScene::pasteItem( CxGraphicsItem* src )
{
	if( src->myType() == TEXTITEM )
	{
		CxTextItem* p = (CxTextItem*) src ;
		CxTextItem* item = new CxTextItem("HELLO TOM") ;
		item->setRect(p->rect()) ;
		item->setZValue(m_itemList.count()+1) ;
		item->setPos(p->pos()) ;
		item->setItemName(p->itemName()) ;
		item->textItem()->setBoundingRect(p->textItem()->boundingRect()) ;
		item->textItem()->setHtml(p->textItem()->toHtml()) ;
		item->setBrush(p->brush()) ;
		item->setItemState(p->itemState()) ;
		addMyItem(item) ;
		return ;
	}
	if( src->myType() == PIXITEM )
	{
		CxImageItem* p = (CxImageItem*) src ;
		CxImageItem* item = new CxImageItem ;
		item->setImageSource(p->imageSource());
		item->setRect(p->rect()) ;
		item->setZValue(m_itemList.count()+1) ;
		item->setPos(p->pos());
		item->setItemName(p->itemName()) ;
		addMyItem(item) ;
	}
	if( src->myType() == MARKITEM )
	{
		CxMarkItem* p = (CxMarkItem*) src ;
		CxMarkItem* item = new CxMarkItem(p->role(), p->number()) ;
		item->setPen(p->pen());
		item->setPos(p->pos()) ;
		item->setRect(p->rect()) ;
		item->setZValue(m_itemList.count()+1) ;
		addMyItem(item) ;
	}
}

void CxGraphicsScene::focusInEvent(QFocusEvent *event)
{
	QGraphicsScene::focusInEvent(event) ;
//	emit __mouseHover(true) ;
}

void CxGraphicsScene::focusOutEvent(QFocusEvent* event)
{
	QGraphicsScene::focusOutEvent(event) ;
//	emit __mouseHover(false) ;
}

bool CxGraphicsScene::event(QEvent* ev)
{
	return QGraphicsScene::event(ev) ;
}

void CxGraphicsScene::setAudioPath(QString path)
{
	m_audioPath = path ;
}

void CxGraphicsScene::setBgBrush( QBrush brush )
{
	m_bgBrush = brush ;
	setBackgroundBrush(Qt::red) ;
}