TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/animal.cpp \
        src/behaviour.cpp \
        src/behaviourherbivorouseat.cpp \
        src/behaviouridle.cpp \
        src/behaviourmitosis.cpp \
        src/behaviourpredatoreat.cpp \
        src/behaviourrandomwalk.cpp \
        src/behaviourstarvation.cpp \
        src/cell.cpp \
        src/entity.cpp \
        src/field.cpp \
        src/herbivorous.cpp \
        src/main.cpp \
        src/obstacle.cpp \
        src/predator.cpp \
        src/simmanager.cpp

HEADERS += \
    include/behaviour.h \
    include/behaviourherbivorouseat.h \
    include/behaviouridle.h \
    include/behaviourmitosis.h \
    include/behaviourpredatoreat.h \
    include/behaviourrandomwalk.h \
    include/behaviourstarvation.h \
    include/renderconfig.h \
    include/animal.h \
    include/cell.h \
    include/coords.h \
    include/entity.h \
    include/field.h \
    include/herbivorous.h \
    include/obstacle.h \
    include/predator.h \
    include/simconfig.h \
    include/simmanager.h \
    include/types.h \
    include/util.h
