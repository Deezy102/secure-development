#include "authpage.h"

AuthPage::AuthPage(QObject *parent)
    : QObject{parent}
{

}

void AuthPage::getPincode(QString pincode)
{
    bool result = false;
    if (pincode == "0000") {
        result = true;
        this->pincode = "0000";
        emit auth(result);
    }

    emit auth(result);
}
