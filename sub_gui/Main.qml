import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
import QtMultimedia
import QtQuick.Shapes


ApplicationWindow {
    id: window
    width: 970
    height: 480
    minimumWidth: 200
    minimumHeight: 250
    visible: true
    title: qsTr("Hello World")

    /*MediaPlayer {
        id: player
        source: "rtsp://192.168.10.59:554/media/live/1/1"

        videoOutput: videoOutput

        Component.onCompleted: play()
    }

    VideoOutput {
        id: videoOutput
        anchors.fill: parent
    }
    */
    Canvas {
        id: canv
        objectName: "canvas"
        anchors.fill: parent

        property real battery_level: 0.4

        onPaint: {
            var ctx = getContext("2d")

            var centerX = width / 2
            var centerY = height / 2
            var radius = 50

            ctx.lineWidth = 15
            ctx.lineCap = "round"
            ctx.strokeStyle = "grey"

            ctx.beginPath()
            ctx.arc(centerX, centerY, radius, 0, 2 * Math.PI)
            ctx.stroke()

            ctx.lineWidth = 10
            ctx.lineCap = "round"
            ctx.strokeStyle = "yellow"

            ctx.beginPath()
            ctx.arc(centerX, centerY, radius, -Math.PI, -Math.PI + Math.PI*battery_level)
            ctx.stroke()

            ctx.lineWidth = 10
            ctx.lineCap = "round"
            ctx.strokeStyle = "black"

            ctx.beginPath()
            ctx.arc(centerX, centerY, radius, Math.PI, -Math.PI - Math.PI*0.8)
            ctx.stroke()
        }
    }
}
