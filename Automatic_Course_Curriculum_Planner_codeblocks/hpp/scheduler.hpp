#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include"clasroom.hpp"
#include"course.hpp"
#include"service.hpp"
#include<string>
#include<iostream>
#include <fstream>
#include <vector>
#include<exception>
#include <fstream>
#include"program.hpp"
#include<cstdlib>
#include<stdlib.h>
#include<time.h>


using namespace std;
class scheduler
{
public:
    scheduler();
    virtual ~scheduler();
    vector<course> electiveCourses;
    vector<course> compulsoryCourses;
    vector<classroom> bigClassroom;
    vector<classroom>smallClassroom;
    vector<program> programs;
    int size;
    vector<service>notChangingCourses;
    vector<service>busyCourses;
    void setProgram();
    bool isBusy(program p);
    bool isIntersect(program p);
    void printScheduler();
    void setElectiveCourses();
    void setServiceCourses();
    void setCompulsoryCourses();
    bool isService(course c);
    void createScheduler();
    void toString();
    void readBusy();
    void readClassroom();
    void readCourses();
    void readService();
    void printBusy();
    void printClassroom();
    void printCourses();
    void printService();

   // void removeCourse();

private:
    string courseDay;
    string courseTime;
    classroom courseClassroom;
    course crs;
};
#endif // SCHEDULER_HPP
