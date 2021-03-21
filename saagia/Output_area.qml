import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15


Rectangle {
    id: text_output

    color: "black"
    border.color: "#1d1b29"
    border.width: 3
    width: 350
    height: 200

        Flickable {
            id: flickable
            anchors.fill: parent
            TextArea.flickable: TextArea {
                text: saagia_view.print_data
                color: "#fff"
                wrapMode: TextArea.Wrap
                placeholderTextColor: "#ffffff"
                font.family: "consolas"
                font.pixelSize: 13
            }
            ScrollBar.vertical: ScrollBar {
                width: 40
            }
        }
        }
