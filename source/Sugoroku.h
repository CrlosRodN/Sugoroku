#ifndef SUGOROKU_H
#define SUGOROKU_H

#include "Token.h"
#include "Dice.h"
#include <QApplication>
#include <QVector>

class MainWindow;

/*!
 * This class is the responsible of the game rules and logic.
 */

class Sugoroku : public QApplication
{

	Q_OBJECT

  private:
	int move_count = 0;
	QTimer *timer;

  protected:
	///Part of the fordward declaration of the class main window
	MainWindow* mainWindow;
	///A vector containing all the tokens of the black player
	QVector<Token*> BlackPlayer;
	///A vector containing all the tokens of the white player
	QVector<Token*> WhitePlayer;
	///The dices used in the game
	Dice* DiceOne;
	Dice* DiceTwo;
	///Is the player who is currently in his turn
	QString currentPlayer;

  public:
	 ///C-Tor
	Sugoroku(int &argc, char *argv[]);
	///D-Tor
	~Sugoroku();

	///runs the Sugoroku game
	int run();
	///
	bool load_tokens();
	bool display_tokens();
	void display_dices();
	void play();
	void next_turn();
	bool have_winner();
	void unlock_all();

	signals:
		void winner_found();

  public slots:
	void token_clicked( Token *active );
	void new_game_selection();
	void display_winner();
};

#endif // SUGOROKU_H
