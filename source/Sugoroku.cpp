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

int Sugoroku::play()
{
    Q_ASSERT(mainWindow == nullptr);
    mainWindow = new MainWindow(this);
    load_tokens();
    display_tokens();
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
            WhitePlayer[count]->tile->setParent(mainWindow->whiteSpace[11] );
            WhitePlayer[count]->tile->setGeometry ( 20 + ( count/4 ) + ( count/4*2 ), 15 + ( i*47 ), 40, 40 );
            BlackPlayer[count]->tile->setParent(mainWindow->blackSpace[11] );
            BlackPlayer[count]->tile->setGeometry ( 20 + ( count/4 ) + ( count/4*2 ), 15 + ( i*47 ), 40, 40 );
            count++;
        }
    return true;
}

/*lines thatcan be of some use*/
//mainWindow->layouts[2]->addWidget(this->WhitePlayer[i]->tile);
//mainWindow->layouts[3]->removeItem( mainWindow->layouts[3]->itemAt(i) );
//mainWindow->layouts[3]->removeItem( dynamic_cast <QLayoutItem*>( WhitePlayer[i]->tile->parentWidget() ) );
//WhitePlayer[i]->tile->show();
//mainWindow->update();
