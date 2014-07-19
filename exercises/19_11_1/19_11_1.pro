TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

OTHER_FILES += \
    counted_ptr.txt \
    test_ptr.txt \
    shared_ptr.txt

HEADERS += \
    reference_count.h \
    counted_ptr.h

