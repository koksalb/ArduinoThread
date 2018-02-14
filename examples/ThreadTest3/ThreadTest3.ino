#include <Thread.h>
#include <ThreadController.h>

//My simple Thread
Thread Thread1 = Thread();
Thread Thread2 = Thread();

ThreadController controll = ThreadController();

// callback for myThread
void Thread1_callBack(){

  if(millis()>5000)
  {
  Serial.print("Thread 1: 5 seconds passed. Thread2 Turn it ON!\n");
  Thread2.enabled=true;
  Thread1.enabled = false;
  }
  else
  {
  Serial.print("Thread 1: Not Yet!\n");
  }
}

void Thread2_callBack(){
  
  Serial.print("Thread 2: Signal Received Turning LED ON!\n");
  digitalWrite(13, HIGH);
  Thread2.enabled = false; 
  
}


void setup(){
  Serial.begin(9600);

  pinMode(13, OUTPUT);

  Thread1.onRun(Thread1_callBack);
  Thread1.setInterval(1000);
 
  Thread2.onRun(Thread2_callBack);
  Thread2.setInterval(1000);
  Thread2.enabled=false;

  controll.add(&Thread1);
  controll.add(&Thread2);
  
}

void loop(){
  // checks if thread should run
  controll.run();
  
if(Thread1.enabled == false && Thread2.enabled== false)
{
Serial.print("Out of threads. END\n");
while(1);
}

}
