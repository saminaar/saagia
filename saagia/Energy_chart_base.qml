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

        legend.visible: false
        theme: ChartView.ChartThemeDark

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
            format: "dd.MM hh:mm" //"dd-MM

            property real range: 100

            min: new Date(2021, 0, 1, 0, 0, 0)
            max: new Date(2021, 0, 1, 12, 30, 30)

            tickCount: 4
        }


    }

    Rectangle {
        id: horizontalScrollMask
        visible: false
    }

    MouseArea {
        id: chart_area
        anchors.fill: chart
        acceptedButtons: Qt.LeftButton

        onMouseXChanged: {
            if ((mouse.buttons & Qt.LeftButton) == Qt.LeftButton) {
                chart.scrollLeft(mouseX - horizontalScrollMask.x);
                horizontalScrollMask.x = mouseX;
            }

        }

        onPressed: {
            if (mouse.button == Qt.LeftButton) {
                horizontalScrollMask.x = mouseX;
            }
        }
    }


    function clear_previous_data(){

        chart.removeAllSeries()
        chart.dates = []
        chart.energy_values = []

    }



    function add_a_new_line(type)
    {

        var line = chart.createSeries(ChartView.SeriesTypeLine, type.toString(), axisX, axisY);

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
    }

    function parseReceivedData(value, start_time, type) {

        console.log(value, start_time)
        // Before parsing: "2021-01-01T01:00:00+0000"
        var parsed_time = start_time.split('T');

        // Before parsing: "2021-01-01"
        var date = parsed_time[0].split('-')

        var year = date[0]
        var month = date[1] - 1 // Javascript starts indexing at 0
        var day = date[2]


        // Before parsing: "01:00:00+0000"
        var time_hh_mm_ms = parsed_time[1].split('+')[0].split(':')

        var hours = time_hh_mm_ms[0]
        var mins = time_hh_mm_ms[1]

        var ms = time_hh_mm_ms[2]

        // Create a new datetime for the X-axis
        var new_date = new Date(year, month, day, hours, mins)

        chart.dates.push(new_date)

        chart.energy_values.push(value)
        /*
        if (type === 1){
            chart.electricity_values.push(value)
        }*/

        // Add the X,Y point to the chart

        if (chart.series(type.toString()) !== null){

            chart.series(type.toString()).append(toMsecsSinceEpoch(new_date), value)

        }

        // Set the min and max values for both axes.
        axisX.min = chart.dates[0]
        axisX.max = chart.dates[7]

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

        function onSendChartData(value, start_time, type) {
            parseReceivedData(value, start_time, type)
        }
        function onClearChartData(type) {
            clear_previous_data(type)
        }
        function onSetLineVisibility(type) {
            set_visibility(type)
        }
        function onAddChartLine(type) {
            add_a_new_line(type)
        }


    }

}
