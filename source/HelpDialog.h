#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

/*!
 * This whole class is the responsible for showing the help message
 * to the user when the user hits the instruction button
 */

namespace Ui {
	class HelpDialog;
}

class HelpDialog : public QDialog
{
	Q_OBJECT

  public:
	explicit HelpDialog(QWidget *parent = 0);
	~HelpDialog();

  private:
	Ui::HelpDialog *ui;
};

#endif // HELPDIALOG_H
