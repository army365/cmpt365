TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    drumset.cpp

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
    drumset.h
