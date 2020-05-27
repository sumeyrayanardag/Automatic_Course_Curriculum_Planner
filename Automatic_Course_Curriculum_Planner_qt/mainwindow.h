#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<scheduler.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


     void takecourses();
     void showcourses();
     void takeclassroom();
     void showclassrooms();
     void on_classroombutton_clicked();
     void takeservice();
     void showservice();
     void takebusy();
     void showbusy();
     void on_servicebutton_clicked();
     void on_showbusy_clicked();
     void setprogram();
     void setServiceCourses();
     bool isIntersect(program);
     void setCompulsoryCourses();
     void setElectiveCourses();
     void showscheduler();
     bool isService(course);
     bool isBusy(program);
     void createScheduler();
     void on_schedulerbutton_clicked();

     void on_create_clicked();

     void on_newclassroom_clicked();


     void on_newbusy_clicked();

     void on_b_create_clicked();

  //   void on_b_showscheduler_clicked();

   //  void on_button_clicked();

    // void on_button2_clicked();

   //  void on_b_showscheduler_clicked();

     void on_b_delete_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
