#include <Thread.h>

//My simple Thread
Thread Thread1 = Thread();
Thread Thread2 = Thread();

int SignalThread1_to_Thread2=0;

// callback for myThread
void Thread1_callBack(){

  if(millis()>5000)
  {
	Serial.print("Thread 1: 5 seconds passed. Thread2 Turn it ON!\n");
	SignalThread1_to_Thread2=1;
  Thread1.enabled = false;
  }
  else
  {
  
  }
}

void Thread2_callBack(){

  if(SignalThread1_to_Thread2!=0)
  {
  Serial.print("Thread 2: Signal Received Turning LED ON!\n");
  digitalWrite(13, HIGH);
  //Serial.println(millis());
  Thread2.enabled = false;
  }
  else
  {
  Serial.print("Thread 2: No signal received yet.\n");  
  }
  
}


void setup(){
	Serial.begin(9600);

	pinMode(13, OUTPUT);

	Thread1.onRun(Thread1_callBack);
  Thread1.setInterval(1000);
 
  Thread2.onRun(Thread2_callBack);
  Thread2.setInterval(1000);
  
}

void loop(){
	// checks if thread should run
	if(Thread1.shouldRun())
		{Thread1.run();}
    
  if(Thread2.shouldRun())
    {Thread2.run();}
if(Thread1.enabled == false && Thread2.enabled== false)
{
Serial.print("Out of threads. END\n");
while(1);
}

}
