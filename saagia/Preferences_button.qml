import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

Button{

        id: button
        text: "<font color='#cccccc'>" + "Preferences" + "</font>"
        font.pixelSize: 13

        icon.source: "images/heart_outline.png"
        icon.color: "#ff6666"
        icon.width: 15
        icon.height: 15


        background: Rectangle {
            id: button_bg
            implicitWidth: 100
            implicitHeight: 35
            color: "transparent"
        }

        //change the color of the button in different button states
        states: [
            State {
                name: "Hovering"
                PropertyChanges {
                    target: button
                    text: "<font color='#ffffff'>" + "Preferences" + "</font>"
                }
            },
            State {
                name: "Pressed"
                PropertyChanges {
                    target: button
                    text: "<font color='#ffffff'><b>" + "Preferences" + "</b></font>"
                }
            }
        ]

        //define transmission for the states
        transitions: [
            Transition {
                from: ""; to: "Hovering"
                ColorAnimation { duration: 10 }
            },
            Transition {
                from: "*"; to: "Pressed"
                ColorAnimation { duration: 10 }
            }
        ]

        //Mouse area to react on click events
        MouseArea {
            hoverEnabled: true
            anchors.fill: button_bg

            onEntered: { button.state='Hovering'}
            onExited: { button.state=''}

            onPressed: { button.state="Pressed" }

            onReleased: {
                if (containsMouse)
                  button.state="Hovering";
                else
                  button.state="";
            }

            onClicked: {
                var component = Qt.createComponent("Preferences.qml")
                var object = component.createObject(left_column_background);
                object.open()
            }

        }
    }
