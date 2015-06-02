#-------------------------------------------------
#
# Project created by QtCreator 2014-12-17T00:15:31
#
#-------------------------------------------------

# INCLUDEPATH += $$PWD/EigenLib/Eigen

# QMAKE_CXXFLAGS_RELEASE -= -O3

INCLUDEPATH += C:\Users\Maniek\Documents\MBSD\Control \
               C:\Users\Maniek\Documents\MBSD\Kernel  \
               C:\Users\Maniek\Documents\MBSD\Haptic


include(Kernel/Kernel.pri)
include(Graphics/Graphics.pri)
include(Dynamics/Dynamics.pri)
include(Control/Control.pri)
include(Spatial/Spatial.pri)
include(Complex/Complex.pri)
include(Haptic/Haptic.pri)


QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MBSD
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    optionswidget.cpp \
    linkspropertieswidget.cpp \
    basepropertieswidget.cpp \
    dialogmeasurement.cpp \
    qcustomplot.cpp \
    projectorygeneratorwindow.cpp \
    positioncontrolerwindow.cpp \
    simulationwidget.cpp \
    multibodysysteminfowidget.cpp \
    HapticDeviceWindow.cpp \
    ControlerWidget.cpp \
    PlotWindow.cpp

HEADERS  += mainwindow.h \
    optionswidget.h \
    programoptions.h \
    linkspropertieswidget.h \
    basepropertieswidget.h \
    dialogmeasurement.h \
    qcustomplot.h \
    projectorygeneratorwindow.h \
    positioncontrolerwindow.h \
    simulationwidget.h \
    multibodysysteminfowidget.h \
    HapticDeviceWindow.h \
    ControlerWidget.h \
    PlotWindow.h

FORMS    += mainwindow.ui \
    optionswidget.ui \
    linkspropertieswidget.ui \
    basepropertieswidget.ui \
    dialogmeasurement.ui \
    projectorygeneratorwindow.ui \
    positioncontrolerwindow.ui \
    simulationwidget.ui \
    multibodysysteminfowidget.ui \
    HapticDeviceWindow.ui \
    ControlerWidget.ui \
    PlotWindow.ui

DISTFILES += \
    Dynamics/Dynamics.pri \
    Control/Control.pri

RESOURCES += \
    main_res.qrc





win32: LIBS += -L$$PWD/include/Haptic/ -lhdl

INCLUDEPATH += $$PWD/include/Haptic
DEPENDPATH += $$PWD/include/Haptic

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/include/Haptic/hdl.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/include/Haptic/libhdl.a


win32: LIBS += -LC:/Users/Maniek/Documents/MBSD/Graphics/Lib -lFreeImage

INCLUDEPATH += C:/Users/Maniek/Documents/MBSD/Graphics/Lib
DEPENDPATH += C:/Users/Maniek/Documents/MBSD/Graphics/Lib

win32:!win32-g++: PRE_TARGETDEPS += C:/Users/Maniek/Documents/MBSD/Graphics/Lib/FreeImage.lib
else:win32-g++: PRE_TARGETDEPS += C:/Users/Maniek/Documents/MBSD/Graphics/Lib/libFreeImage.a




win32: LIBS += -L$$PWD/include/ -llapack

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/include/lapack.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/include/liblapack.a
