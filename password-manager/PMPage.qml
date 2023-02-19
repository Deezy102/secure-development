import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Page {
    ListView {
        implicitWidth: 500
        implicitHeight: 250

        delegate: RowLayout {
            width: parent.width

            Text {
                font.pointSize: 13
            }

            Button {
                text: "Логин"
            }

            Button {
                text: "Пароль"
            }

        }
    }
}
