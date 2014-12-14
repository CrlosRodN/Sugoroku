#ifndef SUGOROKU_H
#define SUGOROKU_H

#include "Token.h"
#include "Dice.h"
#include <QApplication>
#include <QVector>

class MainWindow;

class Sugoroku : public virtual QApplication

{
    protected:
        MainWindow* mainWindow;
        QVector<Token*> BlackPlayer;
        QVector<Token*> WhitePlayer;
        Dice* DiceOne;
        Dice* DiceTwo;

    public:
        Sugoroku(int &argc, char *argv[]);
        ~Sugoroku();

        int run();
        bool load_tokens();
        bool display_tokens();
        void search_active_tokens();
        void display_dices();
};

#endif // SUGOROKU_H
