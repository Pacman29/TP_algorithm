TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -static -Wall -O2 -std=gnu++11 -lm

SOURCES += main.cpp
