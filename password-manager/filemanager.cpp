#include "filemanager.h"

FileManager::FileManager()
{

}

FileManager::FileManager(QString path, QString password)
{
    this->password = password;
    this->path = path;
}
