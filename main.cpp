#include "blisytv.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    blisytv w;
    w.show();
    return a.exec();
}
