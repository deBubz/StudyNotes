# Monday

## Week Task Planning/ Breaking down Tasks

- Interface
  - Email Notification if new bulb is broken?
  - Email Notification when Bulb is fixed/ addded/ removed from queue
- Time keeping function
- Power

## Interface Planning 

Using [MockFlow](https://mockflow.com/)

Only need design for 2 pages
  
- **MainDashboard**
  - Present List of street lights Status
    - On/Off
    - repair Status
    - Location
    - List Agreggate by region( postcode/ detail)
  - Drop down box, to check lights by different postcode, area, street?
  - Data Presented as
    - Table( can be more detailed, need SQL table)
    - Phone apps icons( easier implementation, less data present, noneed to add Sql Table)
- **Bulb Detail**
  - Line graph to display sensor data
    - no need to be live data
    - 2 Graphs? perday/ per week
    - Option to add to repair List if broken (Toggle with remove option)
    - Option to remove from repair queue if its a false alarm.
- **A login screen** also count as a page but it should be a simple enyrt username/password prompt.

## NodeJS Notes

[NodeJS Notes](./NodeJs/README.md)