# Shared library without any Qt functionality
TEMPLATE = lib
QT -= gui core

CONFIG += warn_on plugin release
CONFIG -= thread exceptions qt rtti debug

VERSION = 1.0.0

INCLUDEPATH += ../../SDK-2.1/CHeaders/XPLM
INCLUDEPATH += ../../SDK-2.1/CHeaders/Wrappers
INCLUDEPATH += ../../SDK-2.1/CHeaders/Widgets

# Defined to use X-Plane SDK 2.0 capabilities - no backward compatibility before 9.0
DEFINES += XPLM200

win32 {
    DEFINES += APL=0 IBM=1 LIN=0
    LIBS += -L../../SDK-2.1/Libraries/Win
    LIBS += -lXPLM -lXPWidgets
    LIBS += $$quote(C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/SetupAPI.Lib)
    TARGET = win.xpl
}

HEADERS += \
    xhatswitch.h

SOURCES += \
    xhatswitch.cpp







































