import QtQuick 2.0
import QtCharts 2.3
import QtQuick.Controls 2.0

Rectangle {

    id: background_rect

    color: "#060317"

    ChartView {

        id: chart
        anchors.fill: parent
        antialiasing: true

        property var dates: []
        property var energy_values: []
        property var electricity_values: []

        legend.visible: false
        theme: ChartView.ChartThemeDark
        //animationOptions: ChartView.GridAxisAnimations

        margins.top: 0
        margins.bottom: 0
        margins.left: 10
        margins.right: 30

        // Default grid display seen when launching the software
        LineSeries {
            axisX: axisX
            axisY: axisY

        }

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

            tickCount: 7
        }


    }

    /*
    Timer {
        interval: 100000
        repeat: true
        triggeredOnStart: true
        running: true

        onTriggered: {

        }
    }*/

    function clear_previous_data(type){

        //chart.removeAllSeries()
        //chart.dates = []
        //chart.energy_values = []

        console.log("Created a new type! ", type)
        add_a_new_line(type)

    }

    function add_a_new_line(type)
    {

        var line = chart.createSeries(ChartView.SeriesTypeLine, type.toString(), axisX, axisY);

    }

    function set_min_and_max(){

        e1 = chart.series("1").visible;
        h1 = chart.series("2").visible;
        w1 = chart.series("3").visible;
        n1 = chart.series("4").visible;

        // Kaikki on visible
        if (e1 && h1 && w1 && n1){

        }
        // Vain electricity
        else if(e1 && !h1 && !w1 && !n1){

            axisY.max = Math.max.apply(Math, chart.electricity_values) + 500
            axisY.min =  Math.min.apply(Math, chart.electricity_values)

        }


    }

    function set_visibility(line)
    {

        if(chart.series(line.toString())){

            if( chart.series(line.toString()).visible)
            {

                chart.series(line.toString()).visible = false;

            }

            else{

                chart.series(line.toString()).visible = true;
            }
        }

        // Work in progress:
        //set_min_and_max()

    }

    function parseReceivedData(value, start_time, type) {

        // Before parsing: "2021-01-01T01:00:00+0000"
        var parsed_time = start_time.split('T');

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
        chart.dates.push(new_date)
        chart.energy_values.push(value)

        if (type === 1){
            chart.electricity_values.push(value)
        }

        // Add the X,Y point to the chart
        chart.series(type.toString()).append(toMsecsSinceEpoch(new_date), value);

        // Set the min and max values for both axes.
        axisX.min = chart.dates[0]
        axisX.max = chart.dates[chart.dates.length - 1]

        axisY.max = Math.max.apply(Math, chart.energy_values) + 500
        axisY.min =  Math.min.apply(Math, chart.energy_values)


    }

    function toMsecsSinceEpoch(date) {
        /* Converts date objects to milliseconds */

        var msecs = date.getTime();
        return msecs;
    }

    Connections {
        target: saagia_view
        onSendChartData:  {
            parseReceivedData(value, date, type)
        }
        onClearChartData: {
            clear_previous_data(type)
        }
        onSetLineVisibility: {
            set_visibility(type)

        }
    }

}
