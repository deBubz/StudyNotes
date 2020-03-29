# Database Programming Into ( w01 )

>  tools > db > NLS> set your own date format

- [Database Programming Into ( w01 )](#database-programming-into--w01)
  - [Class Goals](#class-goals)
  - [Intro to Catalogue Tables](#intro-to-catalogue-tables)
  - [SQL revisions](#sql-revisions)
    - [SQL Revision](#sql-revision)
  - [ORACLE SQL features](#oracle-sql-features)
    - [DUAL table](#dual-table)
    - [DATE functions](#date-functions)
      - [Other Date Functions](#other-date-functions)
    - [Character Functions](#character-functions)
    - [NVL](#nvl)
    - [DECODE](#decode)
    - [Sequences](#sequences)

---

## Class Goals

- Have another look at the subj outline
- Review `SQL` language with emphasis on `ORACLE SQLPlus` and its **features**
- Learn *Oracle*'s `PL*Sql`
- Intro to sys admin roles performed by a *DataBase Administrator*
- Discuss Performance Tuning of `Sql queries`

## Intro to Catalogue Tables

- of course the basic `select * from table_name` to look at the db before working
- **Cataloge tables** allow you to see what obj you own or have access to
  - Many system tables name prefix with `user_` or `all_`
    - user: user owned object
    - all: all objects in the system
  - Common catalogue objects
    - dict, user_tables, user_views, user_source, user_objects

## SQL revisions

- practice this shit
- SQL has different flavours
  - **DDL** - Data Definition Language  (Create objects)
  - **DML** - Data Manipulation Language (Insert, Update, Delete, Select data)
  - DCL - Data Control language
- **Revision Questions**
  - **Primary Keys** - unique identifier for each record(entry) of data
  - **Foreign Key** - is a PK of another entity to represent relationship
  - **Alternative Key** - alternative unique identifier. Could be both simple(single) or complex(combinations) of columns to be used as a unique identifier
  - **Referential Integrity** - handles consistency of data within a relationship. This means a foreign key from in an entity must **reference a valid and existing primary key in another table**. Having Referential integrity prevents users from:
    - Adding records to a related table if theres no associated record in the primary table
    - Changing values in the primary table that result in orphaned records in a related table
    - Deleting records if there is a matching related records.

### SQL Revision

- Simple select Statement
  ```SQL
  select custno, custfirstname, custlastname
  from customer
  where custno = 'C71234567'
  and postcode = 2153

  -- select 3 colums from table customer
  -- with the custno and postcode specified
  ```
- Select statement with Join - get customer details and thr order amount for all customers
  ```SQL
  select  c.custno, c.custfirstname, c.custlastname, c.custstreet,
          o.ordno, sum(p.prodprice)
  from    CUSTOMER c join ORDTBL o
  on      c.custno = o.custno
  join    ORDLINE ol on o.ordno = ol.ordno
  join    PRODUCT p on ol.prodno = p.prodno
  group by c.custno, c.custname, c.custlastname, c.custstreet, o.ordno

  -- look at the order entry system diagram to understand
  -- CUSTOMER table has the 
  -- ORDERTBL contains invoices
  -- ORDLINE associative entity for ORDER m:m PRODUCT
  -- PRODUCT product information
  ```
- Select statement with traditional join which produces the **same as above**
  ```sql
  Select    c.custno, c.custfirstname, c.custlastname, c.custstreet,
            o.ordno, sum(p.prodprice)
  from      CUSTOMER c, ORDERTBL o, ORDLINE ol, PRODUCT p
  where     c.custno = o.custno
  and       o.ordno = ol.ordno
  and       ol.prodno = p.prodno
  group by  c.custno, c.custfirstname, c.custlastname, c.custstreet, o.ordno
  ```

## ORACLE SQL features

- Dual table
- Date functions
- Character Function (concatenation)
- [REGEX](http://docs.oracle.com/cd/B12037_01/appdev.101/b10795/adfns_re.htm)
- NVL
- DECODE
- Create and Use of a SEQUENCE

### DUAL table

These are dummy tables in the `Oracle` db, which contain one column called **dummy** having 1 value `X`

- These are useful for computing a constant expression with `SELECT` since `DUEL` only has 1 row ( *the value is returned only once* )
- Alternatively, you can select a **constant**, **pseudo-column** or **expressions** from any table
  - BUT the value will be returned as many time as there a rows in the table

```sql
-- lets try
select sysdate from ordertbl;
select sysdate from DUAL;
select 'hello' from DUAL;
```

### DATE functions

> Be careful about this shit. Its one of the **most important** func of any DB

- Dates are stored as `int` in most db ( e.g unix time )
- System convert this number into a format that is understandable by people
- 2 key dates functions: `to_char()` and `to_date()` both take 2 args, the **data** and the **date format**

```sql
-- try this
select  to_char(sysdate, 'DD-MON-YYY') from DUAL;

update  ordertbl
set     orddate = (to_date('01/03/2020', 'DD/MM/YYY'))
where   ordno = '012341518';
```

> `sysdate` is the built in representation of the current system date

ALSO, dates can be subtracted and added from the other dates

```sql
-- subtract
select sysdate - to_date('04-DEC-1991', 'DD-MON-YYYY') from dual;

--- add 
select  ordno, orddate, sysdate + 21 "Invoice Date"
from    ordtbl;

-- invalid
select sysdate - '04-DEC-1991' from dual;
```

#### Other Date Functions

- `add_months(Date, n_months)`
```sql
-- add n months into Date
-- can be any real number
select sysdate, add_months(sysdate, 12)
from DUAL;
```
- `last_day(Date)`
```sql
-- return last day of the month based on the current date
-- can use this do count how many left at the end of the month
select  sysdate, last_day(sysdate) "Last",
        lastday(sysdate) - sysdate "Days left"
from    DUAL

-- other example
select  emphiredate,
        to_char(add_months(last_day(emphiredate), 6), 'DD-MON-YYYY') "probation"
from    employee
where   upper(empfirstname) = 'THOMAS'
```
- `trunc(DATE, [format])`
```sql
-- return Date with the time portion truncated to the specified format
-- Date is truncated to the nearest day if format is omitted
Select  to_char(sysdate, "DD-MM-YYYY HH24:MI:SS") "dateTime"
        to_char(trunc(sysdate), "DD-MM-YYYY")) "date(time removed)"
        to_char(trunc(sysdate, 'mm'), "DD-MM-YYYY") "dateTime"    -- returns dd-mm-yyyy with the day value truncated to 1
from DUAL;
```
> very useful for comparing dates
- **date formats**: have a look at slide 21 - 23

### Character Functions

- `upper(string)` and `lower(string)`... pretty self explanatory
- **String Concatination**: combining strings using `||`
  - if both strings are `CHAR`, result is `CHAR` which is <= 2000 char
  - if one string is `VARCHAR2`, result is `VARCHAR2` which is <= 4000 char
  ```sql
  -- concatination
  select  custfirstname || ' ' || custlastname
  from    customer
  where   upper(custfirstname) = 'BOB'
  ```
- `substr(char, m, n)` basicly string slicing (m: from index, n: to index)
  ```sql
  --- slicing
  select  substr(empfirstname, 1,1) || '. ' ||
          emptlastname
  from    employee
  ```
- `lpad()` and `rpad()`. args: `(char, n, c)`
  ```sql
  --- padd left/right of char the sequence of c, n-times
  select  rpad(empno, 20, ' ')||
          rpad(empfirstname, 15, ' ')
  from    employee
  ```

### NVL

- This is to handle `NULL` values
- `NVL(expr1, expr2)` will substitute a nominated value for an expression if he expression is `NULL`

```sql
select  empno, nvl(to_char(comm), 'NOT APPLICABLE')
from    employee
```

### DECODE

One of the most helpful functions in SQL. Equivalent to **IF..ELSEIF**

> More like a switch statement

```sql
-- syntax
DECODE(expression, case, action, case2, action2, ...,default)
-- example
select  decode(sex, 'M', 'Male', 'F', 'Female', 'Unknown')
from    customer

-- oracle 9i introduced CASE statement
select  CASE sex  WHEN 'M' THEN 'Male' 
                  WHEN 'F' THEN 'Female'
                  ELSE 'Unknown' END
from    customer
```

### Sequences

- This is a db object fom which multiple users can **generate unique int**.
- Can be used to generate **Primary Keys**

```sql
-- creation syntax
create sequence my_key
start with 1
maxvalue 9999
increment by 1

--- props of a sequence
currval
nextval

--- example using
select  my_key.currval
from    DUAL

--- somthing
insert into my_table(pk_field, field, ...)  -- define columns to add in values
values (my_key.nextval, value, ...)         -- vals to add
```


> lots of code snippets here, lets try it out

