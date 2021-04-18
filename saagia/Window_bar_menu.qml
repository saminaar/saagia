import QtQuick 2.14
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4



MenuBar {
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

        File_dialog{
            id: file_dialog

        }

        Save_file_dialog {
            id: save_file
        }


        Menu {
            title: qsTr("File")

            Action {
                text: qsTr("Save data...")

                onTriggered: {

                    //var component = Qt.createComponent("Save_file_popup.qml")
                    //var object = component.createObject(menu_bar);
                    //object.open()
                    save_file.open()
                }

            }


            Action {
                text: qsTr("Load data...")
                onTriggered: file_dialog.open()
            }

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
            Action {
                text: qsTr("About...")

                onTriggered: {

                    var component = Qt.createComponent("About_popup.qml")
                    var object = component.createObject(menu_bar);
                    object.open()
                }

            }

            // Menu item dropdown style
            delegate: MenuItem {
                id: menuItem_2
                implicitWidth: 100
                implicitHeight: 40


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
                    implicitHeight: 100
                    implicitWidth: 30

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
