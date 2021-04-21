import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.15

Popup {

        property color background_level_0: "#16141f"
        property color background_level_1: "#302c40"
        property color background_level_2: "#dbd6f9"
        property color accent_color: "#ffa500" // orange
        property color text_color: "#cdcdcd" // grey-ish

        property string title_text: qsTr("Save dataset(s)")
        property string subtitle_text: qsTr("Dataset(s) to save..")

        property string error_msg: qsTr("Error: check your input and try again!")

        property Currently_showing_box show_case

        id: popup

        property date start_date;
        property date end_date;

        background: Rectangle {
            height: 315
            color: background_level_0
            opacity: 0.9
            implicitWidth: 400
            implicitHeight: 300
            border.color: "grey"
            border.width: 1
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

        Save_file_dialog {
            id: save_dialog
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

            color: background_level_1
            width: parent.width - 20
            height: parent.height - 40
            x: 10
            y: 30

        Text {
            id: window_subtitle_text
            x: 10
            y: 5
            color: text_color
            font.pixelSize: 13
            text: subtitle_text

        }

        Radio_buttons {

            x: 10
            y: 40
        }

        Date_input {

            x: 10
            y: 100

        }

        Time_input {
            x: 10
            y: 164

        }

        Text {
            id: error_message
            x: 0
            y: 240
            visible: false
            color: accent_color
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
                    source: "qrc:/images/save_icon.png"


            }

            hoverEnabled: true

            ToolTip.delay: 500
            ToolTip.timeout: 5000
            ToolTip.visible: hovered
            ToolTip.text: qsTr("Save selected data")

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

                    save_dialog.open()

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


        Rectangle {

            id: bottom_line

            height: 1
            color: "orange"
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
        }
        }



        function send_request(){

            saagia_controller.load_data("","")
            saagia_controller.set_the_visible_date()
            popup.close()
        }

        Connections {

            target: saagia_view

            function onInputCheckOk() {
                send_request()
            }

            function onInputCheckNotOk(){
                error_message.visible = true;
                error_animation.running = true;
            }

        }
}
