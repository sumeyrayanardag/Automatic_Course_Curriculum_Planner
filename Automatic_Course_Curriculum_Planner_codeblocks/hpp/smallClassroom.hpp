#include"clasroom.hpp"
class smallClassroom : public classroom{
    public:
        ~smallClassroom(){
        }
        smallClassroom(string name,int number){
            classroom(name,number);
        }



};

