QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR     = $$PWD
OBJECTS_DIR = $$PWD/../build/$$TARGET/obj
MOC_DIR     = $$PWD/../build/$$TARGET/moc
RCC_DIR     = $$PWD/../build/$$TARGET/rcc
UI_DIR      = $$PWD/../build/$$TARGET/ui

CONFIG += c++17
CONFIG -= debug_and_release debug_and_release_target

SOURCES += \
    CUiManager.cpp \
    main.cpp \
    Ui\widget.cpp

HEADERS += \
    CUiManager.h \
    Ui\widget.h

FORMS += \
    Ui\widget.ui

# 引用QGobangTool库文件
INCLUDEPATH += ../QGobangTool/include
LIBS += -L$$OUT_PWD/../QGobangTool/lib -lQGobangTool
