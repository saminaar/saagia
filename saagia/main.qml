import QtQuick 2.14
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0

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
                x: 432
                y: 15
                spacing: 20
                width: 503
                height: 624

                Chart_base_beta {
                    id: chart_base_beta
                    width: 500
                    height: 350
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
                x: 416
                anchors.verticalCenter: parent.verticalCenter
                id: save_data_button
            }

            Load_data_button{
                x: 569
                anchors.verticalCenter: parent.verticalCenter
                id: load_data_button
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



/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/
