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
                x: 432
                y: 15
                spacing: 20
                width: 503
                height: 624

                Currently_showing_box{
                   id: show_case

                }


                Chart_base_test {
                    id: chart_base_test_real
                }

                Energy_type_button_row{
                   id: button_row

                }
            }

            Rectangle {
                id: left_column_background
                x: 17
                y: 16
                width: 384
                height: 599
                color: "#2e2c3a"

                Column {
                    id: left_column
                    x: 8
                    y: 8
                    width: 368
                    height: 587
                }

                Text_input_bar {
                    id: text_input_bar
                    x: 684
                    y: -88
                    width: 247
                    height: 52
                }

                Text {
                    id: sub_title
                    x: 16
                    y: 22
                    width: 291
                    height: 54
                    color: "#ffffff"
                    text: qsTr("TO DO")
                    font.pixelSize: 40
                }

                Output_area {
                    id: output_area
                    x: 20
                    y: 149


                }

                New_data_load_popup {
                    id: new_data_load_popup
                    x: 211
                    y: 49
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

            Save_data_button{
                x: 219
                width: 116
                height: 40
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: 445
                id: save_data_button
            }

            Load_data_button{
                x: 67
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: 445
                id: load_data_button
            }
            Title_text{
                x: 25
                y: 26
            }

            Text {
                id: city
                x: 431
                y: 37
                text: qsTr("Current city/region: Tampere")
                font.pixelSize: 20
                color: "#ffffff"
            }


        }
    }

}



/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/
