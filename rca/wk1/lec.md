# Introduction to Embedded Systems

## Overview

- basic concepts of embedded system, embedded processor & its interfaces
  - i/o pins
- using RIMS (a gui simulator) to learn the concepts in this subjects
- understand the requirements of carious components in the embedded system

## Embedded System

embedded systems encompasses
- **electrical devices**
  - embedded with microprocessors (every piece of electronics out there)
- **microprocessors**
  - perform a small number of specific(dedicatied) functions
  - constrains by processsing power, performance size, time, cost (iot concepts)

### Moores law

- IC will double in transistor capacity in every 18 month

## Integratec circuits & Moore's Law

> doesnt explain IC

> look up wiki??

## Bit, switch & Button

- You prob know what this is, but in embedded context
  - **1** HIGH
  - **0** LOW
- this doesnt represent **voltage** but the signal if its on or off
- usually abstracts to abinary value, it changing value overtime is called a digital **signal** 
- often represented as button/ switch / led

## Timing diagram & pulse

> here comes the interesting stuff

- Signal change terminology
  - **0 - 1** rising
  - **1 - 0** falling
  - **pulse** signal portion started by a rising event & ended by a falling event

> is this PWM - pulse width modulation

## Testing

> generic testing paradigm for software engineerign

- Test edgecases, ensure 100% coverage
- USE PRINT STATEMENTS LMAO