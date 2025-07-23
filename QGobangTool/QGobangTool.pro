QT = core

TEMPLATE = lib
CONFIG += staticlib
TARGET = QGobangTool

DESTDIR     = $$PWD/lib
OBJECTS_DIR = $$PWD/../build/$$TARGET/obj
MOC_DIR     = $$PWD/../build/$$TARGET/moc
RCC_DIR     = $$PWD/../build/$$TARGET/rcc
UI_DIR      = $$PWD/../build/$$TARGET/ui

CONFIG += c++17 cmdline
CONFIG -= debug_and_release debug_and_release_target

SOURCES += \
        QGobangRule.cpp

HEADERS += \
  QGobangRule.h



unix {
  DEST_DIR = $$OUT_PWD/include

  QMAKE_POST_LINK += \
    cp $$OUT_PWD/QGobangRule.h $$DEST_DIR
}

win32 {
  DEST_DIR = $$OUT_PWD\\include

  QMAKE_POST_LINK += \
    copy /Y \"$$OUT_PWD\\QGobangRule.h\" \"$$DEST_DIR\"
}
