# uhh I should understand these but i dont


## On the device of the group project

> I think, i am overcomplicating things with bluetooth/wifi connection

- using Arduino would make sending data to the database harder
  - limited rate? payload size
- comm protocol: 
  - MQTT would be good if using multiple mcus, for m-m communications
  - no idea what to do with BLE

## in comparing with last year project

> definitely requires a re-read

- the 2 examples varies greatly in complexity, overal project seems alot less complex
  - provided 
    - very good diagrams, doccumentation
    - scalability is only mentioned in the doc
    - pretty cool with the localisation thing
  - Haydens friends
    - decent diagrams, 
    - scalability is only mentioned in the doc
both docs outline this project is only a rough prototypez

> Data is generally insert into db using **node-red** which is p2p

- last years seems its just reading the raw 1-dimentional data from 3 sensors and have a threshold to trigger an event
- using acc/gyro/mag seems alot more complex, as it needs some calculations to translate the raw sensor data and map it to graphs
- read rate doesnt need to be high, can be slow read rate

---

## hmmmmmmmmmmmmm

- isnt the r-pi a "computer", why does it need to connect to the pc
  - sensor -> r-pi -> pc -> db (is this cloud?)
- am i overblowing/overcomplicating things or does it seems, last year use case is alot simpler
- keep it simple use node-red to insert data into local database? 
- limit to 1 device per user?

## Keeping it simple

- device strap on wrist, read arm movement
  - make it detect stability? if so need calibration



