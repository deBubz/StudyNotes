# Assessment notes

## Misc

- 50 %
- document your approach, keep it short and straight to the point
  - use diagrams, note what you're proud of
- submit: professional presentation in soft copy
- all the code is in the database, don't include any code in your submission
- include `ORACLE userid` in the front page, include email adress for marking sheet
- check `utsonline` regularly for specification adendums

## Overview

- moving to privatization of the retail electricity industry.
- retailers are just responsible to monitor the correct electricity usage and payment
- the market is a pool where producer bid to supply and suppliers bid to buy. Pool managed by **AEMO**
- the bidding by traders determine the price, set at 5min intervals
- **AEMO** aggregates prices to half hour to publish continually.
- trader need to be determine correctly using the time published at the half hours interval
- **AEMO** provide consumption report containing consumption data for each of he participation data in the market.
- Each report is for the total volume for that participant only. Broken down by LR(Local Retailer) and FRMP (Financially Responsible Market Participant)
- Report `RM16` produced weekly for data stored in `NEM_RM16`

## Database Specs

- create `LOCAL_RM16` table to store your calculated forecast values
- could be a direct copy for either of the tables with the object or my view with the object unwrapped into individual attributes.
- VIEW: `V_NEM_RM16`
- free to use either the object or the unwrapped version of the object. depends on you

---

## Task

- forecast energy requirement for each TNI, LR, FRMP combination, daily at each half hour interval
- forecast calculated for 2 weeks into the future.
- forecast should be for each TNI, LR, FRMP at each of the half hour intervals
- Each forecast record you create should have the `statement_type` marked as `FORECAST`
  - forecast values for each day in the future should be based on the avg of the half hour values for the previous same day and half hour combination.
  - **for holidays** 
    - if holiday, average the consumption of past holiday data.
    - if holiday data not available, use past sundays consumption data. DONT mix sundays with with holidays, use one or the other
    - when forcasting non-holidays, must use non-holiday data

> forecast data placed into `LOCAL_RM16`.

`NEM_rm16` or `v_NEM_RM16` are the source consumption data

- your program will run everyday in production.
  - so when you look back to see the `FORECAST` data for some `TNI`s.
  - These FORECAST values should be ignored.
  - only use NON-FORECAST values to determine the average
- updated `change_date` to system date for any records created/updated
- there are some column not relevant. your call to do what ever you want
- produce an XML file to the OS that list total consumption for each TNI for a **single** day.
  - forecast output date will be `sysdate + 1`
  - output filename `<username>_<forecast DD-MON-YYYY>.xml
  - 13363332_DD-MON-YYYY.xml

## Deliverables

> A professional presentation produced by professionals

List of deliverables

- Technical design of the Solution
- Working version of the Solution
- test your code in the database
- Email submission attached:
  - design document attachment
  - user id

> DO NOT CHANGE code after due date. There is a timestamp every code change

REMEMBER TO TEST YOUR PROGRAM


