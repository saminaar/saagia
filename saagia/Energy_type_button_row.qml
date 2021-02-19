import QtQuick 2.14
import QtQuick.Controls 2.14

Rectangle {
    id: energy_button

    width: 500
    height: 70
    color: "#1d1b29"

    Row {
        id: row
        x: 35
        spacing: 20
        anchors.centerIn: parent

        Energy_type_button {
            id: button_1
            buttonIcon: "wind"
            x: 0
            y: 0

        }
        Energy_type_button {
            id: button_2
            buttonIcon: "hydro"
            x: 0
            y: 0

        }
        Energy_type_button {
            id: button_3
            buttonIcon: "nuclear"
            x: 0
            y: 0

        }
        Energy_type_button {
            id: button_4
            x: 0
            y: 0

        }

    }
}

