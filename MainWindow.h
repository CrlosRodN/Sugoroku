#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

class Sugoroku;

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        static const int N = 4;
        Ui::MainWindow *ui;
        QGraphicsScene scene;
        Sugoroku* sugoroku;
        QWidget * central;
            //QGridLayout *gridLayout;
            //QFrame * frames[N];
        QLayout *layouts[N];

    public:
        explicit MainWindow( Sugoroku* sugogoku, QWidget *parent = 0 );
        ~MainWindow();

    protected:
        void load_layouts();

};

#endif // MAINWINDOW_H
