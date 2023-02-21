import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import Creds

Page {
    id: index
    ColumnLayout {
        anchors.fill: parent
        RowLayout {
            TextField {
                       id: searchField

                       Layout.fillWidth: true
                       Layout.preferredHeight: 50

                       placeholderText: "Введите URL для поиска"
                       font.pixelSize: 20

    //                   onDisplayTextChanged:

            }

            Button {
                text: "Добавить"

            }
        }





        ListView {
            id: listView

            Layout.fillHeight: true
            Layout.fillWidth: true
            height: parent.height - 10


            model: CredsModel {
                list: credsList
            }

            delegate: Rectangle {
                id: delegateRect
                width: listView.width
                height:  50
                border.width: 1

                RowLayout {
                    width: listView.width

                    Text {
                        font.pointSize: 13
                        text: model.website
                        Layout.fillHeight: true
                        Layout.preferredWidth: parent.width * 0.35
                    }

                    Text {
                        font.pointSize: 13
                        text: model.login
                        Layout.fillHeight: true
                        Layout.preferredWidth: parent.width * 0.35
                    }

                    Text {
                        font.pointSize: 13
                        text: model.password
                        Layout.fillHeight: true
                        Layout.preferredWidth: parent.width * 0.35
                    }

                }
            }


        }
    }


}
