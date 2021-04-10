import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: show_case

    width: 500
    height: 70
    color: "#16141f"

    Button {

        id: button
        anchors.right: parent.right
        anchors.rightMargin: 13
        anchors.left: parent.left
        anchors.leftMargin: parent.width - 50
        y: 25

        background: Rectangle {

                id: button_bg
                color: "#090426"
                implicitWidth: 35
                implicitHeight: 35
                border.width: 1
                border.color: "#fff"

            }



        Image {

                id: button_image
                width: 20
                height: 20
                anchors.centerIn: parent
                fillMode: Image.Stretch
                source: "qrc:/images/save_icon"

        }

        hoverEnabled: true

        ToolTip.delay: 500
        ToolTip.timeout: 5000
        ToolTip.visible: hovered
        ToolTip.text: qsTr("Save the current chart")

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

            onClicked: saagia_controller.save_chart_image()


        }



    }


    Text {
        id: case_title
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 10

        color: "#ffffff"
        text: saagia_view.active_data
        font.pixelSize: 15

    }
    Text {
        id: energy_type
        anchors.top: case_title.bottom
        anchors.left: parent.left
        anchors.margins: 10

        color: "#66ff99"
        text: saagia_view.current_text
        font.pixelSize: 15
    }


}
