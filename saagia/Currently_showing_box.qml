import QtQuick 2.0

Rectangle {
    id: show_case

    width: 500
    height: 70
    color: "#1d1b29"

    Text {
        id: case_title
        x: 10
        y: 5
        width: 291
        height: 54
        color: "#ffffff"
        text: qsTr("Currently showing")
        font.pixelSize: 15
    }
    Text {
        id: energy_type
        x: 10
        y: 30
        width: 291
        height: 54
        color: "#ffffff"
        text: qsTr("Electricity consumption in Finland (MWh/h)")
        font.pixelSize: 15
    }

}
