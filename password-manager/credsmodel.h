 #ifndef CREDSMODEL_H
#define CREDSMODEL_H

#include <QAbstractListModel>

#include "credslist.h"


class CredsList;

class CredsModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(CredsList *list READ list WRITE setList)

public:
    explicit CredsModel(QObject *parent = nullptr);

    enum {
        websiteRole,
        loginRole,
        passwordRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    CredsList *list() const;
    void setList(CredsList *list);

private:
    CredsList *mList;

};

#endif // CREDSMODEL_H
