TEMPLATE = app

QT += qml quick widgets
QT += core gui
QT += multimedia multimediawidgets

SOURCES += main.cpp \
    soundevent.cpp \
    mainwindow.cpp \
    playback.cpp \
    finalserializer.cpp \
    soundeffectwidget.cpp \
    track.cpp

OTHER_FILES += main.qml \
               drums.js \
               three.js

RESOURCES += qml.qrc


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
#QML_DESIGNER_IMPORT_PATH =

#target.path = $$[QT_INSTALL_EXAMPLES]/canvas3d/threejs/$$TARGET
#INSTALLS += target
# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

#target.path = $$[QT_INSTALL_EXAMPLES]/canvas3d/threejs/$$TARGET
#INSTALLS += target
include(deployment.pri)

HEADERS += \
    mainwindow.h \
    canserialize.h \
    soundevent.h \
    track.h \
    serializer.h \
    soundeffectwidget.h \
    playback.h \
    finalserializer.h

FORMS += \
    mainwindow.ui
