#-------------------------------------------------
#
# Project created by QtCreator 2016-10-19T15:21:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = URFCard
TEMPLATE = app

LIBS += -L"$$_PRO_FILE_PWD_"

LIBS += -lmwrf32


SOURCES += main.cpp\
        URFCard.cpp

HEADERS  += URFCard.h \
    mwrf32.h

FORMS    += URFCard.ui
