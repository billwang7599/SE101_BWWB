#include <Servo.h>

Servo servo;

int pos;

void setup() {
  servo.attach(2);  //attaches the pervo on pin 9

  //make the transistor's pin an output
  pinMode(9, OUTPUT);
  
  Serial.begin(9600);
  while(! Serial);
  Serial.println("__________________");
  Serial.println("--Welcome to the--");
  Serial.println("---SMART GARDEN---");

  
  
  String plant = "a";
  
}

int huminity;

void loop() {
  // put your main code here, to run repeatedly:

  //measure moisture level
  //huminity = ____
  Serial.print("Current Huminity: ");
  Serial.println(huminity);
  delay(3000);
  
  if(huminity < 0.5){
    //open pump
    analogWrite(9, 20);
    for(pos = 45; pos <= 135; pos += 1){
      servo.write(pos);
      delay(20);
    }
    for(pos = 135; pos >= 45; pos -= 1){
      servo.write(pos);
      delay(20);
    }
  }

  //delay(60000);
  
}
