#ifndef AUTHPAGE_H
#define AUTHPAGE_H

#include <QObject>
#include <QString>

class AuthPage : public QObject
{
    Q_OBJECT
public:
    explicit AuthPage(QObject *parent = nullptr);
    QString pincode;
signals:
    void auth(bool success);

public slots:
    void getPincode(QString pincode);
};

#endif // AUTHPAGE_H
