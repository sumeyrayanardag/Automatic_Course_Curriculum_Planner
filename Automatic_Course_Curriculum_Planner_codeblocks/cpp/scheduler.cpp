#include "scheduler.hpp"
#include<string>
#include<iostream>
#include<cstdlib>
#include<string>
#define NULL

using namespace std;
static int lesson=0;
scheduler::scheduler()
{
}
scheduler::~scheduler()
{
}
void scheduler::toString()
{
    cout<<this->crs.getCourseCode()<<" "
        <<this->crs.getCourseName()<<" "
        <<this->courseClassroom.getClassroomType()<<" "
        <<this->courseDay<<" "<<this->courseTime<<endl;
}
void scheduler::readCourses()
{
    ifstream read;
    string courseName;
    string courseCode;
    int year;
    int credit;
    char courseType;
    char depOrServ;
    char symbol;
    string courseInstructor;

    try
    {
        read.open("courses.csv");
        while(true)
        {
            if(read.eof())
            {
                break;
            }

            getline(read,courseCode,';');
            getline(read,courseName,';');
            read>>year;
            read.get(symbol);
            read>>credit;
            read.get(symbol);
            read.get(courseType);
            read.get(symbol);
            read.get(depOrServ);
            read.get(symbol);
            getline(read,courseInstructor,'\n');
            if(courseType=='E')
            {
                course temp(courseCode,courseName,year,credit,depOrServ,courseInstructor,courseType);
                electiveCourses.push_back(temp);
                size++;
            }
            else if(courseType=='C')
            {
                course temp(courseCode,courseName,year,credit,depOrServ,courseInstructor,courseType);
                compulsoryCourses.push_back(temp);
                size++;
            }


        }
    }
    catch(...)
    {
        cout << "Fail!"<<endl;
    }
    read.close();
}
void scheduler::printCourses()
{
    cout<<"Elective Courses"<<endl;
    int i;
    for(i=0; i<electiveCourses.size(); i++)
    {
        cout<<electiveCourses[i].getCourseCode()<<" "
            <<electiveCourses[i].getCourseName()<<" "
            <<electiveCourses[i].getYear()<<" "
            <<electiveCourses[i].getCredit()<<" "
            <<electiveCourses[i].getdepOrServ()<<" "
            <<electiveCourses[i].getCourseInstructor()<<" "
            <<endl;
    }
    cout<<"Compulsive Courses"<<endl;
    cout<<""<<endl;
    int j;
    for(j=0; j<compulsoryCourses.size(); j++)
    {
        cout<<compulsoryCourses[j].getCourseCode()<<" "
            <<compulsoryCourses[j].getCourseName()<<" "
            <<compulsoryCourses[j].getYear()<<" "
            <<compulsoryCourses[j].getCredit()<<" "
            <<compulsoryCourses[j].getdepOrServ()<<" "
            <<compulsoryCourses[j].getCourseInstructor()<<" "
            <<endl;
    }
}
void scheduler::readClassroom()
{
    string type;
    int number;
    ifstream read;
    try
    {
        read.open("classroom.csv");
        while(true)
        {
            if(read.eof())
            {
                break;
            }
            getline(read,type,';');
            read>>number;
            int i;
            if(type=="smallClass")
            {
                for(i=0; i<number; i++)
                {
                    string newName = type + to_string(i+1);
                    classroom temp(newName,number);
                    smallClassroom.push_back(temp);
                }

            }
            else if(type=="bigClass")
            {
                for(i=0; i<number; i++)
                {
                    string newName = type + to_string(i+1);
                    classroom temp(newName,number);
                    bigClassroom.push_back(temp);
                }
            }
            read.get();
        }

        read.close();
    }
    catch(...)
    {
        cout<<"fail"<<endl;
    }

}
void scheduler::printClassroom()
{
    int i;
    cout<<"big classroom names:"<<endl;
    for(i=0; i<bigClassroom.size(); i++)
    {
        cout<<bigClassroom[i].getClassroomType()<<endl;
    }
    int j;
    cout<<"small classroom names:"<<endl;

    for(j=0; j<smallClassroom.size(); j++)
    {
        cout<<smallClassroom[j].getClassroomType()<<endl;
    }

}
void scheduler::readService()
{
    //ZAMANI GÜNÜ ÖNCEDEN BELIRLI KURSLAR
    string courseCode;
    string courseDay;
    string courseTime;
    ifstream read;
    try
    {
        read.open("service.csv");
        while(true)
        {
            if(read.eof())
            {
                break;
            }
            getline(read,courseCode,';');
            getline(read,courseDay,';');
            getline(read,courseTime,'\n');
            service temp(courseCode,courseDay,courseTime);
            notChangingCourses.push_back(temp);
        }


        read.close();
    }
    catch(...)
    {
        cout<<"fail"<<endl;
    }

}
void scheduler::printService()
{
    int i;
    for(i=0; i<notChangingCourses.size(); i++)
    {
        cout<<notChangingCourses[i].getCourseCode()<<" "<<notChangingCourses[i].getCourseDay()<<" "<<notChangingCourses[i].getCourseTime()<<endl;
    }
}
void scheduler::readBusy()
{
    string courseCode;
    string courseDay;
    string courseTime;
    ifstream read;
    try
    {
        read.open("busy.csv");
        while(true)
        {
            if(read.eof())
            {
                break;
            }
            getline(read,courseCode,';');
            getline(read,courseDay,';');
            getline(read,courseTime,'\n');
            service temp(courseCode,courseDay,courseTime);
            busyCourses.push_back(temp);
        }
        read.close();
    }
    catch(...)
    {
        cout<<"Fail";
    }
}
void scheduler::printBusy()
{
    int i;
    for(i=0; i<busyCourses.size(); i++)
    {
        cout<<busyCourses[i].getCourseCode()<<" "<<busyCourses[i].getCourseDay()<<" "<<busyCourses[i].getCourseTime()<<endl;
    }
}
inline void scheduler::setProgram()
{
    string days[]= {"Monday","Tuesday","Wednesday","Thursday","Friday"};
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<bigClassroom.size(); j++)
        {
            program temp(days[i],"Morning",bigClassroom.at(j));
            programs.push_back(temp);
        }
        for(int k=0; k<smallClassroom.size(); k++)
        {
            program temp(days[i],"Morning",smallClassroom.at(k));
            programs.push_back(temp);
        }
        for(int j=0; j<bigClassroom.size(); j++)
        {
            program temp(days[i],"Afternoon",bigClassroom.at(j));
            programs.push_back(temp);
        }
        for(int k=0; k<smallClassroom.size(); k++)
        {
            program temp(days[i],"Afternoon",smallClassroom.at(k));
            programs.push_back(temp);
        }
    }

}
void scheduler::setServiceCourses()
{
    for(int i=0; i<notChangingCourses.size(); i++)
    {
        string code =notChangingCourses.at(i).getCourseCode();
        string day = notChangingCourses.at(i).getCourseDay();
        string time = notChangingCourses.at(i).getCourseTime();
        course c;
        for(int j=0; j<electiveCourses.size(); j++)
        {
            if(code==electiveCourses.at(j).getCourseCode())
            {

                for(int k=0; k<programs.size(); k++)
                {
                    if(programs.at(k).isEmpty()==true&&
                            programs.at(k).getDay()== day &&
                            programs.at(k).getTime()==time)
                    {
                        if( programs.at(k).getClassroom().getClassroomType().at(0)=='b')
                        {
                            c = electiveCourses.at(j);
                            programs.at(k).setCourse(c);
                            lesson++;
                            break;
                        }
                        else
                        {
                            c = electiveCourses.at(j);
                            programs.at(k).setCourse(c);
                            lesson++;
                            break;
                        }

                    }
                }
            }
        }
        for(int j=0; j<compulsoryCourses.size(); j++)
        {
            if(code==compulsoryCourses.at(j).getCourseCode())
            {

                for(int k=0; k<programs.size(); k++)
                {

                    if(programs.at(k).isEmpty()==true
                            &&programs.at(k).getDay().compare(day)==0
                            && programs.at(k).getTime()==time
                            &&programs.at(k).getClassroom().getClassroomType().at(0)=='b')
                    {
                        c = compulsoryCourses.at(j);
                        programs.at(k).setCourse(c);
                        lesson++;
                        break;
                    }
                }
            }
        }
    }
}
bool scheduler::isService(course c)
{
    if(c.getdepOrServ()=='S')
    {
        return true;
    }
    else false;
}
bool scheduler::isBusy(program p)
{
    string codep=p.getCourse().getCourseCode();
    string dayp=p.getDay();
    string timep=p.getTime();
    for(int i=0; i<busyCourses.size(); i++)
    {
        string code=busyCourses.at(i).getCourseCode();
        string day=busyCourses.at(i).getCourseDay();
        string time =busyCourses.at(i).getCourseTime();
        if(code==codep&&day==dayp&&time==timep)
        {
            return true;
        }
    }
    return false;

}
bool scheduler::isIntersect(program p)
{
    string codep = p.getCourse().getCourseCode();
    int yearp = p.getCourse().getYear();
    string dayp = p.getDay();
    string timep = p.getTime();
    for(int i=0; i<programs.size(); i++)
    {
        string code = programs.at(i).getCourse().getCourseCode();
        int year = programs.at(i).getCourse().getYear();
        string day = programs.at(i).getDay();
        string time = programs.at(i).getTime();
        if(yearp==year&&codep!=code&&dayp==day&&timep==time)
        {
            return true;
        }
    }
    return false;
}
void scheduler::setCompulsoryCourses()
{
    srand (time(0));

    for(int i=0; i<compulsoryCourses.size(); i++)
    {
        int flag=0;
        int random;
        if(!isService(compulsoryCourses.at(i)))
        {
            while(flag==0)
            {
                random = rand()%programs.size();
                if(programs.at(random).isEmpty()&&programs[random].getClassroom().getClassroomType().at(0)=='b')
                {
                    flag=1;
                    programs[random].setCourse(compulsoryCourses[i]);
                    if(!(isBusy(programs.at(random))))
                    {

                        if(!(isIntersect(programs.at(random))))
                        {
                            flag=1;
                            lesson++;
                        }
                        else
                        {
                            flag=0;
                            --programs[random];
                        }
                    }
                }
            }
        }
    }
}

void scheduler::setElectiveCourses()
{
    srand (time(0));

    for(int i=0; i<electiveCourses.size(); i++)
    {
        int flag=0;
        int random;
        if(!isService(electiveCourses.at(i)))
        {
            while(flag==0)
            {
                random = rand()%programs.size();
                if(programs.at(random).isEmpty())
                {
                    flag=1;
                    programs[random].setCourse(electiveCourses[i]);
                    if(!(isBusy(programs.at(random))))
                    {
                        if((!isIntersect(programs.at(random))))
                        {
                            flag=1;
                            lesson++;
                        }
                        else
                        {
                            flag=0;
                            --programs[random];
                        }
                    }
                }
            }
        }
    }

}
void scheduler::printScheduler()
{
    for(int i=0; i<programs.size(); i++)
    {
        cout<<programs.at(i).getDay()<<" "<<programs.at(i).getTime()<<" "<<programs.at(i).getClassroom().getClassroomType();
        if(programs.at(i).getCourse().getYear()>0)
        {
            cout<< programs.at(i).getCourse().getCourseCode()<<" "
                <<programs.at(i).getCourse().getCourseName()<<" "
                <<programs.at(i).getCourse().getYear()
                <<endl;
        }
        else
        {
            cout<<"-----------"<<endl;
        }

    }
    cout<<"Number of Lesson:"<<lesson<<endl;
}
void scheduler::createScheduler()
{

    int minCoutSlotSize = compulsoryCourses.size()+electiveCourses.size();
    setProgram();
    const int timeSlot =10;
    int realSize = programs.size();
    if(realSize>=minCoutSlotSize&&bigClassroom.size()*timeSlot>=compulsoryCourses.size())
    {
        setServiceCourses();
        setCompulsoryCourses();
        setElectiveCourses();
        if(lesson==minCoutSlotSize)
        {
            printScheduler();
        }
        else
        {
            cout<<"cannot find avaible scheduler,try again!"<<endl;
        }
    }
    else
    {
        cout<<"increase class number"<<endl;
    }
}


