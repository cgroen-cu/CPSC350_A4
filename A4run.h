//A4run.h
//header file for A4run Class
//This class is used to hold the queues and run the game
#include "Window.h"
#include "GenQueue.h"
#include "Statistics.h"
//#include "fileIO.h"
#include <fstream>  //File IOS

class A4run{
private:
  //int windowNum;
  string file;
  GenQueue<Student> *waitLine;
  Statistics *stats1;
  Window *windows;

public:
  //constructors
  A4run();
  A4run(string f);
  ~A4run();

  //methods
  void simulate(); //loops through the program
  void setUp(int d); //Sets up Windows Array

};
