QT = core

OBJECTS_DIR = $$PWD/../build/$$TARGET/obj
MOC_DIR     = $$PWD/../build/$$TARGET/moc
RCC_DIR     = $$PWD/../build/$$TARGET/rcc
UI_DIR      = $$PWD/../build/$$TARGET/ui

CONFIG += c++17 cmdline
CONFIG -= debug_and_release debug_and_release_target

SOURCES += \
        CServerManager.cpp \
        main.cpp

#引用QGobangTool库文件
INCLUDEPATH += ../QGobangTool/include
LIBS += -L$$OUT_PWD/../QGobangTool/lib -lQGobangTool

HEADERS += \
  CServerManager.h
