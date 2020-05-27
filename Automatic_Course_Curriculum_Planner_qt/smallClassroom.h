//#ifndef SMALLCLASSROOM_H
#define SMALLCLASSROOM_H

#include"classroom.h"
class smallClassroom : public classroom{
    public:
        ~smallClassroom(){
        }
        smallClassroom(QString name,int number){
            classroom(name,number);
        }



};
