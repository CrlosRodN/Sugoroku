#include "Token.h"

Token::Token(const char *svg , QSvgWidget *parent)
    : QSvgWidget( svg, parent )
{

}


Token::~Token()
{

}

#include <QDebug>

void Token::mouseDoubleClickEvent( QMouseEvent* )
{
     emit clicked( this );

    //this->setGeometry( 80 + 20 + ( 1/4 ) + ( 1/4*2 ), 15 + ( 0*47 ), 40, 40 );
    //this->move( 500, 0 );
}
