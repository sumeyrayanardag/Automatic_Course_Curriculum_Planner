#ifndef SERVICE_H
#define SERVICE_H
#include<QString>
#include<iostream>
#include<string>
using namespace std;

//THIS CLASS FOR BUSY CSV AND SERVICE CSV
class service{
public:
    service(){
    }
    ~service(){
        }
    service(QString code,QString day,QString time){
    this->courseCode=code;
    this->courseDay=day;
    this->courseTime=time;
    }
    QString getCourseCode(){
    return this->courseCode;}
    QString getCourseDay(){
    return this->courseDay;}
    QString getCourseTime(){
    return this->courseTime;}
private:
    QString courseCode;
    QString courseDay;
    QString courseTime;


};
#endif
