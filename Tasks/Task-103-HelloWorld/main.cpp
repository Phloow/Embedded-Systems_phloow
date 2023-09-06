/*********
Program: Basic program to test the module support board and its peripherals.
Target device: Nucleo F401RE or Nucleo F429ZI
Framework: Mbed OS
Author: Nicholas Outram (Task 103 from Embedded Systems Course)
Modified by: Folarin Shomefun (slightly and using my template)
Credits: Nicholas Outram
Code Status (Mbed Studio): Compiled and working perfperfectly on F429ZI + MSB
Code Status (PlatformIO): Compiled and working perfperfectly on F429ZI + MSB
Notes: 
*********/

/*----- Module 1 = INCLUDES (Library & files) -----*/
#include "uop_msb.h"    //university of plymouth universal library for the embedded system course
using namespace uop_msb;
/*----- End of Module 1 -----*/

/*----- Module 2 = VARIABLES NAME & TYPE DECLARATION, #DEFINES, VARIABLE INITIALIZATION, PIN DEFINITIONS, LIBRARY INSTATIATION, LIBRARY PORT / SITE ADDRESS ASSIGNMENT, FLAGS, -----*/
#define WAIT_TIME_MS 2000

//Initialise the DigitalOut objects with a default value of 1
DigitalOut ledGreen(PB_0, 1);   // Instantiate the DigitalOut method as a variable called "ledGreen" and pass the port we want to control as its parameter and initialise it to "1" - HIGH. LED 1 is on PB_0 of F429ZI. Unlike Arduino where you have to define a port pin first before setting the mode(OUT or IN), you do this in one go in mbed!
DigitalOut ledBlue(PB_7, 1);    // Instantiate as "ledBlue" and initialise to "1". You can as well replace PB_0, PB_7 and PB_14 with "LED1", "LED2", and "LED3" which are library-defined aliases for these pins 
DigitalOut ledRed(LED3, 1);     // The alias for PB_14 is used here. Instantiate as "ledRed" and initialise to "1"
LCD_16X2_DISPLAY lcd;           // Instantiate the LCD_16X2_DISPLAY class of the libuopmsb library by creating an object "lcd" for it
/*----- End of Module 2 -----*/

/*----- Module 3 = FUNCTION PRE-DECLARATIONS - Only relevant for Arduino framwework -----*/ // none to declare
/*----- Module 4 = SETUP()  - Only relevant for Arduino framwework: Start Libraries/modules, set pin modes, start serial, start libraries, start displays, etc -----*/

/*----- Module 5 = MAIN() -----*/ // none to declare
int main(){
    printf("Hello World\n");        // Write to serial terminal on host PC. Equivalent of "Serial.print()"" in Arduino
    lcd.cls();  // Clear the LCD screen
    wait_us(1000 * WAIT_TIME_MS);   //Small pause for 1s. This is usually necessary to allow the LCD settle after initialisation   
    
    ledRed = 0;     //Turn off red LED
    ledBlue = 0;    //Turn off blue LED
    ledGreen = 0;   //Turn off green LED
    
    lcd.printf("Hello World");  //Write to LCD using the LCD_16X2_DISPLAY driver class. By default, characters start at (0, 0) after a clear screen unless explictly directed otherwise via cursor setting (x, y) == (row, column)
    lcd.locate(1, 0);           //Row 1, Col 0 (x, y) coordinate convention
    lcd.printf("ELEC143");

    volatile int counter = 0;           //define a variable, "counter"
    while (true){                       //infintie loop starts here
        ledBlue = !ledBlue;             //Toggle the blue LED
        counter++;                      //increment "counter"
        printf("Count: %d\n", counter); //Display in the terminal      
        wait_us(WAIT_TIME_MS * 1000);   //Wait
    }
}
/*-----End of Module 5 -----*/
