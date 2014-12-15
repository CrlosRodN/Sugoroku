
#include "Dice.h"
#include <QDebug>

Dice::Dice( QWidget * parent )
    : QLabel( parent )
{
    charge_faces();
}

Dice::~Dice()
{
    delete reader;
    delete timer;
}

void Dice::charge_faces()
{
    for ( int i = 0; i < 6; i++ )
    {
        this->dice_faces.push_back( QString( ":/gameIcons/dice-%1.svg" ).arg( i + 1 ) );
        this->dice_faces.push_back( QString( ":/gameIcons/dice-%1.svg" ).arg( i + 1 ) );
    }

    it = dice_faces.begin();
    reader = new QImageReader( dice_faces[1] );
    reader->setScaledSize( QSize( 60, 60 ) );
    this->setPixmap( QPixmap::fromImage( reader->read() ) );
    timer = new QTimer( this );

}

void Dice::roll()
{
    shuffle();
    it = dice_faces.begin();
    connect( timer, SIGNAL( timeout() ), this, SLOT( test() ) );
    timer->start( 90 );
}

void Dice::test( )
{
    if ( it != dice_faces.end() )
    {
        reader->setFileName( *it );
        this->setPixmap( QPixmap::fromImage( reader->read() ) );
        ++it;
    }
    else
    {
        --it;
        real_value = (*it).at(17).digitValue();
        timer->stop();
    }
}

void Dice::shuffle()
{
    std::random_device rand;
    std::mt19937 seed( rand() );
    std::shuffle( dice_faces.begin(), dice_faces.end(), seed );
}
