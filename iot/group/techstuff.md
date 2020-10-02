# project scope

the tech stuff atleast

thanks for getting back to be about this issue  



Lab 3 Team 2

## The plan

- set up 2x Arduino nano 33 BLE units to monitor the movement of left and right arms or legs of the patient using a gyroscope/accelator during a physio session

> Can I reconfirm the mcu you cold lend are the **Arduino nano 33 BLE sense(with sensors)** or **Arduino nano 33 BLE (without sensors)**

- that data would then be transfererd into a hub (r-pi) via BLE 
- and through node-red to process the raw data, then packaged it to be stored into a cloud db. We're currently deciding between influxdb or mongodb. If we choose influx, we'll use node-red, if mongo we'll probably use node.

Hence the group's system will have 3 devices per doctor.

So far, using what i have, just as a demo, ive managed to set up a nodemcu + a gyro/acc (GY-521) and transfer data to a cloud server through wifi + mosquitto mqtt.
And was able to read the data from both the command line and on node-red.

The decision to use BLE and transfer data into a hub was because i think, for this usecase, its better to get the data at a faster rate since It would produce more accurate and usable data. Having it packaged before saving to the cloud server would be a lot less resouce demanding on the cloud server.
Which is very different and seems quite harder from last years use case ( the fire alarm system )

That brought us to one of our current issues to figgure out. Im not sure how fast the read rate should be an how to bundle up the raw data effectively to minimise errors.

If you could help us figgure this out or point me to any extra resources that could help, I would be very greatful.

Looking forward to hear back from you.

Thankyou for your time and kind regards,
Bao Hoang