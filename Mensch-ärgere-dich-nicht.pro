# -------------------------------------------------
# Project created by QtCreator 2013-11-19T12:41:22
# -------------------------------------------------
QT += core \
    gui
greaterThan(QT_MAJOR_VERSION, 4):QT += widgets
TARGET = test
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    dialog.cpp \
    erstellen.cpp \
    feld.cpp \
    wurfel.cpp \
    spielfeld.cpp \
    startposition.cpp \
    verzweigungsfeld.cpp \
    zielfeld.cpp \
    spielbrett.cpp
HEADERS += mainwindow.h \
    dialog.h \
    erstellen.h \
    feld.h \
    wurfel.h \
    spielfeld.h \
    startposition.h \
    verzweigungsfeld.h \
    zielfeld.h \
    zustand.h \
    Netzwerkverbindung.h \
    Server.h \
    Client.h
FORMS += mainwindow.ui \
    dialog.ui \
    erstellen.ui
RESOURCES += ressourcen/wurfel.qrc \
    ressourcen/icons.qrc \
    ressourcen/felder.qrc \
    ressourcen/figuren.qrc
