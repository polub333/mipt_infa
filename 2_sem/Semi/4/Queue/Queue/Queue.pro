TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS_DEBUG  = -g

SOURCES += \
        circularbufferqueue.cpp \
        list.cpp \
        listqueue.cpp \
        main.cpp \
        vector.cpp \
        vectorqueue.cpp

HEADERS += \
    circularbufferqueue.h \
    list.h \
    listqueue.h \
    vector.h \
    vectorqueue.h
