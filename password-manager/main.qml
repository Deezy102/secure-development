import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: root
    width: 450
    height: 480
    visible: true
    title: "Password Manager"
    minimumHeight: 480
    minimumWidth: 720
//    maximumHeight: 480
    maximumWidth: 720
    property int defMargin: 10
    property string userLogin

    Connections {
        target: authPage
        function onAuthorized() {
            stackView.push(index)
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem:  authPage

    }

    AuthPage {
        id: authPage
    }

    PMPage {
        id: index
        visible: false
        anchors.centerIn: parent
    }



}
