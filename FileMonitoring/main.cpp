#include <QCoreApplication>
#include "manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Manager& instance = Manager::Instance(); //объект-одиночка для слежения за файлами

    return a.exec();
}
