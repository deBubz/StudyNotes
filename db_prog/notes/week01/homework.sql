-- q02 get some data

select  upper('&&name') "name", 
        to_date('&&dob') "birth_date",
        to_char(sysdate, 'yyyy') - to_char(to_date('&&dob'), 'yyyy') "age",
        to_char('what is this') "NOD",
        to_char(to_date('&&dob'), 'DAY') "birth_day",
        to_char(last_day('01-FEB-' || to_char(to_date('&&dob'), 'yyyy')), 'dd') "feb_days"
from DUAL;

--- q03 look for the manager in employee table

select  empno,
        decode(GENDER, 'M', 'Mr ', 'F', 'Ms ', 'unknown') ||
        EMPFIRSTNAME || ' ' || EMPLASTNAME "FullName",
        decode(SUPEMPNO, NULL, '<====BOSS', ' ') "Title"
from    employee;

-- q04 list all orders where the orddate is 20-jan-2020

select  *
from    ordertbl
where   TRUNC(orddate) = to_date('20-JAN-2020', 'dd-MM-yyyy');

-- -- -- big boi questions -- -- --
-- q05 a report of 6 months worth of data
--- generate a date that is start of calendar year or financial year
-- which is furthest to provide atleast 6 months of data
-- financial 01-jul-2019

------ WRONG ------
IF (months_between(sysdate, to_date('01-JAN-2020')) > 6) THEN
    select 'financial year' "year_choice" from DUAL;
ELSE select 'beginning of year' "year_choice" from DUAL;
END IF;
------ ANSWER -----
-- least(a, b, c) returns lowest item
-- trunc(date, 'YY') truncate to first date of year
SELECT  sysdate,
        LEAST(
            TRUNC(sysdate ,'YY'),         
            add_months(
                trunc(add_months( sysdate, -6), 'yy'), 6
            )) cal_fin  
FROM   dual; 


-- close enough but gotta learn oracle sql

-- q06 maths
-- -5 days from 11-oct-1582. is this right NO
select  to_date('11-oct-1582', 'dd-mm-yyyy') "date",
        (to_date('11-oct-1582', 'dd-mm-yyyy') - 5) "ans"
from dual;
-- -5 days from 13-mar-2020. is this right  YES
select  to_date('13-mar-2020', 'dd-mm-yyyy') "date",
        (to_date('13-mar-2020', 'dd-mm-yyyy') - 5) "ans"
from dual;
-- explain
-- https://stackoverflow.com/questions/13568193/how-are-dates-stored-in-oracle

-- q07
define my_string = 'DATABASE PROGRAMMING AND ADMINISTRATION' 
select  substr('&&my_string', 1, 9) word1,
        substr('&&my_string', 10, 12) word2,
        substr('&&my_string', 22, 3) word3,
        substr('&&my_string', 25) word4
from    dual; 