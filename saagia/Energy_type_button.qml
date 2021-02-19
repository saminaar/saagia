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
                case "electricity":
                    "qrc:/images/lighting.png"
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
            energy_button.state == 'Active' ? energy_button.state = "" : energy_button.state = 'Active';

            switch (buttonIcon) {
                case "wind":
                      console.log("Clicked > windy wind button!")
                    break;
                case "nuclear":
                    console.log("Clicked > nuclear button")
                    break;
                case "hydro":
                     console.log("Clicked > water button")
                    break;
                case "electricity":
                    console.log("Clicked > lightning button")
                   break;
                default:
                    // Default, if no other is used
                    console.log("Button not specified")

            }

            if (energy_button.state == 'Active'){
                console.log("Enabled")
            }
            else{
                console.log("Disabled")
            }
            saagia_controller.energy_form_1_selected()
            //console.info("image clicked!")
        }

}
    states: [
        State {
            name: "Active"
            PropertyChanges { target: energy_button; color: "orange" }

        }
    ]

}

