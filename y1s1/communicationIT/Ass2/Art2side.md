# Breaking Fitness Records without Moving: Reverse Engineering and Spoofing Fitbit

## Just some extra data

### Abstract

- Health tracker data
- private information reveals lifestyle
- security flaw
- false data can be pushed for different reasons

### 1.Intro

- 270 mil plus health tracker by 2020
- pregnancy through fitbit data [3], fitbit data in court [4]
- highlight the need to keep the data safe from being edited.
- data editing services for monetary purposes.
- health insurance discount using fitbit data
- services that pays the user for sharing data
- according to surveys fitbit is most secure/ competitive advantage
- Due to innovation is the main objective, Security is often being ignored, where it should be seriously considered in the design.
- growth hindered by mistrust.

- Vulnerability can be exploited in a bigger scale once discovered.
- Demonstrate to breach, recover and temper with current records of the fitbit.
- Contacted fitbit after the discovery and allow sufficient time for fitbit to fix the problem before publishing the paper.

---

### 2.Adversary model

- Fitbit stores data, data then upload to server through app, data then is displayed.
- Can edit the data prior being linked with the cloud server.
- User have both the means and motive to tamper with the data.

### 2.1 Targeted Fibit

- Fitbit flex, fitbit one tracks `steps, distance calories burned, floor ascended, sleep duration, active mins.`
- theyre cheap => percieve to have bad security
- but other models have the same communication methods, same pen method should work

### 2.2 End-to-End communication paradigm

- fitbit ships with 2 different firmware
  - latest version, encrypt record before sync using a pre-installed encryption key
  - earlier version operate in plaintext mode.
- The phone app dont reads the data from the gadget.
  - It converts the data to be send to the server.
  - Then it displays information that the server send back.
- A computer software can also do this with a bluetooth sensor
- Though only the server and gadget have the encryption key, The phone app can reads existing data through the user account, with out the device.
- AND the server accepts both encrypted(updated firmware) and unencrypted data(older firmware, models). Accepting unencrypted data allows data modification.

---

### 3. Protocol Reverse engineering

### 3.1 Man-In-The-Middle setup

- Used to intercept information from the user to the server, vice versa

### 3.3 Microdump

- Summary of tracker`s configurations and status
- generic information use to identify the tracker, and version
- cant use to spoof data

### 3.4 MegaDump Syncronisation Message

- Summary of users activity data from the tracker
- App dont recognise this data, only server will. 

---

### 4. Protocol-based remote Spoofing

- Shows how to construct fake data in the Megadump
- no need to own a tracker, just the trackerID

### 4.1 Submission of Fake Data

- Maynot be encrypted but will still accept the data.
- Even if the Encryption key is not known, possible to construct a frame for the data
- Impersonation Attack, Use a different tracker id, server still accepts the data
- reveals a DoS risk
- risk of fabricated data

---

### 5. Hardware based local spoofing

- Device tear-down to test physical attacks
- Gained access and ability to send encrypted megadumps
- used inexpensive, readily availible tools

---

### 6. Discussion

- implementation guidelines for fitness tracker and other Health related IoT Devices
- Fitbit is the only manufacturer that puts effort into securing their devices
- Suggestions
  - Should consistently enforce encryption of incomming data.
  - better tighten security level in the hardware
  - there should be fraud detection for falcified data

---

### 8. Conclusion

- Trusting the data and integrity of the fitness tracker is very important
- because the data is being used in court trials and health insurance premiums
- vendors/ manufactures should be more strict about their security design to ensure the authitencity of the data.
