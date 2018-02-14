//Signals Come Here
int MainBlock_signal1_out__PrintBlock_signal1_in = 0;
int MainBlock_signal1_out__PrintBlock_signal1_in_Receivers = 0;




//One controller is needed
ThreadController controll = ThreadController();



void printStats()
{
Serial.print("SignalAmount: ");
Serial.print(MainBlock_signal1_out__PrintBlock_signal1_in);
Serial.print(" Receivers: ");
Serial.print(MainBlock_signal1_out__PrintBlock_signal1_in_Receivers);
Serial.print(" \n");
}
