
# Virtual Pin Quick References

## [Sauce](http://iot.nortcele.win/doc/reference/virtual-pins.html)

## Quick Search

### Ctrl+f  `Vn` (replace n with a number)

- **V1** - set default text, sends a text string to device, and be displayed on the LED array.
- **V2** - set default number, same as v1 but only numeric values

- **V3** - set default U64, custom graphic on LED array. [U64 generator](https://xantorohara.github.io/led-matrix-editor/)

- **V4** - set default sensor, can use V4 to send the VPin number of a sensor on the data logger and its value displayed by the LED.

> IF  V4 == “22”, then the LED display will show the current temperature (See V22).

> IF V4 == “28”, the LED display will show the current value of the step count on the data logger (see V28).

- **V5** - set LED brightness (range 0 - 15)

- **V6** - set scroll rate or update frequency of the LED display ( range 10 - 100, increment of 5)

- **V7** - set scroll enable (bool value)

- **V8** - set temporary text, durration is set by V 12

- **V9** - set temporary number

- **V10** - set temporary U64. see V3

- **V11** - set temporary sensor, see V4

- **V12** - set temporary message timeout, set durration for temp msgs

> IF V12 == "3", durration == 3000ms or 3 sec

- **V13** - set temporary “show now”, display temp message with the same durration set in V12.
> Is this a Bool, TEST THIS, attach to sw buttons to redisplay if pressed

- **V15** - joystick input from the Blynk app, can use to controll LED.
  - LED display is 8x12
  - V15[0] sets the x coordinate (range 0-7)
  - V15[1] sets the y coordinate (range 0-11)

- **V18** - read SW_A (range 0 - 255), if Pressed V18 is > 250.

- **V19** - read SW_B (range 0 - 255), if Pressed V18 is > 250.

- **V20** - set push period, controls how often the DataLogger push data to the Blynk server. The value is in seconds
> IF V20 == "5",device will upload its data every 5 seconds.

NOTE :due to background, push periods lower than 3 seconds may not happen in time.

- **V21** - set push enable, enable or disable DataLogger to push data onto Blynk

- **V22** - read temperature from temp sensor.

- **V23** - read humidity from humidity sensor

- **V24** - read heat index (`Hmmmmmm do some googling`)

- **V25** - read dew point (`MOAR Googling`)

- **V26** - read battery voltage (does it need charging)

- **V27** - read light lux from Photosensor (Q1 on circuit)

- **V28** - read step count, calculated by the accelerometer. (`the floating blue chip with 3d axis on the back`)

- **V29** - read orientation from the accelerometer.

- **V30** - read uptime of the device in seconds. (first ex of the [tutorial](http://iot.nortcele.win/doc/tutorials/blynk-app-tab1.html#making-tab-1-display-sensor-data))

- **V31** - read chip Unique ID (UID)
> Usefull for setting up a Db and handle multiple devices.

- **V32** - read WiFi SSID (default display setting)

- **V33** - read WiFi signal strength read by the ESP8266. It is an RSSI value (Received Signal Strength Indicator). Values closer to zero indicate a better signal.

- **V34** - read local IP address (DataLogger's IP). This will normally have been assigned by the WiFi gateway.

- **unused** V14, V16, V17

[back to main](./README.md)
