

#include "Arduino.h"
#include "IR.h"
#include "IRremoteInt.h"
#include "IRremote.h"



#define IR_PIN_OUT	2




IR ir(IR_PIN_OUT);



const int timeout = 10000;       
long time0;


void setup() 
{
    
    Serial.begin(9600);
    while (!Serial) ; 
    Serial.println("start");
    
    // initialize IR device
    ir.init();
    menuOption = menu();
    
}


{
    
    
    if(menuOption == '1') {
   
    long irCode =  ir.detect();
    
    if(irCode)
    {
    Serial.print("0x");
    Serial.println(irCode, HEX);
    }
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}




char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) IR Receiver Diode - TSOP38238"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing IR Receiver Diode - TSOP38238"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
