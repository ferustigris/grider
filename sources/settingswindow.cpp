#include "sources/settingswindow.h"
#include "ui_settingswindow.h"
#include <QCloseEvent>
#include <QMessageBox>
/*! constructor
 * \params
 * - parent - parent widget
 * \return no
 */
SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    settings_array = NULL;
    //setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowTitleHint);
}
/*! destructor
 * \params no
 * \return no
 */
SettingsWindow::~SettingsWindow()
{
    delete ui;
}
/*! change
 * \params no
 * \return no
 */
void SettingsWindow::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
/*! user click on ok
 * \params no
 * \return no
 */
void SettingsWindow::on_ok_clicked()
{
	on_change();
	hide();
}
/*! user click on cancel
 * \params no
 * \return no
 */
void SettingsWindow::on_cancel_clicked()
{
	hide();
}
/*! get settings
 * \params no
 * \return no
 */
bool SettingsWindow::settings(QSettings&settings_array)
{
	ui->horizontal->setValue(settings_array.value("horizontal", 19).toInt());
	ui->vertical->setValue(settings_array.value("vertical", 34).toInt());
	ui->transparenty->setValue(settings_array.value("transparenty", 0.3).toDouble()*100);
	ui->between->setValue(settings_array.value("between", 0).toInt());
	ui->x->setValue(settings_array.value("x", 0).toInt());
	ui->y->setValue(settings_array.value("y", 0).toInt());
	ui->w->setValue(settings_array.value("w", 800).toInt());
	ui->h->setValue(settings_array.value("h", 600).toInt());
	ui->full_screen->setChecked(settings_array.value("full_screen", false).toBool());
	this->settings_array = &settings_array;
	show();
	return true;
}
/*! window can't be closed!
 * \params
 * - event - event descriptor
 * \return no
 */
void SettingsWindow::closeEvent(QCloseEvent *event)
 {
	hide();
	event->ignore();
 }
/*! change horizontal value
 * \params
 * - value - new value
 * \return no
 */
void SettingsWindow::on_horizontal_valueChanged(int )
{
	on_change();
}
/*! change horizontal value
 * \params
 * - value - new value
 * \return no
 */
void SettingsWindow::on_vertical_valueChanged(int )
{
	on_change();
}
/*! change horizontal value
 * \params
 * - value - new value
 * \return no
 */
void SettingsWindow::on_between_valueChanged(int )
{
	on_change();
}
/*! change horizontal value
 * \params
 * - value - new value
 * \return no
 */
void SettingsWindow::on_transparenty_valueChanged(double )
{
	on_change();
}
/*! change horizontal value
 * \params no
 * \return no
 */
void SettingsWindow::on_change()
{
	if(settings_array)
	{
		settings_array->setValue("horizontal", ui->horizontal->value());
		settings_array->setValue("vertical", ui->vertical->value());
		settings_array->setValue("between", ui->between->value());
		settings_array->setValue("transparenty", ((double)ui->transparenty->value()/100.0));
		settings_array->setValue("x", ui->x->value());
		settings_array->setValue("y", ui->y->value());
		settings_array->setValue("w", ui->w->value());
		settings_array->setValue("h", ui->h->value());
		settings_array->setValue("full_screen", ui->full_screen->isChecked());
	}
	emit s_change();
}
/*! change x value
 * \params no
 * \return no
 */
void SettingsWindow::on_x_valueChanged(int )
{
        on_change();
}
/*! change y value
 * \params no
 * \return no
 */
void SettingsWindow::on_y_valueChanged(int )
{
        on_change();
}
/*! change w value
 * \params no
 * \return no
 */
void SettingsWindow::on_w_valueChanged(int )
{
        on_change();
}
/*! change h value
 * \params no
 * \return no
 */
void SettingsWindow::on_h_valueChanged(int )
{
        on_change();
}

void SettingsWindow::on_transparenty_valueChanged(int )
{
	on_change();
}

void SettingsWindow::on_full_screen_stateChanged(int )
{
	on_change();
}
