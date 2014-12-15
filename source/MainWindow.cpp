#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QLayout>
#include <QSvgWidget>
#include <vector>

MainWindow::MainWindow( Sugoroku *sugoroku, QWidget *parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
    , sugoroku(sugoroku)
{
    ui->setupUi( this );
    central = new QWidget( this );
    setCentralWidget( central );
    //load_spaces();
    load_layouts();
    central->setLayout( layouts[0] );
    central->show();
    //this->show();
}

MainWindow::~MainWindow()
{
    delete centerSpace;
    delete whiteSpace;
    delete blackSpace;
    delete ui;
}

void MainWindow::load_layouts()
{
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    for ( int i = 1; i < N; i++ )
    {
        layouts[i] = new QHBoxLayout;
        layout->addLayout(layouts[i]);
        if ( i == 1 )
                layouts[i]->addWidget( whiteSpace );
        else if ( i == 3)
                layouts[i]->addWidget( blackSpace );
        else
            layouts[i]->addWidget( centerSpace );
    }
    layouts[0] = layout;
}

void MainWindow::on_action_New_game_triggered()
{
    emit new_game();
}
