//#include <mbed.h>         // If running from PlatformIO, mbed.h must be included as a global file.
#include "mbed.h"       // this is relevant when programming in the Mbed Studio enviroment.

// Create a DigitalOut “object” called greenLED. Pass constant LED1 as a “parameter”
DigitalOut greenLED(LED1);

//These are "commented out" and so are not part of the program. You can uncomment them by removing the // characters
//Your task is to make a sequence alternating between Green+Red and just Blue 
//DigitalOut blueLED(LED2);
//DigitalOut redLED(LED3);

//The main function - all executable C / C++ applications have a main function. This is our entry point in the software
int main() 
{
    // ALL the repeating code is contained in a  “while loop”
    while(true) 
    { 
        //The code between the { curly braces } is the code that is repeated forever

        // Turn red LED ON  
        //redLED = 1; 

        // Wait 1 second (1 million microseconds)
        //wait_us(1000000); 

        // Turn red LED OFF
        //redLED = 0;

        // Turn blue LED ON  
        //blueLED = 1;

        // Wait 1 second
        //wait_us(1000000); 

        // Turn blue LED OFF  
        //blueLED = 0; 

        int i = 0;
        int j = 0;

        while(i < 2){
            // Turn green LED ON  
            greenLED = 1;

            // Wait 1 second
            wait_us(1000000); 

            // Turn greenLED OFF
            greenLED = 0;

            // Wait 1 second
            wait_us(1000000);
            i = i + 1; 
        }

        while(j < 5) {
            // Turn green LED ON
            greenLED = 1;

            // Wait 1 second
            wait_us(250000);

            // Turn greenLED OFF
            greenLED = 0;

            // Wait 1 second
            wait_us(250000);
            j = j + 1;
          }

        // Turn green LED ON  
        //greenLED = 1;

        // Wait 1 second
       // wait_us(1000000); 

        // Turn greenLED OFF
        //greenLED = 0;

        // Wait 1 second
        //wait_us(1000000);
    }
}