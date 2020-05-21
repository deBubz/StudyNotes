# lecture 06

> Define and Manipulating Cursors Records and Collections

## Cursors

> They are a pointer to the current *set of records* that are a result of a SQL query against a databas table

- **implicit cursor**
  - defined by you or the system (SELECT .. INTO, or any SQL DML statements INSERT UPDATE DELETE)
- **explicit cursor**
  - when you declare a query in the declaration selection with a block?
  - you`ll generally use an explicit cursor when working with multiple records

### Managing Cursor

1. Defining cursor
2. Open a cursor
3. Fetch a cursor
4. Repeat the fetch till theres no more data
5. Close Cursor

### Declaring Cursor

```sql
DECLARE
	CURSOR c_cursorName  is SELECT * from something;
```

### Opening a cursor

next step after declaring

```sql
BEGIN
	open c_cursorName;
```

which will trigger these actions
1. The vars in the `WHERE` clause are examined
2. The active set is determined and the **PLSQL** engine executes the query for that cursor
3. The engine identifies and retrieves the active set of data that meet the `WHERE` conditions
4. The active pointer is set to the first row

### Fetching Row of cursor

after declared and opened, you can then retrieve data from the cursor is referred to as fetching a cursor.

```sql
--- two method of fetching cursor
FETCH c_cursorName into PLSQL_variables
-- or
FETCH c_cursorNAME into PLSQL_record
```

this will happen on fetch
1. fetch is used to retrieve one row at a time from the active set (generally done in a loop)
2. after each fetch, pointer moved to the next row
3. continues until until the entire set is returned.

> Last `FETCH` will not assign values to the output vars; will still contain their prior value

### using the cursor

```sql
DECLARE
	CURSOR c1 is 	select custno, custfirstname, custlastname, custbal
						from customer
						where custbal > 100;
-- each field in the cursor must be bound into a value

--	declare each var for each row
--v_cust_no customer.custno%TYPE;
--v_custfirstname customer.custfirstname%TYPE;
--v_custlastname customer.custlastname%TYPE;
--v_custbal customer.custbal%TYPE;
-- or

r1 c1%ROWTYPE;

BEGIN
	open c1;		-- open cursor
	LOOP
		fetch c1 into r1;		-- fetch value into variable
		EXIT WHEN c1%NOTFOUND;
		dbms_output.put_line('Records in the cursor = '||c1%ROWCOUNT);
	END LOOP;

	CLOSE c1;		-- close cursor
END;
```

### Cursor attributes

every explicit cursor/ cursor var has 4 attributes `%FOUND`, `%NOTFOUND`, `%RPWCOUNT`, `%ISOPEN`

When appended to the cursor or c_Var, these return useful info about the execution of a data manipulation statement.

You can use cursor attr in procedural statements but not SQL statements

> See table slide 9

### Cursor with Parameters

cursor can take params which can appear in the associated query wherever constants can appear
The formal parameter of a cursor must be `IN` params. Therefore, they cannot return values to the actual params

**Why* params?

- Make cursor more reusable
  - instead of hard coding `where` condition, you can use a parameter and pass different values when its opened
- Avoid Scope problem
  - if theres nested blocks, you can define cursor at a higher block and use it in any of the sub blocks with variables defined in those local blocks

**When should you do this*?

if you may use the same cursor many time with different values

Examples

```sql
DECLARE
	cursor c_order IS ...;
	cursor 	c_ordline (p_orderID VARCHAR2) IS
				SELECT prdno, qty, p_orderID
				FROM ordline
				WHERE ordno = p_orderid;
BEGIN
	FOR r_orders IN c_orders LOOP
		--
		FOR r_ordline IN c_ordline(r_orders.ordno) LOOP
		---
		END LOOP;
		---
	END LOOP;
END;
```

NOTES:

- cursor is called with a list of parameter values
- parameters can be used anywhere in the `SELECT` statement
- scope of the cursor parameter is the cursor only
- the mode of the cursor parameter can only be `IN`

### Cursor Summary

---

## Records

- record is a group of related data item stored in fields, each time with its own name and data type.
  - `e.g` you have data on employee (name, salary, date)
- these are logically related but different in type
- A record containing a field for each item let to treat the data as a logical unit

> makes it easier to organize and represent information

**NOTE**:

- the attr `$ROWTYPE` let you declare a record that represents a row in a db table
- BUT you cannot specify the datatype of the fields in the record
  - *or* declare more fields of your own.
- The program defined `RECORD` lifts those restrictions and lets you define your own records.

### Benefits

- **Data abstraction** - generalize data
- **Aggregate operations** - when you have a record, you can perform operations on the whole block of data rather than on each individual attributes
- **Leaner cleaner code** - cut down on variable sprawl, instead of declaring many individual variables.
  - declare single record. Reduce clutter, increases readability and maintainability.

### Declaring records

3 ways of doing it

**Table Based Record**

Use `%ROWTYPE` attr with a table name. Each field correspond to the column in the table

```sql
DECLARE
	r_employee		employee%ROWTYPE
```

**Cursor Based Record**

use `%ROWTYPE` attr with a cursor name. Each field correspond to a cursor field specified in the `SELECT` statement

```sql
DECLARE
	cursor c_EMP is 	SELECT empno
							from employee;
	r_employee c_emp%ROWTYPE;
```

**User Defined Records**

`TYPE RECORD` statement used to defined a record (hard?)

Each field of the record is defined with name and datatype.

A field can be another record type.

Variable then declared of that record type

```sql
DECLARE
	TYPE DeptRec IS RECORD(
		dept_id		dept.deptno%TYPE,
		dept_name	VARCHAR2(14),
		dept_loc		VARCHAR2(12),
		processes	BOOLEAN
	);

	v_dept_rec	DeptRec;
```

> note similar to var declaration


### Working with records

regardless on how you define the record, you work with the resulting record the same way.

you can work with the data at the 'record level' or with the individual fields.

this includes the return datatype from functions.

```sql
DECLARE
	TYPE EmpRec is RECORD (
		emp_id			emp.empno%type,
		---
	);
	---
	PROCEDURE raise_salary (emp_info IN EmpRec);
BEGIN
	---
END;
```

### Record-Level Operations

working at record-level, you avoid references to individual fields in the record. Following are the record level operations that you can perform

- can copy the contends of another record as long as they have the same structure
- can assign NULL to a record with a simple statement
- can define and pass the record as an argument in a parameter list
- can return a record back through a function

> slide 19 - copy record

> slide 20 - making call to functions, procedures and cursors

---

## Collections

datatype which offer ways to store arrays in `PLSQL`

Why arrays/collections are useful

- once collections are loaded into memory, they allow random and bi-directional access to rows in a set
- Improve performance by allowing you to store lookup information into memory and to cache frequently used database values.
- Keep track and return to elements that are selected for special treatments

> More of linked list than arrays

### 3 types of collections in ORACLE

- **Associative arrays** - we will concentrate on this
  - index in any order
- **Nested tables**
- **VARRAYS**

### Declaring and using Collections

1. defined record
2. record defined from record definition
3. variable of the collection type is declared
4. cursor was defined then opened
5. a loop was used to traverse through the cursor, the data was fetched and loaded into the array
6. minor printout done to to demo some features

> see slide 23

> INDEX BY BINARY_INTEGER
>
> set the datatype of the index

Accessing fields following this syntax

`collection(index).attribute`

### Collection methods

- `COUNT`
- `DELETE`
- `EXISTS`
- `EXTEND`
- `FIRST/LAST`
- `LIMIT`
- `PRIOR/NEXT`
- `TRIM`









