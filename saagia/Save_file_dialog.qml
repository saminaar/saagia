
import QtQuick 2.2
import QtQuick.Dialogs 1.3
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.platform 1.1



FileDialog {
            id: saveDialog

            property int dialog_type: 0

            title: "Save as"
            folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
            currentFile: "file:///"
            fileMode: FileDialog.SaveFile

            onAccepted:
                send_request_forward()


            function send_request_forward(){


                if (dialog_type === 0){

                    // tallennetaan datastruktuuria
                    saagia_controller.save_to_file(currentFile)
                }
                else{

                    console.log("Save_file_dialog.qml: TODO: Lähetä eteenpäin tieto preferences tiedoston tallentamisesta")
                }

            }
        }


