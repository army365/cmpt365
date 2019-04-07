import QtQuick 2.9
import QtCanvas3D 1.1
import QtQuick.Controls 2.2
import QtMultimedia 5.12

import "drums.js" as GLCode

ApplicationWindow {
    id: mainview
    title: qsTr("Kizyl Beatz")
    width: 1280
    height: 768
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

    Item {
        focus: true

        Audio {
            id: kick
            source: "kick.mp3"
        }

        Audio {
            id: snare
            source: "snare.mp3"
        }

        Audio {
            id: hihat
            source: "openhat.mp3"
        }

        Audio {
            id: crash
            source: "crash.mp3"
        }

        Keys.onPressed: {
            if(event.key === Qt.Key_B) {
                GLCode.getKey("KeyB");
                kick.play();
            }
            if(event.key === Qt.Key_G) {
                GLCode.getKey("KeyG");
                snare.play();
            }
            if(event.key === Qt.Key_H) {
                GLCode.getKey("KeyH");
                hihat.play();
            }
            if(event.key === Qt.Key_K) {
                GLCode.getKey("KeyK");
                crash.play();
            }
        }
    }
}
