# build plan

## Schedule

- Expanded Development plan for build
- Use Agile
- Backlog each sprint
- Describe Table

## Integration Spins


---

## presentation talking points

---

## Talking points

0. Thanks hayden, Ill be demo-ing our proof of concept.
1. So just to reiterate, The system consist of 2 BLE enabled wearable devices for a patients left and right arm the to help with monitoring their rehabilitation progress.
2. These devices then would gather data from 2 different sensors through the onboard Inertial Measurement unit which incluces
   > - Accelerometer - measure the acceleration of a patients arm
   > - Gyroscope - angular velocity of the 3 roltation axis (roll, pitch yaw). This could be useful to keep track a patients movement range


3. The data will then transmitted to R-pi acting as a hub to be processed, stored locally and sent to the cloud database. All using node-red
   - For demo purposes, wearable device transmitting data through serial to my computer.
   - as there were some issues setting up the BLE
4. lets have a look at the flows
- **Lets start with SerialRead**
  - This is to parse messages from serial and sent to their respective database tables
- **Up next the ShakeTest**
  - flow demonstrate how the generated data could be used to fulfill one of our project requirement.
  - That is to process the raw sensor data to assist the keeping track of a patient's muscle recovery progress
  - For instace this shake test can be paired with the exercise which the patient would pick up different weight dumbells and see how stable they're held up


- **3rd and fimal flow**
  - to periodically upload both raw and processed historical data to the cloud.
  - effectively acting as a buffer
  - Because of the fast rate the data is being generated, it is very resource taxing to the connection if each received messages are imidietly uploaded to the cloud. This could cause packet loss, resulting in the loss of data,

> IS pretty bad if the system was supposedly designed to be accurate.

Yep thats all for the PoC, up next my team mate Harry will present the web interface designed to used by the medical professional