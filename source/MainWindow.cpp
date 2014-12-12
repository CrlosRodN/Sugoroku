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
    load_spaces();
    load_layouts();
    central->setLayout( layouts[0] );
    central->show();
}

MainWindow::~MainWindow()
{
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
            for ( int j = 0; j < 12; j++ )
                layouts[i]->addWidget( whiteSpace[j]);

        else if ( i ==  3)
            for ( int j = 0; j < 12; j++ )
                layouts[i]->addWidget( blackSpace[j]);

        else
        {
            QSvgWidget *tile = new QSvgWidget(":/gameIcons/center.svg");
            layouts[i]->addWidget( tile );
        }
    }
    layouts[0] = layout;
}

void MainWindow::load_spaces()
{
    for ( int x = 0; x < 12; x++ )
    {
        whiteSpace.push_back( new QSvgWidget( ":/gameIcons/square.svg" ) );
        blackSpace.push_back( new QSvgWidget( ":/gameIcons/square.svg" ) );
    }
}


