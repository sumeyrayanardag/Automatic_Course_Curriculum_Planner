
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    scheduler.cpp

HEADERS += \
    ../CENG206_Project2_Group16/CENG206_Project2_Group16/hpp/bigClassroom.hpp \
    ../CENG206_Project2_Group16/CENG206_Project2_Group16/hpp/clasroom.hpp \
    ../CENG206_Project2_Group16/CENG206_Project2_Group16/hpp/compulsoryCourse.hpp \
    ../CENG206_Project2_Group16/CENG206_Project2_Group16/hpp/course.hpp \
    ../CENG206_Project2_Group16/CENG206_Project2_Group16/hpp/electiveCourse.hpp \
    ../CENG206_Project2_Group16/CENG206_Project2_Group16/hpp/program.hpp \
    ../CENG206_Project2_Group16/CENG206_Project2_Group16/hpp/scheduler.hpp \
    ../CENG206_Project2_Group16/CENG206_Project2_Group16/hpp/service.hpp \
    ../CENG206_Project2_Group16/CENG206_Project2_Group16/hpp/smallClassroom.hpp \
    bigclassroom.h \
    classroom.h \
    compulsoryCourse.h \
    course.h \
    electiveCourse.h \
    mainwindow.h \
    program.h \
    scheduler.h \
    service.h \
    smallClassroom.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Desktop/sample/busy.csv \
    ../../Desktop/sample/classroom.csv \
    ../../Desktop/sample/courses.csv \
    ../../Desktop/sample/service.csv \
    ../../Desktop/sample/service.txt
