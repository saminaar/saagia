import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ColumnLayout {

    id: layout
    width: 310
    height: 70

    RadioButton {
        id: button_1
        text: qsTr("Electricity production")

        anchors.top: layout.top
        anchors.left: layout.left

        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_1.leftPadding
            y: parent.height / 2 - height / 2
            radius: 12
            border.color: button_1.down ? "#ff9933" : "#e67300"

            Rectangle {
                width: 10
                height: 10
                x: 5
                y: 5
                radius: 7
                color: button_1.down ? "#ff9933" : "#e67300"
                visible: button_1.checked
            }
        }

        contentItem: Text {
            text: button_1.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_1.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_1.indicator.width + button_1.spacing
        }

        onToggled: saagia_controller.set_data_type(7)
    }

    RadioButton {
        id: button_2
        text: qsTr("Windpower production")

        anchors.top: button_1.bottom
        anchors.left: button_1.left
        anchors.right: button_1.right

        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_2.leftPadding
            y: parent.height / 2 - height / 2
            radius: 12
            border.color: button_2.down ? "#ff9933" : "#e67300"

            Rectangle {
                width: 10
                height: 10
                x: 5
                y: 5
                radius: 7
                color: button_2.down ? "#ff9933" : "#e67300"
                visible: button_2.checked
            }
        }

        contentItem: Text {
            text: button_2.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_2.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_2.indicator.width + button_2.spacing
        }

        onToggled: saagia_controller.set_data_type(8)
    }

    RadioButton {
        id: button_3
        text: qsTr("Electricity consumption")

        anchors.top: layout.top
        anchors.right: layout.right


        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_3.leftPadding + 30
            y: parent.height / 2 - height / 2
            radius: 12
            border.color: button_3.down ? "#ff9933" : "#e67300"

            Rectangle {
                width: 10
                height: 10
                x: 5
                y: 5
                radius: 7
                color: button_3.down ? "#ff9933" : "#e67300"
                visible: button_3.checked
            }
        }

        contentItem: Text {
            text: button_3.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_3.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_3.indicator.width + button_3.spacing + 30
        }

        onToggled: saagia_controller.set_data_type(6)
    }

    RadioButton {
        id: button_4
        text: qsTr("Weather temperature")

        anchors.top: button_3.bottom
        anchors.left: button_3.left
        anchors.right: button_3.right

        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_4.leftPadding + 30
            y: parent.height / 2 - height / 2
            radius: 12
            border.color: button_4.down ? "#ff9933" : "#e67300"

            Rectangle {
                width: 10
                height: 10
                x: 5
                y: 5
                radius: 7
                color: button_4.down ? "#ff9933" : "#e67300"
                visible: button_4.checked
            }
        }

        contentItem: Text {
            text: button_4.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_4.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_4.indicator.width + button_4.spacing + 30
        }

        onToggled: saagia_controller.set_data_type(9)
    }

    RadioButton {
        id: button_5
        text: qsTr("Wind speed")

        anchors.top: button_2.bottom
        anchors.left: button_2.left
        anchors.right: button_2.right

        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_5.leftPadding
            y: parent.height / 2 - height / 2
            radius: 12
            border.color: button_5.down ? "#ff9933" : "#e67300"

            Rectangle {
                width: 10
                height: 10
                x: 5
                y: 5
                radius: 7
                color: button_5.down ? "#ff9933" : "#e67300"
                visible: button_5.checked
            }
        }

        contentItem: Text {
            text: button_5.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_5.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_5.indicator.width + button_5.spacing
        }

        onToggled: saagia_controller.set_data_type(10)
    }

}
