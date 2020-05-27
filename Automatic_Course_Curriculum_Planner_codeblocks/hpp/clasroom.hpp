#ifndef CLASSROOM_HPP
#define CLASSROOM_HPP
#include<iostream>
#include<string>
using namespace std;
class classroom{

     public:
         ~classroom(){
        }
        classroom(string type,int number){
            this->classroomType=type;
            this->number=number;
        }
        classroom(){
        }
        string getClassroomType(){
        return this->classroomType;}
        void setNumber(int number){
        this->number=number;}
        int getNumber(){
        return this->number;}
     private:
        string classroomType;
        int number;

};
#endif
