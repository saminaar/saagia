import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.12


Rectangle {

    width: 205
    height: 70
    color: "transparent"
    property string start_field
    property string end_field

    Text {

        x: 8
        y: 8
        color: "#cdcdcd"
        font.bold: true
        text: qsTr("Start time")
        font.pointSize: 10
        font.family: "Segoe UI"
        font.strikeout: false
        font.italic: false

    }

    TextField {

        id: start_field
        x: 8
        y: 28
        width: 60
        height: 27
        text : "00:00"
        font.letterSpacing: 0
        horizontalAlignment: Text.AlignLeft
        leftPadding: 8
        topPadding: 4
        font.pointSize: 10
        font.italic: false
        font.bold: false
        inputMask: "99:99"
        inputMethodHints: Qt.ImhDigitsOnly

        onEditingFinished: {

            saagia_controller.set_the_selected_time(0, start_field.text + ":00")

        }


    }

    Text {

        x: 133
        y: 8
        color: "#cdcdcd"
        font.bold: true
        text: qsTr("End time")
        font.pointSize: 10
        font.family: "Segoe UI"
        font.strikeout: false
        font.italic: false

    }

    TextField {

        id: end_field
        x: 133
        y: 28
        width: 60
        height: 27
        text : "00:00"
        font.letterSpacing: 0
        horizontalAlignment: Text.AlignLeft
        leftPadding: 8
        topPadding: 4
        font.pointSize: 10
        font.italic: false
        font.bold: false
        inputMask: "99:99"
        inputMethodHints: Qt.ImhDigitsOnly

        onEditingFinished: {

            console.log("End time editing finished")
            console.log("Time: " + end_field.text)
            saagia_controller.set_the_selected_time(1, end_field.text + ":00")

        }

    }

}
