QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barline.cpp \
    basewindow.cpp \
    clef.cpp \
    cmutility.cpp \
    durationbutton.cpp \
    main.cpp \
    mainwindow.cpp \
    metypestring.cpp \
    musicelement.cpp \
    newscoreguide.cpp \
    note.cpp \
    scoreinfo.cpp \
    scorelauncher.cpp \
    staff.cpp \
    stafflist.cpp \
    staffspace.cpp \
    timesignature.cpp

HEADERS += \
    barline.h \
    basewindow.h \
    clef.h \
    cmutility.h \
    durationbutton.h \
    mainwindow.h \
    metypestring.h \
    musicelement.h \
    newscoreguide.h \
    note.h \
    scoreinfo.h \
    scorelauncher.h \
    staff.h \
    stafflist.h \
    staffspace.h \
    timesignature.h

FORMS += \
    mainwindow.ui \
    newscoreguide.ui \
    scorelauncher.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    composer2.qrc
