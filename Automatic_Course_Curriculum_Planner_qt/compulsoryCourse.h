#ifndef COMPULSORYCOURSE_H
#define COMPULSORYCOURSE_H
#include<iostream>
#include<string>
using namespace std;
#include"course.h"

class compulsoryCourse : public course
{
    public:
        compulsoryCourse(){
        }
        compulsoryCourse(QString courseCode, QString courseName,int year,int credit,QChar depOrServ,QString courseInstructor,QChar compOrEl)
        {
            course(courseCode,courseName,year,credit,depOrServ,courseInstructor,compOrEl);
        }
        virtual ~compulsoryCourse(){
        }

};

#endif // COMPULSORYCOURSE_H
