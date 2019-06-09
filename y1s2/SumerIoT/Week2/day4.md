# Optimization 1

## NOTES

- before buildin the interface, I need to figgure the functionalities of the whole system first
- Figgure out a way to add multiple sensors,
  - add more sensors to a single device or more individual devices
    - how the data would be transfer on a larger scale.(each device 1 payload, daisy chain)
- cleaner code
- time stamp
- More accurate data, (record in array, average data, send per sec)

## Current Design

- Single BH1750 sensor + pair with a node mcu. using the wifi capability to report data.
- Using a MQTT to push payloads for data in the format of : `xzyyyycbaaa` mie is `bb0000bd/aaa/`
  - The aggreed upon format of the data consist of:
  > - `x` = device id (a-z, A-Z, 0-9)
  > - `z` = topic (a-z, A-Z, 0-9)
  > - `y` = timestamp
  > - `c` = sensor id (a-z, A-Z, 0-9)
  > - `b` = sensor type (a-z, A-Z, 0-9)
  > - `a` = sensor reading, 3 chars
- This is relatively functional for now, but if built for a larger scale, I would like to use a Relational DB

## Functionalities

- **Purpose** record street light data, to monitor bulb condition to determine
  - Is the bulb non functional (if lux for a sensor is lower than a threshold for a certain amount of time)
  - is  the bulb deteriorating ( track if the lux deterior rates over a long period of time)


## large Scale design

- if my design is implemented on a larger scale(fitted for a city/subburb) I would perfer data is stored in a **RDMS(Relational Database Management system)** as its easier to scale up if there is more of the same `devices, sensors` in the system.
  - If its in **RBMS**, I would like to also include bulb type/ source(manufacturers), price to further compare cost v avg life time of the bulb

## Possible changes

- attatch battery?
- Since because the rate of repair is [once every 8 days for a single bulb](https://www.essentialenergy.com.au/our-network/streetlights) not nececary to record every seccond.
  - data burst - record for a few secconds every interval. (10 sec every min)
  - push data every interval (1hr)?

## TODO

- Add battery ?? Figgure out how that work
- Transmit data in itterations.
  - collect entry[10] persec/average - Package [0]
  - array of 10 entries ( using delay(100))
  - average then push every min
  - delay 59000 m


## QUESTION

- how would Turn the device off, at sunrise. On at sundown?? with out a real time clock