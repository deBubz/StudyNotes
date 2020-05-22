# Database Prog Content Review

> **Last Review**: 22 May 2020


## Week 01 Basics

> [Tute attempt](notes/week01/homework.sql)

- Select statement review
- If else
- Date handling `to_char`, `to_date` `trunc`
- misc functions `NVL`, `Decode`, `sequences`
- console log with `dmbs.put_line()`
- `sysdate` for current date, `dual` table for testing??
- be careful on the date format

## Week 02 Blocks

> [Tute attempt](notes/week02/exercise/tutorial.sql)

- plsql anonymous blocks (`DECLARE`, `BEGIN`, `END`)
- simple operations (line term, assignment, comments)
- variable data type
- anchored data type (`%ROWTYPE`)
- intro to cursors

## Week 03 Loops and Conditions

> [Tute attempt](notes/week03/tute.sql)

- loops (`if`, `case`)
- can use predicate, boolean flags as conditions
- not equal
- careful of null
- using loops(`LOOP`, `WHILE-LOOP`, `FOR-LOOP`), `EXIT` loop using conditions
- using `cursor` in FOR `LOOP`

## Week 04 Functions and Procedure

> [Tute attempt](notes/week04/tut.sql)

- Roll back segment
- Types of blocks (anonymous, procedure, function, packages)
- creating and calling procedures/functions
- read what functions/procedures you've created (table `user_object`, `user_type`)
- **functions** returns value without changing state of system
- **procedures** change the state of the system

> review function and procedures

- theres triggers, dont think thats used


## Week 05 Exceptions

> [Tute attempt](notes/week05/tut.sql)

- `exception` block under `BEGIN`, to write handlers
- types of exception, built in constants `sqlcode`, `sqlerm`
- user defined exceptions (`RAISE`)
- `PRAGMA EXCEPTION_INIT()` bind error code into a user defined exception
- `RAISE_APPLICATION_ERROR` raise user defined error, using a custom code.
- `Transactions` - committing and rolling back changes to database

> TODO review tutorials video

## Week 06

> [Tute attempt](notes/week06/tut.sql)

- purpose of packages, how to use packages to access public elements
- **package body** - main content (private)
- **init** - code run init
- **package specification** - header, declaring public elements(vars, funcs, procs)

> TODO review tutorial video

## Week 07


> TODO review tutorial video

## Week 08


## Week 09


## Week 10











