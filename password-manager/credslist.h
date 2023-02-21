#ifndef CREDSLIST_H
#define CREDSLIST_H

#include <QFile>
#include <QObject>
#include <QVector>
#include <QString>

struct CredsItem {
    QString website;
    QString login;
    QString password;
};

class CredsList : public QObject
{
    Q_OBJECT
public:
    explicit CredsList(QObject *parent = nullptr);

    QVector<CredsItem> getItems() const;

    bool setItemAt(int index, const CredsItem &item);

signals:
    void preItemAppended();
    void postItemAppended();

public slots:
    void appendItem();

private:
    QVector<CredsItem> mItems;

};

#endif // CREDSLIST_H
