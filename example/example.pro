TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp

OTHER_FILES += main.qml \
               example.js \
               Cloth.js \
               three.js \
               circuit_pattern.png \
               grasslight-big.jpg

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

#DEFINES += QT_NO_VERSION_TAGGING
#QMAKE_CXXFLAGS += -D WITH_TIFF=ON -D BUILD_TIFF=ON
#QMAKE_CXXFLAGS_DEBUG+= -D WITH_TIFF=ON -D BUILD_TIFF=ON

#INCLUDEPATH += C:/opencv/build/include
#LIBS += C:\opencv\build\install\x64\mingw\bin\libopencv_core400.dll
#LIBS += C:\opencv\build\install\x64\mingw\bin\libopencv_highgui400.dll
#LIBS += C:\opencv\build\install\x64\mingw\bin\libopencv_imgcodecs400.dll
#LIBS += C:\opencv\build\install\x64\mingw\bin\libopencv_imgproc400.dll
#LIBS += C:\opencv\build\install\x64\mingw\bin\libopencv_features2d400.dll
#LIBS += C:\opencv\build\install\x64\mingw\bin\libopencv_calib3d400.dll

include(deployment.pri)
