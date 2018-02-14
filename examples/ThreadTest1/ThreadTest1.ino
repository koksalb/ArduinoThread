#include <Thread.h>
#include <ThreadController.h>

//My simple Thread
Thread Thread1 = Thread();
Thread Thread2 = Thread();

ThreadController controll = ThreadController();



// callback for myThread
void Thread1_callBack(){
  
	digitalWrite(13, HIGH);
	Serial.print("Thread 1: I'm running on: ");
	Serial.println(millis());
  delay(1000);
  Thread1.enabled = false;
}

void Thread2_callBack(){

  digitalWrite(13, LOW);
  Serial.print("Thread 2: I'm running off: ");
  Serial.println(millis());
  delay(1000);
  Thread2.enabled = false;
}


void setup(){
	Serial.begin(9600);

	pinMode(13, OUTPUT);

	Thread1.onRun(Thread1_callBack);
  Thread1.setInterval(1000);
 
  Thread2.onRun(Thread2_callBack);
  Thread2.setInterval(1000);

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
