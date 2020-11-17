//main.cpp
//main method file for A4
#include "A4run.h"

int main(int argc, char** argv){
  //A4run test
  A4run *testRun;
  string f;
  cout << "Enter File Name: ";
  cin >> f;
  testRun = new A4run(f);
  testRun->simulate();


}
