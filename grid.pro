#-------------------------------------------------
#
# Project created by QtCreator 2011-03-02T09:09:07
#
#-------------------------------------------------

QT       += core gui

TARGET = grid
TEMPLATE = app


SOURCES += sources/main.cpp\
		sources/gridicon.cpp \
    sources/settingswindow.cpp \
    sources/gridwindow.cpp \
    sources/about.cpp

HEADERS  += sources/gridicon.h \
    sources/settingswindow.h \
    sources/gridwindow.h \
    sources/about.h
FORMS    +=  \
    sources/settingswindow.ui \
    sources/gridwindow.ui \
    sources/about.ui

RESOURCES += \
    share/resources.qrc
