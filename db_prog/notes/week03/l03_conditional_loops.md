# Conditional Control Loops

- [Conditional Control Loops](#conditional-control-loops)
  - [Conditional Control](#conditional-control)
    - [`IF` statement](#if-statement)
    - [`CASE` statement](#case-statement)
    - [Predicates](#predicates)
    - [`boolean` flags](#boolean-flags)
    - [`NULL`s in statements](#nulls-in-statements)
  - [Iterative Control](#iterative-control)
    - [`LOOP`](#loop)
    - [`EXIT`](#exit)
      - [`EXIT WHEN`](#exit-when)
    - [`WHILE LOOP`](#while-loop)
    - [`FOR` loop](#for-loop)
      - [numeric `FOR` loop](#numeric-for-loop)
      - [cursor `FOR` loop](#cursor-for-loop)

## Conditional Control

The ability to direct the flow of execution through your program based on certain conditions

### `IF` statement

comes in 3 flavour

```sql
-- if
IF      condition
THEN    code
END IF;

-- if / else
IF      condition
THEN    CODE
ELSE    CODE
END IF;

-- if / elsif / else
IF      condition
THEN    CODE
ELSIF   condition
    code;
ELSE    code;
END IF;
```

### `CASE` statement

```sql
-- you know what this do
CASE    grade
WHEN    'A' THEN dbms_output.put_line('Excellent');
WHEN    'B' THEN dbms_output.put_line('Good');
WHEN    'C' THEN dbms_output.put_line('Nice');
WHEN    'D' THEN dbms_output.put_line('Press F');
ELSE    dbms_output.put_line('No such grade');
END CASE;
```

### Predicates

All predicates available in `sql` are also in `pl*sql`

Full use of predicates is available, combined as required with `AND`, `OR`, `NOT`

Theres are also these comparison operators

- `BETWEEN`
- `LIKE`
- `IS [NOT] NULL`
- `EXISTS`

```sql
-- Comparison operators
DECLARE
    v_username      char(5);
BEGIN
    select upper(substr(ename, 1, 5)) INTO v_username
    from emp
    where empno = 7788;   

    IF  v_username LIKE '%SC%'
    THEN
        ---
    ELSIF substr(v_username ,1 ,1) BETWEEN 'J' and 'M'
    THEN
        ---
    ELSE
        ---
    END IF;
END;
```

### `boolean` flags

you know what this is used for, in this case mostly is to streamline some if statements

```sql
-- from this 
IF order_total > max_allowable_order
THEN
    v_order_exceed_bal := TRUE;
ELSE
    v_order_exceed_bad := FALSE;
END IF;

-- to this
v_oreder_exceed := order_total > max_allowable_order
```

### `NULL`s in statements

> **NOTE** the `<>` operator means not equal

> NULL **is either** TRUE or FALSE
>
> protect yourself using `nvl(variable, replacement)`

## Iterative Control

`LOOP` and `EXIT` statements

Loop let you execute a sequence of statements multiple times.
There are 3 type of `LOOPS`

- LOOP
- WHILE-LOOP
- FOR-LOOP

### `LOOP`

the simplest `loop` statement is the basic (infinite) loop.

```sql
LOOP
    -- code;
END LOOP;
```

This will run **forever** unless there is an `EXIT` statement inside the loop

### `EXIT`

Force a `loop` to complete unconditionally

```sql
LOOP
    -- infinite loop
    IF -- exit condition
    THEN
        -- log? then exit loop
        EXIT;
    END IF;
    --
END LOOP;
```

#### `EXIT WHEN`

lets a loop complete conditionally.
When the `EXIT` statement is encountered, the `WHEN` clause is evaluated.
if the condition is true, the `loop` **finishes** and continue on to the next statement after the loop

```sql
Loop
    fetch c1 into --
    EXIT when c1%NOTFOUND; -- exit when cursor is empty
    --
End Loop;
close c1;

-- replace simple if statements like this
if count > 100 then
    exit;
end if;
-- to thiis
exit when count > 100;
```

### `WHILE LOOP`

you know how this works

```sql
while -- condition
loop
    -- code
end loop;
```

### `FOR` loop

2 types `numeric` and `cursor`

#### numeric `FOR` loop

```sql 
-- syntax
FOR i IN [reverse] low..high
LOOP
    -- code
END LOOP;
```

To loop code for a certain number of times

No need to declare the `index i` it is done automatically. Index is incremented by 1 ( you can bypass this )

The variable that specifies the range is only evaluated once, changing it inside the scope does nothing. But doing this is **bad practice**

Must be at least 1 executable statement in the loop

Loop can be terminated early with `EXIT` but is not recommended

```sql
FOR i IN 1..4 LOOP          -- 1 ,2, 3, 4
    -- code
END LOOP;

FOR i IN REVERSE 1..4 LOOP  -- 4, 3, 2, 1
    -- code
END LOOP;
```

#### cursor `FOR` loop

`For` loops which is associated and defined by a SQL select statement

Using `cursor` **for loops** let you retrieve a *set of records* from the db.
The loop will fetch values from the record set and then traverse through the record set until all the records have been processed.

> can process data very efficiently

It reduces the amount of code required to fetch data from a cursor, thereby reducing the chances of making errors

```sql
-- set output buffer size
set serverouput on size 1000000

declare
    cursor c1 is select * from ordertbl;
begin
    for r1 in c1 loop
        dbms_output.put_line('the order is ' || r1.ordno);
        exit when r1.ordno = 'O1615141';
    end loop;
end;
```