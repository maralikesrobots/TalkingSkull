/* TalkingSkullMeasure
 * Nov 30 2014
 * Uses potentiometer to measure exact degrees of servo
 * Based on "Knob" from Arduino by Michal Rinott
 * http://arduino.cc/en/Tutorial/Knob
 */
 
 #include <Servo.h>
 
 Servo servo1; //3 servos will be used for the skull, but only need one to measure at a time
 
 int potpin = 0;  //analog pin used to connect the potentiometer
 int val;    //variable to read the value from the analog pin 
 
 void setup() 
 { 
   servo1.attach(9);  //attaches servo to 9th pin
 } 
 
 void loop() 
 { 
   val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
   val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
   servo1.write(val);                  // sets the servo position according to the scaled value 
   delay(1000);                           // waits for the servo to move and so not constantly printing value
   Serial.println(servo1.read());
 }
 
 
