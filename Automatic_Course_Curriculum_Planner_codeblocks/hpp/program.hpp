#ifndef PROGRAM_HPP
#define PROGRAM_HPP
#include<iostream>
#include<string>
#include"course.hpp"
#include"clasroom.hpp"
using namespace std;
class program
{

public:
    ~program()
    {
    }
    program(string day,string time,classroom cr)
    {
        this->day=day;
        this->time=time;
        this->cr=cr;
        this->check=true;
    }
    void setCourse(course c)
    {
        this->c=c;
        check=false;
    }
    void setDay(string day="Monday"){
        this->day = day;
    }
    program()
    {
    }
    string getDay()
    {
        return this->day;
    }
    string getTime()
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
   /* void deleteCourse()
    {
        course d;
        c=d;
        check=true;
    }*/
     void operator --()
    {
        course d;
        c=d;
        check=true;
    }

private:
    string day;
    string time;
    classroom cr;
    course c;
    bool check;//true ise boþ

};

#endif
