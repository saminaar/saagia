import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14

RowLayout {
    id: searchBar
    width: 280
    height: 40

    TextField {
        id: searchText
        property bool ignoreTextChange: false
        font.italic: true
        font.pointSize: 10
        height: searchBar.height
        placeholderText: qsTr("Enter a city or region...")
        Layout.fillWidth: true

        background: Rectangle {
            implicitWidth: 200
            implicitHeight: 40
            color: searchText.activeFocus ? "#ffffff" : "#e6e6e6"
            border.color: searchText.activeFocus ? "orange" : "#262626"
            border.width: searchText.activeFocus ? 2 : 1
        }

        onAccepted:{
            saagia_controller.check_place(searchText.text)
            searchText.clear()

        }
    }

    Button {

        id: button
        anchors.left: searchText.right
        anchors.leftMargin: 3
        anchors.right: searchBar.right


        height: searchText.height
        width: height

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
                source: "qrc:/images/search_icon.png"

        }

        hoverEnabled: true

        ToolTip.delay: 500
        ToolTip.timeout: 5000
        ToolTip.visible: hovered
        ToolTip.text: qsTr("Change the location")

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

            onClicked:{
                if (searchText.text != null)
                    saagia_controller.check_place(searchText.text)
                    searchText.clear()
            }

        }

    }
}
