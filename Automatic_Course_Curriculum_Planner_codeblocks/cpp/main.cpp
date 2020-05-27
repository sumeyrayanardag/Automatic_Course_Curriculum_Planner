
#include<iostream>
#include"scheduler.hpp"
#include<cstdlib>
#include<string>
using namespace std;

int main()
{
    scheduler s;
    s.readCourses();
    //s.printCourses();
    s.readClassroom();
    //s.printClassroom();
    s.readService();
    //s.printService();
    s.readBusy();
    //s.printBusy();
    s.createScheduler();
}
