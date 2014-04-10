QT += core gui

TARGET = QtScriptExample
TEMPLATE = app

DESTDIR = ../bin

include( Script/Script.pri )

SOURCES += main.cpp \
    note.cpp \
    formscriptrun.cpp

HEADERS  += \
    note.h \
    formscriptrun.h

FORMS += \
    formscriptrun.ui
