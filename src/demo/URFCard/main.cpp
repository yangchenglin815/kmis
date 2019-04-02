#include "URFCard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    URFCard w;
    w.show();

    return a.exec();
}
