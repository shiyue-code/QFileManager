QT       += core gui webenginewidgets webchannel network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(fmllib.pri)
include($$PWD/../common.pri)

INCLUDEPATH += \
    widget/

DESTDIR = $$SY_DESTDIR

SOURCES += \
    core/messagehandle.cpp \
    main.cpp \
    mainwindow.cpp \
    sy_searchwidget.cpp \
    widget/sy_lineedit.cpp

HEADERS += \
    core/messagehandle.h \
    mainwindow.h \
    sy_searchwidget.h \
    widget/sy_lineedit.h

FORMS += \
    mainwindow.ui \
    sy_searchwidget.ui \
    view/titlebar.ui

TRANSLATIONS += \
    SYFileManager_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#RESOURCES += \
#    icons/icons.qrc


