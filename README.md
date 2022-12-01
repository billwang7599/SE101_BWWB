<h1 align="center"> 
  UWaterloo SE101 2022 | Design Project 
</h1>

---
<p align="center">
  <a href="#summary">Summary</a> •
  <a href="#set-up">Set-up</a> •
  <a href="#circuitry">Circuitry</a> •
  <a href="#materials">Materials</a> •
  <a href="#to-do">To-do</a> •
  <a href="#contributers">Contributers</a>
</p>


### Summary
---
Our proposal is to create an automated smart garden that monitors plant moisture levels and independently gauges when they need to be watered. Based around an Arduino  board framework, a soil moisture sensor receives the plants' soil data and actuates the hydration system. The orientation of the tubing is controlled by a servo motor that changes the angle of the tubing based on the location data of the plants. The amount of water needed to be pumped corresponds with each plant species’ needs found in a plant water intake API. The culminating goal is to be able to automate tending to a garden’s watering needs using the specified software and hardware applications.
<br><br>

### Set-up
---
Plug Arduino into a power source. If testing is needed, set the `bool test = true`, else `bool test = false`. Dry soil is at a soil moisture value of 500. As the soil becomes more dry, the percentage will increase. Reversely, as water content increases, the percentage will decrease. To change what soil moisture percentage you want to water at, change the variables at line 13 and 14: `float plant1Stop` and `float plant2Stop` to what is desired. It will water the soil until it reaches the percentage of the set values.
<br><br>


### Circuitry
---

<table>
<tr>
<td> 

  ### Materials:
- Arduino UNO REV3 + cable
- MMOBIEL SG90 9g Micro Servo Motor
- Gikfun 12V DC Dosing Pump
- Gikfun 2mm ID x 4mm OD Silicone Tube
- Gikfun Capacitative Soil Moisture Sensor
- Male-To-Male Jumper Wires
- Breadboard
- 60V Transistor, 10k Ohm Resistor

</td>
</tr>
</table>
  
First, we establish a connection to the Arduino Uno from the laptop. Afterwards, we attatch the Arduino to the breadboard so that it can interact with the pump, motor, and sensor. This way, we can get data from the soil and the system can act accordingly (dispenses water if needed; continues until desired soil moisture level is reached).

[![Circuit Image](https://github.com/billwang7599/SE101_BWWB/blob/main/info/Circuit.png)](https://www.circuito.io/app?components=9442,10190,10398,11021,13322)
<br><br>

### To-do
---
- [X] Setup Arduino to laptop
- [X] Connect circuitry between Arduino Uno, the breadboard, and other components
- [X] Connect Arduino Uno to computer
- [X] Test Code to activate components
    - [X] Servo Motor
    - [X] Dosing Pump
    - [X] Soil Moisture Sensor
- [X] Have sensor read moisture
- [X] Have water pump automatically after reading moisture
- [X] Have pump water different locations
- [X] Set up automated garden
<br><br>

### Contributers
---
:point_right: Bill Wang<br>
:point_right: Jerry Du<br>
:point_right: Mike Kwak<br>
:point_right: Suh Jin Kim
