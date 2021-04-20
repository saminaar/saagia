import QtQuick 2.14

Rectangle {
    id: energy_button

    width: 40
    height: 40
    color: "#2d384e"
    border.width: 2
    border.color: "grey"
    property string buttonIcon: "default"


    Image {
        id: button_image
        width: 25
        height: 25
        anchors.centerIn: parent
        fillMode: Image.Stretch
        source: {

            switch (buttonIcon) {
                case "electricity_consumption":
                    "qrc:/images/plug.png"
                    break;
                case "electricity_production":
                    "qrc:/images/lighting.png"
                    break;
                case "nuclear":
                     "qrc:/images/nuclear-energy"
                    break;
                case "hydro":
                     "qrc:/images/hydro-power.png"
                    break;
                case "wind":
                    "qrc:/images/wind-power.png"
                    break;
                case "electricity_consumption_forecast":
                    "qrc:/images/plug.png"
                    break;
                case "electricity_production_forecast":
                    "qrc:/images/lighting.png"
                    break;
                case "wind_energy_production_forecast":
                    "qrc:/images/wind-power.png"
                    break;
                case "temperature_forecast":
                    "qrc:/images/celsius.png"
                    break;
                case "wind_speed_forecast":
                    "qrc:/images/wind_speed.png"
                    break;

                default:
                    break;

                }

    }


    }
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            energy_button.state == 'Active' ? energy_button.state = "" : energy_button.state = 'Active';

            switch (buttonIcon) {
                case "electricity_consumption":
                    saagia_controller.dataset_1_selected()
                    break;
                case "electricity_production":
                    saagia_controller.dataset_2_selected()
                    break;
                case "nuclear":
                    saagia_controller.dataset_3_selected()
                    break;
                case "hydro":
                    saagia_controller.dataset_4_selected()
                    break;
                case "wind":
                    saagia_controller.dataset_5_selected()
                    break;
                case "electricity_consumption_forecast":
                    saagia_controller.dataset_6_selected()
                    break;
                case "electricity_production_forecast":
                    saagia_controller.dataset_7_selected()
                    break;
                case "wind_energy_production_forecast":
                    saagia_controller.dataset_8_selected()
                    break;
                case "temperature_forecast":
                    saagia_controller.dataset_9_selected()
                    break;
                case "wind_speed_forecast":
                    saagia_controller.dataset_10_selected()
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

        }

}
    states: [
        State {
            name: "Active"
            PropertyChanges { target: energy_button; color: "#131720" }

        }
    ]


}

