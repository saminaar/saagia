import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {

    id: layout
    width: 320
    height: 500
    color: "transparent"


    Text {
        id: energy_title
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 10
        color: "white"
        font.pixelSize: 13
        text: "Archived data to show..."

    }


    RadioButton {
        id: button_1
        text: qsTr("Electricity production")

        anchors.top: energy_title.bottom
        anchors.left: layout.left
        anchors.margins: 5

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

        onToggled: saagia_controller.set_data_type(2)

    }

    RadioButton {
        id: button_2
        text: qsTr("Nuclear production")

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

        onToggled: saagia_controller.set_data_type(3)
    }

    RadioButton {
        id: button_3
        text: qsTr("Hydro production")

        anchors.top: button_1.top
        anchors.right: layout.right

        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_3.leftPadding
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
            leftPadding: button_3.indicator.width + button_3.spacing
        }

        onToggled: saagia_controller.set_data_type(4)
    }

    RadioButton {
        id: button_4
        text: qsTr("Wind power production")

        anchors.top: button_3.bottom
        anchors.left: button_3.left
        anchors.right: button_3.right

        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_4.leftPadding
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
            width: 160
            text: button_4.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_4.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_4.indicator.width + button_4.spacing
        }

        onToggled: saagia_controller.set_data_type(5)
    }

    RadioButton {
        id: button_11
        width: 115
        text: qsTr("Electricity consumption")

        anchors.top: button_2.bottom
        anchors.left: button_2.left
        anchors.right: button_2.right

        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_11.leftPadding
            y: parent.height / 2 - height / 2
            radius: 12
            border.color: button_11.down ? "#ff9933" : "#e67300"

            Rectangle {
                width: 10
                height: 10
                x: 5
                y: 5
                radius: 7
                color: button_11.down ? "#ff9933" : "#e67300"
                visible: button_11.checked
            }
        }

        contentItem: Text {
            text: button_11.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_11.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_11.indicator.width + button_11.spacing
        }

        onToggled: saagia_controller.set_data_type(1)
    }

    Rectangle {

        id: line
        height: 1
        color: "grey"

        anchors.top: button_11.bottom
        anchors.topMargin: 5
        anchors.left: layout.left
        anchors.leftMargin: 10

        width: parent.width + 30

    }

    Text {

        id: forecast_title
        anchors.top: line.bottom
        anchors.left: layout.left
        anchors.margins: 10
        color: "white"
        font.pixelSize: 13
        text: "Forecast(s) to show.."

    }

    RadioButton {
        id: button_5
        text: qsTr("Electricity production")

        anchors.top: forecast_title.bottom
        anchors.topMargin: 5
        anchors.left: layout.left
        anchors.leftMargin: 5

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
            width: 145
            text: button_5.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_5.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_5.indicator.width + button_5.spacing
        }

        onToggled: saagia_controller.set_data_type(7)
    }

    RadioButton {
        id: button_6
        text: qsTr("Windpower production")

        anchors.top: button_5.bottom
        anchors.left: button_5.left
        anchors.right: button_5.right

        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_6.leftPadding
            y: parent.height / 2 - height / 2
            radius: 12
            border.color: button_6.down ? "#ff9933" : "#e67300"

            Rectangle {
                width: 10
                height: 10
                x: 5
                y: 5
                radius: 7
                color: button_6.down ? "#ff9933" : "#e67300"
                visible: button_6.checked
            }
        }

        contentItem: Text {
            width: 155
            text: button_6.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_6.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_6.indicator.width + button_6.spacing
        }

        onToggled: saagia_controller.set_data_type(8)
    }

    RadioButton {
        id: button_7
        text: qsTr("Electricity consumption")

        anchors.top: button_5.top
        anchors.right: layout.right
        anchors.rightMargin: -31


        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_3.leftPadding
            y: parent.height / 2 - height / 2
            radius: 12
            border.color: button_7.down ? "#ff9933" : "#e67300"

            Rectangle {
                width: 10
                height: 10
                x: 5
                y: 5
                radius: 7
                color: button_7.down ? "#ff9933" : "#e67300"
                visible: button_7.checked
            }
        }

        contentItem: Text {
            text: button_7.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_7.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_7.indicator.width + button_7.spacing
        }
        onToggled: saagia_controller.set_data_type(6)
    }

    RadioButton {
        id: button_8
        text: qsTr("Weather temperature")

        anchors.top: button_7.bottom
        anchors.left: button_7.left
        anchors.right: button_7.right

        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_8.leftPadding
            y: parent.height / 2 - height / 2
            radius: 12
            border.color: button_8.down ? "#ff9933" : "#e67300"

            Rectangle {
                width: 10
                height: 10
                x: 5
                y: 5
                radius: 7
                color: button_8.down ? "#ff9933" : "#e67300"
                visible: button_8.checked
            }
        }

        contentItem: Text {
            text: button_8.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_8.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_8.indicator.width + button_8.spacing
        }

        onToggled: saagia_controller.set_data_type(9)
    }

    RadioButton {
        id: button_9
        width: 115
        text: qsTr("Wind speed")

        anchors.top: button_6.bottom
        anchors.left: button_6.left
        anchors.right: button_6.right

        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_9.leftPadding
            y: parent.height / 2 - height / 2
            radius: 12
            border.color: button_9.down ? "#ff9933" : "#e67300"

            Rectangle {
                width: 10
                height: 10
                x: 5
                y: 5
                radius: 7
                color: button_9.down ? "#ff9933" : "#e67300"
                visible: button_9.checked
            }
        }

        contentItem: Text {
            text: button_9.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_9.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_9.indicator.width + button_9.spacing
        }

        onToggled: saagia_controller.set_data_type(10)
    }

    Rectangle {

        id: line_2
        height: 1
        color: "grey"

        anchors.top: button_9.bottom
        anchors.topMargin: 10
        anchors.left: layout.left
        anchors.leftMargin: 10

        width: parent.width + 30

    }


    RadioButton {
        id: button_10
        width: 162
        text: qsTr("Weather data")

        anchors.top: line_2.bottom
        anchors.topMargin: 5
        anchors.left: layout.left
        anchors.leftMargin: 5

        indicator: Rectangle {
            implicitWidth: 20
            implicitHeight: 20
            x: button_1.leftPadding
            y: parent.height / 2 - height / 2
            radius: 12
            border.color: button_10.down ? "#ff9933" : "#e67300"

            Rectangle {
                width: 10
                height: 10
                x: 5
                y: 5
                radius: 7
                color: button_10.down ? "#ff9933" : "#e67300"
                visible: button_10.checked
            }
        }

        contentItem: Text {
            width: 150
            text: button_10.text
            font.pointSize: 9
            opacity: enabled ? 1.0 : 0.3
            color: button_10.down ? "#ff9933" : "#ffe6cc"
            verticalAlignment: Text.AlignVCenter
            leftPadding: button_10.indicator.width + button_10.spacing
        }

        onToggled: saagia_controller.set_data_type(11)
    }

    Rectangle {

        id: line_3
        height: 1
        color: "grey"

        anchors.top: button_10.bottom
        anchors.topMargin: 10
        anchors.left: layout.left
        anchors.leftMargin: 10

        width: parent.width + 30

    }

}

