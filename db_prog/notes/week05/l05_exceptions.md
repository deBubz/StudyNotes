# Week 05

## Exceptions

### What is Exception

Is to let programmers write more `defensive` code

**exceptions** are unusual conditions ( errors ) encountered during execution. which includes

- run time error
- system error
- logic error
- warning issued by application

And you do that in the `EXCEPTION` block

```sql
DECLARE
-- variable
BEGIN
-- code
EXCEPTION
-- exceptions are handled here
END;
```

From there you can write **exception handlers** to deal with specific errors.

Each exception has a number, but it must be handled by its name

> Once, the exception is handled, control `CANNOT` return to the same block, it will pass to the enclosing block or end if there is no enclosing block.

`e.g`

```sql
create or replace function is_it_number(p_value IN VARCHAR2)
return boolean
IS
    v_numberOK NUMBER;
BEGIN
    v_number := to_number(p_value);
    return true;
EXCEPTION
    when VALUE_ERROR
    then
        dbms_output.put_line('invalid number ' || p_value);
        return false;
END;
```

### Types

the used previously `VALUE_ERROR` is a [**predefined exception**](https://docs.oracle.com/cd/B10501_01/appdev.920/a96624/07_errs.htm)

use `OTHERS` to handle any exception. There are also built in constants `SQLCODE` and `SQLERRM` are useful, they return error number and error message

```sql
-- unhanded error??

create or replace function is_it_number(p_value IN VARCHAR2)
return boolean
IS
    v_numberOK NUMBER;
BEGIN
    v_number := to_number(p_value)/0;   -- error dividing by 0
    return true;
EXCEPTION
    when VALUE_ERROR
    then
        dbms_output.put_line('invalid number ' || p_value);
        return false;
END;
```

### User Defined Exception

You can also define your own and `RAISE` those exceptions, by using a handler with the `WHEN` clause inside the `EXCEPTION` block

Oracle has many error code that has not associated to a predefined name. Use `PRAGMA`, `EXCEPTION_INIT` to bind an error code to a user defined exception

Your Own exception
```sql
DECLARE
    out_of_stock        EXCEPTION;  -- 1. declare
    number_on_hand      NUMBER(4);
BEGIN
    --
    IF number_on_hand < 1 
    THEN
        RAISE out_of_stock          -- 2. raise exception
    END IF;
EXCEPTION
    WHEN out_of_stock               -- 3. handle 
    THEN
        -- handle error
END;
```

Bind to an Oracle ERROR code
```sql
DECLARE
    deadlock_detected       EXCEPTION;
    PRAGMA  EXCEPTION_INIT(deadlock_detected, -60);
BEGIN
    -- some operation that throws an ORA-00060 error
EXCEPTION
    WHEN deadlock_detected
    THEN
        -- handle error
END;
```

### Scope and propagation

> scope of an exception is that portion of code that is covered by that exception

- Exceptions `RAISED` in an inner block system jumps to the exception **in that block**
- IF exception is not found then control passes to exception in the enclosing block
  - this repeats until the error is caught or the system aborts the program

### `RAISE_APPLICATION_ERROR`

`RAISE_APPLICATION_ERROR` is a special built in *procedure* provided by ORACLE

- allows you to issue a user-defined ORA error messages from stored subprograms.
  - so you can report errors to your app and avoid returning unhandled exception
- `raise_application_error(error_number, message)`

example
```sql
create procedure raise_salary(p_emp_id NUBMER, p_amount NUMBER) AS
    v_curr_sal NUMBER;
BEGIN
    SELECT sal INTO v_curr_sal
    FROM emp
    WHERE empno = p_emp_id;

    --
    IF v_curr_sal = is NULL THEN
        raise_application_error(-20101, 'SALARY IS MISSING');
    ELSE
        UPDATE emp
        SET sal = v_curr_sal + p_amount
        WHERE empno = p_emp_id;
    END IF;
    --
END raise_salary;
```

the calling app gets a PLSQL exception which it can process using the error-reporting function `SQLCODE` and `SQLERRM` in an `OTHERS` handler

> IT is important to know how to use exceptions effectively

## Transactions and Autonomous Transactions

Something about a transaction model,
where **Transaction** is a logical unit of work which must be either committed or rolled back (`delete?`)

- transaction implicitly begins with the first SQL statement issued since the last commit or ollback

Your application code will determine what constitutes a transaction

### Transaction

- The env that your program runs in defines a session.
- any `COMMIT` or `ROLLBACK` issued in your session will make any/all changes permanent.
  - be careful with any data updates or inserts
- if you issue a periodic commit
  - what happen if the program failed before completing

example
```sql
DECLARE
    CURSOR c1 is    SELECT ordno, empno from ordertbl
                    WHERE empno is NOT NULL
                    AND orddate = sysdate;     
BEGIN
    --
    FOR r1 in c1 LOOP
        -- foreach order, get total
        -- calc employee comission
        -- UPDATE employee comission
        COMMIT;
    END LOOP;
    --
    COMMIT;     -- could also go here
EXCEPTION
    WHEN OTHERS THEN
        ROLLBACk;
END;
```

### Autonomous Function

before `8i` each session could only have 1 active transaction (bad), dev wants to perform some DML statements without affecting the overall transaction

you can do that with *Autonomous Transactions*, using a Autonomous Transaction block, the main transaction **is suspended** while the autonomous transaction is performed

main transaction is resumed when control returns

> why? to log of course

create an autonomous transaction
```sql
procedure log(  p_msg varchar2,
                p_msg_id  varchar2 default null)
is
    prama AUTONOMOUS_TRANSACTION;
begin
    insert into dbp_message_log(MESSAGE, MSG_ID)
            values(p_msg, p_msg_id);
    commit;     -- apply to the transaction in this scope only
exception
    when others then
        dbms_output.put_line('ERROR encountered trying to insert a log record');
        dbms_output.put_line('ERROR msg: ' || SQLERRM);
        RAISE;      -- consider re raising the error for enclosed scope
end;
```

## Summary

- TRANSACTIONS
  - transaction management is very complicated, this is just surface info
  - autonomous transactions provide versatility and loosen the shackles of traditional Transaction management
    - particular in todays' more distributed and disjointed env of the Internet and e-commerce 