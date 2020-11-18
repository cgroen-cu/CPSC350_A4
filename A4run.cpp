//A4run.cpp
//Implementation file for A4
#include "A4run.h"

A4run::A4run(){
  waitLine = new GenQueue<Student>;
  windows = new Window[5];
  stats1 = new Statistics();
}

A4run::A4run(string f){
  waitLine = new GenQueue<Student>;
  //windowNum = 0;
  file = f;
  stats1 = new Statistics();

}

A4run::~A4run(){}

//Methods
void A4run::simulate(){
  //Open File
  string y;
  int windowNum = 0;
  int openWindowNum = 0;
  int x = 0;
  int f = 0;
  ifstream myfile;
  int lineNum = 0;
  int line;
  int arrivalTime;
  int clockTick = 0;  //holds time
  int nextTime = 0; //holds next time students arrive
  while(x == 0){
    cout << "Opening file: " << file << endl;
    myfile.open (file, ios::in);
      if(!myfile)
      {
          cout << "Incorrect file... \nPlease try again" << endl;
          cout <<"Enter file path: ";
          cin >> file;
      } else {
        ++x;
      }
  }
  x = 0;
  //While Loop to read through file and get total number of lines
  while (getline(myfile, y)){
    lineNum++;
  }
  //cout << "line num: " << lineNum << endl;
  myfile.close();
  myfile.open (file, ios::in);
  //First line set up windows
  myfile >> line;
  this->setUp(line);
  windowNum = line;
  lineNum--;

  //Gets next line of start time
  myfile >> line;
  lineNum--;
//  cout << "Start time is: " << line << endl;
  //Main loop
  while(x<2){
    //cout << " ============ Time: " << clockTick << " ============ " << endl;
    openWindowNum = 0;

    //If statement checking time, if matches line, reads through next part of file
    //It reads unto the next time and then loops until time matches it again
    if(clockTick == line){
      line = arrivalTime;
      myfile >> line;
      lineNum--;
      f = line;
    //  cout << f << " New Students" << endl;
      //Creates a for loop iterating over the number of students gatehred from
      //The line, creating a new student with the appropriate line
      //Adds it to queue
      for (int i = 0; i < f; ++i){
        myfile >> line;
        lineNum--;
      //  cout << "Student with "<< line << endl;
        Student s(clockTick, line);
        waitLine->Enqueue(s);
      }
      //when getline is finished x++
      // - close file
      //cout << "LineNum" << lineNum << endl;
      if (lineNum <= 0){
      //  cout << "No more lines" << endl;
        line = 0;
        x++;
        myfile.close();
      } else {
        myfile >> line;
        lineNum--;
      //  cout << "Next time is: " << line << endl;
      }
    }
    //cout << "lineNum left: " << lineNum << endl;

    //Traverse through window array.
    //if a window is 0-open- and the queue is not empty
    //Pop student from queue and into window - change window state to 1-closed
    // - and call stats of student;s wait time
    //If a student processTime is 0, change window state to 0-open
    //Finally, tick process time of all Students
    //and tick idle time of all open windows
    for (int i = 0; i < windowNum; ++i){
      //cout << "Window: " << i << " State: " << windows[i].getWindowState() << endl;
      //If the window is full, check if student is done
      if (windows[i].getWindowState() && windows[i].getTime() <= 0) {
        //cout << "Student Finished" << endl;
        windows[i].changeWindowState();
        openWindowNum++;
        //cout << "OW ++ " << endl;
        //when windows are all cleared x++ again
        //cout << "x: " << x << endl;
        //cout << waitLine->isEmpty() << endl;
        //cout <<openWindowNum<<endl;
        // if (x > 0 && openWindowNum >= windowNum && waitLine->isEmpty()){
        //   cout << "Windows and queue cleared" << endl;
        //   x++;
        //   break;
        // }
        //Thus making x 2 and ending the loop
      }
      //If the window is empty and queue is not empty
      if (!windows[i].getWindowState() && !waitLine->isEmpty()){
        //cout << "arrival time: " << waitLine->peek().getArrivalTime() << endl;
        //cout << "wait time: " << clockTick - (waitLine->returnPos(0).getArrivalTime()) << endl;
        stats1->newStudent(clockTick - (waitLine->returnPos(0).getArrivalTime()));
        int ss = waitLine->Dequeue().getTime();
        openWindowNum--;
        //cout << "OW --" << endl;

        //Stats of student wait time
        //cout << "Student popped into window " << i << " with process time of " << ss << endl;
        windows[i].nextStudent(ss);

      }
      //if the window is empty and noone in queue, tick idle
      else if (!windows[i].getWindowState()){
        if (x > 0 && openWindowNum >= windowNum && waitLine->isEmpty()){
          //cout << "Windows and queue cleared" << endl;
          x++;
          break;
        }
        windows[i].tickIdleTime();
        openWindowNum++;
        //cout << "OW ++ " << endl;
        //cout << "Queue Empty, Window is idle, tick: " << windows[i].getIdleTime() << endl;
      }

      //Finally, If there is a student that is still processing, tick time
      if (windows[i].getWindowState()){
        windows[i].timeTick();
        //cout << "student at tick "  << windows[i].getTime() << endl;
      }
    }
    //cout << "OW: " << openWindowNum << endl;
    //cout << "Num of Windows: " << windowNum << endl;
    //cout << "x: " << x << endl;


    //traverse through queue of students
    //tick wait time
    //cout << waitLine->getSize() << "Students in line" << endl;



    //At end of loop, TICKS
    //Student wait tick
    ++clockTick;
  }
  //Then needs to send info to stats
  //Loop through window array - sending idle stats
  for (int i = 0; i < windowNum; ++i){
    //send idle stats
    stats1->newIdle(windows[i].getIdleTime());
  }
  //And then print stats
  stats1->calculate();
  cout << stats1->printStats() << endl;
}
void A4run::setUp(int d){
  //windowNum = d;
  windows = new Window[d];
  for(int i = 0; i < d; ++i){
    Window *w = new Window();
    windows[i] = *w;
    //cout << "new window" << endl;
  }
}
