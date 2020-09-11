#include "cxtexteditpanel.h"
#include "common.h"

CxTextEditPanel::CxTextEditPanel(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    for( int i = 1; i < 100; i++ ) ui.cb_font_size->addItem(QString::number(i));
    for( int i = 100; i < 200; i+=20 ) ui.cb_font_size->addItem(QString::number(i)) ;
    m_isRemote = false ;
    connect ( ui.tb_underline, SIGNAL(clicked()), this, SLOT(onUnderlineStateChanged())) ;
    connect( ui.cb_font_size, SIGNAL(currentTextChanged(QString)),this, SLOT(onFontSizeChanged(QString))) ;
    connect( ui.fontComboBox, SIGNAL(currentFontChanged(QFont)), this, SLOT(onFontFamilyChanged(QFont))) ;
    setWindowFlags(Qt::Popup);
}

void CxTextEditPanel::showTextCursor(QGraphicsTextItem* item)
{
    m_isRemote = true ;
    m_item = item ;
    QTextCursor cursor = m_item->textCursor() ;
    QTextCharFormat cfmt = cursor.charFormat() ;
    QFont f = cfmt.font() ;
    ui.fontComboBox->setCurrentIndex(ui.fontComboBox->findText(QFontInfo(f).family()));
    ui.cb_font_size->setCurrentIndex(ui.cb_font_size->findText(QString::number(f.pointSize())));
    QColor col = cfmt.foreground().color() ;
    ui.tb_underline->setChecked(f.underline()) ;
    m_isRemote = false ;
}

void CxTextEditPanel::onUnderlineStateChanged()
{
    if( m_isRemote ) return ;
    QTextCharFormat cfmt ;
    QFont f = m_item->textCursor().charFormat().font() ;
    f.setUnderline(ui.tb_underline->isChecked());
    cfmt.setFont(f);
    m_item->textCursor().mergeCharFormat(cfmt);
}

void CxTextEditPanel::onFontFamilyChanged(QFont f)
{
    if( m_isRemote ) return ;
    QTextCharFormat cfmt ;
    cfmt.setFontFamily(f.family());
    m_item->textCursor().mergeCharFormat(cfmt);
}

void CxTextEditPanel::onFontSizeChanged(QString str)
{
    if( m_isRemote ) return ;
    QTextCharFormat cfmt ;
    QFont f = m_item->textCursor().charFormat().font() ;
    f.setPointSize(str.toInt());
    cfmt.setFont(f);
    m_item->textCursor().mergeCharFormat(cfmt);
}
