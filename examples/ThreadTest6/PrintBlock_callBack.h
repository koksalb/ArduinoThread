#define PrintBlock_STATE__START__STATE 0
#define PrintBlock_STATE__PrintState 1
#define PrintBlock_STATE__InputState 2
#define PrintBlock_STATE__STOP__STATE 3

void PrintBlock__printHelloWorld() {
  Serial.print("Hello World!\n");
}


void PrintBlock_callBack(){

  if(PrintBlock.ThreadState!=PrintBlock_STATE__STOP__STATE)
  {
     switch( PrintBlock.ThreadState) {

    case PrintBlock_STATE__START__STATE:
          PrintBlock.ThreadState = PrintBlock_STATE__PrintState;
           break;

    case PrintBlock_STATE__InputState:
          if(MainBlock_signal1_out__PrintBlock_signal1_in > 0)
          {
            MainBlock_signal1_out__PrintBlock_signal1_in -= 1;
            PrintBlock.ThreadState = PrintBlock_STATE__PrintState;
          }
          else
          {
            //still waiting for the signal
          }
          
          break;
    
    case PrintBlock_STATE__PrintState:
              Serial.print("PrintBlock: ");
          PrintBlock__printHelloWorld();
          PrintBlock.ThreadState = PrintBlock_STATE__InputState;
           break;
    
      
               }//end of switch
   }
  else
  {
  PrintBlock.enabled=false;
  }


  
}
