/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"
#include "homework3.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
//    P1DIR = P1DIR |  BIT0;

//    P1DIR = P1DIR &~ BIT1;//L1
//    P1REN = P1REN |  BIT1;
//    P1OUT = P1OUT |  BIT1;
//////////////////////////////////
//
//    P1DIR = P1DIR &~ BIT4;//L2
//    P1REN = P1REN |  BIT4;
//    P1OUT = P1OUT |  BIT4;
//////////////////////////////////
//
//
//     P5DIR = P5DIR &~ BIT1;//B1
//     P5REN = P5REN |  BIT1;
//     P5OUT = P5OUT |  BIT1;
////////////////////////////////////
//
//     P3DIR = P3DIR &~ BIT5;//B2
//     P3REN = P3REN |  BIT5;
//     P3OUT = P3OUT |  BIT5;
/////////////////////////////////////

//     P1DIR = P1DIR &~ LED1; //LED1
//     GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);

     ///////////////////////////////////

//     P2DIR = P2DIR &~   LED2R;//RED LED2
     GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0);

     ///////////////////////////////////

//     P2DIR = P2DIR &~   LED2G;//GREEN LED2
     GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN1);

     ///////////////////////////////////

//     P2DIR = P2DIR &~   LED2B;//BLUE LED2
     GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2);

     ///////////////////////////////////

//     P2DIR = P2DIR &~   BLEDR;// RED BLED
     GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN6);

     ///////////////////////////////////

//     P2DIR = P2DIR &~   BLEDG;//GREEN BLED
     GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN4);

     ///////////////////////////////////

//     P5DIR = P5DIR &~   BLEDB;//BLUE BLED
     GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN6);

     ///////////////////////////////////

     GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P1, GPIO_PIN1);//L1


     //////////////////////////////////////////////////////////////////

     GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P1, GPIO_PIN4);//L2


     //////////////////////////////////////////////////////////////////

     GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P5, GPIO_PIN1);//B1


     //////////////////////////////////////////////////////////////////

     GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P3, GPIO_PIN5);//B2


     //////////////////////////////////////////////////////////////////




    // Launchpad S1

    // Launchpad S2

    // Boosterpack S1

    // Boosterpack S2

    // Launchpad LED1

    // Launchpad LED2 Red

    // Launchpad LED2 Green

    // Launchpad LED2 Blue

    // Boosterpack LED Red

    // Boosterpack LED Green

    // Boosterpack LED Blue


    // Turn off all LEDs at the start.
     changeLaunchpadLED2(0);
     changeBoosterpackLED(0);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return GPIO_getInputPinValue(GPIO_PORT_P5, GPIO_PIN1);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN5);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN6);
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN4);
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN4);
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
}
