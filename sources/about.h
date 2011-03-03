#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
    class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
	explicit About(QWidget *parent = 0);
	~About();

protected:
	void changeEvent(QEvent *e);
	void closeEvent(QCloseEvent *event);
private:
	Ui::About *ui;

private slots:
	void on_ok_clicked();
};

#endif // ABOUT_H
