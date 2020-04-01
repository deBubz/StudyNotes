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
  - **Scope**
- Blocks can be:
  - **Anonymous** un-named blocks stored as a text file and loaded by user at runtime
  - **Named Blocks** often are procedures and functions stored in the DB in a compiled format.

```md
Notes:

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

## Comments and Effective Coding Style


## Running `PL*SQL` in `SQL*PLUS` (Compiling and Debugging)

---

## Notes

- Cursors - data feed
- sql procedures, functions to be called instead of having that logic implemented in the backend software