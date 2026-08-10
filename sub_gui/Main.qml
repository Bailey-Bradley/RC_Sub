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

    TemperatureWidget {
        objectName: "temp_widget"
        height: 90
        width: 30
    }
}
