#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <QObject>
#include <QString>

class AuthManager : public QObject
{
    Q_OBJECT
public:
    explicit AuthManager(QObject *parent = nullptr);
    QString pincode;
signals:
    void auth(bool success);

public slots:
    void getPincode(QString pincode);
};

#endif // AUTHMANAGER_H
