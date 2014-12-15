#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QSvgWidget>

class Sugoroku;

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::MainWindow *ui;
        Sugoroku* sugoroku;
        QWidget* central;


    public:
        static const int N = 4;
        QLayout *layouts[N];
        QSvgWidget* blackSpace = new QSvgWidget(":/gameIcons/table.svg");
        QSvgWidget* whiteSpace = new QSvgWidget(":/gameIcons/table.svg");
        QSvgWidget* centerSpace = new QSvgWidget(":/gameIcons/center.svg");
        explicit MainWindow( Sugoroku* sugoroku, QWidget *parent = 0 );
        ~MainWindow();

    protected:
        void load_layouts();
        //void load_spaces();


private slots:
        void on_action_New_game_triggered();
};

#endif // MAINWINDOW_H
