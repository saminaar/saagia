import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.12

Button {
    text: "Open"
    onClicked: popup.open()

    Popup {
        id: popup

        background: Rectangle {
            color: "#ddd"
            opacity: 0.9
            implicitWidth: 200
            implicitHeight: 200
            border.color: "orange"
            border.width: 2
        }

        width: 400
        height: 300
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

        enter: Transition {
            NumberAnimation { property: "opacity"; from: 0.0; to: 1.0 }
        }
        exit: Transition {
            NumberAnimation { property: "opacity"; from: 1.0; to: 0.0 }
        }

        Text {
            id: name
            x: 10
            y: 5
            color: "#333"
            text: qsTr("Update data")
        }

        Rectangle{

            color: "#ddd"
            width: parent.width - 20
            height: parent.height - 40
            x: 10
            y: 30

        Text {
            id: energy_type
            x: 10
            y: 5
            text: qsTr("Energy type(s) to show")
        }


        CheckBox {
            id: control
            x: 30
            y: 40
            text: qsTr("Electricity")
            checked: false

            indicator: Rectangle {
                    id: indicator
                    implicitWidth: 16
                    implicitHeight: 16
                    radius: 0
                    border.color: control.activeFocus ? "darkblue" : "gray"
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
                color: control.down ? "#17a81a" : "#000"

                leftPadding: 15
                topPadding: -9
            }
        }

        CheckBox {
            id: wind_check
            x: 30
            y: 65
            text: qsTr("Wind")
            checked: false

            indicator: Rectangle {
                    id: indicator_2
                    implicitWidth: 16
                    implicitHeight: 16
                    radius: 0
                    border.color: wind_check.activeFocus ? "darkblue" : "gray"
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
                color: wind_check.down ? "#17a81a" : "#000"

                leftPadding: 15
                topPadding: -9
            }
        }

        CheckBox {
            id: nuclear_check
            x: 200
            y: 65
            text: qsTr("Nuclear")
            checked: false

            indicator: Rectangle {
                    id: indicator_3
                    implicitWidth: 16
                    implicitHeight: 16
                    radius: 0
                    border.color: nuclear_check.activeFocus ? "darkblue" : "gray"
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
                color: nuclear_check.down ? "#17a81a" : "#000"

                leftPadding: 15
                topPadding: -9
            }
        }

        CheckBox {
            id: hydro_check
            x: 200
            y: 40
            text: qsTr("Hydro")
            checked: false

            indicator: Rectangle {
                    id: indicator_4
                    implicitWidth: 16
                    implicitHeight: 16
                    radius: 0
                    border.color: hydro_check.activeFocus ? "darkblue" : "gray"
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
                color: hydro_check.down ? "#17a81a" : "#000"

                leftPadding: 15
                topPadding: -9
            }
        }

        Text {
            x: 10
            y: 100
            text: qsTr("Start time")
        }


        TextField {
            id: start_time
            x: 10
            y: 120
            placeholderText: qsTr("")
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 10
                color: start_time.enabled ? "#fff" : "#fff"
                border.color: start_time.enabled ? "#222" : "orange"
            }
        }

        Text {
            x: 200
            y: 100
            text: qsTr("End time")
        }


        TextField {
            id: end_time
            x: 200
            y: 120
            placeholderText: qsTr("")
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 10
                color: start_time.enabled ? "#fff" : "#fff"
                border.color: start_time.enabled ? "#222" : "orange"
            }
        }

        Button {
            id: updatebutton
            x: 260
            y: 190
            text: qsTr("Update")


            contentItem: Text {
                text: updatebutton.text
                font: updatebutton.font
                opacity: enabled ? 1.0 : 0.3
                color: updatebutton.down ? "orange" : "black"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }

            background: Rectangle {
                implicitWidth: 80
                implicitHeight: 20
                opacity: enabled ? 1 : 0.3
                color: "#ccc"
                border.color: updatebutton.down ? "orange" : "black"
                border.width: 1
                radius: 2
            }
        }

        Popup{

            id: calendarobject
            /*

            TODO:

            Calendar {
                id: calendarobject_2
                minimumDate: new Date(2017, 0, 1)
                maximumDate: new Date(2018, 0, 1)
            }*/

        }


    }
}

}
