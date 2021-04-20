import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: show_case

    width: 500
    height: 50
    color: "#16141f"

    Button {

        id: button
        anchors.right: button_2.left
        anchors.rightMargin: 5
        y: 25
        anchors.verticalCenter: parent.verticalCenter


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
                source: "qrc:/images/draw_chart"

        }

        hoverEnabled: true

        ToolTip.delay: 500
        ToolTip.timeout: 5000
        ToolTip.visible: hovered
        ToolTip.text: qsTr("Draw the current data")

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


    Button {

        id: button_2
        y: 25
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 5

        background: Rectangle {

                id: button_bg_2
                color: "#090426"
                implicitWidth: 35
                implicitHeight: 35
                border.width: 1
                border.color: "#fff"

            }

        Image {

                id: button_image_2
                width: 20
                height: 20
                anchors.centerIn: parent
                fillMode: Image.Stretch
                source: "qrc:/images/clear"

        }

        hoverEnabled: true

        ToolTip.delay: 500
        ToolTip.timeout: 5000
        ToolTip.visible: hovered
        ToolTip.text: qsTr("Erase the current data")

        states: [
            State {
                name: "Hovering"
                PropertyChanges {
                    target: button_bg_2
                    color: "#252145"
                }
            },
            State {
                name: "Pressed"
                PropertyChanges {
                    target: button_bg_2
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

            anchors.fill: button_bg_2
            hoverEnabled: true

            onEntered: { button_2.state='Hovering'}
            onExited: { button_2.state=''}

            onPressed: { button_2.state="Pressed" }

            onReleased: {
                if (containsMouse)
                  button_2.state="Hovering";
                else
                  button_2.state="";
            }


            onClicked: saagia_controller.erase_chart_and_data()


        }
    }


        Fetch_data_button {

            anchors.verticalCenter: button.verticalCenter
            anchors.right: button.left
            anchors.rightMargin: 5

            hoverEnabled: false
            id: retrieve_button
            onClicked: {
                saagia_controller.set_energy_type(0)
                var component = Qt.createComponent("New_data_load_popup.qml")
                var object = component.createObject();
                object.open()
            }



        }

        Rectangle {
            width: 100
            height: 50
            color: "transparent"

            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left

            anchors.leftMargin: 10

            Image {

                anchors.verticalCenter: parent.verticalCenter
                id: calendar_logo
                width: 20
                height: 20


                source: "qrc:/images/calendar.png"

            }


            Text {
                id: case_title
                anchors.left: calendar_logo.right
                anchors.leftMargin: 5
                anchors.verticalCenter: parent.verticalCenter

                color: "#ffffff"
                text: saagia_view.active_data
                font.pixelSize: 15

            }
        }




/*
    Text {
        id: energy_type
        anchors.top: case_title.bottom
        anchors.left: parent.left
        anchors.margins: 0

        color: "#66ff99"
        text: saagia_view.current_text
        font.pixelSize: 15
    }
*/

}
