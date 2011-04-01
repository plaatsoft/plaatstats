# -------------------------------------------------
# Project created by QtCreator 2010-03-15T16:17:59
# -------------------------------------------------
QT += network

TARGET = Statistics

TEMPLATE = app

SOURCES += main.cpp \
    stats.cpp \
    settings.cpp \
    about.cpp \
    donate.cpp

HEADERS += stats.h \
    settings.h \
    about.h \
    donate.h

FORMS += stats.ui \
    settings.ui \
    about.ui \
    donate.ui

RESOURCES += resource.qrc

RC_FILE = stats.rc
