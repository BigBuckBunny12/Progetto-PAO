QT += core gui widgets

CONFIG += c++17 console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = MediaViewer

# Sorgenti C++
SOURCES += \
    createmediamodel.cpp \
    jsonmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowmodel.cpp \
    media.cpp \
    mediamanager.cpp \
    imedia.cpp \
    book.cpp \
    mediaregistry.cpp \
    movie.cpp \
    article.cpp \
    createmediadialog.cpp \
    mediacreationformvisitor.cpp \
    getuserinputvisitor.cpp \
    checkuserinputvisitor.cpp \
    mediawidgetvisitor.cpp \
    applyuserinputvisitor.cpp \
    savemediavisitor.cpp \
    viewmediacreationvisitor.cpp \
    viewmediadialog.cpp \
    viewmediamodel.cpp

# Header
HEADERS += \
    createmediamodel.h \
    jsonmanager.h \
    mainwindow.h \
    mainwindowmodel.h \
    media.h \
    mediamanager.h \
    imedia.h \
    book.h \
    movie.h \
    article.h \
    createmediadialog.h \
    mediaregistry.h \
    mediavisitor.h \
    mediacreationformvisitor.h \
    getuserinputvisitor.h \
    checkuserinputvisitor.h \
    mediawidgetvisitor.h \
    applyuserinputvisitor.h \
    savemediavisitor.h \
    viewmediacreationvisitor.h \
    viewmediadialog.h \
    viewmediamodel.h

# Form UI
FORMS += \
    mainwindow.ui \
    media.ui \
    createmediadialog.ui \
    viewmediadialog.ui

# Risorse
RESOURCES += \
    resource.qrc

# File extra (immagini, ecc.)
DISTFILES += \
    img/test.jpg
