import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.15

Popup {

        property color background_level_0: "#16141f"
        property color background_level_1: "#302c40"
        property color background_level_2: "#dbd6f9"
        property color accent_color: "#ffa500" // orange
        property color text_color: "#cdcdcd" // grey-ish

        property string title_text: qsTr("Retrieve new datasets")
        property string subtitle_text: qsTr("Energy type(s) to show..")

        property Currently_showing_box show_case

        id: popup


        background: Rectangle {
            height: 180
            color: background_level_0
            opacity: 0.9
            implicitWidth: 400
            implicitHeight: 300
            border.color: "grey"
            border.width: 1
        }

        width: 400
        height: 175
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

        enter: Transition {
            NumberAnimation { property: "opacity"; from: 0.0; to: 1.0 }
        }
        exit: Transition {
            NumberAnimation { property: "opacity"; from: 1.0; to: 0.0 }
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

        Rectangle {

            id: background
            color: background_level_1
            width: parent.width - 20
            height: parent.height - 40
            x: 10
            y: 30

        Image {
            id: logo
            width: 140
            height: 40


            source: "qrc:/images/application_name.png"
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.centerIn: parent
        }


        Text {
            id: title_text

            text: qsTr("Version: 1.0")

            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: logo.bottom

            color: text_color
            font.pixelSize: 13
            horizontalAlignment: Text.AlignHCenter

        }

        Rectangle {

            id: top_line

            height: 1
            color: "orange"
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
        }


        Rectangle {

            id: bottom_line

            height: 1
            color: "orange"
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
        }
        }
}
