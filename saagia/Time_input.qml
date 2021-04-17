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
        y: 9
        color: "#cdcdcd"
        font.bold: true
        text: qsTr("Start time")
        font.pointSize: 8
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

        enabled: true

        background: Rectangle {
            implicitWidth: 200
            implicitHeight: 40
            color: start_field.activeFocus ? "#ffffff" : "#e6e6e6"
            border.color: start_field.activeFocus ? "orange" : "#262626"
            border.width: start_field.activeFocus ? 2 : 1
        }

        onEditingFinished: {

            saagia_controller.set_the_selected_time(0, start_field.text + ":00")

        }


    }

    Text {

        x: 149
        y: 9
        color: "#cdcdcd"
        font.bold: true
        text: qsTr("End time")
        font.pointSize: 8
        font.family: "Segoe UI"
        font.strikeout: false
        font.italic: false

    }

    TextField {

        id: end_field
        x: 149
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

        background: Rectangle {
            implicitWidth: 200
            implicitHeight: 40
            color: end_field.activeFocus ? "#ffffff" : "#e6e6e6"
            border.color: end_field.activeFocus ? "orange" : "#262626"
            border.width: end_field.activeFocus ? 2 : 1
        }

        onEditingFinished: {

            console.log("End time editing finished")
            console.log("Time: " + end_field.text)
            saagia_controller.set_the_selected_time(1, end_field.text + ":00")

        }

    }

}
