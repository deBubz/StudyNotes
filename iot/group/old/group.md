# notes on the group assessment

## parts list

## Submission requirements

- report max 12 000 words

## project description

design and implementation of **rehabilitation asssistant** sub system for tracking of movements and activities of patients with sensors:

- temp, muscle strain gagues

need front end to render/visualise and analyse data recieved from the subsystem

process of rehab theraby involves

- treatment focused on restoring body functionality loss. can occur as result of:
  - injury
  - surgery
  - illness
  - natural aging

the rehab assistant can be a subsystem gathering data from sensors/actuators, 
can also use to monitor rehab and recovery tracking analysis as well for diagnostic.

data to be stored over a long period of time,

The project only aims to be retrieving data from the product. Both the front end and the Assistant Subsystem communicates via streams of data into/out of a local **Edge host** and possibly **Cloud Base**

Some basic calc/data processing is required the provided solution resembles actual medical solution. This project will include a couple, 3 simple calc methods to illustrate that the feature is available

### Problem requirements

1. system collect quantitative data through sensors
2. implemented as a wearable
3. store previous datasets as away of tracking muscle recovery as log files
4. developed with an integrated set of devices for demoing IoT Tech
5. users need to view dashboard in **different forms** with data from the DB. The IoT need to provide basic rehab state pattern change representations, models and visualizations.
`e.g` images of body parts, component, their positions, movement capabilities, and can show/involve reading of temperature and/or strain (stretch) data ,,,
6. User should be able to update data with user input (doctors input)
7. allow communication between patients and doctors by adding events and appointments
8. include a db which data of both the IoT component (raw from sensor) and fornt end (user data) are stored

non-functional aspects the product hopes to achieve

1. Scalability
2. Accesibility
3. Security