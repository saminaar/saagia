import QtQuick 2.1
import QtQuick.Window 2.1

Window {
    width: 1000
    height: 780
    visible: true
    color: "transparent"
    title: qsTr("Saagia - application for weather and energy analyzing")

    Rectangle {
        id: main_container
        x: 0
        y: 14
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
                x: 474
                y: 16
                spacing: 20
                width: 456
                height: 624

                AnimatedImage {
                    id: animatedImage
                    width: 450
                    height: 300
                    source:"qrc:/images/chart_example.gif"
                }

                Row {
                    id: row
                    x: 35
                    width: 380
                    height: 60
                    spacing: 20

                    Rectangle {
                        id: button_1
                        x: 0
                        y: 0
                        width: 60
                        height: 60
                        color: "#f2f2f2"
                    }

                    Rectangle {
                        id: button_2
                        x: 0
                        y: 0
                        width: 60
                        height: 60
                        color: "#f2f2f2"
                    }

                    Rectangle {
                        id: button_3
                        x: 0
                        y: 0
                        width: 60
                        height: 60
                        color: "#f2f2f2"
                    }

                    Rectangle {
                        id: button_4
                        x: 0
                        y: 0
                        width: 60
                        height: 60
                        color: "#f2f2f2"
                    }

                    Rectangle {
                        id: button_5
                        x: 0
                        y: 0
                        width: 60
                        height: 60
                        color: "#f2f2f2"
                    }
                }
            }

            Rectangle {
                id: left_column_background
                x: 17
                y: 16
                width: 429
                height: 612
                color: "#2e2c3a"

                Column {
                    id: left_column
                    x: 8
                    y: 8
                    width: 413
                    height: 587
                }
            }
        }

        Item {
            id: top_bar
            x: 0
            y: 0
            width: 1000
            height: 92

            Text {
                x: 841
                y: 35
                id: load_button_text
                color: "#ffffff"
                text: qsTr("LOAD DATA")
                font.pixelSize: 20
            }

            Text {
                x: 633
                y: 35
                id: save_button_text
                color: "#ffffff"
                text: qsTr("SAVE DATA")
                font.pixelSize: 20
            }

            Text {
                id: title_text
                x: 36
                y: 24
                width: 247
                height: 45
                color: "#ffffff"
                text: "SAAGIA"
                font.pixelSize: 40
            }
        }
    }

}


