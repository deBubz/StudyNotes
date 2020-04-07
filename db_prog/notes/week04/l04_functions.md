# Procedures Function and Triggers

## Some Info

When data is inserted into a table, memory requirement always grow but are never reclaimed without some specific process.
When doing the **assessment** you may need to reclaim the space or at least "lower the high water mark" in the tables you`ll be using.

`Delete from a Table` put data into the **rollback segment** until a rollback or commit is issued. the **space** that the data is occupied is not reclaimed 

> `DELETE FROM FSS_TRANSACTIONS;

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


### Packages

