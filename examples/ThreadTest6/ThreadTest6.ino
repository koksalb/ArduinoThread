#include <Thread.h> 
#include <ThreadController.h>

#include "GlobalVariables.h"

//Block Threads are created here
Thread MainBlock = Thread();
Thread PrintBlock = Thread();


#include "MainBlock_callBack.h"
#include "PrintBlock_callBack.h"


void setup(){
  Serial.begin(9600);//necessary line
  randomSeed(analogRead(0));
  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  
  MainBlock.onRun(MainBlock_callBack);
  PrintBlock.onRun(PrintBlock_callBack);

  
  MainBlock.setInterval(100);
  PrintBlock.setInterval(100);
  
  MainBlock.enabled=true;
  PrintBlock.enabled=true;

  
  controll.add(&MainBlock);
  controll.add(&PrintBlock);
  
}

//Thread controller ran in loop
void loop(){
  controll.runRandomly();
}
