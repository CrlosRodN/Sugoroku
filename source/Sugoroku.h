#ifndef SUGOROKU_H
#define SUGOROKU_H

#include "Token.h"
#include <QApplication>
#include <QVector>

class MainWindow;

class Sugoroku : public virtual QApplication

{
    protected:
        MainWindow* mainWindow;
        QVector<Token*> BlackPlayer;
        QVector<Token*> WhitePlayer;

    public:
        Sugoroku(int &argc, char *argv[]);
        ~Sugoroku();

        int play();
        bool load_tokens();
        bool display_tokens();
};

#endif // SUGOROKU_H
