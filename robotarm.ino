#include <Servo.h>

Servo claw;
Servo base;
Servo upanddown;
Servo forwardsandbackwards;// create servo object to control a servo
int pos = 90; // variable to store the servo position

int VRx1 = A0;
int VRy1 = A1;
int SW1 = 11;

int xPosition1 = 0;
int yPosition1 = 0;
int SW_state1 = 0;
int mapX1 = 0;
int mapY1 = 0;

int VRy2 = A2;
int VRx2 = A3;
int SW2 = 12;

int xPosition2 = 0;
int yPosition2 = 0;
int SW_state2 = 0;
int mapX2 = 0;
int mapY2 = 0;

void setup() {
    // attaches the servo on pin 9 to the servo object
  base.attach(2);
  claw.attach(4);
  upanddown.attach(3);
  forwardsandbackwards.attach(5);
  
  Serial.begin(9600); 
  pinMode(VRx1, INPUT);
  pinMode(VRy1, INPUT);
  pinMode(SW1, INPUT_PULLUP); 
}

void loop() {
  xPosition1 = analogRead(VRx1);
  yPosition1 = analogRead(VRy1);
  SW_state1 = digitalRead(SW1);
  mapX1 = map(xPosition1, 0, 1023, -512, 512);
  mapY1 = map(yPosition1, 0, 1023, -512, 512);
  
  xPosition2 = analogRead(VRx2);
  yPosition2 = analogRead(VRy2);
  SW_state2 = digitalRead(SW2);
  mapX2 = map(xPosition2, 0, 1023, -512, 512);
  mapY2 = map(yPosition2, 0, 1023, -512, 512);
  
  
  Serial.print("X1: ");
  Serial.print(mapX2);
  Serial.print(" | Y1: ");
  Serial.print(mapY2);
  Serial.print(" | Button1: ");
  Serial.println(SW_state2);

  delay(100);
  base.write(90);
  claw.write(90);
  while(mapX2 < -300)
  {
    xPosition2 = analogRead(VRx2);
    yPosition2 = analogRead(VRy2);
    SW_state2 = digitalRead(SW2);
    mapX2 = map(xPosition2, 0, 1023, -512, 512);
    mapY2 = map(yPosition2, 0, 1023, -512, 512);  
    claw.write(100);
    delay(10);
    Serial.println(mapX2);
    
  } 
  while(mapX2 > 300)
  {
    xPosition2 = analogRead(VRx2);
    yPosition2 = analogRead(VRy2);
    SW_state2 = digitalRead(SW2);
    mapX2 = map(xPosition2, 0, 1023, -512, 512);
    mapY2 = map(yPosition2, 0, 1023, -512, 512);
    claw.write(85);
    delay(10);
    Serial.println(mapX2);
  }
   while(mapX1 < -500)
  {
    xPosition1 = analogRead(VRx1);
    yPosition1 = analogRead(VRy1);
    SW_state1 = digitalRead(SW1);
    mapX1 = map(xPosition1, 0, 1023, -512, 512);
    mapY1 = map(yPosition1, 0, 1023, -512, 512);
    base.write(180);
    delay(10);
    Serial.println("X");
    Serial.println(mapX1);
    
  }
   while(mapX1 > 300)
  {
    xPosition1 = analogRead(VRx1);
    yPosition1 = analogRead(VRy1);
    SW_state1 = digitalRead(SW1);
    mapX1 = map(xPosition2, 0, 1023, -512, 512);
    mapY1 = map(yPosition2, 0, 1023, -512, 512);
    base.write(20);
    delay(10);
    Serial.println("X");
    Serial.println(mapX1);
  }
  while(mapY2 < -500)
  {
    xPosition2 = analogRead(VRx2);
    yPosition2 = analogRead(VRy2);
    SW_state2 = digitalRead(SW2);
    mapX2 = map(xPosition2, 0, 1023, -512, 512);
    mapY2 = map(yPosition2, 0, 1023, -512, 512);
    claw.write(180);
    delay(10);
    Serial.println(mapY2);
    
  } 
  while(mapY2 > 300)
  {
    xPosition2 = analogRead(VRx2);
    yPosition2 = analogRead(VRy2);
    SW_state2 = digitalRead(SW2);
    mapX2 = map(xPosition2, 0, 1023, -512, 512);
    mapY2 = map(yPosition2, 0, 1023, -512, 512);
    claw.write(20);
    delay(10);
    Serial.println(mapY2);
  }
   while(mapY1 < -300)
  {
    xPosition1 = analogRead(VRx1);
    yPosition1 = analogRead(VRy1);
    SW_state1 = digitalRead(SW1);
    mapX1 = map(xPosition1, 0, 1023, -512, 512);
    mapY1 = map(yPosition1, 0, 1023, -512, 512);
    upanddown.write(150);
    delay(10);
    Serial.println("Y");
    Serial.println(mapY1);
    
  }
   while(mapY1 > 300)
  {
    xPosition1 = analogRead(VRx1);
    yPosition1 = analogRead(VRy1);
    SW_state1 = digitalRead(SW1);
    mapX1 = map(xPosition2, 0, 1023, -512, 512);
    mapY1 = map(yPosition2, 0, 1023, -512, 512);
    upanddown.write(85);
    delay(180);
    Serial.println("Y");
    Serial.println(mapY1);
  }
  
}
