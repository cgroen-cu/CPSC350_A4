//student.cpp
//Implementation file for student class
#include "student.h"

Student::Student(){}

Student::Student(int a, int p){
  arrivalTime = a;
  processingTime = p;
  waitTimes = 0;
}

Student::Student(Student *s){
  processingTime = s->getTime();
}

bool Student::timeTick(){
  if(processingTime == 0){
    return 0;
  } else {
    processingTime--;
    return 1;
  }
}

int Student::getTime(){
  return processingTime;
}

int Student::getArrivalTime(){
  return arrivalTime;
}

void Student::waitTick(){
  cout << "WAITTICK" << endl;
  waitTimes++;
  cout << waitTimes << endl;
}

int Student::getWait(){
  return waitTimes;
}
