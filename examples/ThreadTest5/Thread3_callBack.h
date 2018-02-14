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