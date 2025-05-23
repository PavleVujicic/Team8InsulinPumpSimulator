QT       += core gui

# Include Qt Charts module
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    user.cpp \
    device.cpp \
    main.cpp \
    mainwindow.cpp \
    profilemanager.cpp \
    historymanager.cpp

HEADERS += \
    user.h \
    device.h \
    mainwindow.h \
    profilemanager.h \
    historymanager.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images/Images.qrc
