import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

Button{

        id: button
        text: "<font color='#ffffff'>" + "Retrieve datasets" + "</font>"
        font.pixelSize: 13

        icon.source: "images/refresh.png"
        icon.color: "#d6d6d6"
        icon.width: 15
        icon.height: 15


        background: Rectangle {
            id: button_bg
            implicitWidth: 100
            implicitHeight: 35
            color: "#090426"
            border.color: "white"
            border.width: 1
        }

        //change the color of the button in different button states
        states: [
            State {
                name: "Hovering"
                PropertyChanges {
                    target: button_bg
                    color: "#252145"
                }
            },
            State {
                name: "Pressed"
                PropertyChanges {
                    target: button_bg
                    color: "orange"
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
                 saagia_controller.reset_input()
                 var component = Qt.createComponent("New_data_load_popup.qml")
                 var object = component.createObject(left_column_background);
                 object.open()
            }

        }
    }

