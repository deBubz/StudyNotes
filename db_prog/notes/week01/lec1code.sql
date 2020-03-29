-- 31253 Code for Lectures

SELECT  c.custno, c.CUSTFIRSTNAME,
        c.CUSTLASTNAME, c.CUSTSTREET, 
        o.ORDNO, sum(p.PRODPRICE)
FROM    CUSTOMER C JOIN ORDERTBL O 
ON      C.custno = O.custno 
JOIN    ORDLINE ol ON O.ordno = ol.ordno
JOIN    PRODUCT p  ON ol.PRODNO = p.PRODNO
GROUP BY c.custno, c.CUSTFIRSTNAME, 
         c.CUSTLASTNAME, c.CUSTSTREET, o.ORDNO

-- generate the standard join syntax from the one above 
--Alternate join syntax
SELECT  c.custno, c.CUSTFIRSTNAME,
        c.CUSTLASTNAME, c.CUSTSTREET, 
        o.ORDNO, sum(p.PRODPRICE)
FROM    CUSTOMER C, ORDERTBL O, ORDLINE ol, PRODUCT p
WHERE   C.custno = O.custno
and     O.ordno = ol.ordno
AND     ol.PRODNO = p.PRODNO
and custfirstname = 'Ron'
GROUP BY c.custno, c.CUSTFIRSTNAME, 
         c.CUSTLASTNAME, c.CUSTSTREET, o.ORDNO 	 
		



Select sysdate 
from    ordertbl

Select sysdate 
from    DUAL

select 23+35+67 from dual;

-- ask the students what the answer is
select 50 + 50 - 25 * 0 + 2 + 2 from dual;  

Select 'Hello World'
from    DUAL

Select TO_CHAR(sysdate, 'DD-MON-YYYY')
From DUAL

update ORDERTBL
set orddate = (TO_DATE('26/02/2020', 'DD/MM/YYYY'))
WHERE  ordno = 'O1241518';

rollback

select sysdate - to_date('04-DEC-1990', 'DD-MON-YYYY')
from dual

select sysdate - '04-DEC-1990' from dual  -- Note - Invalid syntax Why



Select ORDNO, ORDDATE, sysdate + 21 "Invoice date"
From  ORDERTBL


SELECT sysdate, ADD_MONTHS(sysdate, 12) PLUS1
From      DUAL

SELECT  emphiredate,
              TO_CHAR(ADD_MONTHS(LAST_DAY(emphiredate),6), 'DD-MON-YYYY') "Probation"
FROM    employee
WHERE  upper(empfirstname) = 'THOMAS';

SELECT SYSDATE,
                LAST_DAY(SYSDATE) "Last",
                LAST_DAY(SYSDATE) - SYSDATE "Days Left"
FROM DUAL;


Select to_char(sysdate, 'DD-MON-YYYY HH24:MI:SS') "DATE"
From   dual

Select to_char(TRUNC(sysdate), 'DD-MON-YYYY HH24:MI:SS') "DATE"
From   dual

Select to_char(TRUNC(sysdate,'mm'), 'DD-MON-YYYY') "DATE"
From   dual

-- watch the minutes
Select to_char(sysdate, 'DD-MON-YYYY HH24:MM:SS') "DATE"
From   dual

select greatest(10,15) from dual



select custno,             
       LOWER(custfirstname),        
       UPPER(custlastname) 
from   customer
where  rownum < 10

select custno,             
       LOWER(custfirstname),        
       UPPER(custlastname) 
from   customer
where  UPPER(custfirstname) = 'BOB'
and    rownum < 10

