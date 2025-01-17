// You need this to use the Module Support Board
//include "mbed.h"  //not necessary because it has already been included in the uop_msb library
#include "uop_msb.h"    //university of plymouth universal library for the embedded system course
using namespace uop_msb;

#define WAIT_TIME_MS 500    // set a base line delay time as 500 (constant) and name it "WAit_TIME_MS"
DigitalOut greenLED(TRAF_GRN1_PIN); //instantiate an LED for the 'DigitalOut' object
Buzzer buzz;        // instantiate 'Buzzer' as 'buzz'
Buttons buttons;    // instantuate 'Buttons' as 'buttons'

// TIP: (I suggest you read this!)
//
// Press the black reset button to restart the code (and stop the sound)
// Otherwise, the noise can be "distracting" :)

int main()
{
    //Wait for the BLUE button to be pressed (otherwise this becomes super annoying!)
    while (buttons.BlueButton == 0);
    
    //Repeat everything "forever" (until the power is removed or the chip is reset)
    while (true)
    {
        //On for 500ms
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 1000);  //500ms


        //Off for 500ms
        greenLED = 0;
        buzz.playTone("C", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS * 1000);  //500ms

        //Pause
        buzz.rest();
        wait_us(WAIT_TIME_MS * 1000);
    }
}