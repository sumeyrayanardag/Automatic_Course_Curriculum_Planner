#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QWidget>
#include<QWidgetItem>
#include "scheduler.h"
#include<iostream>
#include<cstdlib>
#include<string>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QStringList>
#include<regex>
#include <QUrl>
#define null

using namespace std;
static int lesson=0;
static int class_i = 0;
static int class_j =0;
std::vector<course> electiveCourses;
 std::vector<course> compulsoryCourses;
 std::vector<classroom> bigClassroom;
std::vector<classroom> smallClassroom;
 std::vector<program> programs;
 std::vector<service> notChangingCourses;
 std::vector<service> busyCourses;


scheduler::scheduler()
{
}
scheduler::~scheduler()
{
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::takecourses(){
    QString courseCode ;
    QString courseName ;
     QString year;

    QString credit;


    QString courseInstructor;
    QString depOrServ;
    QString courseType;
    QString tempLine;
    QFile file("C:\\Users\\Gold-S\\Desktop\\project_2\\sample_files\\courses.csv");
          QTextStream in(&file);
     if(!file.open(QIODevice::ReadOnly)){
             QMessageBox::information(0,"info",file.errorString());}


     while(true){
             tempLine=in.readLine();
             if(tempLine == EOF || tempLine ==""){
                   break;}
else{
 QStringList pieces = tempLine.split( ";" );
            courseCode=pieces.at(0);
             courseName=pieces.at(1);
             year=pieces.at(2);
             credit=pieces.at(3);
               courseType=pieces.at(4);
               depOrServ=pieces.at(5);
               courseInstructor=pieces.at(6);
                 //QMessageBox::information(0,"info",courseInstructor);
               if(courseType=="E")
                   {
                       course temp(courseCode,courseName,year,credit,depOrServ,courseInstructor,courseType);
                       electiveCourses.push_back(temp);

                   }
                   else if(courseType=="C")
                   {
                       course temp(courseCode,courseName,year,credit,depOrServ,courseInstructor,courseType);
                       compulsoryCourses.push_back(temp);

                   }
            }

         }

}
void MainWindow::showcourses(){

    int esize=electiveCourses.size();
    int csize=compulsoryCourses.size();
    QString tempstr="";
    QString tempstrcom="";


 for(int i=0;i<esize;i++){
     tempstr.append(electiveCourses.at(i).getCourseCode()+ " ");
      tempstr.append(electiveCourses.at(i).getCourseName()+ " ");
       tempstr.append(electiveCourses.at(i).getYear()+ " ");
        tempstr.append(electiveCourses.at(i).getCredit()+ " ");
         tempstr.append(electiveCourses.at(i).getcompOrEl()+ " ");
          tempstr.append(electiveCourses.at(i).getdepOrServ()+ " ");
           tempstr.append(electiveCourses.at(i).getCourseInstructor()+ "\n");



 }
 ui->textEdit->setPlainText("Elective Courses\n" + (QString)tempstr);
 for(int i=0;i<csize;i++){
     tempstrcom.append(compulsoryCourses.at(i).getCourseCode()+ " ");
      tempstrcom.append(compulsoryCourses.at(i).getCourseName()+ " ");
       tempstrcom.append(compulsoryCourses.at(i).getYear()+ " ");
        tempstrcom.append(compulsoryCourses.at(i).getCredit()+ " ");
         tempstrcom.append(compulsoryCourses.at(i).getcompOrEl()+ " ");
          tempstrcom.append(compulsoryCourses.at(i).getdepOrServ()+ " ");
           tempstrcom.append(compulsoryCourses.at(i).getCourseInstructor()+ "\n");


 }ui->textEdit->append("Compulsory Courses\n" +(QString)tempstrcom);

}


void MainWindow::on_pushButton_clicked()
{
    takecourses();
    showcourses();
  }


static int small_cnt = 0;
void MainWindow::takeclassroom(){
    QString type=ui->classroomtype->text();



   int number = ui->classroomnumber->text().toInt();

            if(type=="smallClass")
            {
                for(class_j; class_j<number; class_j++)
                {
                    QString newName = type + QString :: number(class_j+1);
                    classroom temp(newName,number);
                    smallClassroom.push_back(temp);
                }

            }
            else if(type=="bigClass")
            {
                for(class_i; class_i<number; class_i++)
                {
                    QString newName = type + QString :: number(class_i+1);
                    classroom temp(newName,number);
                    bigClassroom.push_back(temp);
                }
            }
small_cnt += number;

 }
void MainWindow::showclassrooms(){
       QString temp1="";
       QString temp2="";
       int bclass =bigClassroom.size();
       int sclass=smallClassroom.size();
       for(int i=0; i<bclass; i++)
       {
           temp1.append(bigClassroom[i].getClassroomType()+ "\n");

       }


       for(int j=0; j<sclass; j++)
       {   temp2.append(smallClassroom[j].getClassroomType() + "\n");

       }

         ui->classroom->setPlainText(temp1+temp2);

}
void ::MainWindow::on_classroombutton_clicked(){

    showclassrooms();

}
void::MainWindow::on_newclassroom_clicked(){
     takeclassroom();

     ui->classroomtype->clear();
     ui->classroomnumber->clear();

}
void::MainWindow::takeservice(){


    //ZAMANI GÜNÜ ÖNCEDEN BELİRLİ KURSLAR
    QString courseCode;
    QString courseDay;
    QString courseTime;
    QString tempLine;
      QFile file("C:\\Users\\Gold-S\\Desktop\\project_2\\sample_files\\service.csv");
            QTextStream in(&file);
       if(!file.open(QIODevice::ReadOnly)){
               QMessageBox::information(0,"info",file.errorString());}




      while (true) {
          tempLine=in.readLine();

          if(tempLine==EOF || tempLine=="")
          {

              break;


          }
          else{
               QStringList words=tempLine.split(";");
              courseCode=words.at(0);

              courseDay=words.at(1);
              courseTime=words.at(2);
              service temp(courseCode,courseDay,courseTime);
              notChangingCourses.push_back(temp);


          }
      }


        }

void::MainWindow::showservice(){

    int i;
    int notsize=notChangingCourses.size();
     ui->showservice->setText((QString)notsize);
    QString temp="";
    for(i=0; i<notsize; i++)
    {

        temp.append(notChangingCourses.at(i).getCourseCode()+ " ");
        temp.append(notChangingCourses.at(i).getCourseDay()+ " ");
        temp.append(notChangingCourses.at(i).getCourseTime()+"\n");


   }

ui->showservice->setPlainText(temp);

}
void::MainWindow::on_servicebutton_clicked(){

     takeservice();
    showservice();


}

void::MainWindow::takebusy(){

    QString courseCode=ui->busycode->text();
    QString courseDay=ui->busyday->text();
    QString courseTime=ui->busytime->text();

            service temp(courseCode,courseDay,courseTime);
            busyCourses.push_back(temp);

}

void::MainWindow::showbusy(){



    int i;
    QString temp="";
    int bussize=busyCourses.size();
    for(i=0; i<bussize; i++)
    {

        temp.append(busyCourses.at(i).getCourseCode()+" ");
        temp.append(busyCourses.at(i).getCourseDay()+ " ");
        temp.append(busyCourses.at(i).getCourseTime()+ "\n");
  }

ui->busytext->setPlainText(temp);



}
void::MainWindow::on_showbusy_clicked(){

    showbusy();
}
void::MainWindow::on_newbusy_clicked(){

    takebusy();
    ui->busyday->clear();
    ui->busycode->clear();
    ui->busytime->clear();

}

inline void::MainWindow::setprogram(){

    QString days[]= {"Monday","Tuesday","Wednesday","Thursday","Friday"};
    int bsize=bigClassroom.size();
    int ssize=smallClassroom.size();
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<bsize; j++)
        {
            program temp(days[i],"Morning",bigClassroom.at(j));
            programs.push_back(temp);
        }
        for(int k=0; k<ssize; k++)
        {
            program temp(days[i],"Morning",smallClassroom.at(k));
            programs.push_back(temp);
        }
        for(int j=0; j<bsize; j++)
        {
            program temp(days[i],"Afternoon",bigClassroom.at(j));
            programs.push_back(temp);
        }
        for(int k=0; k<ssize; k++)
        {
            program temp(days[i],"Afternoon",smallClassroom.at(k));
            programs.push_back(temp);
        }
    }


}


void::MainWindow::setServiceCourses(){


    int notsize=notChangingCourses.size();
    int psize=programs.size();
    int esize=electiveCourses.size();
    int csize=compulsoryCourses.size();
    for(int i=0; i<notsize; i++)
    {
        QString code =notChangingCourses.at(i).getCourseCode();
        QString day = notChangingCourses.at(i).getCourseDay();
        QString time = notChangingCourses.at(i).getCourseTime();
        course c;
        for(int j=0; j<esize; j++)
        {
            if(code==electiveCourses.at(j).getCourseCode())
            {

                for(int k=0; k<psize; k++)
                {
                    if((programs.at(k).isEmpty()==true)&&
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
        for(int j=0; j<csize; j++)
        {
            if(code==compulsoryCourses.at(j).getCourseCode())
            {

                for(int k=0; k<psize; k++)
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


bool::MainWindow::isIntersect(program p){

    QString codep = p.getCourse().getCourseCode();
    QString yearp = p.getCourse().getYear();
    QString dayp = p.getDay();
    QString timep = p.getTime();
    int psize =programs.size();
    for(int i=0; i<psize; i++)
    {
        QString code = programs.at(i).getCourse().getCourseCode();
        QString year = programs.at(i).getCourse().getYear();
        QString day = programs.at(i).getDay();
        QString time = programs.at(i).getTime();
        if(yearp==year&&codep!=code&&dayp==day&&timep==time)
        {
            return true;
        }
    }
    return false;

}

void::MainWindow::setCompulsoryCourses(){

    int csize=compulsoryCourses.size();

    srand (time(0));

      for(int i=0; i<csize; i++)
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
                              //programs[random].deleteCourse();
                          }
                      }
                  }
              }
          }
      }


}
bool::MainWindow::isService(course c){

        if(c.getdepOrServ()=="S")
        {
            return true;
        }
      return false;

}
bool::MainWindow::isBusy(program p){


        QString codep=p.getCourse().getCourseCode();
        QString dayp=p.getDay();
        QString timep=p.getTime();
        int busysize=busyCourses.size();
        for(int i=0; i<busysize; i++)
        {
            QString code=busyCourses.at(i).getCourseCode();
            QString day=busyCourses.at(i).getCourseDay();
            QString time =busyCourses.at(i).getCourseTime();
            if(code==codep&&day==dayp&&time==timep)
            {
                return true;
            }
        }
        return false;


}

void::MainWindow::setElectiveCourses(){

    int esize=electiveCourses.size();

       srand (time(0));

          for(int i=0; i<esize; i++)
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
                                 // programs[random].deleteCourse();
                              }
                          }
                      }
                  }
              }
          }

}

void::MainWindow::showscheduler(){
    int psize=programs.size();
    QString temp="";

        for(int i=0; i<psize; i++)
        {
            temp.append(programs.at(i).getDay());
            temp.append(programs.at(i).getTime());
            temp.append(programs.at(i).getClassroom().getClassroomType());
            temp.append(programs.at(i).getCourse().getCourseCode());
            temp.append(programs.at(i).getCourse().getCourseName());
            temp.append(programs.at(i).getCourse().getcompOrEl());
            temp.append(programs.at(i).getCourse().getYear());
       }

}
void::MainWindow::createScheduler(){


    int minCoutSlotSize = compulsoryCourses.size()+electiveCourses.size();
        setprogram();
        const int timeSlot =10;
        int realSize = programs.size();
        if(realSize>=minCoutSlotSize&&bigClassroom.size()*timeSlot>=compulsoryCourses.size())
        {
            setServiceCourses();
            setCompulsoryCourses();
            setElectiveCourses();
            if(lesson==minCoutSlotSize)
            {
                showscheduler();
            }
            else
            {

                for(int i=0;i<10;i++){
                for(int k=0;k<4;k++){


                            QTableWidgetItem *ite = new QTableWidgetItem();
                           ite->setText("");
                            ui->table->setItem(i, k, ite);

                             }
            }

                QMessageBox::information(0,"info","There is NO suitable schedule!!");

            }
        }
        else
        {

            for(int i=0;i<10;i++){
                for(int k=0;k<4;k++){


                            QTableWidgetItem *ite = new QTableWidgetItem();
                           ite->setText("");
                            ui->table->setItem(i, k, ite);

                             }
            }
            QMessageBox::information(0,"info","Increase the class");

        }



}
void::MainWindow::on_create_clicked(){

    createScheduler();

}
void::MainWindow::on_schedulerbutton_clicked(){


    showscheduler();

}


void::MainWindow::on_b_create_clicked(){

    programs.erase( programs.begin(), programs.end() );

        createScheduler();

        ui->table->clearContents();
            ui->table->setRowCount(0);

        ui->table->setColumnCount(4);  //bigClassroom.size()+smallClassroom.size()
        ui->table->setRowCount(10);

        QTableWidgetItem *monday_m = new QTableWidgetItem();
        monday_m->setText("Monday Morning");
        ui->table->setVerticalHeaderItem(0,monday_m);
        QTableWidgetItem *monday_a = new QTableWidgetItem();
        monday_a->setText("Monday Afternoon");
        ui->table->setVerticalHeaderItem(1,monday_a);

        QTableWidgetItem *tuesday_m = new QTableWidgetItem();
        tuesday_m->setText("Tuesday Morning");
        ui->table->setVerticalHeaderItem(2,tuesday_m);
        QTableWidgetItem *tuesday_a = new QTableWidgetItem();
        tuesday_a->setText("Tuesday Afternoon");
        ui->table->setVerticalHeaderItem(3,tuesday_a);

        QTableWidgetItem *wednesday_m = new QTableWidgetItem();
        wednesday_m->setText("Wednesday Morning");
        ui->table->setVerticalHeaderItem(4,wednesday_m);
        QTableWidgetItem *wednesday_a = new QTableWidgetItem();
        wednesday_a->setText("Wednesday Afternoon");
        ui->table->setVerticalHeaderItem(5,wednesday_a);

        QTableWidgetItem *thursday_m = new QTableWidgetItem();
        thursday_m->setText("Thursday Morning");
        ui->table->setVerticalHeaderItem(6,thursday_m);
        QTableWidgetItem *thursday_a = new QTableWidgetItem();
        thursday_a->setText("Thursday Afternoon");
        ui->table->setVerticalHeaderItem(7,thursday_a);

        QTableWidgetItem *friday_m = new QTableWidgetItem();
        friday_m->setText("Friday Morning");
        ui->table->setVerticalHeaderItem(8,friday_m);
        QTableWidgetItem *friday_a = new QTableWidgetItem();
        friday_a->setText("Friday Afternoon");
        ui->table->setVerticalHeaderItem(9,friday_a);


        for(int i=0; i<4;i++)
        {

            QTableWidgetItem *big = new QTableWidgetItem();
            QString newName = QString :: number(i+1) + ".Year"  ;
            big->setText(newName);


            ui->table->setHorizontalHeaderItem(i,big);
        }


        int p_size = programs.size();

      QStringList str;
      str << "1" << "2"<< "3"<< "4";

        for(int i=0;i<p_size;i++){
            for(int k=0;k<4;k++){

            if(programs.at(i).getCourse().getYear() == str.at(k)){
                if(programs.at(i).getDay() == "Monday"){
                    if(programs.at(i).getTime() == "Morning"){
                        QTableWidgetItem *ite = new QTableWidgetItem();
                        QString newName = programs.at(i).getCourse().getCourseCode() + "\n" + programs.at(i).getClassroom().getClassroomType() ;
                        ite->setText(newName);
                        ui->table->setItem(0, k, ite);
                    }
                    else{
                        QTableWidgetItem *ite = new QTableWidgetItem();
                        QString newName = programs.at(i).getCourse().getCourseCode() + "\n" +  programs.at(i).getClassroom().getClassroomType() ;
                        ite->setText(newName);
                        ui->table->setItem(1, k, ite);
                    }
                }
                else if(programs.at(i).getDay() == "Tuesday"){
                    if(programs.at(i).getTime() == "Morning"){
                        QTableWidgetItem *ite = new QTableWidgetItem();
                        QString newName = programs.at(i).getCourse().getCourseCode() + "\n" + programs.at(i).getClassroom().getClassroomType() ;
                        ite->setText(newName);
                        ui->table->setItem(2, k, ite);
                    }
                    else{
                        QTableWidgetItem *ite = new QTableWidgetItem();
                        QString newName = programs.at(i).getCourse().getCourseCode() +"\n" +  programs.at(i).getClassroom().getClassroomType() ;
                        ite->setText(newName);
                        ui->table->setItem(3, k, ite);
                    }
                }
                else if(programs.at(i).getDay() == "Wednesday"){
                    if(programs.at(i).getTime() == "Morning"){
                        QTableWidgetItem *ite = new QTableWidgetItem();
                        QString newName = programs.at(i).getCourse().getCourseCode() +"\n" +  programs.at(i).getClassroom().getClassroomType() ;
                        ite->setText(newName);
                        ui->table->setItem(4, k, ite);
                    }
                    else{
                        QTableWidgetItem *ite = new QTableWidgetItem();
                        QString newName = programs.at(i).getCourse().getCourseCode() +"\n" +  programs.at(i).getClassroom().getClassroomType() ;
                        ite->setText(newName);
                        ui->table->setItem(5, k, ite);
                    }
                 }
                else if(programs.at(i).getDay() == "Thursday"){
                    if(programs.at(i).getTime() == "Morning"){
                        QTableWidgetItem *ite = new QTableWidgetItem();
                        QString newName = programs.at(i).getCourse().getCourseCode() + "\n" + programs.at(i).getClassroom().getClassroomType() ;
                        ite->setText(newName);
                        ui->table->setItem(6, k, ite);
                    }
                    else{
                        QTableWidgetItem *ite = new QTableWidgetItem();
                        QString newName = programs.at(i).getCourse().getCourseCode() +"\n" +  programs.at(i).getClassroom().getClassroomType() ;
                        ite->setText(newName);
                        ui->table->setItem(7, k, ite);
                    }


                 }
                else if(programs.at(i).getDay() == "Friday"){
                    if(programs.at(i).getTime() == "Morning"){
                        QTableWidgetItem *ite = new QTableWidgetItem();
                        QString newName = programs.at(i).getCourse().getCourseCode() +"\n" +  programs.at(i).getClassroom().getClassroomType() ;
                        ite->setText(newName);
                        ui->table->setItem(8, k, ite);
                    }
                    else{
                        QTableWidgetItem *ite = new QTableWidgetItem();
                        QString newName = programs.at(i).getCourse().getCourseCode() +"\n" +  programs.at(i).getClassroom().getClassroomType() ;
                        ite->setText(newName);
                        ui->table->setItem(9, k, ite);
                    }
                }
}
        }

}}

void::MainWindow::on_b_delete_clicked(){
    for(int i=0;i<10;i++){
        for(int k=0;k<4;k++){


                    QTableWidgetItem *ite = new QTableWidgetItem();
                   ite->setText("");
                    ui->table->setItem(i, k, ite);

                     }
    }
    programs.erase( programs.begin(), programs.end() );


}
