
//![2]
import QtQuick 2.0
//![2]

import QtCharts 2.3

Rectangle{

    id: rektis
    color: "black"
    width: 500
    height: 350

    ChartView {
        id: line
        width: 500
        height: 350
        title: "Example"
        clip: false
        LineSeries {
            name: "Energy"
            XYPoint {
                x: 0
                y: 2
            }

            XYPoint {
                x: 1
                y: 1.2
            }

            XYPoint {
                x: 2
                y: 3.3
            }

            XYPoint {
                x: 5
                y: 2.1
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
