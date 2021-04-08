import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: show_case

    width: 500
    height: 70
    color: "#1d1b29"

    Button {

        anchors.right: parent.right
        anchors.rightMargin: 13
        anchors.left: parent.left
        anchors.leftMargin: parent.width - 50
        y: 25

        background: Rectangle {
                color: "#090426"
                implicitWidth: 35
                implicitHeight: 35
                border.width: control.activeFocus ? 2 : 1
                border.color: "#fff"

            }



        Image {

                id: button_image
                width: 20
                height: 20
                anchors.centerIn: parent
                fillMode: Image.Stretch
                source: "qrc:/images/save_icon"

        }

        hoverEnabled: true

        ToolTip.delay: 500
        ToolTip.timeout: 5000
        ToolTip.visible: hovered
        ToolTip.text: qsTr("Save the current chart")

        onClicked: saagia_controller.save_chart_image()

    }


    Text {
        id: case_title
        x: 10
        y: 5
        width: 291
        height: 54
        color: "#ffffff"
        text: saagia_view.active_data
        font.pixelSize: 15

    }
    Text {
        id: energy_type
        x: 10
        y: 30
        width: 291
        height: 54
        color: "#66ff99"
        text: saagia_view.current_text
        font.pixelSize: 15
    }


}
