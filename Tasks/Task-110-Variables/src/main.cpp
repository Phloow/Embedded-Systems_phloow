/*********
Program:        Basic program to demonstrate the use of variables
Target device:  Nucleo F401RE or Nucleo F429ZI
Framework:      Mbed OS
Author:         Nicholas Outram (Task 110 from Embedded Systems Course)
Modified by:    Folarin Shomefun (slightly and using my template)
Credits:        Nicholas Outram
Code Status:    //!Mbed Studio - Not tested on Mbed Studio (leave 'libuopmsb.lib' and 'mbed-os.lib' in the root folder if you want to compile with Mbed Studio)
Code Status:    //TODO: PlatformIO - Compiled and working perfectly on F429ZI + MSB
Notes:          //?For PlatformIO, libuopmsb library folder needed to be copied into the "lib" folder as a local library. There was no need to include "mbed.h" as defining framwork in platformio.ini takes care of this
                //*Sometimes, you may need to compile more than once, if you get an error on compilation the first time> This happens very often!
*********/

/*----- Module 1 = INCLUDES (Library & files) -----*/
#include "uop_msb.h"
using namespace uop_msb;    //university of plymouth universal library for the embedded system course
/*----- End of Module 1 -----*/

/*----- Module 2 = VARIABLES NAME & TYPE DECLARATION, #DEFINES, VARIABLE INITIALIZATION, PIN DEFINITIONS, LIBRARY INSTATIATION, LIBRARY PORT / SITE ADDRESS ASSIGNMENT, FLAGS, -----*/
Buzzer buzz;    //create a "buzz" object instance of the 'Buzzer' module

PortOut LED_PORTE(PortE, LED_MASK); //assign port E of the MCU as a universal output port named 'LED_MASK'

DigitalOut LED_BAR_OE(LED_BAR_OE_PIN,1);      //Off by default
DigitalOut LED_DIGIT_OE(LED_DIGIT_OE_PIN,1);   //Off by default

DigitalOut LED_D1_LE(LED_D1_LE_PIN,0);
DigitalOut LED_D2_LE(LED_D2_LE_PIN,0);
DigitalOut LED_RED_LE(LED_RED_LE_PIN,0);
DigitalOut LED_GRN_LE(LED_GRN_LE_PIN,0);
DigitalOut LED_BLUE_LE(LED_BLUE_LE_PIN,0);

DigitalIn BlueButton(USER_BUTTON);

BusOut ledData(LED_D0_PIN, LED_D1_PIN, LED_D2_PIN, LED_D3_PIN, LED_D4_PIN, LED_D5_PIN, LED_D6_PIN, LED_D7_PIN);
/*----- End of Module 2 -----*/

/*----- Module 3 = FUNCTION PRE-DECLARATIONS - Only relevant for Arduino framwework -----*/ // none to declare
/*----- Module 4 = SETUP()  - Only relevant for Arduino framwework: Start Libraries/modules, set pin modes, start serial, start libraries, start displays, etc -----*/

/*----- Module 5 = MAIN() -----*/ // none to declare
int main()
{
    printf("\nTASK-110\n");

    // Integer
    int count = 0;
    printf("count = %d\n", count);

    // Add one to count
    count = count + 1;
    printf("New value of count = %d\n", count);

    // Char
    char character;
    character = 'A';
    printf("The character %c has the ASCII code %d\n", character, character);

    // Short
    short shortCount = 32766;
    printf("The value of shortCount is %hd\n", shortCount);
    shortCount = shortCount + 1;
    printf("add 1 and shortCount is %hd\n", shortCount);

    // Long long
    long long NN = 0x12345678ABCD0001LL; //Literal in HEX
    printf("A very large number %lld\n", NN);
    printf("A very large number in hex %llX\n", NN);

    // unsigned
    unsigned short p = 1; //16 bit
    printf("unsigned int p = %u\n", p);
    p = p - 2;
    printf("Subtract 2. Now unsigned int p = %u\n", p);

    // float 
    float pi_float = 3.1415926536;
    printf("The value of pi is approximately %f\n", pi_float);

    // double
    double pi_double = 3.1415926536l;
    printf("The value of pi is approximately %lf\n", pi_double);

    // Data type sizes (in bytes)
    printf("Size of a char is %d bytes\n", sizeof(char));
    printf("Size of a short is %d bytes\n", sizeof(short));
    printf("Size of a int is %d bytes\n", sizeof(int));
    printf("Size of a long is %d bytes\n", sizeof(long));
    printf("Size of a long long is %d bytes\n", sizeof(long long));
    printf("Size of a float is %d bytes\n", sizeof(float));
    printf("Size of a double is %d bytes\n", sizeof(double));

    // Stop
    while (true);   
}
/*-----End of Module 5 -----*/
