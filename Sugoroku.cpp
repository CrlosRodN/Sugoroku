#include "Sugoroku.h"
#include "MainWindow.h"
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
    mainWindow->show();
    std::srand( std::time(nullptr) );
    return exec();
}
