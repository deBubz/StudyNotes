# Assessment notes

## Misc

- document your approach, keep it short and straight to the point
  - use diagrams, note what you're proud of
- submit: professional presentation in soft copy
- all the code is in the database, don't include any code in your submission
- include `ORACLE userid` in the front page, include email adress for marking sheet
- check `utsonline` regularly for specification adendums

## Database Specs

- use the view to generate data: `V_NEM_RM16`

---

## Task

- forecast calculated for 2 weeks into the future.
- forecast should be for each `TNI`, `LR`, `FRMP` at each of the half hour intervals
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


---

## Schema

The tables to use in your program

### RUN_TABLE

- used to log the processes running your program

| var | datatype | notes |
|:---|:---:|:---|
|run_id | number | |
|run_start| date | |
|run_end | date | |
|outcome | varchar2(15) | |
|remarks | varchar2(255)| |


### DBP_PARAMETER

- parameter table for data type, date/string format??
- gotta need to ask about this

| var | datatype | notes |
|:---|:---:|:---|
|category | varchar2(35) | |
|code| varchar2(35) | |
|value | varchar2(35) | |
|active | varchar2(1) 'y' | |
|modified | date(sysdate)| |

### DBP_MESSAGE_LOG

| var | datatype | notes |
|:---|:---:|:---|
|studentID | varchar2(50) | |
|msg_date| datetime | |
|msg_id | varchar2(35) | |
|message | varchar2(2000) | |



### DBP_HOLIDAY

- holiday dates to watch out for??

| var | datatype | notes |
|:---|:---:|:---|
|holiday_date | date |


------------------

> edit these under here

### V_NEM_RM16

| var | datatype | notes |
|:---|:---:|:---|
|run_id | number | |
|run_start| date | |
|run_end | date | |
|outcome | varchar2(15) | |
|remarks | varchar2(255)| |

### DBP_LOCALRM16

| var | datatype | notes |
|:---|:---:|:---|
|run_id | number | |
|run_start| date | |
|run_end | date | |
|outcome | varchar2(15) | |
|remarks | varchar2(255)| |

