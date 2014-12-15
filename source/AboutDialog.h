#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

/*!
 * This whole class is the responsible for showing th e about message
 * to the user when the user hits the about button
 */

namespace Ui {
	class About;
}

class AboutDialog : public QDialog
{
	Q_OBJECT

  public:
	explicit AboutDialog(QWidget *parent = 0);
	~AboutDialog();

  private:
	Ui::About *ui;
};

#endif // DIALOG_H
