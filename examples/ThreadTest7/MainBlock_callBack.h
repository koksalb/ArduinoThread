#define MainBlock_STATE__START__STATE 0
#define MainBlock_STATE__MainState 1
#define MainBlock_STATE__MainState__Wait 2

#define MainBlock_STATE__STOP__STATE 3

#define MainBlock_STATE__MainBlock_signal1_out__PrintBlock_signal1_in__Send 4
#define MainBlock_STATE__MainBlock_signal1_out__PrintBlock_signal1_in__Confirm 5




int MainBlock_periodstart = 5;
int MainBlock_periodend = 5;


void MainBlock_callBack(){
   
  
  if(MainBlock.ThreadState!=MainBlock_STATE__STOP__STATE)
  {
     switch( MainBlock.ThreadState) {

    case MainBlock_STATE__START__STATE:
          MainBlock.ThreadState = MainBlock_STATE__MainState;
          break;
    
    case MainBlock_STATE__MainState:
        MainBlock.waitFor(2000,5000);
        MainBlock.ThreadState = MainBlock_STATE__MainState__Wait;
         break;

    case MainBlock_STATE__MainState__Wait:
              Serial.print("\n");
              Serial.print(millis());
              Serial.print(" MainBlock: Wants to send a signal. ");
              printStats();
        MainBlock.ThreadState = MainBlock_STATE__MainBlock_signal1_out__PrintBlock_signal1_in__Send;
         break;
         

      case MainBlock_STATE__MainBlock_signal1_out__PrintBlock_signal1_in__Send:
       if(MainBlock_signal1_out__PrintBlock_signal1_in_Receivers > 0)
       {
        MainBlock_signal1_out__PrintBlock_signal1_in+=1;
              Serial.print("\n");
              Serial.print(millis());
              Serial.print(" MainBlock: ");
              Serial.print("Sends one signal. ");
              printStats();
              
        MainBlock.ThreadState = MainBlock_STATE__MainBlock_signal1_out__PrintBlock_signal1_in__Confirm;
       }
       else
       {
       //Serial.print("Alternative Path.\n");
       }
        break;
        
    case MainBlock_STATE__MainBlock_signal1_out__PrintBlock_signal1_in__Confirm:
      if(MainBlock_signal1_out__PrintBlock_signal1_in_Receivers==0)
          {
            MainBlock.ThreadState =   MainBlock_STATE__MainState;
          }
        
        break;


      
     }
  }
  else
  {
  MainBlock.enabled=false;
  }

}



