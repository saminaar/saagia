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
        property string subtitle_text: qsTr("Energy type(s) to show..")
        property string error_msg: qsTr("Error: check your input and try again!")

        property Currently_showing_box show_case

        signal forwardParameters(string test)

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

        Checkbox_column {

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
            x: 260
            y: 190
            text: qsTr("Retrieve")


            contentItem: Text {
                text: updatebutton.text
                font: updatebutton.font
                opacity: enabled ? 1.0 : 0.3
                color: updatebutton.down ? "orange" : "orange"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }

            background: Rectangle {
                implicitWidth: 80
                implicitHeight: 20
                opacity: enabled ? 1 : 0.3
                color: updatebutton.down ? "#201d2d" : "#16141f"
                border.color: updatebutton.down ? "orange" : "#ccc"
                border.width: 1
                radius: 2
            }

            onClicked: {

                 check_input()
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

            saagia_controller.check_input()

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


