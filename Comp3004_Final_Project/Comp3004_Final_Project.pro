QT       += core gui

<<<<<<< HEAD
# Include Qt Charts module
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts
=======
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
>>>>>>> f2be3f35f87feabeb74f29cd0bbb95dd6da2b27e

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
<<<<<<< HEAD
    User.cpp \
=======
>>>>>>> f2be3f35f87feabeb74f29cd0bbb95dd6da2b27e
    main.cpp \
    mainwindow.cpp \
    profilemanager.cpp

HEADERS += \
<<<<<<< HEAD
    User.h \
=======
>>>>>>> f2be3f35f87feabeb74f29cd0bbb95dd6da2b27e
    mainwindow.h \
    profilemanager.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
