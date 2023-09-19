/*********
Program:        Basic program to monitor two switches using rapid polling.
Target device:  Nucleo F401RE or Nucleo F429ZI
Framework:      Mbed OS
Author:         Nicholas Outram (Task 134 from Embedded Systems Course)
Modified by:    Folarin Shomefun (slightly and using my template)
Credits:        Nicholas Outram
Code Status:    Mbed Studio - //! Not compiled on Mbed OS
Code Status:    //!PlatformIO - Compiled and working perfectly on F429ZI + MSB. Restructured library (uopmsb) is placed on GitHub and cloned to have a local copy.
Notes:          //?For PlatformIO, the repo clone is symlinked as a dependency in platformio.ini (see mindmap for details) for any project that needs the library.
                //todo:Sometimes, you may need to compile more than once, if you get an error on compilation the first time. This happens very often!
*********/

/*----- Module 1 = INCLUDES (Library & files) -----*/
// include "mbed.h"         //not necessary because it has already been included in the uop_msb library
#include "uop_msb.h"        //university of plymouth universal library for the embedded system course
using namespace uop_msb;
/*----- End of Module 1 -----*/

/*----- Module 2 = VARIABLES NAME & TYPE DECLARATION, PIN DEFINITIONS, & #DEFINES: //! VARIABLE INITIALIZATION,  LIBRARY INSTATIATION, LIBRARY PORT / SITE ADDRESS ASSIGNMENT, FLAGS (for Mbed, these go under int main() before the while(1) loop -----*/
BusIn buttons(BTN1_PIN, BTN2_PIN, BTN3_PIN, BTN4_PIN);
// DigitalIn buttonA(BTN1_PIN);    //ButtonA is synonamous with buttons[0]
// DigitalIn buttonB(BTN2_PIN);
// DigitalIn buttonC(BTN3_PIN);
// DigitalIn buttonD(BTN4_PIN);

DigitalOut redLED(TRAF_RED1_PIN);    //'TRAF_RED1_PIN' decalred in the uop_msb library and is the alias for PC_2.
DigitalOut yellowLED(TRAF_YEL1_PIN); //'TRAF_YEL1_PIN' decalred in the uop_msb library and is the alias for PC_3.
DigitalOut greenLED(TRAF_GRN1_PIN);  //'TRAF_GRN1_PIN' decalred in the uop_msb library and is the alias for PC_6.


// Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);
/*----- End of Module 2 -----*/

/*----- Module 3 = FUNCTION PRE-DECLARATIONS - Only relevant for Arduino framwework -----*/ // none to declare
/*----- Module 4 = SETUP()  - Start Libraries/modules, set pin modes, start serial, start libraries, start displays, etc //!Only here for Arduino framwework. For Mbed, this goes under "int main()" module before the while(1) loop) -----*/

/*----- Module 5 = MAIN() -----*/
int main()
{
    volatile int count = 0;

    // This little C++ trick allows us to use BOTH BusIn and DigitalIn
    DigitalIn &buttonA = buttons[0]; // ButtonA is synonamous with buttons[0]
    DigitalIn &buttonB = buttons[1];
    DigitalIn &buttonC = buttons[2];
    DigitalIn &buttonD = buttons[3];

    // Configure switches
    buttonC.mode(PullDown);         // set up buttonC pin with pull-down 
    buttonD.mode(PullDown);         // set up buttonD pin with pull-down

    // Turn ON the 7-segment display
    disp.enable(true);

    // ****************************************
    // THE FOLLOWING CODE IS NOT WELL WRITTEN!
    // IT NEEDS FIXING
    // ****************************************

    while (true)
    {

        // Update display
        disp = count;

        // Wait for button A
        while (buttonA == 0)
        {
        }

        if (count > 0)
        {
            count -= 1;
        }

        // Wait for button B
        while (buttonB == 0)
        {
        }

        if (count < 99)
        {
            count += 1;
        }

        // Reset condition
        if ((buttonA == 1) && (buttonB == 1))
        {
            count = 0;
        }

        // Slow it down a bit (and debounce the switches)
        wait_us(250000);
    }
}
/*-----End of Module 5 -----*/

/*----- Module 6 = MACROS -----*/
// Special macros that are to be called from within the main program loop
// This can also be a separate header file to reduce the length of the main program - check the "myVars_myFunctionsHheadersTest" repo fro example
/*----- End of Module 6 -----*/