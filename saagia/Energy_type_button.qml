import QtQuick 2.0

import QtCharts 2.0

Item {
    anchors.fill: parent
    property variant othersSlice: 0

    //![1]
    ChartView {
        id: chart
        title: "Top-5 car brand shares in Finland"
        anchors.fill: parent
        legend.alignment: Qt.AlignBottom
        antialiasing: true

        PieSeries {
            id: pieSeries
            PieSlice { label: "Volkswagen"; value: 13.5 }
            PieSlice { label: "Toyota"; value: 10.9 }
            PieSlice { label: "Ford"; value: 8.6 }
            PieSlice { label: "Skoda"; value: 8.2 }
            PieSlice { label: "Volvo"; value: 6.8 }
        }
    }

    Component.onCompleted: {
        // You can also manipulate slices dynamically, like append a slice or set a slice exploded
        othersSlice = pieSeries.append("Others", 52.0);
        pieSeries.find("Volkswagen").exploded = true;
    }
    //![1]
}

/*
Rectangle {
    id: energy_button

    width: 60
    height: 60
    color: "#d9d9d9"
    border.width: 3
    border.color: "orange"

    Text {
        id: button_title
        text: "Wind"
        color: "#4c476c"
        anchors.verticalCenter: parent.verticalCenter

        anchors.horizontalCenter: parent.horizontalCenter
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: energy_button.state == 'Active' ? energy_button.state = "" : energy_button.state = 'Active';
    }

    states: [
        State {
            name: "Active"
            PropertyChanges { target: energy_button; color: "white" }
            PropertyChanges {
                target: button_title
                color: "red"

            }

        }
    ]

}

*/
