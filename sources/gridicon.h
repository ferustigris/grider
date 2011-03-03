#ifndef GridIcon_H
#define GridIcon_H

#include <QMenu>
#include <QSettings>
#include <QSystemTrayIcon>

class GridIcon : public QSystemTrayIcon
{
    Q_OBJECT

public:
	explicit GridIcon(QWidget *parent = 0);
	~GridIcon();
private:
	QMenu ppTopMenu;
	QSettings settings;
private slots:
	void on_close();
	void on_settings();
	void on_grid();
	void on_help();
	void on_change();
        void on_activate( QSystemTrayIcon::ActivationReason reason );
signals:
	void s_change();
};

#endif // GridIcon_H
