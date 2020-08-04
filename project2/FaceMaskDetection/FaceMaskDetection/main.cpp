#include "FaceMaskDetection.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	system("chcp 65001");
    QApplication a(argc, argv);
    FaceMaskDetection w;
    w.show();

    return a.exec();
}
