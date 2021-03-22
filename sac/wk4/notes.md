# Synchronous SM

> state machines with time management

## Time interval behavior

- functionality when events are carried out by specific interval of real time (ms)
- time intervals shown as vertical lines
- time interval will usually also tied with the embedded system's operations

---

## synchronous SM

- each interval is called a **tick** with a specific rate (period)
- a SM with a specific period is called **synchronousSM** or **syncSM**
- entering a state causes near instant execution of actions then stall for the duration length of the period
  - nothing happens at this time
  - system inactive between ticks


ex 4.2.1 festive lights RIMS

ex 4.2.1 Sequence LED

ex 4.2.2 festive lights revisited

ex 4.2.3 festive lights bounce

---

## SynchSMs and time interval for inputs

- time interval are also used for inputs
- talks about temperature system taking average of readings
  - each readings are made every 3000ms and the latest 3 readings are stored to generate average

4.3.1 Fuel level sensor

- another scenario is to measure time between 2 input events

4.3.2 Baby monitor

4.3.3 reaction timer