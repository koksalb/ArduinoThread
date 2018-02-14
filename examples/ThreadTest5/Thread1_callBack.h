void Thread1_callBack(){
  delay(1000);
  Serial.print("Thread 1: Sending one signal\n");
  SignalSent += 1;

}