//Statistics.cpp
//implementation file for Stastics class
#include "Statistics.h"

Statistics::Statistics(){
  //Student Stats
  //StudentMean = 0;
  median = 0;
  longestWait = 0;
  numStudents = 0;
  StudentProcessTime = 0;
  StudentLongWait = 0;
  StudentMean = 0;

  //Window Stats
  numIdle = 0;
  sumIdle = 0;
  meanIdle = 0;
  longestIdle = 0;
  longIdle = 0;
}

void Statistics::newStudent(int p){
  if (p==0){
  } else {
    //For mean
    numStudents++;
    StudentProcessTime += p;
    if (p > longestWait){
      longestWait = p;
    }
    if(p > 10){
      StudentLongWait++;
    }
    //Sort into list
    studentMedian[numStudents] = p;
  }

}

void Statistics::newIdle(int d){
  numIdle++;
  sumIdle += d;

  if(d>longestIdle){
    longestIdle = d;
  }
  if(d > 5){
    longIdle++;
  }
}

void Statistics::calculate(){
  int x = 0;
  int y = 0;

  if (numStudents <= 1){
    //cout << "1 student" << endl;
    StudentMean = longestWait;
    median = longestWait;
  }
  else {
    StudentMean = (double)StudentProcessTime/(double)numStudents;

    sort(studentMedian, studentMedian + numStudents);
    //If there is an odd number of students, just take the middle value
    if (numStudents % 2 != 0){
      //cout << "Odd" << endl;
      median = (double)studentMedian[numStudents / 2];
    }
    //else if theres an even number, take 2 middle values n find average
    else{
      //cout << "even" << endl;
      x = studentMedian[(numStudents - 1) / 2];
      y = studentMedian[numStudents / 2];
    //  cout << "x: " << x << ", y: " << y << endl;
      median = (x + y) / 2.0;
    //  x = numStudents/2;
    //  y = studentMedian[3];
      //median = (double)studentMedian[6];
    }
  }
}

string Statistics::printStats(){
  this->calculate();
  //mean
  string output = "Statistics: \n1. The mean student wait time: ";
  output += to_string(StudentMean);
  //median
  output += "\n2. The median student wait time: ";
  output +=to_string(median);
  //Longest wait
  output += "\n3. The longest student wait time: ";
  output += to_string(longestWait);
  //Over10minWait
  output += "\n4. The number of students waiting over 10 minutes: ";
  output += to_string(StudentLongWait);
  //Mean window idle time
  output += "\n5 .The mean window idle time: ";
  output += to_string((double)sumIdle/(double)numIdle);
  //Longest idle
  output += "\n6. The longest window idle time: ";
  output += to_string(longestIdle);
  //Over5min Idle
  output += "\n7. Number of windows idle for over 5 minutes: ";
  output += to_string(longIdle);
  //Finished adn return
  return output;
}
