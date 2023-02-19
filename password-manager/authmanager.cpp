#include "authmanager.h"

AuthManager::AuthManager(QObject *parent)
    : QObject{parent}
{

}

void AuthManager::getPincode(QString pincode)
{
    bool result = false;
    if (pincode == "0000") {
        result = true;
        this->pincode = "0000";
        emit auth(result);
    }

    emit auth(result);
}
