import QtQuick 2.9
import QtCanvas3D 1.1
import QtQuick.Controls 2.2
import QtMultimedia 5.12

import "drums.js" as GLCode

ApplicationWindow {
    id: mainview
    title: qsTr("Kizyl Beatz")
    width: 2500
    height: 1500
    visible: true

    Canvas3D {
        id: canvas3d
        anchors.fill: parent

        onInitializeGL: {
            GLCode.initializeGL(canvas3d);
        }

        onPaintGL: {
            GLCode.paintGL(canvas3d);
        }

        onResizeGL: {
            GLCode.resizeGL(canvas3d);
        }
    }

    Button {
        id: saveButton
        anchors.left: parent.left
        width: parent.width / 2
        text: "Save"

        onClicked: console.log("save - call c++ object")
    }

    Button {
        id: loadButton
        anchors.left: saveButton.right
        width: parent.width / 2
        text: "Load"

        onClicked: console.log("load - call c++ object")
    }

    Button {
        id: playButton
        anchors.bottom: parent.bottom
        width: parent.width / 3
        text: "Play"

        onClicked: console.log("play - call c++ object")
    }

    Button {
        id: recordButton
        anchors.bottom: parent.bottom
        anchors.left: playButton.right
        width: parent.width / 3
        text: "Record"

        onClicked: console.log("record - call c++ object")
    }

    Button {
        id: stopButton
        anchors.bottom: parent.bottom
        anchors.left: recordButton.right
        width: parent.width / 3
        text: "Stop"

        onClicked: console.log("stop - call c++ object")
    }

    Item {
        focus: true

        Audio {
            id: kick
            source: "Bass-Drum-3.wav"
            autoLoad: true
        }

        Audio {
            id: snare
            source: "Ensoniq-ESQ-1-Snare-2.wav"
            autoLoad: true
        }

        Audio {
            id: hihat
            source: "Open-Hi-Hat-5.wav"
            autoLoad: true
        }

        Audio {
            id: crash
            source: "Crash-Cymbal-2.wav"
            autoLoad: true
        }

        Keys.onPressed: {
            if(event.key === Qt.Key_B) {
                GLCode.getKey("KeyB");
                if(kick.playbackState === 1) kick.stop();
                kick.play();
            }
            if(event.key === Qt.Key_G) {
                GLCode.getKey("KeyG");
                if(snare.playbackState === 1) snare.stop();
                snare.play();
            }
            if(event.key === Qt.Key_H) {
                GLCode.getKey("KeyH");
                if(hihat.playbackState === 1) hihat.stop();
                hihat.play();
            }
            if(event.key === Qt.Key_V) {
                GLCode.getKey("KeyV");
                if(crash.playbackState === 1) crash.stop();
                crash.play();
            }
        }
    }
}
