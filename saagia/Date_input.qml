import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.12

Rectangle {

    width: 260
    height: 80
    color: "transparent"

    Text {

        x: 12
        y: 8
        color: "#cdcdcd"
        font.bold: true
        text: qsTr("Start date")
        font.pointSize: 9
        font.family: "Segoe UI"
        font.strikeout: false
        font.italic: false

    }

    Rectangle {

        x: 10
        y: 30
        id: start_time_rect
        width: 100
        height: 30
        color: "#dbd6f9"
        border.color: "#16141f"
        border.width: 2


        Text {
            id: start_time
            anchors.margins: 7
            anchors.fill: start_time_rect
            font.pointSize: 10
            text: qsTr("")


            MouseArea {

                anchors.fill: start_time
                onClicked: calendarobject_2.open()
            }

            Popup{

                id: calendarobject_2

                Calendar_model{

                    minimumDate: new Date(2021, 0, 1)

                    onClicked: {
                        console.log("Clicked")
                        console.log(date)

                        saagia_controller.set_the_selected_date(0, Qt.formatDateTime(date, "yyyy-MM-dd"))
                        calendarobject_2.close()

                        start_time.text = Qt.formatDateTime(date, "dd/MM/yyyy")

                    }

                }
            }
        }
    }

    Text {

        x: 152
        y: 8
        color: "#cdcdcd"
        font.bold: true
        text: qsTr("End date")
        font.pointSize: 10
    }

    Rectangle {

        x: 150
        y: 30
        id: end_time_rect
        width: 100
        height: 30
        color: "#dbd6f9"
        border.color: "#16141f"
        border.width: 2
        transformOrigin: Item.Center


        Text {
            id: end_time
            anchors.fill: end_time_rect
            anchors.margins: 7
            font.pointSize: 10
            text: qsTr("")


            MouseArea {

                anchors.fill: end_time
                onClicked: calendarobject_1.open()
            }

            Popup{

                id: calendarobject_1

                Calendar_model{


                    maximumDate: new Date()

                    onClicked: {

                        //const json = JSON.stringify(date);

                        saagia_controller.set_the_selected_date(1, Qt.formatDateTime(date, "yyyy-MM-dd"))
                        //saagia_controller.change_enddate(json);
                        calendarobject_1.close()

                        end_time.text = Qt.formatDateTime(date, "dd/MM/yyyy")

                    }

                }
            }
        }
    }

    Text {
        x: 123
        y: 35
        color: "#cdcdcd"
        text: qsTr("to")
        font.pointSize: 10
        minimumPixelSize: 12
        font.bold: true
    }

}

