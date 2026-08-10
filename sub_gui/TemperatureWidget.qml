import QtQuick

Item {
    width: 30
    height: 100

    property real temp: 50.0
    property real maxTemp: 100.0
    property real minTemp: 0.0

    property real marginSize: width * 0.1

    property real font_size: width * 0.6

    Rectangle {
        id: bulb

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        height: width
        radius: width / 2
    }

    Rectangle {
        id: tube

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        width: parent.width * 0.5
        radius: width / 2
    }

    Rectangle {
        id: temp_indicator

        anchors.bottom: tube.bottom
        anchors.left: tube.left
        anchors.right: tube.right
        anchors.margins: marginSize

        height: Math.min(bulb.height + ((temp - minTemp) / (maxTemp - minTemp)) * (tube.height - bulb.height), tube.height - 2 * marginSize)

        radius: tube.radius
        color:  "red"
    }

    Rectangle {
        id: mercury_blob

        anchors.fill: bulb
        anchors.margins: marginSize
        radius: bulb.radius

        color: "red"
    }

    Text {
        id: temp_value
        text: qsTr(temp.toFixed(1) + " °C")
        color: "white"

        font.pointSize: font_size

        anchors.left: tube.right
        anchors.bottom: tube.bottom
        anchors.leftMargin: parent.width * 0.3
        anchors.bottomMargin: parent.height * 0.3
    }
}
