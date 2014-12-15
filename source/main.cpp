#include "MainWindow.h"
#include "Sugoroku.h"
#include <QApplication>

int main( int argc, char *argv[] )
{
	///creates a instance of the game and runs it.
    Sugoroku game( argc, argv );
    return game.run();
}
