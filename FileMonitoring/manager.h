#ifndef MANAGER_H
#define MANAGER_H
#include <QObject>
#include <QVector>
#include "file.h"
#include "consolelogger.h"

class Manager:public QObject //класс Manager, наследуемый от QObject, для реализации наблюдения за файлами
{
    Q_OBJECT //макрос для корректной реализации сигнально-слотной связи
public:
    Manager();
    ~Manager();
    void Monitoring(); //метод, реализующий слежение за характеристиками файлов: размер и факт существования
    void AddFiles(QString path); //метод добавления файл7ов (так как вектор files приватный) для слежения за ними в основной программе

private:
    QVector<File> files; //Вектор files для хранения информации о файлах
    ConsoleLogger *logger; // Объявляем logger как член класса
signals:
   void FileSizeHasChanged(QString path, bool state, int size); //генерируется, когда происходит изменение размера в файле
   void FileExistenceHasChanged(QString path, bool state, int size); //генерируется, когда происходит изменение существования файла
};

#endif // MANAGER_H
