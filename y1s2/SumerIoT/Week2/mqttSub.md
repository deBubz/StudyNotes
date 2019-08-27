# Something

Analyse dis convert to Sub only

```js
var mqtt = require('mqtt')
var client  = mqtt.connect('mqtt://test.mosquitto.org')
 
client.on('connect', function () {
    // why is this here
  client.subscribe('presence', function (err) {
    if (!err) {
        // publish Hello mqtt to topic presence
      client.publish('presence', 'Hello mqtt')
    }
  })
})
 
client.on('message', function (topic, message) {
  // message is Buffer
  console.log(message.toString())
  client.end()

  // Output: Hello Mqtt
})
```