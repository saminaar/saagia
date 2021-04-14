import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14

RowLayout {
    id: searchBar
    width: 280
    height: 40

    TextField {
        id: searchText
        property bool ignoreTextChange: false
        font.italic: true
        font.pointSize: 10
        height: searchBar.height
        placeholderText: qsTr("Enter a city or region...")
        Layout.fillWidth: true

        onAccepted: saagia_controller.check_place(searchText.text)
    }

    Rectangle {
        id: searchButton
        height: searchText.height
        width: height
        color: "#090426"
        border.width: 2
        border.color: "white"
        // iconSource: ".."
        //onClicked: doSearch(searchText.text)
        //Also clears the textfield




        Image {
            id: search_button_image
            width: 20
            height: 20
            anchors.centerIn: parent
            fillMode: Image.Stretch
            source: "qrc:/images/search_icon.png"

            MouseArea{
                            anchors.fill: parent
                            onClicked:{
                                if (searchText.text != null)
                                    saagia_controller.check_place(searchText.text);
                            }
                        }
    }
    }
}



