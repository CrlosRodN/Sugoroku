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
    delete mainWindow;
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
    display_tokens();
    display_dices();
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
        Token* blackToken = new Token(":/gameIcons/black.svg");
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

void Sugoroku::search_active_tokens()
{
    for ( int i = 0; i < BlackPlayer.size(); i++ )
        ! BlackPlayer[i]->active ? qDebug() << "token " << i << " is active" : qDebug() << "token " << i << " is inactive";
}

void Sugoroku::display_dices()
{
    QVBoxLayout* layout = new QVBoxLayout;
    mainWindow->centerSpace->setLayout( layout );
    DiceOne = new Dice();
    DiceTwo = new Dice();
    QString temp = ( "DICEONE" );
    QString temp2 = ( "DICETWO" );
    DiceOne->setText( temp );
    DiceTwo->setText( temp2 );
    layout->addWidget( DiceOne );
    layout->addWidget( DiceTwo );
    layout->setAlignment(Qt::AlignRight);
    //diceOne->setParent( mainWindow->centerSpace );
    //diceOne->show();
}
