#include "credslist.h"

CredsList::CredsList(QObject *parent)
    : QObject{parent}
{

}

QVector<CredsItem> CredsList::getItems() const
{
    return mItems;
}

bool CredsList::setItemAt(int index, const CredsItem &item)
{
    if (index < 0 || index >= mItems.size()){
        return false;
    }

    mItems[index] = item;
    return true;
}

void CredsList::appendItem()
{
    emit preItemAppended();

    CredsItem item;
    mItems.append(item);

    emit postItemAppended();
}
