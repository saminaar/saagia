import QtQuick 2.14
import QtQuick.Controls 2.14

Rectangle {
    id: background
    height: 120
    color: "transparent"

    Rectangle {
        id: line
        height: 1
        width: parent.width
        color: "grey"

        Text {

            text: "<b>Toggle data visibilities</b>"
            color: "#f2f2f2"
            anchors.top: line.bottom
            anchors.topMargin: 10
        }
    }


    Rectangle {
        id: energy_buttons
        height: 100
        color: "#16141f"
        width: parent.width/2 - 5
        anchors.right: parent.right
        anchors.leftMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -20

        Rectangle {

            height: parent.height - 10
            width: parent.width - 10
            color: "transparent"
            border.color: "grey"
            border.width: 1
            anchors.centerIn: parent

            Text {
                text: "<b>Archived data</b>"
                color: "#f2f2f2"
                horizontalAlignment: Text.AlignHCenter
                width: parent.width
                anchors.top: parent.top
                anchors.topMargin: 10
            }

        Row {

            spacing: 10
            id: button_row_1
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Component.onCompleted: create_new_button()


        function create_new_button(){

            var list = ["\"electricity_consumption\"",
                        "\"electricity_production\"", "\"wind\"",
                         "\"hydro\"",
                        "\"nuclear\""];

            // number of displayed energy types
            var i;

            for (i = 0; i < 5; i++) {
                var newObject = Qt.createQmlObject('import QtQuick 2.0;
                            Energy_type_button {buttonIcon: ' + list[i] +'}',
                                                   button_row_1);

            }

            }
        }
        }
    }


    Rectangle {
        id: forecast_buttons
        height: 100
        color: "#16141f"
        width: parent.width/2
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -20

        Rectangle {
            id: rectangle

            height: parent.height - 10
            width: parent.width - 10
            color: "transparent"
            border.color: "grey"
            border.width: 1
            anchors.centerIn: parent


        Text {
            text: "<b>Forecasts</b>"
            color: "#f2f2f2"
            horizontalAlignment: Text.AlignHCenter
            width: parent.width
            anchors.top: parent.top
            anchors.topMargin: 10
        }

        Row {

            id: button_row_2
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10
            Component.onCompleted: create_new_button()


        function create_new_button(){


            var list = ["\"electricity_consumption_forecast\"",
                        "\"electricity_production_forecast\"",
                        "\"wind_energy_production_forecast\"",
                        "\"temperature_forecast\"", "\"wind_speed_forecast\""];


            // number of displayed energy types
            var i;

            for (i = 0; i < 5; i++) {
                var newObject = Qt.createQmlObject('import QtQuick 2.0;
                            Energy_type_button {buttonIcon: ' + list[i] +'}',
                                                   button_row_2);

            }

        }
    }
    }
}
}



