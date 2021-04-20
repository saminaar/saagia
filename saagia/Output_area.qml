import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15


Rectangle {
    id: text_output

    color: "transparent"

    Text {
                text: saagia_view.print_data
                color: "#fff"
                font.family: "consolas"
                font.pixelSize: 13

        }
}

