## uWaterloo SE101 2022 | Design Project 
### Summary
---
Our proposal is to create an **automatic smart garden** that monitors the plants and waters automatically using Arduino. Using a soil moisture sensor, soil data will be sent to pumps to water the garden based on their positions. The pumps will shoot quantities of water corresponding with each plant species’ needs found in a plant water intake API. The endmost goal is to be able to automate tending to a garden’s nourishment using the specified software and hardware applications.
<br>

### Installation
---
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent vel leo metus. Pellentesque vel turpis pretium, consectetur diam at, pellentesque ante. Etiam eleifend gravida purus, eu laoreet diam dapibus ac. Donec sagittis vehicula diam. Integer a fermentum leo. Vestibulum sit amet metus id libero iaculis posuere. Mauris ultrices, libero et volutpat laoreet, magna ipsum tristique ligula, vitae commodo ligula tellus et tellus. Morbi mollis elit sit amet euismod faucibus. Donec at eros at sapien blandit dignissim vel nec elit. Morbi condimentum est quis ante pretium, sed facilisis turpis aliquam. Pellentesque felis dui, faucibus non lacus eget, imperdiet consectetur nunc. Aenean consequat libero id vestibulum sagittis.
<br>

### Circuitry
---
- Arduino UNO REV3 + cable
- MMOBIEL SG90 9g Micro Servo Motor
- Gikfun 12V DC Dosing Pump
- Gikfun 2mm ID x 4mm OD Silicone Tube
- Gikfun Capacitative Soil Moisture Sensor
- Male-To-Male Jumper Wires
- "Small Breadboard"
- *possibly: 60V Transistor, 10k Ohm Resistor*

First, we establish a connection to the Arduino Uno from the laptop. Afterwards, we attatch the Arduino to the breadboard so that it can interact with the pump, motor, and sensor. This way, we can get data from the soil and the system can act accordingly.
<br>

### To-do
---
- [ ] Setup Arduino to laptop
- [ ] Connect Arduino to motors and pumps
[^1]: Bill Wang, Jerry Du, Mike Kwak, Thomas Kim [^1]
