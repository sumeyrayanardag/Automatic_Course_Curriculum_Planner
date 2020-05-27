#ifndef BIGCLASSROOM_H
#define BIGCLASSROOM_H
#include <QObject>
#include<classroom.h>

class bigClassroom : public classroom{
public:
    bigClassroom();
   bigClassroom(QString name,int number){
               classroom(name,number);

};

#endif // BIGCLASSROOM_H
};
