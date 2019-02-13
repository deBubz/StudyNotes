# 2nd Sprint day 1

## S

## Week Plan

- Completing 

- figgure out poc (move data from DLogger to Broker via ESP8266)
  - `pending` from ESP8266 to Broker [PubSubClient API](https://github.com/knolleary/pubsubclient/blob/master/examples/mqtt_esp8266/mqtt_esp8266.ino)
  - Create another Vultr Server to insert data in DB (sqlServer) (see 3. below)

## Guest Lec

- Systems Engineering & Design thinking

## Notes

- bh1750 Addr pin to GnDh

- Catching up in making a Proof of Concept prototype
  - Working light sensor (BH1750)
  - Working data publishing to MQTT broker (leonidas )

- Use Library examples Bh1750 and Mqtt from PlatformIo

- Device Framework
  1. Device(publisher)
  1. MQTT broker(leonidas)
  1. Subscriber serv()
  1. DB serv(turtle)
  1. Webapp server (grab data, process, present on a website).