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
    for ( int i = 0; i < 4; i++ )
    {
        //mainWindow->layouts[2]->addWidget(this->WhitePlayer[i]->tile);
        //mainWindow->layouts[3]->removeItem( mainWindow->layouts[3]->itemAt(i) );
        WhitePlayer[i]->tile->setParent(mainWindow->whiteSpace[11] );
        WhitePlayer[i]->tile->setGeometry ( 15, i*53, 50, 50 );
        BlackPlayer[i]->tile->setParent(mainWindow->blackSpace[11] );
        BlackPlayer[i]->tile->setGeometry ( 15, i*53, 50, 50 );
        //mainWindow->layouts[3]->removeItem( dynamic_cast <QLayoutItem*>( WhitePlayer[i]->tile->parentWidget() ) );
        //WhitePlayer[i]->tile->show();
        //mainWindow->update();
    }
    return true;
}
