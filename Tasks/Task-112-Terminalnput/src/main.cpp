/*********
Program:        Basic program to demonstrate terminal input
Target device:  STM32 (Nucleo F401RE or Nucleo F429ZI)
Framework:      Mbed OS
Author:         Nicholas Outram (Task 110 from Embedded Systems Course)
Modified by:    Folarin Shomefun (slightly and using my template)
Credits:        Nicholas Outram
Code Status:    //!Mbed Studio - Not attempted in Mbed Studio
Code Status:    //!PlatformIO - Compiled and working perfectly on F429ZI + MSB. Restructured library (uopmsb) is placed on GitHub and cloned to have a local copy.
Notes:          //?For PlatformIO, the repo clone is symlinked as a dependency in platformio.ini (see mindmap for details) for any project that needs the library.
                //todo:Sometimes, you may need to compile more than once, if you get an error on compilation the first time. This happens very often!
                //!Use the "platformio.ini" and "mbed_app.json" files od this project to any new project you are compiling to use their default settings as my preferred settings.
                //?If you simply want to upload your precompiled firmware to the Nucleo board, open ".pio\build\nucleo_f429zi" and drag "firmware.bin" onto the F429ZI drive D in your windows explorer window.
*********/

/*----- Module 1 = INCLUDES (Library & files) -----*/
// include "mbed.h"     //not necessary because it has already been included in the uop_msb library
#include "uop_msb.h"
using namespace uop_msb;
/*----- End of Module 1 -----*/

/*----- Module 2 = VARIABLES NAME & TYPE DECLARATION, #DEFINES, VARIABLE INITIALIZATION, PIN DEFINITIONS, LIBRARY INSTATIATION, LIBRARY PORT / SITE ADDRESS ASSIGNMENT, FLAGS, -----*/
Buzzer buzz;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
/*----- End of Module 2 -----*/

/*----- Module 3 = FUNCTION PRE-DECLARATIONS - Only relevant for Arduino framwework -----*/ // none to declare
/*----- Module 4 = SETUP()  - Only relevant for Arduino framwework: Start Libraries/modules, set pin modes, start serial, start libraries, start displays, etc -----*/

/*----- Module 5 = MAIN() -----*/ // none to declare
int main()
{
    printf("\nTASK-112\n");

    // getchar
    char c1, c2;
    printf("\n\nPress a key\n");
    c1 = getchar();
    printf("You entered character %c which has the ASCII code %d\n", c1, c1);

    printf("\n\nPress another key\n");
    c2 = getchar();
    printf("You entered character %c which has the ASCII code %d\n", c2, c2);

    // scanf
    printf("\n\nTo set the delay (in ms), type in an integer number and press return\n");
    int delay_ms;
    int parsed = scanf("%d", &delay_ms);

    printf("You entered %d correct integer values. The value was %dms\n", parsed, delay_ms);

    // Stop
    while (parsed > 0)
    {
        wait_us(delay_ms * 1000);
        led1 = 1;
        led2 = 1;
        led3 = 1;
        wait_us(delay_ms * 1000);
        led1 = 0;
        led2 = 0;
        led3 = 0;
    }

    printf("Invalid - please restart and try again\n");
    while (1)
        ;
}
/*-----End of Module 5 -----*/

/*----- Module 6 = MACROS -----*/
// Special macros that are to be called from within the main program loop
// This can also be a separate header file to reduce the length of the main program - check the "myVars_myFunctionsHheadersTest" repo fro example
/*----- End of Module 6 -----*/