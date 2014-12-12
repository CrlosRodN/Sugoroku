#include "Token.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>


Token::Token( const char *svg )
    :image( svg )
{
    tile = new QSvgWidget( image );
}

Token::~Token()
{
    delete tile;
}

//void Token::mouseClickEvent(QGraphicsSceneMouseEvent* /*event*/)
//{
//    scene()->removeItem(this);
//}

