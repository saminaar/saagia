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
}

