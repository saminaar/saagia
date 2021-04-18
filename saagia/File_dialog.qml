import QtQuick 2.2
import QtQuick.Dialogs 1.3
import Qt.labs.platform 1.1
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.0

FileDialog {
        id: loadDialog
        nameFilters: "*.json , *.txt"
        selectMultiple: false
        folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
        onAccepted: {
            console.log("Opened data: send this forward to datareader!")
            console.log(loadDialog.fileUrl)
            saagia_controller.load_from_file(loadDialog.fileUrl)
            // Tästä tieto eteenpäin databasehandlerille!
        }

    }
