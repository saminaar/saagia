import QtQuick 2.0

Rectangle {
    id: show_case

    width: 500
    height: 70
    color: "#1d1b29"


    Rectangle {
        id: save_image_button
        anchors.right: parent.right
        anchors.rightMargin: 13
        anchors.leftMargin: 452
        y: 25
        width: 35
        height: 35
        color: "#090426"
        border.width: 1
        anchors.left: parent.left
        border.color: "white"

        Image {
            id: button_image
            width: 20
            height: 20
            anchors.centerIn: parent
            fillMode: Image.Stretch
            source: "qrc:/images/save_icon"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
              saagia_controller.save_chart_image()
            }
        }
    }



    Text {
        id: case_title
        x: 10
        y: 5
        width: 291
        height: 54
        color: "#ffffff"
        text: qsTr("Timeframe: 01.01.2021 00:00 - 01.01.2021 23:00")
        font.pixelSize: 15
    }
    Text {
        id: energy_type
        x: 10
        y: 30
        width: 291
        height: 54
        color: "#66ff99"
        text: qsTr("Electricity consumption in Finland (MWh/h)")
        font.pixelSize: 15
    }



}
