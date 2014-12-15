#include "Sugoroku.h"
#include "MainWindow.h"
#include <QLayout>
#include <ctime>

Sugoroku::Sugoroku( int& argc, char* argv[] )
	: QApplication( argc, argv )
	, mainWindow(nullptr)
{}

Sugoroku::~Sugoroku()
{
	delete DiceOne;
	delete DiceTwo;
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
	connect( mainWindow, SIGNAL( new_game() ), this, SLOT( new_game_selection() ) );
	load_tokens();
	display_dices();
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
		timer = new QTimer( this );
		connect( timer, SIGNAL( timeout() ), this, SLOT( display_winner() ) );
		this->WhitePlayer.push_back( whiteToken );
		this->BlackPlayer.push_back( blackToken );
		DiceOne = new Dice();
		DiceTwo = new Dice();
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
	DiceOne->setGeometry( 860, 30, 60, 60 );
	DiceTwo->setGeometry( 860, 120, 60, 60 );
	DiceOne->setParent( mainWindow->centerSpace );
	DiceTwo->setParent( mainWindow->centerSpace );
}

void Sugoroku::play()
{
	display_tokens();
	mainWindow->blackSpace->setEnabled( false );
	next_turn();
}

void Sugoroku::token_clicked( Token* active )
{
	int x = active->pos().rx();
	int y = active->pos().ry();
	int new_x = ( move_count == 0 ) ? x - 11/*DiceOne->real_value*/ * 80 : x - 11/*DiceTwo->real_value*/ * 80;
	new_x = ( new_x < 0 ) ? ( 2 * 80 + new_x * -1 ) + ( new_x % 80 * 2): new_x;
	active->move( new_x, y );
	if ( new_x > 0 && new_x < 80 )
	active->setEnabled( false );

	if ( have_winner() )
	{
		play();
		unlock_all();
	}

	move_count++;
	if ( move_count == 2)
	{
	move_count = 0;
	next_turn();
	}
}

void Sugoroku::next_turn()
{
    if ( mainWindow->whiteSpace->isEnabled() )
    {
        mainWindow->whiteSpace->setEnabled( false );
        mainWindow->blackSpace->setEnabled( true );
        currentPlayer = "black";
    }
    else
    {
        mainWindow->whiteSpace->setEnabled( true );
        mainWindow->blackSpace->setEnabled( false );
        currentPlayer = "white";
    }
    DiceOne->roll();
    DiceTwo->roll();
}

bool Sugoroku::have_winner()
{
    if ( currentPlayer == "white" )
        for ( int i = 0; i < WhitePlayer.size(); i++ )
            if ( WhitePlayer[i]->pos().rx() > 80 )
                return false;

    if ( currentPlayer == "black" )
        for ( int i = 0; i < BlackPlayer.size(); i++ )
            if ( BlackPlayer[i]->pos().rx() > 80 )
                return false;

	emit winner_found();
	timer->start( 90 );
	//qDebug() << currentPlayer;
    return true;
}

void Sugoroku::unlock_all()
{
    for ( int i = 0; i < BlackPlayer.size(); i++ )
    {
        BlackPlayer[i]->setEnabled( true );
        WhitePlayer[i]->setEnabled( true );
    }
}

void Sugoroku::new_game_selection()
{
	unlock_all();
	play();
}

void Sugoroku::display_winner()
{	qDebug() << currentPlayer;
	QFont f("Arial", 26, QFont::Bold);
	QLabel* showWinner = new QLabel( QString( "Winner: %1 player" ).arg( currentPlayer ) );
	showWinner->setParent( mainWindow->centerSpace );
	showWinner->setFont(f);
	showWinner->setGeometry( 280, 0, 400, 211 );
	showWinner->show();
	timer->stop();
}
