import QtQuick 2.14
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    width: 1000
    height: 780
    visible: true
    color: "transparent"
    title: qsTr("Saagia - application for weather and energy analyzing")


    menuBar: MenuBar {
        id: menu_bar
        height: 32

        // Style for the menu bar itself (not Menu-items)
        background: Rectangle {
            implicitHeight: 30
            implicitWidth: 1000
            color: "#16141f"

            Rectangle {
                width: parent.width
                height: 1
                anchors.bottom: parent.bottom
                color: "transparent"
                border.color: "orange"
            }
        }

        Menu {
            title: qsTr("File")
            Action { text: qsTr("Save data...") }
            Action { text: qsTr("Load data...") }

            // Menu item dropdown style
            delegate: MenuItem {
                id: menuItem
                implicitWidth: 100
                implicitHeight: 30

                contentItem: Text {
                    leftPadding: menuItem.indicator.width
                    rightPadding: menuItem.arrow.width
                    text: menuItem.text
                    font: menuItem.font
                    opacity: enabled ? 1.0 : 0.3
                    color: menuItem.highlighted ? "#000000" : "#ffffff"
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 30
                    opacity: enabled ? 1 : 0.3
                    color: menuItem.highlighted ? "orange" : "#2c283e"
                }
            }
        }

        Menu {
            title: qsTr("Help")
            Action { text: qsTr("About...") }

            // Menu item dropdown style
            delegate: MenuItem {
                id: menuItem_2
                implicitWidth: 100
                implicitHeight: 30

                contentItem: Text {
                    leftPadding: menuItem_2.indicator.width
                    rightPadding: menuItem_2.arrow.width
                    text: menuItem_2.text
                    font: menuItem_2.font
                    opacity: enabled ? 1.0 : 0.3
                    color: menuItem_2.highlighted ? "#000000" : "#ffffff"
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 30
                    opacity: enabled ? 1 : 0.3
                    color: menuItem_2.highlighted ? "orange" : "#2c283e"
                }
            }
        }

        ///


        // Style for the menu bar item (not the dropdown)
        delegate: MenuBarItem {
            id: menuBarItem
            padding: 5

            contentItem: Text {
                text: menuBarItem.text
                font: menuBarItem.font
                opacity: enabled ? 1.0 : 0.3
                color: menuBarItem.highlighted ? "orange" : "#ffffff"
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }

            background: Rectangle {
                implicitWidth: 30
                implicitHeight: 30
                opacity: enabled ? 1 : 0.3
                color: menuBarItem.highlighted ? "#2c283e" : "#16141f"
            }
        }

    }

    Rectangle {
        id: main_container
        x: 0
        y: 0
        width: 1000
        height: 780
        opacity: 0.9
        color: "#1d1b29"

        Rectangle {
            id: container
            x: 26
            y: 94
            width: 948
            height: 654
            opacity: 0.9
            color: "#3a3749"

            Column {
                id: right_column
                x: 344
                y: 96
                spacing: 20
                width: 571
                height: 531


                Chart_base_test {
                    id: chart_base_test_real
                }

                Energy_type_button_row{
                    id: button_row
                    width: right_column.width

                }
            }

            Rectangle {
                id: left_column_background
                x: 17
                y: 96
                width: 314
                height: 531
                color: "#1d1b29"

                Column {
                    id: left_column
                    x: 9
                    y: 8
                    width: 297
                    height: 515
                }

                Text {
                    id: sub_title
                    x: 29
                    y: 220
                    width: 196
                    height: 25
                    color: "#ffffff"
                    text: qsTr("Debug console")
                    font.pixelSize: 15
                    font.italic: true
                }

                Output_area {
                    id: output_area
                    x: 24
                    y: 251
                    width: 268
                    height: 258


                }

                New_data_load_popup {
                    id: new_data_load_popup
                    x: 211
                    y: 49

                }

            }

            Currently_showing_box{
                id: show_case
                x: 15
                y: 15
                width: 900

                Fetch_data_button {

                    y: 25
                    anchors.left: parent.right
                    anchors.right: parent.right
                    anchors.leftMargin: -213
                    anchors.rightMargin: 64
                    hoverEnabled: false
                    id: retrieve_button
                    onClicked: {
                        saagia_controller.set_energy_type(0)
                        var component = Qt.createComponent("New_data_load_popup.qml")
                        var object = component.createObject(left_column_background);
                        object.open()
                    }
                }

            }


        }

        Item {
            id: top_bar
            x: 0
            y: 0
            width: 1000
            height: 92

            /*Text {
                x: 569
                y: 35
                id: load_button_text
                color: "#ffffff"
                text: qsTr("LOAD DATA")
                font.pixelSize: 20
            }

            Text {
                x: 416
                y: 35
                id: save_button_text
                color: "#ffffff"
                text: qsTr("SAVE DATA")
                font.pixelSize: 20
            }*/
            Title_text{
                x: 25
                y: 26
            }

            Text {
                id: city
                x: 431
                y: 35
                text: qsTr("Current city/region: Tampere")
                font.pixelSize: 20
                color: "#ffffff"
            }

            Text_input_bar {
                id: text_input_bar
                x: 727
                y: 25
                width: 247
                height: 52
            }


        }
    }

}



/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:29}
}
##^##*/
