import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.15


Popup {

        signal dateChange(string start, string end)

        property color background_level_0: "#16141f"
        property color background_level_1: "#302c40"
        property color background_level_2: "#dbd6f9"
        property color accent_color: "#ffa500" // orange
        property color text_color: "#cdcdcd" // grey-ish

        property string title_text: qsTr("Retrieve new datasets")
        property string error_msg: qsTr("<b>Error:</b> check your input and try again!")

        property Currently_showing_box show_case

        signal forwardParameters(string test)

        id: popup

        property date start_date;
        property date end_date;

        background: Rectangle {
            height: 545
            color: background_level_0
            opacity: 0.9
            implicitWidth: 400
            implicitHeight: 430
            border.color: "grey"
            border.width: 1
        }

        width: 420
        height: 380
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
            id: window_title_text
            x: 10
            y: 4
            color: text_color
            font.bold: true
            font.pixelSize: 15
            text: title_text
        }

        Image {
            id: exit_window
            width: 15
            height: 15
            anchors.right: parent.right
            source: "qrc:/images/cancel.png"

            MouseArea {

                anchors.fill: parent
                onClicked: {
                    popup.close()
                }
            }
        }

        Rectangle {

            id: background_2
            color: background_level_1
            width: parent.width - 20
            height: parent.height + 110
            x: 10
            y: 30

        Radio_buttons {

            id: radio_buttons
            x: 5
            y: 5
        }


        Date_input {

            x: 5
            y: 330

        }

        Time_input {
            x: 9
            y: 390

        }

        Text {
            id: error_message
            anchors.right: parent.right

            y: 475
            visible: false
            color: "#ff4d4d"
            font.pixelSize: 13
            minimumPointSize: 10
            minimumPixelSize: 10
            text: error_msg


            PropertyAnimation {
                id: error_animation
                running: false
                target: error_message
                property: 'visible'
                to: false
                duration: 4000
            }

        }



        Button {

            id: updatebutton
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10


            height: 40
            width: height

            background: Rectangle {

                    id: button_bg_2
                    color: background_level_0
                    implicitWidth: 35
                    implicitHeight: 35
                    border.width: 1
                    border.color: accent_color

            }



            Image {

                    id: button_image
                    width: 20
                    height: 20
                    anchors.centerIn: parent
                    fillMode: Image.Stretch
                    source: "qrc:/images/refresh.png"

            }

            hoverEnabled: true

            ToolTip.delay: 500
            ToolTip.timeout: 5000
            ToolTip.visible: hovered
            ToolTip.text: qsTr("Load selected data")

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
                hoverEnabled: true
                anchors.fill: button_bg_2

                onEntered: { updatebutton.state='Hovering'}
                onExited: { updatebutton.state=''}

                onPressed: { updatebutton.state="Pressed" }

                onReleased: {
                    if (containsMouse)
                      updatebutton.state="Hovering";
                    else
                      updatebutton.state="";
                }
                onClicked: {
                    check_input()
                }

            }

        }


        Rectangle {

            height: 1
            color: "orange"
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
        }

        Preferences_button {

            id: button
            signal send(string txt)

            anchors.top: bottom_line.bottom
            anchors.left: bottom_line.left
            anchors.leftMargin: -5

            testeri: "Send this message forward"

            background: Rectangle {
                id: button_bg
                implicitWidth: 100
                implicitHeight: 35
                color: "transparent"
            }

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
                    button.send(button.testeri)
                    object.open()
                }

            }

        }

        Rectangle {

            id: bottom_line

            height: 1
            color: "orange"
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
        }

        }

        function check_input(){

            if ( saagia_controller.check_input() ) {
                send_request()
            }
            else {
                error_message.visible = true;
                error_animation.running = true;
            }

        }

        function send_request(){

            saagia_controller.load_data()
            console.log("Send request qml:stä")
            saagia_controller.set_the_visible_date()
            popup.close()

        }

}
