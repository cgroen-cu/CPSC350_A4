//Window.h
//header file for windows class
#include "student.h"

class Window{
private:
  bool windowState; //1 = closed 0 = open
  //Student *student;  //Holds the student in the window
  int idleTime;
  int processTime;
public:
  //Constructors/Destructor
  Window();
  //Window(Student *s);
  Window(int a);
  ~Window();
  //Methods
  bool getWindowState(); //returns window's state, 1=closed,0=open
  void changeWindowState(); //Changes the windows state
  void tickIdleTime();  //Increments idleTime
  int getIdleTime(); //returns the time idle of window
  int popIdleTime(); //returns the idle time of window and resets it to 0
  //Student Management
  int getTime(); //calls students getTime
  void timeTick(); //calls students timeTick
  void nextStudent(int s); //puts in new student's time

};
