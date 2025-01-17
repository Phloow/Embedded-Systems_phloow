/*********
Program:        Basic program to demonstrate traffic light operation using the module support board and its peripherals.
Target device:  Nucleo F401RE or Nucleo F429ZI
Framework:      Mbed OS
Author:         Nicholas Outram (Task 104 from Embedded Systems Course)
Modified by:    Folarin Shomefun (slightly and using my template)
Credits:        Nicholas Outram
Code Status:    //! Mbed Studio - Not tested on Mbed Studio; leave 'libuopmsb.lib' and 'mbed-os.lib' in the root to compile with Mbed Studio
Code Status:    //* PlatformIO - Compiled and working perfectly on F429ZI + MSB. Restructured library (uopmsb) is placed on GitHub and cloned to have a local copy.
Notes:          //? For PlatformIO, the repo clone is symlinked as a dependency in platformio.ini (see mindmap for details) for any project that needs the library.
                //todo: Sometimes, you may need to compile more than once, if you get an error on compilation the first time> This happens very often!
*********/

/*----- Module 1 = INCLUDES (Library & files) -----*/
// include "mbed.h"  //not necessary because it has already been included in the uop_msb library
#include "uop_msb.h" //university of plymouth universal library for the embedded system course
using namespace uop_msb;
/*----- End of Module 1 -----*/

/*----- Module 2 = VARIABLES NAME & TYPE DECLARATION, #DEFINES, VARIABLE INITIALIZATION, PIN DEFINITIONS, LIBRARY INSTATIATION, LIBRARY PORT / SITE ADDRESS ASSIGNMENT, FLAGS, -----*/
#define WAIT_TIME_MS 500

DigitalOut red(TRAF_RED1_PIN, 1);   //'TRAF_RED1_PIN' decalred in the uop_msb library and is the alias for PC_2. Note the initial state
DigitalOut amber(TRAF_YEL1_PIN, 0); //'TRAF_YEL1_PIN' decalred in the uop_msb library and is the alias for PC_3.
DigitalOut green(TRAF_GRN1_PIN, 0); //'TRAF_GRN1_PIN' decalred in the uop_msb library and is the alias for PC_6.

LCD_16X2_DISPLAY lcd; // instatiate the LCD library(part of the 'uop_msb' library) with a user-defined object called "lcd"
/*----- End of Module 2 -----*/

/*----- Module 3 = FUNCTION PRE-DECLARATIONS - Only relevant for Arduino framwework -----*/ // none to declare
/*----- Module 4 = SETUP()  - Start Libraries/modules, set pin modes, start serial, start libraries, start displays, etc //!Only here for Arduino framwework. For Mbed, this goes under "int main()" module before the while(1) loop) -----*/

/*----- Module 5 = MAIN() -----*/
int main()
{
    lcd.puts("Red");  // show "RED" on LCD because red LED was initialised as ON at the beginning of the code
    wait_us(3000000); // slight delay for 1s

    amber = 1;         // turn on the YEL led
    lcd.cls();         // erase the LCD
    lcd.puts("Amber"); // display "Amber" to match the LED
    wait_us(3000000);  // slight delay

    green = 1;         // turn on green LED
    lcd.cls();         // clear screen
    lcd.puts("Green"); // display "Green" to match LED
    wait_us(3000000);

    lcd.cls();
    lcd.puts("TASK-104");

    // Infinite loop
    while (true) // infintie loop starts here
    {
        red = !red;     // invert status of red led
        amber = !amber; // invert status of amber led
        green = !green; // invert status of green led
        wait_us(WAIT_TIME_MS * 1000);
    }
}
/*----- End of Module 5 -----*/

/*----- Module 6 = MACROS -----*/
// Special macros that are to be called from within the main program loop
// This can also be a separate header file to reduce the length of the main program - check the "myVars_myFunctionsHheadersTest" repo fro example
/*----- End of Module 6 -----*/
