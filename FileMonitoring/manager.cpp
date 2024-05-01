#include "manager.h"

Manager::Manager()
{
    // Создание экземпляра ConsoleLogger
    logger = new ConsoleLogger();
    // Подключение сигналов к слотам
    connect(this, &Manager::FileExistenceHasChanged, logger, &ConsoleLogger::PrintFileExistenceChange);
    connect(this, &Manager::FileSizeHasChanged, logger, &ConsoleLogger::PrintFileSizeChange);
}

Manager::~Manager()
{
    delete logger; // Освобождаем память после использования
}

void Manager::Monitoring() //метод, реализующий слежение за характеристиками файлов: размер и факт существования
{
    for (int i = 0; i < files.size(); i++)
    {
        File file = files.at(i); //метод at() для доступа к файлам (элементам вектора files)
        if (file.isChangedStatus()) //если в файле был изменен статус, то
        {
            file.Update(); //обновляем информацию о файле
            emit FileExistenceHasChanged(file.path, file.status, file.size); //генерация сигнала
        }

        else if (file.isChangedSize()) //если в файле был изменен размер, то
        {
            file.Update(); //обновляем информацию о файле
            emit FileSizeHasChanged(file.path, file.status, file.size); //генерация сигнала
        }
    }
}

void Manager::AddFiles(QString path) //метод добавления файлов для слежения за ними в основной программе
{
    File file(path); //создаем объект file, которому передаем путь текущего файла
    files.push_back(file); //добавляем его в вектор files с помощью метода push_back()
}
