TEMPLATE = subdirs

SUBDIRS += \
  QGobangClient \
  QGobangServer \
  QGobangTool

QGobangClient.depends = QGobangTool
QGobangServer.depends = QGobangTool
