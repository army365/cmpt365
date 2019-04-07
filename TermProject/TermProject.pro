#-------------------------------------------------
#
# Project created by QtCreator 2019-04-01T14:26:58
#
#-------------------------------------------------

QT       += core gui
QT       += core gui multimedia
QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TermProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    sndfile.h \
    sndfile.hh

FORMS    += mainwindow.ui
DEFINES += QT_NO_VERSION_TAGGING
QMAKE_CXXFLAGS += -D WITH_TIFF=ON -D BUILD_TIFF=ON
QMAKE_CXXFLAGS_DEBUG+= -D WITH_TIFF=ON -D BUILD_TIFF=ON

INCLUDEPATH += C:/opencv/build/include
LIBS += C:\opencv\build\install\x64\mingw\bin\libopencv_core400.dll
LIBS += C:\opencv\build\install\x64\mingw\bin\libopencv_highgui400.dll
LIBS += C:\opencv\build\install\x64\mingw\bin\libopencv_imgcodecs400.dll
LIBS += C:\opencv\build\install\x64\mingw\bin\libopencv_imgproc400.dll
LIBS += C:\opencv\build\install\x64\mingw\bin\libopencv_features2d400.dll
LIBS += C:\opencv\build\install\x64\mingw\bin\libopencv_calib3d400.dll

macx: LIBS += -L$$PWD/./ -lsndfile

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

RESOURCES += \
    sound.qrc

