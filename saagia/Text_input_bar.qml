import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14

RowLayout {
    id: searchBar
    width: 350
    height: 40

    TextField {
        id: searchText
        property bool ignoreTextChange: false
        font.italic: true
        font.pointSize: 9
        placeholderText: qsTr("Enter a city or region...")
        Layout.fillWidth: true
/**        onTextChanged: {
            if (!ignoreTextChange)
                searchTextChanged(text)
        }
        onAccepted: doSearch(searchText.text)**/
    }

    Rectangle {
        id: searchButton
        height: searchText.height
        width: height
        color: "white"
        border.width: 2
        border.color: "orange"
        // iconSource: ".."
        //onClicked: doSearch(searchText.text)
        //Also clears the textfield

    }
}



