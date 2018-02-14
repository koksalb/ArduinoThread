#define MainBlock_STATE__START__STATE 0
#define MainBlock_STATE__MainState 1
#define MainBlock_STATE__STOP__STATE 2

int MainBlock_period = 2;


void MainBlock_callBack(){
   
  
  if(MainBlock.ThreadState!=MainBlock_STATE__STOP__STATE)
  {
     switch( MainBlock.ThreadState) {

    case MainBlock_STATE__START__STATE:
          MainBlock.ThreadState = MainBlock_STATE__MainState;
          break;
    
    case MainBlock_STATE__MainState:
        delay(MainBlock_period*1000);
        MainBlock_signal1_out__PrintBlock_signal1_in+=1;
              Serial.print("MainBlock: Sending one signal.\n");
        MainBlock.ThreadState = MainBlock_STATE__MainState;
         break;

      
     }
  }
  else
  {
  MainBlock.enabled=false;
  }

}



