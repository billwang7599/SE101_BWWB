## uWaterloo SE101 2022 | Design Project 
### Summary
---
Our proposal is to create an **automatic smart garden** that monitors the plants and waters automatically using Arduino. Using a soil moisture sensor, soil data will be sent to pumps to water the garden based on their positions. The pumps will shoot quantities of water corresponding with each plant species’ needs found in a plant water intake API. The endmost goal is to be able to automate tending to a garden’s nourishment using the specified software and hardware applications.
<br><br>

### Installation
---
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent vel leo metus. Pellentesque vel turpis pretium, consectetur diam at, pellentesque ante. Etiam eleifend gravida purus, eu laoreet diam dapibus ac. Donec sagittis vehicula diam. Integer a fermentum leo. Vestibulum sit amet metus id libero iaculis posuere. Mauris ultrices, libero et volutpat laoreet, magna ipsum tristique ligula, vitae commodo ligula tellus et tellus. Morbi mollis elit sit amet euismod faucibus. Donec at eros at sapien blandit dignissim vel nec elit. Morbi condimentum est quis ante pretium, sed facilisis turpis aliquam. Pellentesque felis dui, faucibus non lacus eget, imperdiet consectetur nunc. Aenean consequat libero id vestibulum sagittis.
<br><br>

### Circuitry
---
- Arduino UNO REV3 + cable
- MMOBIEL SG90 9g Micro Servo Motor
- Gikfun 12V DC Dosing Pump
- Gikfun 2mm ID x 4mm OD Silicone Tube
- Gikfun Capacitative Soil Moisture Sensor
- Male-To-Male Jumper Wires
- Breadboard
- 60V Transistor, 10k Ohm Resistor

First, we establish a connection to the Arduino Uno from the laptop. Afterwards, we attatch the Arduino to the breadboard so that it can interact with the pump, motor, and sensor. This way, we can get data from the soil and the system can act accordingly (dispenses water if needed; continues until desired soil moisture level is reached).

![Circuit Image](https://github.com/billwang7599/SE101_BWWB/blob/main/info/Circuit.png)
<br><br>

### To-do
---
- [ ] Setup Arduino to laptop
- [ ] Connect Arduino to motors and pumps
<br><br>

### Contributers
---
:point_right: Bill Wang<br>
:point_right: Jerry Du<br>
:point_right: Mike Kwak<br>
:point_right: Suh Jin Kim
