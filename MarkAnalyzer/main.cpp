#include "Controllers/mainwindow.h"
#include "Managers/appinitializator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppInitializator::shared().setupApplication();

    MainWindow w;
    w.show();

    return a.exec();
}
