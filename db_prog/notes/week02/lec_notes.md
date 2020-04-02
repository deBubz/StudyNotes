# Week 02 `Pl*SQL`

## Intro to `Pl*SQL`

- `PL*SQL` Procedural language Extension to-the Structured Query Language
  - Highly Structured integrated with SQL
  - Model after **ADA Language**
- **NOT** a stand alone language (No executable)
- runs in a **host database environment** and invoked through interfaces (`SQL*Plus`)

> We're using `Oracle Db version 11g`

Other Oracle DB Tools

- Toad
- SqlNavigator
- Pl/SQL Developer
- SQL Tools

## Language Fundamentals

> `PL*SQL` BLOCKS are the fundamental unit of organization

- This enables:
  - **Modularization** basic unit of code where you will build **modules**(procedures, function)
  - **Scope** provide scope or context for logically related objects
- Blocks can be:
  - **Anonymous** un-named blocks stored as a text file and loaded by user at runtime
  - **Named Blocks** often are procedures and functions stored in the DB in a compiled format.

```md
;           line terminator
:=          assignment operator
--          line comment
/* */       block comments
```

```sql
-- block analogy
DECLARE
    v_counter NUMBER;
BEGIN
    v_counter := 0;
    v_counter := v_counter + 1;
---
        IF v_counter = 10 THEN
            DBMS_OUTPUT.PUT_LINE('Counter at ' || v_counter);
        END IF;
---
EXCEPTION
-- run time error handler
END;
```

#### Nested Blocks

Nested blocks are basically "sub-blocks" which are **nested** inside another block.

- Some other **terms** for nested block
  - Enclosed block
  - Child block
  - Sub block
- **Outer** block
  - Enclosing block
  - Parent block
- Some **benefits**
  - Let you create **scope** for variables, executable statement in that block
  - variables, exception, modules and few other structures are local to the block that declares them
  - "trapping" errors/exceptions in a block let the program to continue executing rather than aborting with the error

### DataTypes

This is a strongly typed language.
Hence variables must be `DECLARED` and assigned a datatype before use.

```sql
DECLARE
  v_char1           CHAR(10);
  v_char2           VARCHAR(15);    -- oracle datatype
  v_date            DATE;
  v_number          NUMBER(23, 2);  -- floating point: 23 digits, 2decimal
  v_FIRSTANDSECOND  VARCHAR2(23);
  v_flag            BOOLEAN;        -- 1 or 0
```

- `char(10)` reserve 10 characters/bytes string
- `varchar2(15)` 15 char/bytes string, but will automatically resize if less is used
  - if more is used, it is truncated

Different ways to work with variables

```sql
DECLARE
  -- init a value
  v_gravity     NUMBER := 9.8;
  -- constant
  con_gravity   CONSTANT NUMBER := 9.8;
  -- anchored variables declarations
  -- this relate code with data in the db
  -- assign datatype which are already set for the db
  v_cust_id     customer.customer_id%TYPE;  -- bind datatype
  r_customer    customer%ROWTYPE;           -- bind table
  -- declaring cursor
  CURSOR  customer_cur is
          SELECT  custno, custbal;
          FROM    customer; 
```

### **Anchored Data Variable**

```sql
set serveroutput on -- allow output

DECLARE
  r_customer      customer%ROWTYPE;
BEGIN
  SELECT *
  INTO customer     -- dangerous
  WHERE rownum < 2; -- why limit to 1 record  
                    -- 

  DBMS_OUTPUT.PUT_LINE('The customer number is ' || r_customer.custno);
END;
```

> NOTE:
> - the `%ROWTYPE` anchors the var into a db table definition
> - the SQL statement must select each attr in the table, hence the `select *` ( be careful )
> - accessing each elem of the record is achieved using `r_customer.custno`

### **Cursor Variable**

```sql
set serveroutput on;

DECLARE
  cursor cur_customer IS
    SELECT custno, custfirstname, custlastname, custbal
    FROM customer;
BEGIN
  FOR rec_customer IN cur_customer
  LOOP
    DBMS_OUTPUT.PUT_LINE('Cust number is ' || rec_customer.custno);
  END LOOP;
END;
```

> NOTE:
> - The `CURSOR` data defines a pointer to the output of the SQL statement
> - using a `CURSOR` *For Loop* to traverse through the record one at a time.
> - Accessing each element of the record is achieved by using the `.` notation (`customer_rec.custno`)

## Comments and Effective Coding Style

> DO COMMENTS

- generally use comments to describe the purpose and use of each code segments.
- explain complex process
- BUT be careful of documenting the obvious to avoid clutter

### Variable naming

- your variables should be **self documenting** so the reader could easily determine the purpose of your code.
- should avoid unnecessary ambiguous variable names

> This is important


## Running `PL*SQL` in `SQL*PLUS` (Compiling and Debugging)

---

## Notes

- Cursors - data feed
- sql procedures, functions to be called instead of having that logic implemented in the backend software