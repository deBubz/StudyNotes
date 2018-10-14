# If you can’t understand it, you can’t properly assess it! The reality of assessing security risks in Internet of Things systems

## Jason R C Nurse, Petar Radanliev, Sadie Creese, David De Roure

## Abstract

- As complexity, pervasiveness and automation of technology  systems increases, esp IoT, we will need new approach to risk aseess and build system trust.
- Report, Scoping workshops and interview with industry proffesional (Enterprise systems, IoT and Risk) to validate the above arguement.
- Consult with proffessionals to understand:
  - Identify wider concerns of corporations in adopting IoT systems(smart manufactoring floor or a smart office)
  - Challanges for industry that attempts to properly addresses the Risks of IoT.

---

## Introduction

IoT is set to change our society just as the internet it self. Beside from being a buzzwordm, IoT is a complex technology paradigm.
It represents the __convergence of varying visions__ for the future of IoT, multiple people have a different vision for IoT(ref 1)

Although it stands to provide increased productivity and efficientcy in manufacturing and argiculture. Massive economic impact, predicted to reach 4 trillion per year.
Could create a new paragdigm to save lives in __smart health__.

But there are also challanges with its wide spread use. Threats can originate fom physical or cyber attacks. can target __any central layers of an IoT system__.
Many are known to have shortcommings interms of security and  privacy.

organisations conditioned to response to threats and vulnerabilities through the process of __Risk assessment__.

Assessment use methadologies based from: __National Institite of Standards and Technologu (NIST)__ Special Publication, Industry-developed standards ISO 27000 series.

Aim to Identify relevant assets, vulnerabilities and threats, Impatcs.

Howeverm there are some issues will impact the application of existing sec assessment methods to IoT Systems. This Includes inadequate of current __periodic assessments__, Unknown System boundaries at the time of assessment, fail to acknowledge __assessts as attack vectors__ instead of just value.

> Overall, manufactures often ignores the product after production/ does not seem the importance of periodical update their devices.

### This report

- scopinng workshops
- Intervire with professionals from indystry and vusiness sector.

Goal to: validate stated issues and their significance.
The paper `"believe that the IoT security research field in general stands to benefid from this stakleholder engagement."` as it addressess concerns from the industry and informing future research.

### Structure

- __Section 2__: reflect resrarch in the domain of cyber-risk, risk0assessment for IoT systems
- __Section 3__: Issues that could complicate the risk assessment process.
- __Section 4__: Detailed research  approaches to examine such issues with profesionals.
- __Section 5__: Present/Discuss core research findings from study. show Implications of Security Risk.
- __Section 6__: Avenues of future work.

---

## 2.Background / Related Work

### 2.1 IoT and Security Concern

IoT is the intersection of 3 visions for technology

- __Things-Oriented__: presence of lots of devices
- __Semantic-Oriented__: The collection and storage of items (Data)
- __Network-Oriented__: the use of networks for interconnected items.

> These visions are presented in the definition of IoT `interconnected networks of digitised physical devices which
interact to achieve some purpose.`

IoT systems are divided into:

- __Applications__: objective of the IoT Systems. Covering domains such as smart health, smart building and automation.
- __Cloud Service__ or __cloud computing__: The software component.
- __Things (both physical and digital)__ Interacts with the realworld, devices, sensors.

The main concerns of IoT has always been is __security__, __privacy__ and __trust__. Most importantly is __security__, from it will ensure __trust__ and __privacy__ from users.

Many challages to achieve security, but the majority of research involves issues regarding __Identity and authentication__, __access controll__, __protocol and network security__, __fault tollerance and governance__.

More Detailed level threats:

- Storage management: Data management, management confidentiality
- Communications : DDOS
- Embedded System: sidechannel and tampering attacks, hardware attack

> Many threats are excerbated(made to be worse) by IoT in context.
>> This is because of __low resource__ nature of IoT devices, __Open accesibility__ over the net and the __pervasiveness__.

### 2.2 Risk Assessment Context

Used by organisation to manage risk and security concerns by identifying and prioritization risks (__factors__: impacts, vulnerabilities, threats..)

Current risk assessment methodologies are not tailors to handle IoT and its ever changing environment. __Section3__ will explore more challanges of these approach. For the methods created specificly for IoT, there is a lot more focus  on automated, mathematical approaches.

---

## 3. Security Risks in IoT systems

In general its a difficult process made even harder for IoT.
This is the case when traditional approaches are used for IoT (Still widely used) because it fail to take in considerations of the nuances for IoT.

__4 reasons__ why current approaches are not suitable for IoT:

- __FIRST__ Current assessment does not take in account that the system would not hav __significant changes in a short window of time__. IoT have varying scales of system, dymanism and system coupling. Through time IoT systems might need to adapt and increase efficientcy, or function with new devices. These adaptation might happen before the __schedueled reassessment__ (typically quarterly or bi-annually)

- __SECCOND__ The type of knowledge required to conduct a detailed tradditional risk assessment is extremely challenging due to the continuously changing nature of IoT. It is hard to keep track of the System and often have unknown components (data from partnering companies). __Therefore__ it is difficult to assess threats and impacts without a good understanding of the assets of the IoT system.

- __THIRD__ Tradditional methods focuses more on tangible(physical devices) assets and often ignore the other. In some cases, `vital tacit knowledge is overlooked in risk assessments over physical assets`. This is concerning as each of the components that made up the IoT System is an avenue for attacks.

- __LAST__ Mirai botnet Dyn DDOS attack using compromised IoT devices. This is a strong arguement for why assets should also be viewd as an attack platform.

--- 

## 4. Approach to Consulting Industry Experts

Explanation of how the research is conducted

Conducted a series of workshops and interviews. Pose several discussion point, then step back and allow the professional to deliberate on the discussion.
All data is recorded and transcribed to be assessesed.

- `reread if you need to validate the research`

---

## 5. Result and discussions

__AIM__ to discuss challangeses professionals find in assessing environments containing IoT. Participants are proffessional in Enterprise System, Risk assesment and IoT systems and are currently employed in med-large tech enterprises.

### 5.1 Periodic Assessment vs and Evolving IoT System

- IoT is capable to evolve continuously during operation.
- change may encompas new devices and services.
- devices may include physical sensors  to take measurements or Cloud services included to support reasoning and predictions from the recorded data
- In this ever changing environment, periodic assessment is not sufficient.
- supports their hypothesis of the issue of keeping up with the system (due to difficulty in keeping up with system assests)
- for Small-Medium Enterprises(SME), security is viewed to be a single point to reach rather than a continuous process
> ..once they have reached a level of security, they are
often tempted to think that the task is complete. The
fact that security is dynamic and is changing all the
time is something these companies will need to get
accustomed to as this is not their expectation.

- Security is often supported/ suited to the periodic risk assessment. `no need to pay attention to after implimentation`

- for some enterprises, risk assessment is viewd to be a checkbox exercise. It is simply just a process to meet regulation. This can also explained by regulations being well behind tech.

---

### 5.2 Risk Assessing a complex, autonomous Black box

- look at the knowledge and insight kept by users and the IoT team. This show how knowledge(or lack their of) impact how risk is assessed.
