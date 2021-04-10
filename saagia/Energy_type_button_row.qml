import QtQuick 2.14
import QtQuick.Controls 2.14

Rectangle {
    id: energy_button
    height: 60
    color: "#16141f"


    Row {

        id: row_
        anchors.verticalCenterOffset: 2
        anchors.horizontalCenterOffset: 156
        spacing: 20
        anchors.centerIn: parent

        Component.onCompleted: create_new_button()


    function create_new_button(){

        var list = ["\"wind\"", "\"electricity\"", "\"hydro\"", "\"nuclear\""];

        // number of displayed energytypes
        var i;

        for (i = 0; i < 4; i++) {
            var newObject = Qt.createQmlObject('import QtQuick 2.0; Energy_type_button {buttonIcon: ' + list[i] +'}',
                                               row_);

        }

    }
}
}

