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