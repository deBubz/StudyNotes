# Procedures Function and Triggers

## Some Info

When data is inserted into a table, memory requirement always grow but are never reclaimed without some specific process.
When doing the **assessment** you may need to reclaim the space or at least "lower the high water mark" in the tables you`ll be using.

`Delete from a Table` put data into the **rollback segment** until a rollback or commit is issued. the **space** that the data is occupied is not reclaimed 

> DELETE FROM FSS_TRANSACTIONS;

`Truncate a Table` Remove **all data**, there is no opportunity to recover. The "high water mark" restored back to base level.

> TRUNCATE TABLE FSS_TRANSACTIONS;

## Modular code

**Modularisation** is the process by which you break up large blocks of code into smaller piece that can be called by other modules

Pros:

- reusable code
- manageable code
- readable code
- reliable code

`PL*SQl` supports 4 types of modules

- Anonymous blocks
- Procedure
- Functions
- Packages

> There are also other types of modules
>
> - trigger
> - cohesion - modules focused on specific task
> - coupling - how big the daisy chains of modules

### Anonymous blocks

- **Anonymous Block**
  - we've been using this
  - an anonymous block have no name, therefore they cannot be called by another block
  - not stored in the database
  - must be compiled and then run each time the script is run
- **Named Block**
  - subprograms that are compiled and stored in the db
  - can be called by other subprograms
  - can accept parameters ( not&variable )

### Procedure

- A module performing => 1 actions
- can have void return type
- may have => 0 parameters
- generally change the state of the machine

All procedures have 2 parts

- **The Header** - contains the procedure name and the parameters
- **The Body** - contains all the code for the procedure

```sql
-- procedure with 0 params
CREATE OR REPLACE PROCEDURE     -- header
check_order IS                  -- no declare
--
CURSOR c_order is
    SELECT ordno, orddate, custno
    FROM ordertbl
    WHERE orddate is NOT NULL;
BEGIN
    NULL;
    -- code
END;
```

```sql
-- procedure with params
CREATE OR REPLACE PROCEDURE
check_order(
    p_ordernr IN ordertbl.ordno%TYPE,
    p_date IN DATE) IS
    
    -- IN keyword

    CURSOR c_order IS
        SELECT ordno, orddate, custno
        FROM ordertbl
        WHERE orddate is NOT NULL
        AND ordno = p_ordernr;
BEGIN
    FOR r_order IN c_order LOOP
        dbms_output.put_line('Order is ' || order.ordno);
    END LOOP;
END;
```

Declaring params is similar to variables in the `DECLARE` block

```sql
PROCEDURE my_procedure(
    p_param1    DATE,
    p_param2    VARCHAR2,
    p_param3    NUMBER
)
```

#### Check and run the procedure

Checking

```sql
-- user_objects let you check details of your procedure
-- e.g its STATUS
select *
from user_objects
where object_type = 'PROCEDURE';    

-- user_source allow you to list the code
-- that makes up the procedure
select *
from user_source
where name = 'CHECK_ORDER';
```

Running

- called in a SQLPlus environment
  ```sql
    exec check_order('a', 'b');
  ```
- called in a module
  ```sql
    begin
        check_order('a','b');
    end;
  ```
- delete the procedure from the database
  ```sql
    drop procedure check_order;
  ```

### Functions

Functions are module that returns a value and **DO NOT** change the state of the machine.
These are standalone executable statement,
a call to a function can exist as part of an executable statement, such as an element in an expression or the value assigned as the default in a declaration of a variable

Every single business rule or formula should be placed in a function

Single row query should be defined within a function.

#### Function Structure

Mostly the same as a **Procedure** except it has a `RETURN` clause

```sql
-- example function
CREATE OR REPLACE FUNCTION Order_total 
  (p_ordernr IN ordertbl.ordno%TYPE)
  RETURN NUMBER IS
---
v_total_order NUMBER;
---
BEGIN
---
  RETURN NVL(v_total_order, 0);
END;

-- using this to assign a variable
v_orderTotal := Order_total('a');
```

- **RETURN** can return an type of data known to PL*SQL from simple ( numbers, strings, dates ) to complex ( collections, object types, and cursor variables )
- **function header** is the signature of the function. you should not need to look inside of the body in order to be able to determine how to call it from another module 
  - a la self documenting name

### Params

procedure and functions both use parameters to pass data back and forth between the module and the calling program.
Params should be designed sensibly, so that they are self documenting and easy to use.

OK, how does plSQL know which actual parameter goes with which formal parameter?

- **positional notation**
- **named notation** the parameters in the calling routine are explicitly stated using `=>`

```sql
--- procedure header
PROCEDURE check_ (  p_ordno in VARCHAR2,
                    p_date in ordertbl.orddate%type) is
--- procedure call
check_ (  p_ordno => 'a',
          p_date => '20-JAN-2019');
```

You also need to specify the way it will be used when defining a parameter. There are 3 different **parameter modes** in `plsql` for both Functions and Parameter

- `IN` - read only
- `OUT` - write only
- `IN OUT` - read/write

> look more into this

```sql
-- example
procedure predict_ (  p_last_date IN  DATE,
                      p_task_desc IN OUT VARCHAR2,
                      p_next_date_out OUT DATE) IS
  v_dummy varchar(2000)
---
-- IN param can only be read in the module
-- IN OUT param can only be read, if needed write
-- OUT  param can be only written to, away to return multiple values
```

But is this **good programming**?

we have a function. The values need to be calculated and returned through the `OUT` params.
The function returns a `bool` which the caller can test. It will tell the caller an exception occurred.
But whats the exception.

```sql
-- multi returns
FUNCTION GETSTARTENDDATE (
  p_datenow DATE,
  p_startDate OUT DATE,
  p_endDate OUT DATE)
RETURN boolean IS

BEGIN
  SELECT
    next_day(p_datenow, 'SUN'),
    next_day(p_datenow, 'SUN')+6 INTO p_startDate, p_endDate
  FROM dual;
  RETURN TRUE;
EXCEPTION
  WHEN others THEN
  RETURN FALSE;
END;
```

Theres also **polymorphism** and **function overloading**

### Triggers

A trigger is a piece of `plsql` code attached to a table/instance and executed on a predetermined event. These are:

- pre/post insert
- pre/post update
- pre/post delete

Triggers are used to

- implement database assertions
- perform audit functionality
- maintain data integrity ( on top or normal db functionality )
- automate housekeeping task and more

A trigger has 2 properties/attributes. `:OLD` and `:NEW`

- on `INSERT` there is no `:OLD` only `:NEW`
- on `DELETE` there is no `:NEW` only `:OLD`
- on `UPDATE` there is both

```sql
-- trigger definition
create or replace TRIGGER cust_HISTORY
after DELETE [or update]
on customer
REFERENCING NEW AS NEW OLD AS OLD
FOR EACH ROW  -- each row or session

BEGIN
  [WHEN DELETING | INSERTING | UPDATING]
  delete from ordertbl
  where custno = :old.custno;

  insert into customer_history(
    custno, custfirstname, custlastname
  )
  values(:old.custno, :old.custfirstname, :old.custlastname)

  exception
    when others then
      dbms_output.put_line('trgger generated an error ' || SQLERM);
      RAISE;  -- note this
END cust_history;
```

