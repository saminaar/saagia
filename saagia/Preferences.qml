import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.15


Popup {

        id: popup

        property color background_level_0: "#16141f"
        property color background_level_1: "#302c40"
        property color background_level_2: "#dbd6f9"
        property color accent_color: "#ffa500" // orange
        property color text_color: "#cdcdcd" // grey-ish

        property string title_text: qsTr("Preferences")

        property string testeri: ""
        property string chosen_start_date: ""
        property string chosen_end_date: ""
        property string chosen_start_time: ""
        property string chosen_end_time: ""

        background: Rectangle {
            height: 150
            color: background_level_0
            opacity: 0.9
            implicitWidth: 400
            implicitHeight: 300
            border.color: "grey"
            border.width: 1
        }


        width: 300
        height: 150
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

        enter: Transition {
            NumberAnimation { property: "opacity"; from: 0.0; to: 1.0 }
        }
        exit: Transition {
            NumberAnimation { property: "opacity"; from: 1.0; to: 0.0 }
        }

        Text {
            id: window_title_text
            x: 10
            y: 4
            color: accent_color
            font.bold: true
            font.pixelSize: 15
            text: title_text
        }

        ComboBox {

            id: combobox
            anchors.top: window_title_text.bottom
            anchors.left: window_title_text.left
            anchors.topMargin: 10

            width: 200
            model: [ "Saved preference 1", "Saved preference 2", "Saved preference 3" ]
        }

        Save_file_dialog {
            id: save_dialog
            dialog_type: 1

        }


        Button{

                anchors.top: combobox.bottom
                anchors.topMargin: 10
                anchors.left: combobox.left

                id: load
                text: "<font color='#ffffff'>" + "Load settings" + "</font>"
                font.pixelSize: 13

                icon.source: "images/refresh.png"
                icon.color: "#d6d6d6"
                icon.width: 15
                icon.height: 15


                background: Rectangle {
                    implicitWidth: 50
                    implicitHeight: 35
                    color: "#090426"
                    border.color: "white"
                    border.width: 1
                }

                onClicked: {

                    console.log(testeri)
                    // Palauta asetukset popupille
                }

        }

        Button{

                anchors.top: combobox.bottom
                anchors.topMargin: 10

                anchors.left: load.right
                anchors.leftMargin: 5

                id: save
                text: "<font color='#ffffff'>" + "Save settings" + "</font>"
                font.pixelSize: 13

                icon.source: "images/save_icon.png"
                icon.color: "#d6d6d6"
                icon.width: 15
                icon.height: 15


                background: Rectangle {
                    implicitWidth: 50
                    implicitHeight: 35
                    color: "#090426"
                    border.color: "white"
                    border.width: 1
                }

                onClicked: {
                    save_dialog.open()


                    // Save dialogille settingsit tähän mukaan!
                }


        }

        Image {
            id: exit_window
            width: 15
            height: 15
            anchors.right: parent.right
            source: "qrc:/images/cancel.png"


            MouseArea {

                anchors.fill: parent
                onClicked: {
                    popup.close()
                }
            }
        }


        Connections {
          target: button
          function onSend(txt) {
              testeri = txt
          }
        }


}

