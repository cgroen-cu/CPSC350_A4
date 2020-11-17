//student.h
//Header file for student class
using namespace std;
#include<iostream>

class Student{
public:
  Student();
  Student(int a, int p);  //Overload constructor taking ints for arrival and processing time
  Student(Student *s);
  bool timeTick(); //Method used to deincriment processing time
  int getTime();  //method used to retrieve the processing time
  int getArrivalTime();
  void waitTick(); //increment wait tme
  int getWait();  //returns wait time

private:
  int arrivalTime;
  int processingTime;
  int waitTimes;
};
