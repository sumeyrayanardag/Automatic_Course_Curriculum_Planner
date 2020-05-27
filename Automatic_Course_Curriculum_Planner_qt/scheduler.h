#ifndef SCHEDULER_H
#define SCHEDULER_H
#include<QMainWindow>
#include"classroom.h"
#include"course.h"
#include"service.h"
#include<string>
#include<iostream>
#include <fstream>
#include <vector>
#include<exception>
#include"program.h"
#include<cstdlib>
#include<stdlib.h>
#include<time.h>

extern std::vector<course> electiveCourses;
extern std::vector<course> compulsoryCourses;
extern std::vector<classroom> bigClassroom;
extern std::vector<classroom> smallClassroom;
extern std::vector<program> programs;
extern std::vector<service> notChangingCourses;
extern std::vector<service> busyCourses;

using namespace std;
class scheduler
{
public:
    scheduler();
    virtual ~scheduler();

    int size;

    void setProgram();
    bool isBusy(program p);
    bool isIntersect(program p);
    void printScheduler();    
    bool isService(course c);    
    void createScheduler();   
    void toString();
    bool isEmpty();
    void readBusy();
    void readClassroom();
    void readCourses();
    void readService();
    void printBusy();
    void printClassroom();
    void printCourses();
    void printService();

private:
    string courseDay;
    string courseTime;
    classroom courseClassroom;
    course crs;

};
#endif // SCHEDULER_HPP
