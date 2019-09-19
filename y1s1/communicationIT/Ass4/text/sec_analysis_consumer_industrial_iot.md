# Security Analysis on Consumer and Industrial IoT Devices

## Abstract

- fast development of IoT and __Cyber-physical Systems (CPS)__ had triggered a massive demand for sensors to be built in for smart devices.
- The fast deployment for devices and market pressures has rases security concerns.
- This paper, to help better understand existing vulnerabilities and promote low cost security implementations, uses both comercial and industrial devices and analyses the hardware, software and network vulnerabilities.
- Security analysis on a smart home system to prove flaws are common for most devices.
- discuss mitigation strategies.

---

## Intro

- Devices approaching 15 bil, avereaging 2/person. [1]
- Extimated to reach 26 bil in 2020 where the majority are wearables [2]
- filled with sensors, and have network capability to transfer collected data to a remote-collection point.
- "the nature of IoT devices" are to collect, process and relay data through a communication channel and sometimes controll a larger unit.
- Manufactures knows about the security and privacy implications. However, security in IoT is often ignored. due to short __time to market (TTM)__ and lower cost.
- Devices will be open to attacks. very attracktive to who that wants the information it carries.
- Some devices having __always-on__ connectivity having increased risk of harmful usage.
- Those that have security usually only have __software level__ protection. It is good but unefficient as it leaves the hardware level vulnerable.

2 Case example: smart controller for home automation, and smart meter for mordern power grid.

---

## 2. Commercial IoT device IoT analysis

- targets end users and focuses on device functionalities.
- security if added in an ad-hoc(as a response/ after thought) manner. => hardware vulnerability
- Haiser smartcare home automation system.

### Highlevel overview

- Designed to read data from sensors all around the home such as a smoke sensor, water leakage sensor, remote-power switch, sensor to check if doors are oppened or closed.
- Zigbee protocol (Ohboy).
- allow users to monitor their home on their smartphone app.
- then connet the Haiser smartcare through an ethernet connection.
- create an account with the manufacturers cloud service. allow users to view their device outside of their LAN.
- able to interact with their device through the application.

- Able toread amd modify important keys and variables. And from then derrived a root password for the device.
- upon finding the password, The team used this to try to gain access to other linked Hiessen devices/sensors.

### Network Analysis

- Using the root credential, they managed to gain acess to the root shell
- perform MiTM to track LAN traffic.
- still investigating.

--- 

## Industrial Analysis

- when breached may have more serious impact then commercial device.
- Itron Centron smart meter.
- Used to record and report energy usage through a RF channel to a nearby reader or a local substation. The data is used to charged users for their energy usage.
- The device is an add on to existing meter, so there is no need to replace the whole device.
- The daughterboard is used to collect energy use information along with tamper data and the ID of the board itself. Its possible to enable write access for on chip memory through a microcontroller on the board.
- was able to change the devices ID
- Therefore, MASSIVE flaw. An effected meter can represent it self as anyother meters. => energy theft.

---

## Discussion

### Security Impact

- IoT devices can be easily compromised during transport and deployment.
- Effects of these attacks can be a simple back door or total compromisation of the device.
- Compromised Haiser Smart Home system can lead to property damage or loss as attackers can hijack funtionalities of connected devices.
- Attacker can also use it to harm other devices connected in the local network, acting as a bridge to other devices.
- As it provide a rich Operating System Environment, A compromised Haisen SmartCare can be used to deploy rogue services in a LAN, disrupting operations of other network nodes.
- Can also participate in Adress Resolution Protocol (ARP) based attack, masking as routers and allowing capturing targeted computer traffic.
- Industrial devices poses bigger threats if compromised. They were able to change the ID of the tracker which can alter how billing works for their power consumption (nasty).
- This also can have a detrimental effect on the economy as it can disrupt the data of power consumption.

### Safety concern

- Safety complication from affected IoT devices.
- These devices can be used to directly harm its users[15]
- Compromised industrial devices can harm cyber physical systems just as the power grid. Untract excess energy use can overload the grid, causes blackout and damage equipment.

### Privacy concern

- for the Home automation system, a compromised hub can be used to build a profile of its users. Tracking their habits.

### Device Security Enhancement

- Restricting access to important information of the device.
- Using better hashing algorithms for passwords.
- encrypting file system, as the fileSystem would allow direct modification of the device's software
- Seccure update channels, so it cant be tricked by attackers.
- External programmability must be protected. (hardware)

---

## Conclusion

- Both commercial and Industrial devices are flawed and vulnerable to IoT specific attacks.
- Should take security into consideration when buildingh a modern IoT device.
- There will be a massive privacy and security concern if the current design pattern is still used.
- There need to be an IoT specific design-for-security methodologies to protect future devices.
