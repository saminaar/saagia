import QtQuick 2.0
import QtCharts 2.3

Rectangle {

    id: background_rect
    width: 500
    height: 400
    color: "#090426"

    ChartView {
        anchors.fill: parent
        antialiasing: true

        legend.visible: false
        theme: ChartView.ChartThemeDark
        //animationOptions: ChartView.GridAxisAnimations

        margins.top: 0
        margins.bottom: 0
        margins.left: 10
        margins.right: 30

        LineSeries {
            id: energy_series
            axisX: axisX
            axisY: axisY

        // The Y-axis of the chart
        ValueAxis {
            id: axisY
            gridVisible: true

            // Determines the visible grid's ticks
            tickCount: 7

            // Set minimum and maximum from the start
            min: 0
            max: 10
        }

        // The X-axis of the chart
        DateTimeAxis {
            id: axisX
            gridVisible: true
            format: "hh:mm"

            min: new Date(2021, 1, 1, 0, 0, 0)
            max: new Date(2021, 1, 1, 12, 30, 30)

            tickCount: 5
        }
        }

    }

    Timer {
        interval: 100000
        repeat: true
        triggeredOnStart: true
        running: true

        onTriggered: {

            //var date_request = "2021-01-01T00%3A00%3A00Z&end_time=2021-01-01T23%3A00%3A00Z"

            fetch_data("https://api.fingrid.fi/v1/variable/124/events/json?start_time=2021-01-01T00%3A00%3A00Z&end_time=2021-01-01T23%3A00%3A00Z")

        }
    }


    function fetch_data(url){

        // Make HTTP GET request and parse the result
        var xhr = new XMLHttpRequest;

        // This link is currently hardcoded (as you can see) and will always fetch the
        // same data.. so it is not "refreshing".
        xhr.open("GET", url, true);

        // This is needed for authentication
        xhr.setRequestHeader("x-api-key","YR7mX5L1Hb4Xjn4PHq4mk1t2T6ToN6f92isw3ejP");
        xhr.send();

        // After getting the data, parse!
        xhr.onreadystatechange = function() {
            if (xhr.readyState === XMLHttpRequest.DONE) {
                var received_data = JSON.parse(xhr.responseText);
                parseReceivedData(received_data);

            }
        }

    }

    function parseReceivedData(energy_data) {
        /* Parses the raw data into usable formats */

        // Both lists are for getting the min and max value
        // of each type (needed for the graph axises)
        var date_objects = [];
        var energy_values = [];

        // To make sure there aren't any values set yet
        energy_series.clear()

        // Messy parser.. does it's job
        for (var i in energy_data){

            var energy_value = energy_data[i]["value"];

            // Before parsing: "2021-01-01T01:00:00+0000"
            var parsed_time = energy_data[i]["start_time"].split('T');

            // Before parsing: "2021-01-01"
            var date = parsed_time[0].split('-')

            var year = date[0]
            var month = date[1]
            var day = date[2]

            // Before parsing: "01:00:00+0000"
            var time_hh_mm_ms = parsed_time[1].split('+')[0].split(':')

            var hours = time_hh_mm_ms[0]
            var mins = time_hh_mm_ms[1]
            var ms = time_hh_mm_ms[2]

            // Create a new datetime for the X-axis
            var new_date = new Date(year, month, day, hours, mins, ms)

            date_objects.push(new_date)
            energy_values.push(energy_value)

            // Add the X,Y point to the chart
            energy_series.append(toMsecsSinceEpoch(new_date), energy_value);

            // Set the min and max values for both axes.
            axisX.min = date_objects[0]
            axisX.max = date_objects[date_objects.length - 1]

            axisY.max = Math.max.apply(Math, energy_values)
            axisY.min =  Math.min.apply(Math, energy_values) - 500

        }
    }

    function toMsecsSinceEpoch(date) {
        /* Converts date objects to milliseconds */

        var msecs = date.getTime();
        return msecs;
    }

}
