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

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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
    Models/shapefactormarkmodel.h

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
    Models/shapefactormarkmodel.cpp


FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
