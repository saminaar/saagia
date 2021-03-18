import QtQuick 2.12
import QtQuick.Controls 2.12
Grid {
    id: grid

    width: 200
    height: 60
    clip: false
    padding: 2
    topPadding: 8
    bottomPadding: 0
    leftPadding: 10
    rightPadding: 6
    layoutDirection: Qt.LeftToRight
    verticalItemAlignment: Grid.AlignBottom
    horizontalItemAlignment: Grid.AlignLeft
    flow: Grid.LeftToRight
    rows: 2
    columns: 2
    spacing: 0

    CheckBox {
        id: control
        text: qsTr("Electricity")
        checked: false

        indicator: Rectangle {
                id: indicator
                implicitWidth: 16
                implicitHeight: 16
                radius: 0
                border.color: control.activeFocus ? "orange" : "#cdcdcd"
                border.width: 1

                Rectangle {
                    visible: control.checked
                    color: "#555"
                    border.color: "#333"
                    radius: 1
                    anchors.margins: 4
                    anchors.fill: parent
                }
        }

        contentItem: Text {
            text: control.text
            font: control.font
            opacity: enabled ? 1.0 : 0.3
            color: control.down ? "orange" : "#cdcdcd"

            leftPadding: 15
            topPadding: -9
        }

        onToggled: {
            saagia_controller.set_energy_type(1)
        }
    }

    CheckBox {
        id: wind_check
        text: qsTr("Wind")
        font.letterSpacing: 0
        display: AbstractButton.TextBesideIcon
        checked: false

        indicator: Rectangle {
                id: indicator_2
                implicitWidth: 16
                implicitHeight: 16
                radius: 0
                border.color: wind_check.activeFocus ? "orange" : "#cdcdcd"
                border.width: 1

                Rectangle {
                    visible: wind_check.checked
                    color: "#555"
                    border.color: "#333"
                    radius: 1
                    anchors.margins: 4
                    anchors.fill: parent
                }
        }

        contentItem: Text {
            text: wind_check.text
            font: wind_check.font
            opacity: enabled ? 1.0 : 0.3
            color: wind_check.down ? "orange" : "#cdcdcd"

            leftPadding: 15
            topPadding: -9
        }

        onToggled: {
            saagia_controller.set_energy_type(2)
        }
    }

    CheckBox {
        id: nuclear_check
        text: qsTr("Nuclear")
        checked: false

        indicator: Rectangle {
                id: indicator_3
                implicitWidth: 16
                implicitHeight: 16
                radius: 0
                border.color: nuclear_check.activeFocus ? "orange" : "#cdcdcd"
                border.width: 1

                Rectangle {
                    visible: nuclear_check.checked
                    color: "#555"
                    border.color: "#333"
                    radius: 1
                    anchors.margins: 4
                    anchors.fill: parent
                }
        }

        contentItem: Text {
            text: nuclear_check.text
            font: nuclear_check.font
            opacity: enabled ? 1.0 : 0.3
            color: nuclear_check.down ? "orange" : "#cdcdcd"

            leftPadding: 15
            topPadding: -9
        }

        onToggled: {
            saagia_controller.set_energy_type(3)
        }
    }

    CheckBox {
        id: hydro_check
        text: qsTr("Hydro")
        spacing: 11
        checked: false

        indicator: Rectangle {
                id: indicator_4
                implicitWidth: 16
                implicitHeight: 16
                radius: 0
                border.color: hydro_check.activeFocus ? "orange" : "#cdcdcd"
                border.width: 1

                Rectangle {
                    visible: hydro_check.checked
                    color: "#555"
                    border.color: "#333"
                    radius: 1
                    anchors.margins: 4
                    anchors.fill: parent
                }
        }

        contentItem: Text {
            text: hydro_check.text
            font: hydro_check.font
            opacity: enabled ? 1.0 : 0.3
            color: hydro_check.down ? "orange" : "#cdcdcd"

            leftPadding: 15
            topPadding: -9
        }

        onToggled: {
            saagia_controller.set_energy_type(4)
        }
    }


}
