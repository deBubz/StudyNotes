-- Question 1

select  upper('&&name') "name", 
        to_date('&&dob') "birth_date",
        to_char(sysdate, 'yyyy') - to_char(to_date('&&dob'), 'yyyy') "age",
        to_char(to_date('&&dob'), 'DAY') "birth_day",
        to_char(last_day(sysdate), 'dd') "feb_day"
from DUAL;

-- testing q1

select extract(month from date to_date('&&dob')) "month"
from DUAL;
;

Select  to_char(sysdate, "DD-MM-YYYY HH24:MI:SS") "dateTime",
        to_char(trunc(sysdate), "DD-MM-YYYY") "date(time removed)",
        to_char(trunc(sysdate, 'mm'), "DD-MM-YYYY") "dateTime"    -- returns dd-mm-yyyy with the day value truncated to 1
from DUAL;

