#include <Thread.h>
#include <ThreadController.h>

//My simple Thread
int SignalSent = 0;


Thread Thread1 = Thread();

Thread Thread2 = Thread();
Thread Thread3 = Thread();
Thread Thread4 = Thread();



ThreadController controll = ThreadController();

// callback for myThread
void Thread1_callBack(){
  delay(1000);
  Serial.print("Thread 1: Sending one signal\n");
  SignalSent += 1;

}

void Thread2_callBack(){
  if(SignalSent>0)
  {
  Serial.print("Thread 2: Signal Received. Yellow LED\n");
  digitalWrite(13, !digitalRead(13));
  SignalSent -= 1;

  delay(500);
  digitalWrite(13, !digitalRead(13));
  }
}

void Thread3_callBack(){
  if(SignalSent>0)
  {
  Serial.print("Thread 3: Signal Received. Green LED\n");
  digitalWrite(12, !digitalRead(12));
  SignalSent -= 1;

  delay(500);
  digitalWrite(12, !digitalRead(12));
  }
}

void Thread4_callBack(){
  if(SignalSent>0)
  {
  Serial.print("Thread 4: Signal Received. Red LED\n");
  digitalWrite(11, !digitalRead(11));
  SignalSent -= 1;

  delay(500);
  digitalWrite(11, !digitalRead(11));
  
  }
}


void setup(){
  Serial.begin(9600);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  
  Thread1.onRun(Thread1_callBack);
  Thread1.setInterval(100);
 
  Thread2.onRun(Thread2_callBack);
  Thread2.setInterval(100);

  Thread3.onRun(Thread3_callBack);
  Thread2.setInterval(1000);

  Thread4.onRun(Thread4_callBack);
  Thread2.setInterval(100);
  
  Thread1.enabled=true;
  Thread2.enabled=true;
  Thread3.enabled=true;
  Thread4.enabled=true;
  controll.add(&Thread1);
  controll.add(&Thread2);
  controll.add(&Thread3);
  controll.add(&Thread4);
  
}

void loop(){
  // checks if thread should run

  delay(1000);
  
  controll.run();


}
