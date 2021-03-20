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
