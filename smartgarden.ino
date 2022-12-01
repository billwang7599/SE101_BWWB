#include <Servo.h>

#define sensorPin1 A5 //Soil moisture sensor 1
#define sensorPin2 A3 //Soil moisture sensor 2
#define pumpPin A0 //pump
#define servoPin 3 //servo

int avg = 100; // average of this many readings
float sensorValue1 = 0; // Soil moisture sensor 1 value
float sensorValue2 = 0; // Soil moisture sensor 2 value
int plant1Water = 500; // once it reaches a dryness level of INT, it would start watering
int plant2Water = 500; // same as above -- higher values means less moisture
float plant1Stop = 0.90; // dryness percent for it to stop
float plant2Stop = 0.80; // same as above
int timeDelay = 0; // time before each read (ms)
Servo servo; // Initializes Servo as servo

// define vars for testing menu
const int timeout = 10000;     //define timeout of 10 sec
char menuOption = 0;
long time0;
bool test;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT); // set pump digital pin to output
  digitalWrite(pumpPin, 0); // makes sure the pump isn't on
}

void loop() {
  bool  test = true; // whether or not to test each component
  sensorValue1 = 0; // resets sensor values
  sensorValue2 = 0;

  // averages  huminity readings
  for (int i = 0; i <= avg; i++) {  //sensor 1
    sensorValue1 = sensorValue1 + analogRead(sensorPin1);
    delay(50);
  }
  for (int i = 0; i <= avg; i++) { // sensor 2
   sensorValue2 = sensorValue2 + analogRead(sensorPin2); 
    delay(50);
  } 
  sensorValue1 = sensorValue1/avg;
  sensorValue2 = sensorValue2/avg;
  
  Serial.print("Plant 1 dryness: ");
  Serial.print(sensorValue1/plant2Water*100); //displays avg percentage value /plant1Water*100
  Serial.print("%");
  Serial.println();
  Serial.print("Plant 2 dryness: ");
  Serial.print(sensorValue2/plant2Water*100); //displays avg percentage value
  Serial.print("%");
  Serial.println();
  Serial.println();
  delay(300);

  if (sensorValue1/plant1Water > plant1Stop) {
    servo.attach(servoPin); // initializes servo to the respective pin
    servo.write(10); // turns servo 10 degrees from base (0)
    digitalWrite(pumpPin, HIGH); // turns on pump

    while (sensorValue1/plant1Water > plant1Stop) { // if the dryness percent is too high, continue to water
      sensorValue1 = 0;
      for (int i = 0; i <= avg; i++) {  //sensor 1
        sensorValue1 += analogRead(sensorPin1); 
        delay(50);
      } 
      sensorValue1 = sensorValue1/avg;

      /*/DISPLAYS THE VALUE
      Serial.print("Sensor 1: ");
      Serial.print(sensorValue1/plant1Water); //displays average value
      Serial.println();
      Serial.println();
      */
      
    }
    delay(1000);
  }
  
  if (sensorValue2/plant2Water > plant2Stop) {
    servo.attach(servoPin); // initializes servo to the respective pin
    servo.write(120); // turns servo 120 degrees from base (0)
    digitalWrite(pumpPin, HIGH); // turns on pump

    while (sensorValue2/plant2Water > plant2Stop) { // if the dryness percent is too high, continue to water
      sensorValue2 = 0;

      for (int i = 0; i <= avg; i++) { // sensor 2
        sensorValue2 += analogRead(sensorPin2); 
        delay(50);
      } 
      sensorValue2 = sensorValue2/avg;
      /*/ DISPLAYS THE VALUE
      Serial.print("Sensor 2: ");
      Serial.print(sensorValue2/plant2Water); //displays average value
      Serial.println();
      Serial.println();
      */
      
    }
    delay(1000);
  }
  
  if (test) {
    digitalWrite(pumpPin, 0);
    menuOption = menu();
    if(menuOption == '1') {
      servo.attach(servoPin);
      servo.write(10);
      delay(1000); 
      servo.write(120);       
      delay(1000); 
      servo.write(10);
      delay(1000); 
      servo.write(120);       
      delay(1000); 
      servo.write(10);
      delay(1000); 
    }
    else if(menuOption == '2') { // waters mint (1)
      servo.write(10);
      digitalWrite(pumpPin, HIGH);
      delay(10000);
    }
    else if(menuOption == '3') { // waters rosemary (2)
      servo.write(120);
      digitalWrite(pumpPin, HIGH);
      delay(10000);
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
  }

  Serial.println();
  digitalWrite(pumpPin, 0); // stops pump
  delay(1000);
  servo.detach(); // detaches servo to save power 
  delay(1000);
  if (!test) delay(timeDelay); // waits 1 minute before checking again
}

// testing
char menu()
{

    Serial.println(F("\nMenu: "));
    Serial.println(F("(1) Servo"));
    Serial.println(F("(2) Water Mint"));
    Serial.println(F("(3) Water Rosemary"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now testing servo"));
    		else if(c == '2') 
    			Serial.println(F("Now watering Mint (1)"));
    		else if(c == '3') 
    			Serial.println(F("Now watering Rosemary (2)"));
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
