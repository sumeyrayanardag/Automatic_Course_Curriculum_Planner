#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include <iostream>
using namespace std;

#include "course.h"
class electiveCourse : public course
{
    public:
        electiveCourse(){
        }
        electiveCourse(QString courseCode, QString courseName,int year,int credit,QChar depOrServ,QString courseInstructor,QChar compOrEl)
        :course(courseCode,courseName,year,credit,depOrServ,courseInstructor,compOrEl){

        }
        virtual ~electiveCourse(){
        }

};
#endif // ELECTIVECOURSE_H
