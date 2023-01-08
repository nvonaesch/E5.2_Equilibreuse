#include "equlibreuse.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Equlibreuse w;
    w.show();
    return a.exec();
}
