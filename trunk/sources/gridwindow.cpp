#include "sources/gridwindow.h"
#include "ui_gridwindow.h"
#include <QPainter>
#include <QCloseEvent>

/*! constructor
 * \params
 * - parent - parent widget
 * \return no
 */
GridWindow::GridWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GridWindow)
{
    ui->setupUi(this);
    settings_array = NULL;
	w = 35;
	h = 19;
	between = 0;
	trasp = 0.3;
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);
        //grabKeyboard();
}
/*! destructor
 * \params no
 * \return no
 */
GridWindow::~GridWindow()
{
    releaseKeyboard();
    delete ui;
}
/*! change
 * \params no
 * \return no
 */
void GridWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
/*! paint
 * \params no
 * \return no
 */
void GridWindow::paintEvent ( QPaintEvent * event )
{
    Q_UNUSED(event);
	QPainter painter(this);
	for(int i = 0; i < 4000; i += w)
	{
		painter.drawLine(i, 0, i, 4000);
		i += between;
		painter.drawLine(i, 0, i, 4000);
	}
	for(int i = 0; i < 4000; i += h)
	{
		painter.drawLine(0, i, 4000, i);
		i += between;
		painter.drawLine(0, i, 4000, i);
	}
}
/*! grid show
 * \params no
 * \return no
 */
void GridWindow::grid (QSettings&settings)
{
    settings_array = &settings;
    //QMessageBox::information(0, settings.value("vertical").toString(), settings.value("horizontal").toString());
    if(isVisible())
    {
        settings_array = NULL;
        hide();
    }
    else
    {
        on_change();
        show();
    }
}
/*! window can't be closed!
 * \params
 * - event - event descriptor
 * \return no
 */
void GridWindow::closeEvent(QCloseEvent *event)
 {
	 event->ignore();
 }

void GridWindow::on_actionMove_to_left_triggered()
{
    move(100,100);
}
/*! move
 * \params
 * - event - event descriptor
 * \return no
 */
void GridWindow::moveEvent ( QMoveEvent * event )
{
    if(settings_array)
    {
        settings_array->setValue("x", event->pos().x());
        settings_array->setValue("y", event->pos().y());
    }
}
/*! key pressed
 * \params
 * - event - event descriptor
 * \return no
 */
void GridWindow::keyPressEvent ( QKeyEvent * event )
{
    switch(event->key())
    {
    case Qt::Key_Left:
        move(x()-1, y());
        break;
    case Qt::Key_Right:
        move(x()+1, y());
        break;
    case Qt::Key_Up:
        move(x(), y()-1);
        break;
    case Qt::Key_Down:
        move(x(), y()+1);
        break;
    case Qt::Key_Plus:
        resize(width()+1, height()+1);
        break;
    case Qt::Key_Minus:
        resize(width()-1, height()-1);
        break;
    case Qt::Key_Escape:
        hide();
        break;
    }
}
/*! resize event
 * \params
 * - event - event descriptor
 * \return no
 */
void GridWindow::resizeEvent(QResizeEvent * event )
{
    if(settings_array)
    {
        settings_array->setValue("w", event->size().width());
        settings_array->setValue("h", event->size().height());
    }
}
/*! for link with third
 * \params no
 * \return no
 */
void GridWindow::on_change()
{
    if(settings_array)
    {
        move(settings_array->value("x").toInt(), settings_array->value("y").toInt());
        resize(settings_array->value("w").toInt(), settings_array->value("h").toInt());
        w = settings_array->value("horizontal").toInt();
        h = settings_array->value("vertical").toInt();
        between = settings_array->value("between").toInt();
        trasp = settings_array->value("transparenty").toDouble();
        setWindowOpacity(trasp);
        repaint();
    }
}
