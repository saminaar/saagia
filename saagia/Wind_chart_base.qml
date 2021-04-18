import QtQuick 2.0
import QtCharts 2.3
import QtQuick.Controls 2.0


ChartView {

        id: chart
        anchors.fill: parent
        antialiasing: true

        legend.visible: true
        theme: ChartView.ChartThemeDark
        //animationOptions: ChartView.GridAxisAnimations

        margins.top: 0
        margins.bottom: 0
        margins.left: 10
        margins.right: 30

        // Default grid display seen when launching the software

        BarSeries {
            id: mySeries
            axisX: BarCategoryAxis { categories: ["2007", "2008", "2009", "2010", "2011", "2012" ] }
            BarSet { label: "Cloudiness"; values: [2, 2, 3, 4, 5, 6] }
            BarSet { label: "Temperature"; values: [5, 1, 2, 4, 1, 7] }
            BarSet { label: "Other"; values: [3, 5, 8, 13, 5, 8] }
        }

        // The Y-axis of the chart
        ValueAxis {
            id: axisY
            gridVisible: true

            // Determines the visible grid's ticks
            tickCount: 6

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

            tickCount: 6
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

            // Create a new datetime for the X-axis
            var new_date = new Date(year, month, day, hours, mins, ms)

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
/*
        Connections {
            target: saagia_view

            function onSendChartData(value, date, type) {
                parseReceivedData(value, date, type)
            }
        }*/
}

