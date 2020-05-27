#ifndef CLASSROOM_H
#define CLASSROOM_H

#include<iostream>
#include<string>
#include<QObject>
using namespace std;
class classroom{

     public:
         ~classroom(){
        }
        classroom(QString type,int number){
            this->classroomType=type;
            this->number=number;
        }
        classroom(){
        }
        QString getClassroomType(){
        return this->classroomType;}
        void setNumber(int number){
        this->number=number;}
        int getNumber(){
        return this->number;}
     private:
        QString classroomType;
        int number;

};
#endif
