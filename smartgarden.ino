#include <Servo.h>

Servo servo;
int analogPin;  //needs to be set

void setup() {
  servo.attach(2);  //attaches the servo on pin 9

  //make the transistor's pin an output
  pinMode(9, OUTPUT);
  
  Serial.begin(9600);
  while(! Serial);
  Serial.println("__________________");
  Serial.println("--Welcome to the--");
  Serial.println("---SMART GARDEN---");
  Serial.println("_______Demo_______");
}

int pos;
int huminity;

void loop() {
  //measure moisture level
  huminity = analogRead(analogPin);
  Serial.print("Current Huminity: ");
  Serial.println(huminity);
  delay(3000);
  
  if(huminity < 0.5){
    digitalWrite(9, 20);
    
    for(int i = 0; i < 10; i++){
      for(pos = 45; pos <= 135; pos += 1){
        servo.write(pos);
        delay(20);
      } 
      for(pos = 135; pos >= 45; pos -= 1){
        servo.write(pos);
        delay(20);
      }
    }
    digitalWrite(9, 0);
  }

  //delay(60000);
  
}
