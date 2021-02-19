import QtQuick 2.0


Rectangle {
    id: energy_button

    color: "white"
    border.color: "#1d1b29"
    border.width: 3
    width: 350
    height: 200

    TextEdit {
        id: textEdit
        width: 10
        height: 70
        text: qsTr("The program will print out stuff here. . .")
        font.pixelSize: 13
    }


}
