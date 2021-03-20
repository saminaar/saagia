import QtQuick 2.0


Rectangle {
    id: text_output

    color: "white"
    border.color: "#1d1b29"
    border.width: 3
    width: 350
    height: 200

    TextEdit {
        id: textEdit
        width: 10
        height: 70
        //text: cardView.cardValue
        text: saagia_view.print_data
        font.pixelSize: 13
    }


}
