# Database Programming Into

- **DualTable**
- **Date func**
  - becareful when dealing with dates, look at TRUNC(DATE)
- **Char concat**
- **Regex**
- **NVL**
- **Decode**
- **Sequence**
- tools > db > NLS> set your own date format

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

### DATE functions

### Character Functions

### NVL

### DECODE

### Sequences

--

## Summary