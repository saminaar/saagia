import QtQuick 2.0

Rectangle {
    id: energy_button

    width: 60
    height: 60
    color: "#d9d9d9"
    border.width: 3
    border.color: "orange"

    Text {
        id: button_title
        text: "Wind"
        color: "#4c476c"
        anchors.verticalCenter: parent.verticalCenter

        anchors.horizontalCenter: parent.horizontalCenter
    }


    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: energy_button.state == 'Active' ? energy_button.state = "" : energy_button.state = 'Active';
    }

    states: [
        State {
            name: "Active"
            PropertyChanges { target: energy_button; color: "white" }
            PropertyChanges {
                target: button_title
                color: "red"

            }

        }
    ]

}
