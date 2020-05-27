#include "mainwindow.h"

#include <QApplication>
#include<iostream>
#include"scheduler.h"
#include<cstdlib>
#include<string>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
   /* scheduler s;
    s.readCourses();
    //s.printCourses();
    s.readClassroom();
    //s.printClassroom();
    s.readService();
    s.printService();
    s.readBusy();
    //s.printBusy();
    s.createScheduler();*/
}
