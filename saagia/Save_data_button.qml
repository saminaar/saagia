import QtQuick 2.14

Rectangle {
    id: save_button
    color: "#090426"
    width: 130
    height: 40

    Text {
        id: load_button_text
        text: "SAVE DATA"
        color: "#ffffff"
        font.pixelSize: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        Connections {
            target: mouseArea
            onClicked:
                function pressed_button() {
                    saagia_controller.save_data()
                }
        }
    }
}
