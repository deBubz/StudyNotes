# IoT Architecture

## Agenda

- overview
  - intro to IoT architecture
  - why understanding matters
- need for IoT reference architecture
  - case studies 
- IoT architectural drivers
- IoT node architecture


## why understanding IoT architecture matters

## architecture

layered model

### collection of architectures

### reference model

## IoT architectural components

modular end to end

tiers

### Case Study: FMS

### Case Study: FDS

### Case Study: Azure IoT architecture

## Architectural Drivers


IoT Lifetime

IoT Data collection

IoT Data dissemination

## IoT architecture models

### Topological models

### Communication patterns

### Device Classes

## IoT Node Architecture

### Node architecture components

## Application-specific Integrated Circuit

## Field Programmable GateArray

## Comparison

## Communication interfaces

## Inter Intergrated Circuit (I2C)

example:

- CC2650 sensortag architecture
- ARM in RP4

## Comms Interfaces - summary

## Conclusions

- In IoT its better if the amount of range communications as much as possible
  - communicating 1b wirelessly at short range consumes more energy than processing that bit.
  - For **sensoria** and **berkeley** motes ratio of energy consumption of `communication:computation` is `1000:10000` 
- In contrast to other ad-hoc networks
  - sensing and data processing in IoT is essential
  - IoT have alot more nodes are more densely deployed
  - hardware must be cheap (nodes are prone to failures)
  - IoT operates under strict energy constraints
  - IoT nodes are typically static
  - Coms scheme is m-1 (data collected at a base station) not p2p