
Week 2: Concepts, Definitions, Models and Applications

**Week Agenda**

# Intro

- [Intro](#intro)
  - [Common Terms](#common-terms)
- [Key concepts and definition](#key-concepts-and-definition)
  - [Wireless Sensor Network/ IoT](#wireless-sensor-network-iot)
  - [Edge/ IoT Computing/ Fog](#edge-iot-computing-fog)
  - [Various Terms](#various-terms)
- [IoT Components](#iot-components)
  - [Sensor Network and Nodes](#sensor-network-and-nodes)
  - [IoT Node Components](#iot-node-components)
  - [IoT NOde Services](#iot-node-services)
- [Characteristics](#characteristics)
  - [Other Characteristis](#other-characteristis)
- [Categories of Apps](#categories-of-apps)
  - [Examples](#examples)
    - [Habitat Monitoring](#habitat-monitoring)
    - [Health Monitoring](#health-monitoring)
    - [Precision Agiculture/ vertical Agriculture](#precision-agiculture-vertical-agriculture)
    - [Condition-based Maintenance](#condition-based-maintenance)
- [IoT Enablers](#iot-enablers)
- [Challenges and Issues](#challenges-and-issues)
  - [Challenges](#challenges)
    - [Energy](#energy)
    - [Network layers protocols and software](#network-layers-protocols-and-software)
    - [Communications issues](#communications-issues)
    - [Autonomics: self management](#autonomics-self-management)
    - [Autonomics](#autonomics)
    - [Decentralization](#decentralization)
    - [Security](#security)
    - [Design Constraints](#design-constraints)
    - [Design Issues](#design-issues)
  - [Other Issues](#other-issues)
    - [Data Aggregation](#data-aggregation)
    - [Different type of queries](#different-type-of-queries)
    - [Routing and group Communications](#routing-and-group-communications)
    - [Routing Protocols](#routing-protocols)
    - [Event/clock Synchronisation](#eventclock-synchronisation)
    - [Localisation](#localisation)
    - [Fault Tollerance](#fault-tollerance)
    - [Computing inIoT](#computing-iniot)
    - [Cooprerative Processing](#cooprerative-processing)
    - [IoT Architectural Decomposition](#iot-architectural-decomposition)
- [Active Areas of Development](#active-areas-of-development)
- [Conclusion](#conclusion)

## Common Terms

Hoooly 

- IOT, WSN and motes
- Sensor
- Actuator
- Network topology
- Routing
- Data-centric
- Geographic routing
- In-network
- State
- Uncertainty
- Sensor Task
- Cooperative processing
- Detection
- Classification
- Clustering
- Localisation and tracking
- Value of information or information utility
- Resource Management
- System Performance goal
- Evaluation Metrics
- Node services
- Data storage
- Embedded OS

# Key concepts and definition

the **Internet of things** is a network of connected devices with a unique identifier(ip),
have embedded technologies that enabled them to **sense**, **collect**, and **communicate data** about themselves or the environment theyre placed

There are many flavours of Iot:

- Industrial Internet of Things
- Internet of Everything (people, processes, data)
- Consumer IoT

The `potential` *doesnt just* rely on its ability to connect IoT enabled obj nor in the embedded tech such as sensors, actuatorsm embedded devices and connectivity capabilities

> IoT's potential comes from how its used to project insight from data, automate, digitise, digitalise, visualise, optimise and in more mature stages transform processes, business model and even industries ina scope of digital transformation

## Wireless Sensor Network/ IoT

**WSN** is a network consisting of **spacially distributed autonomous devices**(motes) using **sensors and actuators** to cooperatively monitor (and affect) phys or environmental coditions (temp, sond, vibration, motion, polutants.)

- IoT exist at a higher level than WSN (tech used within IoT)
- multiple **motes** (hundreds/thousands distributed in an *ad hoc* manner) forms the network to cooperatively monitor large/complex physical environments
- the info gathered is processed to get relevant results
- IoT consist of protocols and algos with autonomic capabilities

## Edge/ IoT Computing/ Fog

- **edge computing** is processing data near the edge of the network where data is generated **instead** of in a centralised data-processing warehouse

> its a distributed, open IT architecture that features decentralised processing power.
> enabling mobile computing and IoT technologies. in edge computing, data is processed by the device itself or by a local PC/Server rather than being transmitted to a data center

## Various Terms

- **motes** or **Wireless sensors** - physical sensing/actuating devices that is used sense a variety of physical attributes (`slide 8`)
  - **Sensing** - technique to gather info about physical obj/area
  - **sensor (transducer)** - device converting a quantity of one type to another ( mainly electrical signals)
    - eyes captures optical info/light, ears capture accoustic info/sound, nose capture olfacotry info/smell, skin capture tactile info/shape,texture
  - **microsensor** a sensor that has at least 1 physical dimension at a submil level (small)
  - **actuator** device that converts and electrical signal into a non-electrical quantity

Regarding sensing/data acquisition

- **signal conditioning** - prepare capture signals for further use (amplification, attenuation, filtering of unwanted frequency)
- **analog-to-digital conversion (ADC)** - translate analog signal into digital signal
  - digital signal is then processed, and output is given(via ADC and signal conditioner) to an actuator (to interact witht the world)

Regarding Mirco-Electro-Mechanical-System

- **MEMS** device created using compatible micro fabrication techniques
  - converting phys stimuli to electrical, mechanical and optical signals
  - performing actuation, sensing and other functions
- **MEMS** consist of microsensors, actuators and microelectronic Circutry
- **microsystems** came from the continuous miniturisation of technology

Regarding Representation & Topologies

- **Communication Graph** where `motes` are the nodes and link are the edges
- IoT Topology
  - **Star Topology** - every sensor communicates direcly with the base station, may need large transmit power and be infeasable in large geographic areas
  - **Mesh Topology** - sensors itself serve as `relays` for other sensor nodes to hop, this reduces power consumption and allow for better coverage, this introduces the problem of **routing**

# IoT Components

## Sensor Network and Nodes

- **Network Channels** - usernode or gateways and onward transmission to other network
- **Sensor Channels** - communicates among sensor nodes and targets

Sensor networks has 3 type of nodes

- **Sensor nodes** - monitor immediate environemtn
- **Target nodes** - generates various stimuli for sensor nodes
- **user nodes** - client and administration of IoTs

## IoT Node Components

IoT are typically made of small, battery powered wireless devices or nodes capable of on-board processing, commnication, sensing and actuation capabilities

- **low power processor** 
- **memory**
- **radio**
- **sensor**
- **power**

> You know this, slide 16 - 17

## IoT NOde Services

Some important IoT Services

- Query and data aggregation mechanism
- Routing and group communication
- Clock synchronisation
- Localisation
- Fault tollerance
- Computing v Comms
- Autonomous, proactive and Cooperating computing

# Characteristics

The main characteristics of IoT

1. **Connectivity**
2. **Things**
3. **Data**
4. **Communinication**
5. **Intelligence**
6. **Action**
7. **Ecosystem**

## Other Characteristis

general **mote** limitations:

- low power, processing and memory
- low communication capabilities and bandwidth
- Wireless networks can be deployed in **extreme environmental** conditions and are prone to malicious attacks
- since theyare often deployed in an **ad hoc** manner, they need to be **self organised** and **self healing** as they can face constant reconfiguration

Types of network (slide 21)

- MANET
- cellular network
- wireless sensor network

Limiations

- limited support for **Networking** - network is p2p with a mesh topology and a dynamic, mobile and unreliable connectivity
- limited support for **software development** - task are typically real time and massively distributed, involve dynamic collaboration among nodes.?? wierd wording

**Communication**

# Categories of Apps

IoT apps are often divided to these categories

1. **Monitoring of Object**
   - Structural Monitoring
   - Eco-physiology
   - Condition-based Maintenance
   - Medical Diagnostics
   - Urban Terrain Mapping
   - Often the parrameter for monitoring are maybe: temp, humidity, movement, speed, direction, pressure, noise level, mechanical stress levels
2. **Monitoting of an area**
   - Environmental and habitat Monitoring
   - Precision Agriculture
   - Smart Office, Smart Houses, Smart Infrastructures
   - Indoor climate Control
   - Military Surveilance
   - Treaty Verification?
   - Smart Alarms
3. **Monitoring of both area and objects**
   - WildLife Habitat
   - Disaster Management
   - Emergency Response
   - Ubiquitous Computing
   - Asset Tracking
   - Health Care
   - Manufactoring Process FLows
   - `software is a major role in this area`
4. **Monitoring events**??

## Examples

### Habitat Monitoring

- ZebraNet Project
- YellowStone Project
- Coyote Network Infrastructure Project

### Health Monitoring

- smart watches
- pacemakers

### Precision Agiculture/ vertical Agriculture

- aims at making argicultral operations more efficient, while reducing env impacts
- sensors are use to collect and evaluate data such as sowing density, fertilizers, pesticides to maximise crop yield

### Condition-based Maintenance

- manufactoring and fabrication plants needs
  - sensors collecting vibration data, monitor wear and tear + reporting data in real time
  - helps redduce need for a team of engineers, cutting cost for the organization

# IoT Enablers

- improving operational efficiency
- improving productivity
- creating new business opportuninites
- reducing downtime
- maximizing asset utilization
- ability to sell products as a service
- redicing asset lifestyle cost
- enhacing worker safety
- enhancing product innovation process
- better understanding of customer demand

# Challenges and Issues

## Challenges

### Energy

### Network layers protocols and software

### Communications issues

### Autonomics: self management

### Autonomics

### Decentralization

### Security

### Design Constraints

### Design Issues

## Other Issues

### Data Aggregation


### Different type of queries

### Routing and group Communications

### Routing Protocols

### Event/clock Synchronisation

### Localisation

### Fault Tollerance

### Computing inIoT

### Cooprerative Processing

### IoT Architectural Decomposition

# Active Areas of Development

- Smart home/ smart offices
- Biomedical/ medical
- Military
- Industrial & Commercial
- Traffic management & monitoring

# Conclusion

> Holy fuck this is alot of content to swallow