import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Private 1.0

Calendar {

    id: calendar

        style: CalendarStyle {
            background: Rectangle {
                color: "grey"
                implicitWidth: Math.max(250, Math.round(TextSingleton.implicitHeight * 14))
                implicitHeight: Math.max(250, Math.round(TextSingleton.implicitHeight * 14))
            }


            dayOfWeekDelegate: Rectangle {
                color: "#fff"

                implicitHeight: Math.round(TextSingleton.implicitHeight * 2.25)
                Label {
                    color: "#333"
                    text: control.__locale.dayName(styleData.dayOfWeek, control.dayOfWeekFormat)
                    anchors.centerIn: parent
                }
            }

            navigationBar: Rectangle {

                height: 40
                color: "#16141f"

                Rectangle {
                    color: "orange"
                    height: 2
                    width: parent.width
                }

                Rectangle {
                    anchors.bottom: parent.bottom
                    height: 2
                    width: parent.width
                    color: "orange"
                }
                HoverButton {
                    id: previousMonth
                    width: parent.height
                    height: width
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    source: "qrc:/images/left-arrow.png"
                    onClicked: control.showPreviousMonth()
                }
                Label {
                    id: dateText
                    color: "#fff"
                    text: styleData.title
                    elide: Text.ElideRight
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 22
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: previousMonth.right
                    anchors.leftMargin: 2
                    anchors.right: nextMonth.left
                    anchors.rightMargin: 2
                }
                HoverButton {
                    id: nextMonth
                    width: parent.height
                    height: width
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    source: "qrc:/images/right-arrow.png"
                    onClicked: control.showNextMonth()
                }
            }

            dayDelegate: Item {
                Rectangle {
                    id: rect
                    anchors.fill: parent
                    border.color: "orange"
                    color:"#fff"

                    Label {
                        text: styleData.date.getDate()

                        anchors.centerIn: parent
                        color: styleData.selected ? "#000" : (styleData.visibleMonth && styleData.valid ? "#111" : "#666")
                        font.bold: styleData.selected ? true : false

                    }

}
            }
        }
}
