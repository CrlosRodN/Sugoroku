#ifndef SUGOROKU_H
#define SUGOROKU_H

#include "Token.h"
#include "Dice.h"
#include <QApplication>
#include <QVector>

class MainWindow;

class Sugoroku : public QApplication
{

    Q_OBJECT

    private:
        int move_count = 0;

    protected:
        MainWindow* mainWindow;
        QVector<Token*> BlackPlayer;
        QVector<Token*> WhitePlayer;
        Dice* DiceOne;
        Dice* DiceTwo;
        QString currentPlayer;

    public:
        Sugoroku(int &argc, char *argv[]);
        ~Sugoroku();

        int run();
        bool load_tokens();
        bool display_tokens();
        void search_active_tokens();
        void display_dices();
        void play();
        void next_turn();
        bool have_winner();
        void unlock_all();

    public slots:
        void token_clicked( Token *active );
        void new_game_selection();
};

#endif // SUGOROKU_H
