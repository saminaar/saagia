import QtQuick 2.0

Rectangle  {
    id: title_text
    width: 180
    height: 50
    color: "transparent"

    Image {
        id: title_image
        width: 180
        height: 50
        anchors.centerIn: parent
        fillMode: Image.Stretch
        source: "qrc:/images/application_name.png"
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0

    }
}
