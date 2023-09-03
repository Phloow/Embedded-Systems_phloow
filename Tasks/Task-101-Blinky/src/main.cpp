/*********
Program: Basic program to blink the onboard LED on the Nucleo board.
Target device: Nucleo F401RE or Nucleo F429ZI
Framework: Mbed OS
Author: Nicholas Outram (Task 1 from Embedded Systems Course)
Modified by: Folarin Shomefun (using my template)
Credits: Nicholas Outram
Code Status: Working perferctly as tested with nucleo boards F401RE and F429ZI from Nick.
*********/

/*----- Module 1 = INCLUDES (Library & files) -----*/
#include "mbed.h" //this is relevant to be able to use mbed commands and sysntax.
/*-----End of Module 1 -----*/

/*----- Module 2 = VARIABLES NAME & TYPE DECLARATION, #DEFINES, VARIABLE INITIALIZATION, PIN DEFINITIONS, LIBRARY INSTATIATION, LIBRARY PORT / SITE ADDRESS ASSIGNMENT, FLAGS, -----*/
DigitalOut greenLED(PB_0);  //Instantiate the DigitalOut method as a variable called "greenLED" and pass the port we want to control as its parameter. LED 1 is on PB_0 of F429ZI. Unlike Arduino where you have to define a port pin first before setting the mode(OUT or IN), you do this in one go in mbed!
DigitalOut blueLED(PB_7);  // LED2 port pin on F429ZI. You can as well replace PB_0, PB_7 and PB_14 with "LED1", "LED2", and "LED3" which are library defined aliases for these pins 
DigitalOut redLED(PB_14);   // LED3 port pin on F429ZI
/*-----End of Module 2 -----*/

/*----- Module 3 = FUNCTION PRE-DECLARATIONS -----*/ // none to declare
/*----- Module 4 = SETUP() Start Libraries/modules, set pin modes, start serial, start libraries, start displays, etc  -----*/
// Mbed OS does not use a setup() function; everything goes into module 2

/*----- Module 5 = MAIN() -----*/
int main()
{      
    while (true) // Unlike Arduino, where the loop() function automatically repaeats, in Mbed (more C++esque), you have to introduce the while(true) loop yourself.
    {
        int i = 0; // iterant definition and initialisation
        int j = 0; // another iterant definition and initialisation

        while (i <= 2) {
            greenLED = !greenLED;   //invert the state of greenLED, whatever it is, every cycle
            wait_us(1000000);   // Wait 1 second      
            i++;
        }

        while (j <= 5) {
          redLED = !redLED; //invert the state of redLED, whatever it is, every cycle
          wait_us(250000); // Wait 1/4 second
          j++;
        }
    }
}
/*-----End of Module 5 -----*/
