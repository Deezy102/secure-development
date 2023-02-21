#include "credsmodel.h"

CredsModel::CredsModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int CredsModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    return mList->getItems().size();
}

QVariant CredsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    CredsItem item = mList->getItems().at(index.row());
    switch (role) {
        case websiteRole:
            return QVariant(item.website);
        case loginRole:
            return QVariant(item.login);
        case passwordRole:
            return QVariant(item.password);
    }

    return QVariant();
}

bool CredsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList) {
        return false;
    }

    CredsItem item = mList->getItems().at(index.row());
    switch (role) {
        case websiteRole:
            item.website = value.toString();
            break;
        case loginRole:
            item.login = value.toString();
            break;
        case passwordRole:
            item.password = value.toString();
            break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags CredsModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QHash<int, QByteArray> CredsModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[websiteRole] = "website";
    names[loginRole] = "login";
    names[passwordRole] = "password";

    return names;
}

CredsList *CredsModel::list() const
{
    return mList;
}

void CredsModel::setList(CredsList *list){
    beginResetModel();

    if (mList) {
        mList->disconnect(this);
    }

    mList = list;

    if (mList) {
        connect(mList, &CredsList::preItemAppended, this, [=](){
            const int index = mList->getItems().size();
            beginInsertRows(QModelIndex(), index, index);
        });

        connect(mList, &CredsList::postItemAppended, this, [=](){
           endInsertRows();
        });
    }
}
