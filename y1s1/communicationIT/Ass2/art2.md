# Anatomy of a Vulnerable Fitness Tracking System  ACM

## Dissecting the Fitbit Cloud, App, and Firmware

## OK LEGOO

### Abstract

### 1.Intro 

- 830 million wearable gadgets will be shipped by 2020
- Appealing for people that wants to monitor daily activities
- expected to have broader implications on healthcare, workplace provisions and the judiciary
- Wearable devices and the mobile apps record, store, and exchange sensitive information with remote servers
- includes age, gender, weight, heart rate, distances traveled, geo-position, duration of activity periods, and sleep habits
- Data stored on tracker, but can only be read on the mobile app after its synchronized with the server.
- user can get payed for sharing this data with third parties
- this gives further incentives for attacks.

- can be compromized through the application, MITM (intercepting data while transmitting) attacks.
- current industry values innovation over ensuring security.
- Manufactureres must focus on security more, due to the delicacy of the information
- Modify the official app so it can edit encrypted fitbit traffic
- Reveals 
  - Privacy Leakage, attacker can extract users data, and also aquire authentication credentials to gain access to the tracker`s command LIVE
  - Firmware Modification, can access and modify the tracker`s firmware, hence can disabble all security mechanisms, including authentication and encryption
  - Subversion of fitbit cloud, enable dev options in the official app

- suggest design improvements for activity trackers.

---

### 2. Fitbit communication paragigm

- communication model gadget <=> app <=> server
- risk of interception in pre 2015 models
- anyone within wireless range can connect using a code that the tracker displats.
- can request server generated commands. set alarms, reading the gagets internal memory and activate live mode - reading live data.


---

### 3. Adversial Model

- Fitbit regarded as the most secure health tracker.
- demonstrate what part can be compromised

### 3.1 Attacker Capabilities

1. spying
2. financial interest, ransomeware or monetary rewards,
3. dos
4. cloud independance from official service
5. non adversial applications for healthcare and research

### 3.2 Attack Scenario

- Spying
  - detect ongoing tracker and app operations and interact with it
  - proximal expionage, connect to tracker within wireless range, track it and request its data.
  - remote expionage: steal data remotely
  - spyware: firmware modification 
- financial interest: attacks that generates money
  - Selling fitness data - selling fake data that certify a healthy lifestule, as some third party insurance companies offer rewards and cheaper premiums.
  - Ransome ware: victims can be extorted through interfeering with their devices, set alarms off at random times, mess with the data, disable functions.
- DoS: denile of serviice annnoys the users, and also damage fitbit`s rep
  - local wireles command- dates and alarms can be manipulated to deny service to fitbiet end users
  - False Firmware update, permanantly disable the tracker
  - virtually stealing tracker: remotely disable syncronization, rendering the tracker useless
- Cloud independance: makes the traker independent of the fitbit cloud, Users will no longer able to sync with the server.

---

### 7 DESIGN RECOMMENDATIONS

- hope to not just strengthen the fitbit ecosystem, but also hope that other vendors will take more care in their design

### 7.1 Security by Design

- discover that fitbit architechture was design without much consideration for the security system
- it was designed with the assumption that the user will only be interested in tracking their own data
- security features was added after the product was shipped, there ares still lots of vulnerable trackers in the current market
- Alot of the vulnerabilities could be avoided if a "security by design" approach was implemented from the start
- Even the update system is compromosed due to users do not have enough knowledgornpatience to foccrctly follow update procedures

### 7.2 Secure Device Association

### 7.3 Serial Number Protection

### 7.4 Stricter Encryption

### 7.5 Android App and Usable Security

### 7.6 Firmware and Microcontroller

---

### 8 RELATED WORK

### 9 CONCLUSIONS
