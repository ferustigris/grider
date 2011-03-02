#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QSettings>
namespace Ui {
    class SettingsWindow;
}
//! settings ui
class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
	explicit SettingsWindow(QWidget *parent = 0);
	~SettingsWindow();
	bool settings(QSettings&settings_array);
protected:
	void changeEvent(QEvent *e);
        void on_change();
        void closeEvent(QCloseEvent *event);

private:
	Ui::SettingsWindow *ui;
	QSettings *settings_array;
private slots:
        void on_h_valueChanged(int );
 void on_w_valueChanged(int );
 void on_y_valueChanged(int );
 void on_x_valueChanged(int );
 void on_transparenty_valueChanged(double );
	void on_between_valueChanged(int );
	void on_vertical_valueChanged(int );
	void on_horizontal_valueChanged(int );
	void on_cancel_clicked();
	void on_ok_clicked();
signals:
        void s_change();
};

#endif // SETTINGSWINDOW_H
