#include "sources/about.h"
#include <QCloseEvent>
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
		ui->setupUi(this);
}

About::~About()
{
		delete ui;
}

void About::changeEvent(QEvent *e)
{
		QDialog::changeEvent(e);
		switch (e->type()) {
		case QEvent::LanguageChange:
			ui->retranslateUi(this);
			break;
		default:
			break;
		}
}
/*! user close window
 * \params
 * - event - event descriptor
 * \return no
 */
void About::on_ok_clicked()
{
	hide();
}
/*! window can't be closed!
 * \params
 * - event - event descriptor
 * \return no
 */
void About::closeEvent(QCloseEvent *event)
 {
	hide();
	event->ignore();
 }
