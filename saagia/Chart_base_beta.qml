import QtQuick 2.14
import QtCharts 2.3


Rectangle {
    width: 500
    height: 400
    color: "#090426"
    clip: true

    ChartView {
        id: chartView
        anchors.fill: parent
        antialiasing: true
        legend.visible: false

        margins.top: 0
        margins.bottom: 0
        margins.left: 10
        margins.right: 30

        x: 10
        y: 20

        ValueAxis{
            id: valueAxisY
            max: 10
            titleText: "Energy (MWh)"
        }

        ValueAxis{
            id: valueAxisX
            min: 0
            max: 15
            visible: false
        }

        BarCategoryAxis {
            id: barCategoriesAxis
            titleText: "Time (h)"
            categories: ["00:00", "01:00", "02:00", "03:00"]

        }

        LineSeries {

            id: energy_consumption
            axisX: barCategoriesAxis
            axisY: valueAxisY
            name: "Electricity consumption in Finland"

        }
    }

    // Timer refreshes the chart in 5 minutes
    Timer {
        interval: 300000
        repeat: true
        triggeredOnStart: true
        running: true

        onTriggered: {

                // Make HTTP GET request and parse the result
                var xhr = new XMLHttpRequest;

                // This link is currently hardcoded (as you can see) and will always fetch the
                // same data.. so it is not "refreshing".
                xhr.open("GET",
                         "https://api.fingrid.fi/v1/variable/124/events/json?start_time=2021-01-01T00%3A00%3A00Z&end_time=2021-01-01T23%3A00%3A00Z", true);

                // This is needed for authentication
                xhr.setRequestHeader("x-api-key","YR7mX5L1Hb4Xjn4PHq4mk1t2T6ToN6f92isw3ejP");
                xhr.send();

                // After getting the data, parse!
                xhr.onreadystatechange = function() {
                    if (xhr.readyState === XMLHttpRequest.DONE) {

                        var a = JSON.parse(xhr.responseText);
                        parseReceivedData(a);

                    }
                }

        }
    }

    function parseReceivedData(energy_data) {

        // Clear previous values
        energy_consumption.clear();

        // This is where all the data values are stored (main purpose is
        // to look for the min and the max value of the fetched data)
        var values = [];

        for (var i in energy_data){


            var energy_value = energy_data[i]["value"];
            values.push(energy_value);

            var start_time = energy_data[i]["start_time"];
            var end_time = energy_data[i]["end_time"];

            var parsed = energy_data[i]["start_time"].split('T');
            var time_hh_mm = parsed[1].slice(0,5);


            energy_consumption.append(Number(i), energy_value);

            // Set the min and max values of the axises
            valueAxisX.min = 0;
            valueAxisX.max = Number(i) + 1;

            valueAxisY.max = Math.max.apply(Math, values)
            valueAxisY.min =  Math.min.apply(Math, values) - 500

            // Set the x-axis labels to the dates of the forecast
            barCategoriesAxis.categories.push(time_hh_mm);


        }
    }

}

