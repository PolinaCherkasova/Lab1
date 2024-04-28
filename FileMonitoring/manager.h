#ifndef MANAGER_H
#define MANAGER_H
#include <QObject>
#include <QVector>
#include "file.h"

class Manager:public QObject //класс Manager, наследуемый от QObject, для реализации наблюдения за файлами
{
    Q_OBJECT //макрос для корректной реализации сигнально-слотной связи
public:
    static Manager& Instance() //статический метод для создания объекта-одиночки
    {
        static Manager s;
        return s;
    }
    void Monitoring(int i); //метод, реализующий слежение за характеристиками файлов: размер и факт существования
    void AddFiles(QString path); //метод добавления файлов (так как вектор files приватный) для слежения за ними в основной программе

private:
    Manager() {} //приватный конструктор по умолчанию
    //необходимо также запретить копирование
    Manager(Manager const&); //реализация не нужна
    Manager& operator= (Manager const&); //и тут реализация не нужна

    QVector<File> files; //Вектор files для хранения информации о файлах
signals:
   void FileSizeHasChanged(); //генерируется, когда происходит изменение размера в файле
   void FileExistenceHasChanged(); //генерируется, когда происходит изменение существования файла

   //connect();
   //connect();
};

#endif // MANAGER_H
