//Statistics.h
//Header file for Statistics Class
//This class takes in data from the program and computes it to output statistics
/* Calculates:
1.The mean student wait time.
2.The median student wait time.
3.The longest student wait time.
4.The number of students waiting over 10 minutes
5.The mean window idle time
6.The longest window idle time
7.Number of windows idle for over 5 minutes. */
using namespace std;
#include <string>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <iostream>


class Statistics{
public:
  Statistics();
  void newStudent(int p);  //Method called when making new student - checks with student statistics
  void newIdle(int d); //Called when window stops being idle - calculates stats
  void calculate(); //Calculates stats
  string printStats();  //converts stats to string and returns
private:
  //Student Statistics Variables
  double StudentMean;
  double median;
  int studentMedian[100];
  int longestWait; //Int holding the longest wait time ()
  int numStudents;  //Int holding the number of students
  int StudentProcessTime; //Int holding the total student processing time
  int StudentLongWait;  //Holding number of students waiting over 10 min

  //Wndow Statistics Variables
  int numIdle; //number of times windows idle used for mean
  int sumIdle; //Sum of idle time
  int meanIdle;
  int longestIdle;
  int longIdle;
};
