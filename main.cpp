#include "widget.h"
#include <QApplication>
#include "odbchelper.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OdbcHelper help;
    help.getPointId();

    return a.exec();
}
