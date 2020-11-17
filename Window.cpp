//Window.cpp
//Implementation file for Window class
#include "Window.h"

//Constructors/Destructors
Window::Window(){
  //student = NULL;
  windowState = 0;
  idleTime = 0;
}
// Window::Window(Student *s){
//   student = s;
//   windowState = 1;
//   idleTime = 0;
// }
Window::Window(int a){
  processTime = a;
  windowState = 1;
  idleTime = 0;
}
Window::~Window(){
  delete this;
}

//Methods
bool Window::getWindowState(){
  return windowState;
}
void Window::changeWindowState(){
  windowState = !windowState;
}
void Window::tickIdleTime(){
  idleTime++;
}
int Window::getIdleTime(){
  return idleTime;
}
int Window::popIdleTime(){

}
//Student methods
int Window::getTime(){
  //return student->getTime();
  return processTime;
}
void Window::timeTick(){
  //student->timeTick();
  processTime--;
}
void Window::nextStudent(int s){
  //student = s;
  processTime = s;
  this->changeWindowState();
}
