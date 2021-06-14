#include <Servo.h> 

Servo servo;  // create servo object to control a servo

int pos = 90;    // variable to store the servo position 

void setup() {
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 90; pos <= 180; pos += 1) { // the servo does not move at first, speed increases over time
    // in steps of 1 
    servo.write(pos);              // tell servo to increase speed to 'pos'
    delay(15);                       // waits 15ms 
  }
  for (pos = 180; pos >= 0; pos -= 1) { // slows down and starts turnin in the opposite direction
    servo.write(pos);              // tell servo to decrease/increase speed to match speed described by 'pos'
    delay(15);                       // waits 15ms 
  }
}
