#ifndef GRIDWINDOW_H
#define GRIDWINDOW_H

#include <QMainWindow>
#include <QSettings>
namespace Ui {
    class GridWindow;
}

class GridWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GridWindow(QWidget *parent = 0);
    ~GridWindow();
     void grid(QSettings&settings);
protected:
    void changeEvent(QEvent *e);
    virtual void paintEvent ( QPaintEvent * event );
    virtual void closeEvent(QCloseEvent *event);
    virtual void moveEvent ( QMoveEvent * event );
    virtual void keyPressEvent ( QKeyEvent * event );
    virtual void resizeEvent ( QResizeEvent * event );
private:
    Ui::GridWindow *ui;
	int w, h;//! width & height grid
	int between;//! between cells
	double trasp;//! transporent level
        QSettings *settings_array;
private slots:
    void on_actionMove_to_left_triggered();
public slots:
    void on_change();
};

#endif // GRIDWINDOW_H
