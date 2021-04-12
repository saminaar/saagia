import QtQuick 2.11
import QtCharts 2.2
import QtQuick.Window 2.11
import QtCharts 2.3
import QtQuick.Controls 2.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property real epochCreated :  new Date(Date.now()).valueOf();
    property real chartAge     : Date.now() - root.epochCreated;
    property real tzMs: ((new Date().getTimezoneOffset()) * 60000); // returns minuites not MS so we need to convert down

    property real spanMs: 120000; // 2 min in ms

    //function updateTimeAxis(chartTimeMin, chartTimeMax, memoryAddress){ // cpp remote control calls me

    ChartView {
        id: chartView
        width: root.width
        height: root.height
        antialiasing: true
        legend.visible: false

        ValueAxis {
            id: valueAxis
            min: 0
            max: 20
            tickCount: 10
            minorTickCount: 2
        }

        DateTimeAxis {// move with slider
            id: dateTimeAxisVisible;
            visible: true;
            format: "mm.ss"
            min: new Date(root.chartAge - dateTimeAxis.max.valueOf()); // init
            max: new Date(root.chartAge - dateTimeAxis.min.valueOf()); // init
        }

        LineSeries {
            id: nothingSeries
            useOpenGL: true
            axisX: dateTimeAxisVisible
            axisY: valueAxis
            XYPoint { x:  new Date(Date.now()).getTime(); y: 0 }
        }

        DateTimeAxis {
            id: dateTimeAxis
            visible: false;
        }
        LineSeries {
            id: lineSeries
            name: "Line Series"
            axisXTop: dateTimeAxis
            axisY   : valueAxis
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs      ; y:0;    }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +1500; y:1.1;  }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +2000; y:10.9; }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +2500; y:2.1;  }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +3100; y:20.9; }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +3500; y:3.4;  }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +4000; y:4.1;  }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +4500; y:10;   }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +5000; y:19.1; }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +5500; y:11.9; }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +6000; y:16.1; }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +6500; y:12.9; }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +7000; y:13.4; }
            XYPoint { x: (new Date(Date.now())).getTime() + root.tzMs +7500; y:14.1; }
        }
    }

    Rectangle {
        id: horizontalScrollMask
        visible: false
    }

    MouseArea {
        id: chart_area
        anchors.fill: chartView
        acceptedButtons: Qt.LeftButton

        onMouseXChanged: {
            if ((mouse.buttons & Qt.LeftButton) == Qt.LeftButton) {
                chartView.scrollLeft(mouseX - horizontalScrollMask.x);
                horizontalScrollMask.x = mouseX;
            }

            console.log(chart.s)

        }
        onPressed: {
            if (mouse.button == Qt.LeftButton) {
                horizontalScrollMask.x = mouseX;
            }
        }
    }


    function updateTimeAxis()// chartTimeMin, chartTimeMax){
    {
    //    root.chartAge = Date.now() - root.epochCreated; // update age
        var now = Date.now();
        dateTimeAxis.min = new Date((now - root.spanMs) + root.tzMs); //chartTimeMin);
        dateTimeAxis.max = new Date( now                + root.tzMs); //chartTimeMax);

   //     dateTimeAxisVisible.min = new Date(root.chartAge - dateTimeAxis.max.valueOf());
   //     dateTimeAxisVisible.max = new Date(root.chartAge - dateTimeAxis.min.valueOf());
    }
}
