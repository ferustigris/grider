#include <QtGui/QApplication>
#include "gridicon.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	GridIcon w;
    w.show();

    return a.exec();
}
