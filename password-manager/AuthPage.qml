import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Page {
    id: authPage

    signal authorized()

    Connections {
        target: auth
        function onAuth(success) {
            if (success) {
                authPage.authorized();
            }
            if (!success) {
                incorrect.visible = true
                incorrect.text = "Введен неверный пинкод"
            }
        }
    }

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Text {
            id: incorrect
            visible: false
            color: "red"
            font.pointSize: 15
        }

        TextField {
            id: pincode
            Layout.preferredWidth: 200
            Layout.preferredHeight: 40
            Layout.alignment: Qt.AlignHCenter
            placeholderText: "Введите пинкод"
            echoMode: TextInput.Password
            font.pointSize: 15
        }

        Button {
            Layout.preferredWidth: 200
            Layout.preferredHeight: 40
            Layout.alignment: Qt.AlignHCenter
            text: "Войти"
            font.pointSize: 15
            onClicked: auth.getPincode(pincode.text)
        }
    }
}
