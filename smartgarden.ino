#include <Servo.h>

#define sensorPin A5
#define pumpPin A0
#define servoPin 3
int pos;
float sensorValue = 0; 
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(pumpPin, OUTPUT); // set pump digital pin to output
  digitalWrite(pumpPin, 0); // makes sure the pump isn't on
  servo.attach(servoPin);

}

void loop() {
  // averages  huminity readings
  for (int i = 0; i <= 50; i++) { 
   sensorValue = sensorValue + analogRead(sensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0; 
 Serial.println(sensorValue); //displays average value
 delay(300);

 if (sensorValue < 200) {
    servo.write(20);
    delay(1000);

    digitalWrite(pumpPin, HIGH);
 }
 else {
   digitalWrite(pumpPin, 0);
   servo.write(120);
 }

}
