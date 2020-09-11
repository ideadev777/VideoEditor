#ifndef CXMARKITEM_H
#define CXMARKITEM_H
#include "common.h"
#include "cxgraphicsitem.h"

class CxMarkItem : public CxGraphicsItem
        
{
public:
    CxMarkItem(int role=RECTMARKROLE, int markNum=0);
    void setRole( int role ) ;
	void setNumber( int num ) { m_markNum = num ; update() ; }
	int role(){ return m_role ; }
	int number(){ return m_markNum ; }
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
private:
    int m_role ;
	int m_markNum ;
};

#endif // CXMARKITEM_H
