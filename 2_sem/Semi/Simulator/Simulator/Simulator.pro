TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/cell.cpp \
        src/main.cpp

HEADERS += \
    include/animal.h \
    include/cell.h \
    include/entity.h \
    include/field.h \
    include/herbivorous.h \
    include/obstacle.h \
    include/predator.h \
    include/strategy.h \
    include/types.h
