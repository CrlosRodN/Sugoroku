#include "Sugoroku.h"
#include "MainWindow.h"
#include <QLayout>
#include <ctime>

Sugoroku::Sugoroku( int& argc, char* argv[] )
    : QApplication( argc, argv )
    , mainWindow(nullptr)
{
}

Sugoroku::~Sugoroku()
{
    for ( int i = 0; i < BlackPlayer.size(); ++i )
    {
        delete BlackPlayer[i];
        delete WhitePlayer[i];
    }
}

int Sugoroku::run()
{
    Q_ASSERT(mainWindow == nullptr);
    mainWindow = new MainWindow(this);
    load_tokens();
    play();
    mainWindow->show();
    mainWindow->setFixedSize( mainWindow->size() );
    std::srand( std::time(nullptr) );
    return exec();
}

bool Sugoroku::load_tokens()
{
    for ( int i = 0; i < 16; i++ )
    {
        Token* whiteToken = new Token(":/gameIcons/white.svg");
        connect( whiteToken, SIGNAL( clicked( Token* ) ), this, SLOT( token_clicked( Token* ) ) );
        Token* blackToken = new Token(":/gameIcons/black.svg");
        connect( blackToken, SIGNAL( clicked( Token* ) ), this, SLOT( token_clicked( Token* ) ) );
        this->WhitePlayer.push_back( whiteToken );
        this->BlackPlayer.push_back( blackToken );
    }
    return true;
}

bool Sugoroku::display_tokens()
{
    int count = 0;
    while ( count < 16 )
        for ( int i = 0; i < 4; i++ )
        {
            WhitePlayer[count]->setParent( mainWindow->whiteSpace );
            WhitePlayer[count]->setGeometry ( ( 11 * 80 ) + 20 + ( count/4 ) + ( count/4*2 ), 15 + ( i*47 ), 40, 40 );
            BlackPlayer[count]->setParent( mainWindow->blackSpace );
            BlackPlayer[count]->setGeometry ( ( 11 * 80 ) + 20 + ( count/4 ) + ( count/4*2 ), 15 + ( i*47 ), 40, 40 );
            count++;
        }
    return true;
}

#include <QDebug>

void Sugoroku::display_dices()
{
    QVBoxLayout* layout = new QVBoxLayout;
    mainWindow->centerSpace->setLayout( layout );
    DiceOne = new Dice();
    DiceTwo = new Dice();
    layout->addWidget( DiceOne );
    layout->addWidget( DiceTwo );
    layout->setAlignment(Qt::AlignCenter);
}

void Sugoroku::play()
{
    display_tokens();
    display_dices();
    DiceOne->roll();
    DiceTwo->roll();
}

void Sugoroku::token_clicked( Token* active )
{
    int x = active->pos().rx();
    int y = active->pos().ry();
    move_count == 0 ? active->move( x - DiceOne->real_value * 80, y ) : active->move( x - DiceTwo->real_value * 80, y );
    move_count++;
}
