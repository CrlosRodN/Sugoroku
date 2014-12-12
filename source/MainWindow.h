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
        QWidget * central;


    public:
        static const int N = 4;
        QLayout *layouts[N];
        QVector<QSvgWidget*> blackSpace;
        QVector<QSvgWidget*> whiteSpace;
        explicit MainWindow( Sugoroku* sugogoku, QWidget *parent = 0 );
        ~MainWindow();

    protected:
        void load_layouts();
        void load_spaces();


};

#endif // MAINWINDOW_H
