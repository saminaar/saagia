import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

Button{

        text: "<font color='#cccccc'>" + "Preferences" + "</font>"
        font.pixelSize: 13

        icon.source: "images/heart_outline.png"
        icon.color: "#ff6666"
        icon.width: 15
        icon.height: 15



        property string chosen_start_date: "test"
        //property string chosen_end_date: "hi"
        //property string chosen_start_time: "hullo"
        //property string chosen_end_time: "yap"

        property string testeri: ""

        //change the color of the button in different button states
        states: [
            State {
                name: "Hovering"
                PropertyChanges {
                    target: button
                    text: "<font color='#ffffff'>" + "Preferences" + "</font>"
                }
            },
            State {
                name: "Pressed"
                PropertyChanges {
                    target: button
                    text: "<font color='#ffffff'><b>" + "Preferences" + "</b></font>"
                }
            }
        ]

        //define transmission for the states
        transitions: [
            Transition {
                from: ""; to: "Hovering"
                ColorAnimation { duration: 10 }
            },
            Transition {
                from: "*"; to: "Pressed"
                ColorAnimation { duration: 10 }
            }
        ]

        onClicked: {
            console.log(testeri)
        }

        Connections {
          target: popup
          function onForwardParameters(txt) {
              testeri = txt
          }
        }


    }
