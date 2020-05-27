using namespace std;
#include"course.hpp"

class compulsoryCourse : public course
{
    public:
        compulsoryCourse(){
            //constructor
        }
        compulsoryCourse(string courseCode, string couseName,int year,int credit,char depOrServ,string courseInsructor,char compOrEl)
        {
            course(courseCode,courseName,year,credit,depOrServ,courseInstructor,compOrEl);
        }
        virtual ~compulsoryCourse(){
            //destructor
        }

};
