#ifndef COURSE_HPP
#define COURSE_HPP
#include<iostream>
#include<string>

using namespace std;

class course
{
    public:
        course(string courseCode, string couseName,int year,int credit,char depOrServ,string courseInsructor,char compOrEl){
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
        string getCourseCode(){
        return this->courseCode;}
        string getCourseName(){
        return this->couseName;}
        int getYear(){
        return this->year;}
        char getdepOrServ(){
        return this->depOrServ;}
        string getCourseInstructor(){
        return this->courseInsructor;}
        int getCredit(){
        return this->credit;}
        char getcompOrEl(){
        return this->compOrEl;}
        void setCourseCode(string code){
        this->courseCode=code;}

    private:
        string courseCode;
        string couseName;
        int year=0;
        int credit;
        char depOrServ;
        char compOrEl;
        string courseInsructor;
};
#endif
