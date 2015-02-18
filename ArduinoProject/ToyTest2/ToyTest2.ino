/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
#include <Firmata.h>

byte analogPin = 0;

void analogWriteCallback(byte pin, int value)
{
    if (IS_PIN_PWM(pin)) {
        pinMode(PIN_TO_DIGITAL(pin), OUTPUT);
        analogWrite(PIN_TO_PWM(pin), value);
    }
}

const int buttonPin = 2;     // the number of the pushbutton pin
const int toyPin1 =  13;
const int toyPin2 =  12;// the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
   Firmata.setFirmwareVersion(0, 1);
   Firmata.attach(ANALOG_MESSAGE, analogWriteCallback);
   Firmata.begin(57600);
  
  // initialize the LED pin as an output:
  pinMode(toyPin1, OUTPUT);
  pinMode(toyPin2, OUTPUT);  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
}

void loop(){
  while(Firmata.available()) {
        Firmata.processInput();
    }
    // do one analogRead per loop, so if PC is sending a lot of
    // analog write messages, we will only delay 1 analogRead
    Firmata.sendAnalog(analogPin, analogRead(analogPin)); 
    analogPin = analogPin + 1;
    if (analogPin >= TOTAL_ANALOG_PINS) analogPin = 0;
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  Serial.print(buttonState);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(toyPin1, HIGH);
    digitalWrite(toyPin2, LOW);   
  } 
  else {
    // turn LED off:
    digitalWrite(toyPin2, HIGH);
    digitalWrite(toyPin1, LOW);   
  }
}
