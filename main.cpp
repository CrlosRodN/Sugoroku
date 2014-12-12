#include "MainWindow.h"
#include "Sugoroku.h"
#include <QApplication>

int main( int argc, char *argv[] )
{
    Sugoroku game( argc, argv );
    return game.play();
}
