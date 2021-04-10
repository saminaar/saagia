import QtQuick 2.0
import QtCharts 2.3
import QtQuick.Controls 2.0


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
}

