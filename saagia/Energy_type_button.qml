import QtQuick 2.14

Rectangle {
    id: energy_button

    width: 60
    height: 60
    color: "#d9d9d9"
    border.width: 3
    border.color: "orange"


    Text {
        id: button_title
        text: "?"
        color: "black"
        anchors.verticalCenter: parent.verticalCenter

        anchors.horizontalCenter: parent.horizontalCenter
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        Connections {
            target: mouseArea
            onClicked:
                function pressed_button() {

                    console.log("Clicked");




                        //![3]
                        // Make HTTP GET request and parse the result

                        var xhr = new XMLHttpRequest;
                        xhr.open("GET",
                                 "https://api.fingrid.fi/v1/variable/245/events/xml?start_time=2020-01-19T16:00:00Z&end_time=2020-01-19T19:00:00Z&key="
                                 , true);

                        xhr.setRequestHeader("x-api-key","YR7mX5L1Hb4Xjn4PHq4mk1t2T6ToN6f92isw3ejP");
                        xhr.send();
                        xhr.onreadystatechange = function() {
                            if (xhr.readyState === XMLHttpRequest.DONE) {
                                console.log(xhr.responseText);
                                var a = JSON.parse(xhr.responseText);
                            }
                        }
                        xhr.send();
                        //![3]



                }
        }
    }


    states: [
        State {
            name: "Active"
            PropertyChanges { target: energy_button; color: "white" }
            PropertyChanges {
                target: button_title
                color: "red"

            }

        }
    ]

}

