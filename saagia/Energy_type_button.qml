import QtQuick 2.14

Rectangle {
    id: energy_button

    width: 50
    height: 50
    color: "#090426"
    border.width: 3
    border.color: "white"
    property string buttonIcon: "default"

    Image {
        id: button_image
        width: 30
        height:30
        anchors.centerIn: parent
        fillMode: Image.Stretch
        source: {

            switch (buttonIcon) {
                case "wind":
                      "qrc:/images/wind-power.png"
                    break;
                case "nuclear":
                     "qrc:/images/nuclear-energy"
                    break;
                case "hydro":
                     "qrc:/images/hydro-power.png"
                    break;
                default:
                    // Default, if no other is used
                    "qrc:/images/lighting.png"
                }


    }


    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
           console.info("image clicked!")
        }
    }


}

