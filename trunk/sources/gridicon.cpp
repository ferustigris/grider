#include "gridicon.h"
#include "settingswindow.h"
#include "gridwindow.h"
#include "about.h"
#include <QEvent>
#include <QMessageBox>
/*! constructor
 * \params
 * - parent - parent object
 * \return нет
 */
GridIcon::GridIcon(QWidget *parent) :
	QSystemTrayIcon(parent),
	settings("settings.ini", QSettings::IniFormat)
{
	setIcon(QIcon(":/icons/main"));
	//setContextMenu(&ppTopMenu);
	QAction *grid = new QAction(QIcon(":/icons/grid"), tr("Show grid"), this);
	connect(grid, SIGNAL(triggered()), this, SLOT(on_grid()));
	ppTopMenu.addAction(grid);
	QAction *settings = new QAction(QIcon(":/icons/settings"), tr("Settings"), this);
	connect(settings, SIGNAL(triggered()), this, SLOT(on_settings()));
	ppTopMenu.addAction(settings);
	QAction *help = new QAction(QIcon(":/icons/help"), tr("About"), this);
	connect(help, SIGNAL(triggered()), this, SLOT(on_help()));
	ppTopMenu.addAction(help);
	ppTopMenu.addSeparator();
        QAction *close = new QAction(QIcon(":/icons/close"), tr("Exit"), this);
	connect(close, SIGNAL(triggered()), this, SLOT(on_close()));
	ppTopMenu.addAction(close);
	setContextMenu(&ppTopMenu);
	setToolTip(tr("Devel tools: grid"));
        connect(this, SIGNAL(activated ( QSystemTrayIcon::ActivationReason)),
                this, SLOT(on_activate ( QSystemTrayIcon::ActivationReason)));
}
/*! destructor
 * \params no
 * \return no
 */
GridIcon::~GridIcon()
{
}
/*! user click on close
 * \params no
 * \return no
 */
void GridIcon::on_close()
{
	hide();
	exit(0);
}
/*! for link settings & grid forms
 * \params no
 * \return no
 */
void GridIcon::on_change()
{
        emit s_change();
}
/*! user click on about
 * \params no
 * \return no
 */
void GridIcon::on_help()
{
	static About window;
	window.show();
}
/*! user click on settings
 * \params no
 * \return no
 */
void GridIcon::on_settings()
{
	static SettingsWindow window;
        connect(&window, SIGNAL(s_change()), this, SLOT(on_change()));
	window.settings(settings);
}
/*! user click on show grid
 * \params no
 * \return no
 */
void GridIcon::on_grid()
{
	static GridWindow window;
        connect(this, SIGNAL(s_change()), &window, SLOT(on_change()));
        window.grid(settings);
}
/*! user click on system tray
 * \params no
 * \return no
 */
void GridIcon::on_activate( QSystemTrayIcon::ActivationReason reason )
{
    if(reason == QSystemTrayIcon::Trigger)
    {
        on_grid();
    }
}
