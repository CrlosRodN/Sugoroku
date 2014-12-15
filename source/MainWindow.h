#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QSvgWidget>

class Sugoroku;

namespace Ui { class MainWindow; }

/*!
 * This class is the responsible of generating the main window
 */

class MainWindow : public QMainWindow
{
	Q_OBJECT

  private:
	///The main window instance
	Ui::MainWindow *ui;
	///Part of the fordward declaration of the class sugoroku
	Sugoroku* sugoroku;
	///Is the background of the main window, and is the board of the game
	QWidget* central;


  public:

	static const int N = 4;
	QLayout *layouts[N];
	///Is the side of the board where the black tokens are located
	QSvgWidget* blackSpace = new QSvgWidget(":/gameIcons/table.svg");
	///Is the side of the board where the white tokens are located
	QSvgWidget* whiteSpace = new QSvgWidget(":/gameIcons/table.svg");
	///Is the center of the board where the dices are located
	QSvgWidget* centerSpace = new QSvgWidget(":/gameIcons/center.svg");
	///C-tor
	explicit MainWindow( Sugoroku* sugoroku, QWidget *parent = 0 );
	///D-tor
	~MainWindow();

  signals:
	///Is the slot that will be executed when the new_Game button is pressed
	void new_game();

  protected:
	///Load the parts of the board
	void load_layouts();

  protected slots:
	///shows the about message
	void showAboutMessage();
	///shows the help message
	void showHelpMessage();

  private slots:
	///emits the newgame() signal
	void on_action_New_game_triggered();
};

#endif // MAINWINDOW_H
