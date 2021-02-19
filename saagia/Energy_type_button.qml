import QtQuick 2.14

Rectangle {
    id: energy_button

    width: 60
    height: 60
    color: "#d9d9d9"
    border.width: 3
    border.color: "orange"


    Text {
        id: button_title
        text: "?"
        color: "black"
        anchors.verticalCenter: parent.verticalCenter

        anchors.horizontalCenter: parent.horizontalCenter
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        Connections {
            target: mouseArea
            onClicked:
                function pressed_button() {

                        //![3]
                        // Make HTTP GET request and parse the result

                        var xhr = new XMLHttpRequest;
                        xhr.open("GET",
                                 "https://api.fingrid.fi/v1/variable/124/events/json?start_time=2021-01-01T00%3A00%3A00Z&end_time=2021-01-01T23%3A00%3A00Z"
                                 , true);

                        xhr.setRequestHeader("x-api-key","YR7mX5L1Hb4Xjn4PHq4mk1t2T6ToN6f92isw3ejP");
                        xhr.send();
                        xhr.onreadystatechange = function() {
                            if (xhr.readyState === XMLHttpRequest.DONE) {
                                console.log(xhr.responseText);
                                var a = JSON.parse(xhr.responseText);
                                parseEnergyData(a)
                            }
                        }
                        xhr.send();
                        //![3]

                }
        }
    }


    function parseEnergyData(energyData) {
        // Clear previous values
        maxTempSeries.clear();
        minTempSeries.clear();
        weatherImageModel.clear();


        //![4]
        // Loop through the parsed JSON
        for (var i in weatherData.data.weather) {
            var weatherObj = weatherData.data.weather[i];
            //![4]

            //![5]
            // Store temperature values, rainfall and weather icon.
            // The temperature values begin from 0.5 instead of 0.0 to make the start from the
            // middle of the rainfall bars. This makes the temperature lines visually better
            // synchronized with the rainfall bars.
            maxTempSeries.append(Number(i) + 0.5, weatherObj.tempMaxC);
            minTempSeries.append(Number(i) + 0.5, weatherObj.tempMinC);
            rainfallSet.append(i, weatherObj.precipMM);
            weatherImageModel.append({"imageSource":weatherObj.weatherIconUrl[0].value});
            //![5]

            // Update scale of the chart
            valueAxisY.max = Math.max(chartView.axisY().max,weatherObj.tempMaxC);
            valueAxisX.min = 0;
            valueAxisX.max = Number(i) + 1;

            // Set the x-axis labels to the dates of the forecast
            var xLabels = barCategoriesAxis.categories;
            xLabels[Number(i)] = weatherObj.date.substring(5, 10);
            barCategoriesAxis.categories = xLabels;
            barCategoriesAxis.visible = true;
            barCategoriesAxis.min = 0;
            barCategoriesAxis.max = xLabels.length - 1;
        }
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

