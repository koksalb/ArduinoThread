#include <Thread.h> 
#include <ThreadController.h>

#include "GlobalVariables.h"

//Block Threads are created here
Thread Thread1 = Thread();
Thread Thread2 = Thread();
Thread Thread3 = Thread();
Thread Thread4 = Thread();


#include "Thread1_callBack.h"
#include "Thread2_callBack.h"
#include "Thread3_callBack.h"
#include "Thread4_callBack.h"


void setup(){
  Serial.begin(9600);//necessary line

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  
  Thread1.onRun(Thread1_callBack);
  Thread2.onRun(Thread2_callBack);
  Thread3.onRun(Thread3_callBack);
  Thread4.onRun(Thread4_callBack);

  
  //Thread1.setInterval(100);
  //Thread2.setInterval(100);
  //Thread3.setInterval(100);
  //Thread4.setInterval(100);
  
  Thread1.enabled=true;
  Thread2.enabled=true;
  Thread3.enabled=true;
  Thread4.enabled=true;

  
  controll.add(&Thread1);
  controll.add(&Thread2);
  controll.add(&Thread3);
  controll.add(&Thread4);
  
}

//Thread controller ran in loop
void loop(){
  controll.runRandomly();
}
