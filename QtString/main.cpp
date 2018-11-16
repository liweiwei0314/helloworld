#include "qtstringdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtStringDialog w;
    w.show();

    return a.exec();
}
