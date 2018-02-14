#define PrintBlock_STATE__START__STATE 0
#define PrintBlock_STATE__PrintState 1
#define PrintBlock_STATE__InputState 2
#define PrintBlock_STATE__InputState__Wait 3

#define PrintBlock_STATE__STOP__STATE 4



#define PrintBlock_STATE__MainBlock_signal1_out__PrintBlock_signal1_in_Receive 5

void PrintBlock__printHelloWorld() {
  Serial.print("Hello World! ");
}


void PrintBlock_callBack(){

  if(PrintBlock.ThreadState!=PrintBlock_STATE__STOP__STATE)
  {
     switch( PrintBlock.ThreadState) {

    case PrintBlock_STATE__START__STATE:
          PrintBlock.ThreadState = PrintBlock_STATE__InputState;
           break;

    case PrintBlock_STATE__InputState:
           PrintBlock.waitFor(1000,3000);
           PrintBlock.ThreadState = PrintBlock_STATE__InputState__Wait;
          break;


        case PrintBlock_STATE__InputState__Wait:
              MainBlock_signal1_out__PrintBlock_signal1_in_Receivers += 1;
              Serial.print("\n");
              Serial.print(millis());
              Serial.print(" PrintBlock: Wants to Receive a signal. ");
              printStats();
           PrintBlock.ThreadState = PrintBlock_STATE__MainBlock_signal1_out__PrintBlock_signal1_in_Receive;
          break;

          
    
    
    case  PrintBlock_STATE__MainBlock_signal1_out__PrintBlock_signal1_in_Receive:
      
          if(MainBlock_signal1_out__PrintBlock_signal1_in > 0)
          {
            MainBlock_signal1_out__PrintBlock_signal1_in -= 1;
            MainBlock_signal1_out__PrintBlock_signal1_in_Receivers -= 1;
            PrintBlock.ThreadState = PrintBlock_STATE__PrintState;
          }
          else
          {
            //still waiting for the signal
            //Serial.print("Alternative Path.\n");
          }

          break;

      case PrintBlock_STATE__PrintState:
              Serial.print("\n");
              Serial.print(millis());
              Serial.print(" PrintBlock: ");
          PrintBlock__printHelloWorld();
          printStats();
          PrintBlock.ThreadState = PrintBlock_STATE__InputState;
           break;
           
               }//end of switch
   }
  else
  {
  PrintBlock.enabled=false;
  }


  
}
