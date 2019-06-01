#-------------------------------------------------
#
# Project created by QtCreator 2019-05-23T12:54:22
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

TARGET = MarkAnalyzer
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += open_cv\include

#LIBS += $${_PRO_FILE_PWD_}\open_cv\lib\lopencv_core341
#LIBS += -lopencv_core341 -lopencv_imgproc341 -lopencv_highgui341 \
#-lopencv_ml341 -lopencv_video341 -lopencv_features2d341 -lopencv_calib3d341 \
#-lopencv_objdetect341 -lopencv_flann341 -lopencv_videoio341

LIBS += $${_PRO_FILE_PWD_}/open_cv/bin/libopencv_calib3d341.dll
LIBS += $${_PRO_FILE_PWD_}/open_cv/bin/libopencv_core341.dll
LIBS += $${_PRO_FILE_PWD_}/open_cv/bin/libopencv_features2d341.dll
LIBS += $${_PRO_FILE_PWD_}/open_cv/bin/libopencv_highgui341.dll
LIBS += $${_PRO_FILE_PWD_}/open_cv/bin/libopencv_imgcodecs341.dll
LIBS += $${_PRO_FILE_PWD_}/open_cv/bin/libopencv_photo341.dll
LIBS += $${_PRO_FILE_PWD_}/open_cv/bin/libopencv_imgproc341.dll

HEADERS += \
    Controllers/mainwindow.h \
    Views/imageview.h \
    Views/imageviewmode.h \
    Views/waitingspinnerwidget.h \
    Common/consts.h \
    Common/currentappstate.h \
    Common/magic.h \
    Common/settingsstorage.h \
    Models/seriamodel.h \
    Common/staticstorage.h \
    Models/markmodel.h \
    Models/energymarkmodel.h \
    Models/inertiamomentmarkmodel.h \
    Models/entropymarkmodel.h \
    Models/localuniformitymarkmodel.h \
    Models/markmodels.h \
    Managers/appinitializator.h \
    core.h \
    Common/customtypes.h \
    Models/maxprobabilitymarkmodel.h \
    Models/imagemodel.h \
    Managers/markscalculatetask.h \
    Models/shapefactormarkmodel.h \
    Common/opencv.h \
    Models/areamarkmodel.h

SOURCES += \
        main.cpp \
    Controllers/mainwindow.cpp \
    Views/imageview.cpp \
    Views/waitingspinnerwidget.cpp \
    Common/currentappstate.cpp \
    Common/settingsstorage.cpp \
    Models/seriamodel.cpp \
    Common/staticstorage.cpp \
    Models/markmodel.cpp \
    Models/energymarkmodel.cpp \
    Models/inertiamomentmarkmodel.cpp \
    Models/entropymarkmodel.cpp \
    Models/localuniformitymarkmodel.cpp \
    Managers/appinitializator.cpp \
    core.cpp \
    Models/maxprobabilitymarkmodel.cpp \
    Models/imagemodel.cpp \
    Managers/markscalculatetask.cpp \
    Models/shapefactormarkmodel.cpp \
    Models/areamarkmodel.cpp


FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
