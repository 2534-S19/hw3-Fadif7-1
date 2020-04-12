#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
 #include "homework3.h"
 #include "myGPIO.h"
 #include "myTimer.h"
#include <stdio.h>
typedef enum{off, two, three, four, five, six, seven, eight}color;
 int main(void)
 {
     // Count variables to control the LEDs.
     unsigned int count0 = 0;
     unsigned int count1 = 0;

     // TODO: Declare the variables that main uses to interact with your state machine.


     // Stops the Watchdog timer.
     initBoard();
     // Initialize the GPIO.
     // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
     initGPIO();
     // Initialize Timer0 to provide a one second count interval for updating LED2.
     // YOU MUST WRITE THIS FUNCTION IN myTimer.c
     initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT,false);
     // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
     // YOU MUST WRITE THIS FUNCTION IN myTimer.c
     initTimer(TIMER1, TIMER1_PRESCALER, TIMER1_COUNT,false);


     button_status currentS1 = up_state;    //S1 State
     char buttonHistoryS1 = 0xFF; //S1 History

     while(1)
     {
         // Update the color of LED2 using count0 as the index.
         // YOU MUST WRITE THIS FUNCTION BELOW.
         changeLaunchpadLED2(count0);
         // Update the color of the Boosterpack LED using count1 as the index.
         // YOU MUST WRITE THIS FUNCTION BELOW.
         changeBoosterpackLED(count1);

         // TODO: If Timer0 has expired, increment count0.
         // YOU MUST WRITE timer0expired IN myTimer.c
         if(timer0Expired() && count0 < 8)
         {
             count0++;
             printf("this is the timer)Exp counter0 val %d \n",count0);
             if(count0 == 8){
                 count0 = 0;
             }
         }



         // TODO: If Timer1 has expired, update the button history from the pushbutton value.
         // YOU MUST WRITE timer1expired IN myTimer.c
         if(timer1Expired())
             if(checkStatus_BoosterpackS1() == PRESSED)
             {
                buttonHistoryS1 = buttonHistoryS1 << 1;
                buttonHistoryS1 |= BIT0;
             }else
                 buttonHistoryS1 = buttonHistoryS1 << 1;


         // TODO: Call the button state machine function to check for a completed, debounced button press.
         // YOU MUST WRITE THIS FUNCTION BELOW.


        bool pressed = fsmBoosterpackButtonS1(buttonHistoryS1);




         // TODO: If a completed, debounced button press has occurred, increment count1.
        if(pressed)
            count1 = count1 + 1;
//         if((checkStatus_BoosterpackS1() == pressed) && count1 < 8)
//         {
//             count1++;
//             printf("this is the timer)Exp counter0 val %d \n",count0);
//             if(count1 == 8){
//                 count1 = 0;
//             }
//         }
//
     }

 }

 void initBoard()
 {
     WDT_A_hold(WDT_A_BASE);
 }

 // TODO: Map the value of a count variable to a color for LED2.
 // Since count is an unsigned integer, you can mask the value in some way.
 void changeLaunchpadLED2(unsigned int count0)
 {


     switch(count0 % 8)
     {
     case off:
         turnOff_LaunchpadLED2Red();//no LEDs
         turnOff_LaunchpadLED2Green();
         turnOff_LaunchpadLED2Blue();
         break;
     case two:
         turnOn_LaunchpadLED2Red();//only Red
         turnOff_LaunchpadLED2Green();
         turnOff_LaunchpadLED2Blue();
         break;
     case three:
         turnOn_LaunchpadLED2Green();//only Green
         turnOff_LaunchpadLED2Red();
         turnOff_LaunchpadLED2Blue();
         break;
     case four:
         turnOn_LaunchpadLED2Red();//Red and Green on = Yellow
         turnOn_LaunchpadLED2Green();
         turnOff_LaunchpadLED2Blue();
         break;
     case five:
         turnOn_LaunchpadLED2Blue();//Only Blue
         turnOff_LaunchpadLED2Red();
         turnOff_LaunchpadLED2Green();
         break;
     case six:
         turnOn_LaunchpadLED2Red();// Red and Blue on = pink
         turnOn_LaunchpadLED2Blue();
         turnOff_LaunchpadLED2Green();
         break;
     case seven:
         turnOn_LaunchpadLED2Green();// Green and Blue on = Cyan
         turnOn_LaunchpadLED2Blue();
         turnOff_LaunchpadLED2Red();
         break;
     case eight:
         turnOn_LaunchpadLED2Red();// Red and Blue on = pink
         turnOn_LaunchpadLED2Blue();
         turnOn_LaunchpadLED2Green();
         break;
     default:
         break;
     }
 }

 // TODO: Maybe the value of a count variable to a color for the Boosterpack LED
 // This is essentially a copy of the previous function, using a different LED
 void changeBoosterpackLED(unsigned int count1)
 {

     switch(count1 % 8)
         {
         case off:
         {
             turnOff_BoosterpackLEDRed();
             turnOff_BoosterpackLEDGreen();
             turnOff_BoosterpackLEDBlue();
             break;
         }
         case two:
         {
             turnOn_BoosterpackLEDRed();
             turnOff_BoosterpackLEDGreen();
             turnOff_BoosterpackLEDBlue();
             break;
         }
         case three:
         {
             turnOn_BoosterpackLEDGreen();
             turnOff_BoosterpackLEDRed();
             turnOff_BoosterpackLEDBlue();
             break;
         }
         case four:
         {
             turnOn_BoosterpackLEDRed();//Red and Green on = Yellow
             turnOn_BoosterpackLEDGreen();
             turnOff_BoosterpackLEDBlue();
             break;
         }
         case five:
         {
             turnOn_BoosterpackLEDBlue();
             turnOff_BoosterpackLEDRed();
             turnOff_BoosterpackLEDGreen();
             break;
         }
         case six:
         {
             turnOn_BoosterpackLEDRed();// Red and Blue on = pink
             turnOn_BoosterpackLEDBlue();
             turnOff_BoosterpackLEDGreen();
             break;
         }
         case seven:
         {
             turnOn_BoosterpackLEDGreen();// Green and Blue on = Cyan
             turnOn_BoosterpackLEDBlue();
             turnOff_BoosterpackLEDRed();
             break;
         }
         case eight:
         {
             turnOn_BoosterpackLEDRed();// Red and Blue on = pink
             turnOn_BoosterpackLEDBlue();
             turnOn_BoosterpackLEDGreen();
             break;
         }
         default:
             break;
         }
 }

 // TODO: Create a button state machine.
 // The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonHistoryS1)
{
    bool pressed;
    static button_status currentState = up_state;

    switch (currentState)
    {
    case up_state:
    {
        if (buttonHistoryS1 & BIT0)
        {
            pressed = true;
            currentState = down_state;
        }
        else
        {
            pressed = false;
            currentState = up_state;
        }
        break;
    }
    case down_state:
        if (buttonHistoryS1 & BIT0)
        {
            pressed = false;
            currentState = down_state;
        }
        else
        {
            pressed = false;
            currentState = up_state;
        }
        break;

    }
    return pressed;
}

