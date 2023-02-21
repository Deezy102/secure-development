#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "credslist.h"

#include <QObject>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>


class FileManager
{
public:
    FileManager();
    FileManager(QString path, QString password);

    QVector<CredsItem> load();
    bool save();

    bool fileExists();
private:
    QString path;
    QString password;
    QFile file;
    QJsonObject json;

};

#endif // FILEMANAGER_H
