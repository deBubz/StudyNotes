# Sensors and actuators

## Agenda

- recap on contents
- overview on sensing
- sensors and actuators
- sensor systems
- sensors and acuators characteristics
- A/D and D/A conversions
- Important Theorems

## Recap 1 & 2

What is IoT


Sensing

- Sensor
- actuator
- tranducer
- signal conditioning
- A-D conversion

IoT node architecture

IoT Architecture and Modelling

---

## On Sensing

### Data Aquisition and Control

- two way traffic of sensor data and actuation data
  - Sensor: physical world signals converts to digital data to be processed
  - Actuator: digital signal converts into physical interactions

> what about traffic of *config controls*, *sens/acs calibration*, *energy management*, *radio management* and *hardware setups* 

Sensors, Actuators & Transdusors (sensor types)

1. Analog
2. Discrete
  - binary
  - digital

some sensor types

- sound
- touch
- ultrasonic
- light
- rfid
- barcode
- proximity
- vision
- gyroscope
- compass
- tilt/acceleration

Sensor Examples

> have a look for some ideas sl 10

## Sensor Systems

- converts desired parameter into ellectrically measured signal
- General components of electronic sensor
  - **primary tranducer** changes real world params into electrical signal
  - **secondary tranducer**: converts electrical signal into analog/digital values

> In a sensor the 
> Prime tranducer convert realworld signals into analog signal
>
> THEN sec tranducer converts that into usable values
>
> THEN gets processed by the microcontroler to be sent through the network

- The sensor components varies depends on the application
  - Digital sensors within an instrument
  - MC with signal timing
  - Data storage

> lost

- Analog sensor analyzed by a PC
- Multiple sensors dispayed over the internet

## Integrated MEMS System

**MEMS** micro electro mechanical system (verry small, mini tranducers creted using IC fabrication processes)

> these are probably some examples

- Micro-accelerometer
  - cantilever beam
  - suspended mass
- Roltation - gyro
- Pressure

## Actuators

- These are devices taht convert a controler command into a **change** in a physical parameter
  - **change** is usually mechanical (pos or velocity)
  - also counts as a **tranducer** as it changes one type of quantity(physical) into another form
  - usually activated by a low-level command signal, may require an amp to provide sufficient power to activate the actuator

### Type of Actuators

1. Electrical actuators
   - motors (DC servomotors, AC motors, stepper motors)
2. Hydraulic actuators
   - use hydraulic fluid to amp the controller command signals
3. Pneumatic actuators
   - use compressed air as driving force

> sl 16 some diagrams explaining how stepper motor and servomotor works
>
> sl 17 some maths for eng stuff i guess?

## Characteristics of Sensors & Actuators

- **response function**: output v quantity being sensed 
- **sensitivity**: change in output/unit change in input (how sensitive)
- **linearity error**: difference between sensor response and a best fit line?
- **accuracy error**
- **stability**: rate of fluctuation? repetition of result
- **noise**: part of the signal that is independent of quantity being sensed
- **response time**: how quickly the output respond to abrubt changes in input
- **temp coefficient**: changes in sensor's response per unit temp. this characteristics aplied to all sensors (sensors result depending on env temp)
- **hysteresis (backlash)**: sensr output depends of previous history? common in magnetic and mechanical systems? (does it mean it needs calibration)

## Characterisits of measurements system

sensor classification

> s20 some sensors examples for sensor type:
>
> resistive, capacitive, inductive, electro magnetic, generating...

range, span, linearity

- **range**: sensor min-max value
- **span**: varuation in i/o
- **linearity**: no idea what tisis
- non-linearity

> some eng stuff

hysteresis and sensitivity

accuracy, resolution and precision

## Analog to Digital conversion

- important features
- quantisation
- encoding
- resolution
- conversion time
- conversion method

successive approximation methods

## Digital to Analog Conversion

---

## Intro Friis Formula

## Intro Shannon Capacity Theorem
