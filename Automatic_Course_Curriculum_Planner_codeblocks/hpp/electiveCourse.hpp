using namespace std;

#include "course.hpp"
class electiveCourse : public course
{
    public:
        electiveCourse(){
        }
        electiveCourse(string courseCode, string couseName,int year,int credit,char depOrServ,string courseInsructor,char compOrEl)
        :course(courseCode,courseName,year,credit,depOrServ,courseInstructor,compOrEl);
        {

        }
        virtual ~electiveCourse(){
        }

};


