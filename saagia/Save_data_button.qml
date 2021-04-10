import QtQuick 2.14

Rectangle {
    id: save_button
    color: "#090426"
    width: 130
    height: 40

    Text {
        id: load_button_text
        text: "SAVE DATA"
        color: "#ffffff"
        font.pixelSize: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        Connections {
            target: mouseArea
            onClicked:
                function pressed_button() {
                    saagia_controller.save_data()
                }
        }
    }        states: [
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
             saagia_controller.set_energy_type(0)
             var component = Qt.createComponent("New_data_load_popup.qml")
             var object = component.createObject(left_column_background);
             object.open()
        }

    }
}
