#include "Token.h"

Token::Token(const char *svg , QSvgWidget *parent)
    : QSvgWidget( svg, parent )
{

}


Token::~Token()
{

}

#include <QDebug>

void Token::mouseDoubleClickEvent( QMouseEvent* event )
{
    qDebug() << "DoubleClickEvent";
    delete this;
}
