QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    directory.cpp \
    file.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    tag.cpp \
    tree.cpp \
    treefile.cpp \
    url.cpp \
    user.cpp \
    userfile.cpp \
    userlist.cpp \
    widgetitem.cpp

HEADERS += \
    directory.h \
    file.h \
    loginwindow.h \
    mainwindow.h \
    tag.h \
    tree.h \
    treefile.h \
    url.h \
    user.h \
    userfile.h \
    userlist.h \
    widgetitem.h

FORMS += \
    loginwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    MyFile.qrc
