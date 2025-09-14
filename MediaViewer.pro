QT += core gui widgets

CONFIG += c++17 console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = MediaViewer

# Directory di include (necessario per trovare gli header nelle sottocartelle)
INCLUDEPATH += headers \
               headers/gui \
               headers/logic

# Sorgenti C++
SOURCES += \
    sources/gui/createmediadialog.cpp \
    sources/gui/mainwindow.cpp \
    sources/gui/media.cpp \
    sources/gui/mediacreationformvisitor.cpp \
    sources/gui/mediawidgetvisitor.cpp \
    sources/gui/viewmediacreationvisitor.cpp \
    sources/gui/viewmediadialog.cpp \
    sources/logic/applyuserinputvisitor.cpp \
    sources/logic/article.cpp \
    sources/logic/book.cpp \
    sources/logic/checkuserinputvisitor.cpp \
    sources/logic/createmediamodel.cpp \
    sources/logic/getuserinputvisitor.cpp \
    sources/logic/imedia.cpp \
    sources/logic/jsonmanager.cpp \
    sources/logic/main.cpp \
    sources/logic/mainwindowmodel.cpp \
    sources/logic/mediafilter.cpp \
    sources/logic/mediamanager.cpp \
    sources/logic/mediaregistry.cpp \
    sources/logic/movie.cpp \
    sources/logic/savemediavisitor.cpp \
    sources/logic/viewmediamodel.cpp

# Header
HEADERS += \
    headers/gui/createmediadialog.h \
    headers/gui/mainwindow.h \
    headers/gui/media.h \
    headers/gui/mediacreationformvisitor.h \
    headers/gui/mediawidgetvisitor.h \
    headers/gui/viewmediacreationvisitor.h \
    headers/gui/viewmediadialog.h \
    headers/logic/applyuserinputvisitor.h \
    headers/logic/article.h \
    headers/logic/book.h \
    headers/logic/checkuserinputvisitor.h \
    headers/logic/createmediamodel.h \
    headers/logic/getuserinputvisitor.h \
    headers/logic/imedia.h \
    headers/logic/jsonmanager.h \
    headers/logic/mainwindowmodel.h \
    headers/logic/mediaconstvisitor.h \
    headers/logic/mediafilter.h \
    headers/logic/mediamanager.h \
    headers/logic/mediaregistry.h \
    headers/logic/mediavisitor.h \
    headers/logic/movie.h \
    headers/logic/savemediavisitor.h \
    headers/logic/viewmediamodel.h

# Form UI
FORMS += \
    uiFiles/mainwindow.ui \
    uiFiles/media.ui \
    uiFiles/createmediadialog.ui \
    uiFiles/viewmediadialog.ui

# Risorse (qrc deve essere aggiornato per riflettere i nuovi path delle immagini)
RESOURCES += \
    resource.qrc \
    uiFiles/resource.qrc

# File extra
DISTFILES += \
    img/test.jpg
