#ifndef PROGRAM_H
#define PROGRAM_H
#include<QObject>
#include<iostream>
#include<string>
#include"course.h"
#include"classroom.h"
using namespace std;
class program
{

public:


    ~program()
    {
    }
    program(QString day,QString time,classroom cr)
    {
        this->day=day;
        this->time=time;
        this->cr=cr;
        this->check=true;
    }void operator --()
    {
        course d;
        c=d;
        check=true;
    }

void setDay(QString day="Monday"){
        this->day = day;
    }
    void setCourse(course c)
    {
        this->c=c;
        check=false;
    }
    program()
    {
    }
    QString getDay()
    {
        return this->day;
    }
    QString getTime()
    {
        return this->time;
    }
    classroom getClassroom()
    {
        return this->cr;
    }
    course getCourse()
    {
        return this->c;
    }
    bool isEmpty(){
        return this->check;
    }
    void deleteCourse()
      {
          course d;
          c=d;
          check=true;
      }

private:
    QString day;
    QString time;
    classroom cr;
    course c;
    bool check;//true ise boþ

};

#endif
