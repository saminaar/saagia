import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

Button{

        id: button
        text: "<font color='#ffffff'>" + "Retrieve datasets" + "</font>"
        font.pixelSize: 13


        icon.source: "images/refresh.png"
        icon.color: "#d6d6d6"
        icon.width: 15
        icon.height: 15


        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 35
            color: button.down ? "#d6d6d6" : "#090426"
            border.color: "white"
            border.width: 1
        }

}


