
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