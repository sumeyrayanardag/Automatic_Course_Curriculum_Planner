#ifndef COURSE_H
#define COURSE_H

#include<iostream>
#include<string>
#include<QObject>
using namespace std;

class course
{
    public:
        course(QString courseCode, QString couseName,QString year,QString credit,QString depOrServ,QString courseInsructor,QString compOrEl){
            this->courseCode=courseCode;
            this->couseName=couseName;
            this->year=year;
            this->credit=credit;
            this->depOrServ=depOrServ;
            this->courseInsructor=courseInsructor;
            this->compOrEl = compOrEl;
        }

        ~course(){
        }
        course(){
        }
        QString getCourseCode(){
        return this->courseCode;}
        QString getCourseName(){
        return this->couseName;}
        QString getYear(){
        return this->year;}
        QString getdepOrServ(){
        return this->depOrServ;}
        QString getCourseInstructor(){
        return this->courseInsructor;}
        QString getCredit(){
        return this->credit;}
        QString getcompOrEl(){
        return this->compOrEl;}
        void setCourseCode(QString code){
        this->courseCode=code;}

    private:
        QString courseCode;
        QString couseName;
        QString year;
        QString credit;
        QString depOrServ;
        QString compOrEl;
        QString courseInsructor;
};
#endif

