

- why use RFID in IoT
- what is RFID
- application of RFID
- standards and operating technologies
- case studies
- developing RFID solution
- beacon technology

## Intergrating RFID and IoT

considering the following ideas

- asset management
  - costly equipment
- logistics: events & object tracking
  - objects (items, assets, people)
  - multiple users, multiple items
- access & protocol control
  - accountability
  - many userss: reservation system for users
  - cost (TCO)

## RFID

**Radio frequency Identification**
encorporates electromagnetic/ electrostatic coupling in the **RF** of the **EM spectrum** to uniquely **identify** an object/identity (originates from ww2 era)
- RFID being evaluated/implemented in the industry as an alternative to barcodes
- RFID gaining use in IoT apps

### How does it work

1. RF signals are transmitted by the transceiver & activate the transponder
2. Transponder transmit ID/data back to the transceiver
3. Reader receives and decodes which are sent to the user application

### Applications of RFIDs

- tracking books in libraries
- inventory tracking
- authorization access cards
- passprtys
- credit cards
- entry tickets
- toll booths
- car keys, wireless entry and ignition
- chipping animals
- tags for hospital patients and equipment

### RFID standards and specs

Standards frequencies
- IOS 18000-2 : 135kHz
- ISO 18000-3 : 13.56
- ISO 18000-4 : 2.45 GHz1
- ISO 18000-6 : 800-900 MHZ
- ISO 18000-7 : 433 MHZ

For tracking Animals
- ISO 11784 - specifies the structure of the ID code
- ISO 11785 - specifies how transponder is activated
- ISO 14223/1 - specifies RF code for advanced transponders
For credit cards
- ISO 15693 - specifies modulation and coding
For passports & proximity cards
- ISO 14443 - specifies modulation and coding
For general frequency bands
- IOS 18000 series (2, 3, 4, 6, 7)

### Examples

- Passport system sl09
- Medical Applications sl10
- Medical Applications(home care) sl11
- Medical Applications Architecture sl12
- Car Fleet Management
- Monitoring Health of Machines

## Developing RFID

- First consider the item, object level RFID based system first
- room to room item tracking: identifying location of items (equipment) 
- student used, equipment booking system

### The Environment

- explore the environment
- check your inventory & what could be tagged

### Things to understand

Questions to Ask:
- what items & how many are in the store-room, cabinet or shelf?
- Do we understand EPC/RFID stds (standards?) (Global GS1)?
- Who currently has issued items?
- Which specific utens were removed from the shelf, by whom?
- Time to completion, how items are being used, Data analytics?

> more in sl17

### Implementing

- create a program to interact with reader
- creating appropriate **database schema** so that all required info can be determined
  - history, times, current tags, past tags, ect
  - Reservation subsystem
    - truncate table
    - binary search tree (with dws?)
    - appropriate DB v software workload sharing
  - appropriate queries

### Designing UI

UI for users to unteract with the system

### Things to consider

Range and mobility
- placement of devices
- tracking fast moving ibjects
- operation environment
- ranging capability (passive v active)
  - which frequency to use

Vertical Integration

- Range of RFID heads and tags to choose from
- RFID control interface
- RFID handheld readers
- RFID software

### How others do it

Scalability focus

> sl23

Vertical Integration - microservices

> sl24

### RFID considerations

- Cost
  - transceiver ~$1000
  - RFID tags $0.20
  - Barcode is aloooooot cheaper
- UHF signal problematic near metal, water, human body
- Reader Collisions (manageble using TDMA tech)
- Tag Collisions (managable with some clever engineering of tag tansmit timing)
- Security concerns

## Beacon technology

Beacon technology includes 
- Bluetooth
- BLE
- Estimote

These are standalone devices that constantly send out a UUID (universally unique identifier) using BLE 4.0
iBeacon device can can come in different formfactors.
Turn any device that has BLE radio onboard into a IBeacon device

## Bluetooth Low Energy

BLE is a wireless network tech, to provide considerably reduced power consumption and lower cost

- includes bluetooth 4.0
- geo fence (in door navigator)
- support p2p WPAN
- low power consumption/cost
- speedup setup time
- better sec than classic bluetooth
- multi vendor interoperability

BLE have **2types**

- **Bluetooth Smart Ready** (dual mode device) typically laptop/smart phone which is compatible with both Classic and LE
- **Bluetooth Smart** (only LE) oftena bettery operated sensor, REUIRES another SMART or SMART ready device

### Bluetooth v BLE

> Difference table sl29

- BLE has less distance/range and data transfer
- More efficient time to connect and power consumption
- network connection can use 1-1 or 1-m (wifi)

### NFC v BLE

> difference table sl 30

- NFC is slower
- NFW works with an unpoweredc device (RFID)
- NFC have higher power consumption
- NFC doesnt require pairing (COMFORTABLE, not secure)
- NFC lower transfer data rate 
- NFC great for p2p communication
- BLE can use like on wifi

### What is transmitted

- Beacon use 3 cusomizable values to identify itself (to connect/ transmit data)
  - proximity UUID
  - proximity UUID and major
  - proximity UUID and major / minor
- An internet connection isn't required to activate the beacon experience
- A connection is needed to send contents coupons or other info that maybe driven by the app

### Paypal beacons

- to let its client pay for products in physical stores using phones
- Use BLE
- geo-fence(in door navigator)

### Beacons uses

## Conclusion

- RFID and Beacon tech continue to evolves
- It is considerd less threating han other techs
- Within IoT app space, sensors can be itntegrated with RF tags (smart sensors) and sensor data can be communicated using RF waves
- RFID enabled system can gateher and process sensor data in addition to identifying and track object
- RFID looks good as it is likely to contemporary biological metaphores in the next few yeas