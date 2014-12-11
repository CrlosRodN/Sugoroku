#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        static const int N = 4;
        Ui::MainWindow *ui;
        QGraphicsScene scene;
        QWidget * central;
            //QGridLayout *gridLayout;
            //QFrame * frames[N];
        QLayout *layouts[N];

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    protected:
        void load_layouts();

};

#endif // MAINWINDOW_H
