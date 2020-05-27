#ifndef SERVICE_HPP
#define SERVICE_HPP
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
    service(string code,string day,string time){
    this->courseCode=code;
    this->courseDay=day;
    this->courseTime=time;
    }
    string getCourseCode(){
    return this->courseCode;}
    string getCourseDay(){
    return this->courseDay;}
    string getCourseTime(){
    return this->courseTime;}
private:
    string courseCode;
    string courseDay;
    string courseTime;


};
#endif
