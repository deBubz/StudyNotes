- [Lec 1 - basics of RDB](#lec-1---basics-of-rdb)
- [Lec 2 - relationships](#lec-2---relationships)
- [lec 3 - subtypes / supertypes](#lec-3---subtypes--supertypes)
- [lec 4 - relational model](#lec-4---relational-model)
- [lec 5 - normalization](#lec-5---normalization)
- [lec 6 - more Normalization](#lec-6---more-normalization)
- [lec 7 - SQL](#lec-7---sql)
  - [Select statements](#select-statements)
- [lec 8 - Joining table](#lec-8---joining-table)
- [lec 9 - sub-queries](#lec-9---sub-queries)


# Lec 1 - basics of RDB

- Initial db tings
- Pros of DB
  - Linking data, prevent duplication/redundancy, promote data sharing
  - DB allow central repository of shared data, managed by a controlling agent, standardized format.
- **Metadata**: properties & characteristics of users data (type, length, name)
- **relation** represented by common values in related tables (primary keys, foreign keys)
- **Data model(ERD)** graphical system to display relationship
  - *entity* each row of the table table(person, place, object, event, concept)
  - *attributes* properties of the entity (column)
  - *relationship* link between entities
- **Identifiers** (keys)
  - Keys are unique identifiers can be singular(one attribute) or composite(combination)
- **relationship**
  - Primary key - unique identifier of the entity
  - foreign key - identify dependent relation 

---

# Lec 2 - relationships

- modeled as lines between entities
- degree of relationship : number of entity types participate in it
  - unary (self relation)
  - binary (1 : 1)
  - ternary (between 3 entities)
- relationship cardinality
  - 1 : 1
  - 1 : m
  - m : m
- cardinality constraints: number of instances one entity must be associated with (optional, mandatory)
- **associative entities** linking tables, decomposing m : m relationships
- strong entity can exist by itself, weak entity cannot

---

# lec 3 - subtypes / supertypes

- basically table inheritance
  - **supertypes** entities with relationship with +1 subtype, containing common attribute shared between subtypes
  - **subtype**: a entities containing both attributes of the supertypes and its own distinct types
- supertypes **constraints** 
  - completeness constraints 
    - total specialization - 1 entry must be 1 subtype
    - partial specialization - 1 entry can be 0 or more subtypes

# lec 4 - relational model

- generally converting table to models
- entity constraints (metadata)
  - domain constraints (data type, description, length)
  - entity integrity - non null keys
  - referential integrity - existing foreign keys
- **referential integrity** also relates to deleting method
  - **restrict** block delete if exist on dependent side
  - **cascade** delete parent also delete dependent
  - **set-to-null** set foreign key to null if deleted

> the rest is transforming stuff into erd

---

# lec 5 - normalization

- functional dependencies
- normalization
> maybe skip? 

# lec 6 - more Normalization

---

# lec 7 - SQL 

- SQL data types
- creating tables
```sql
create table Customer_T (
    -- auto generated ID
    (CustomerID         INTEGER GENERATED ALWAYS AS IDENTITY
        (START WITH 1 INCREMENTED BY 1
        MINVALUE 1 MAXVALUE 10000
        NO CYCLE),
    CustomerName        VARCHAR2(25)    NOT NULL,
    CustomerStreet      VARCHAR2(25),
    CustomerCity        VARCHAR2(20),
    CustomerState       CHAR(2),
    CustomerPostalCode  VARCHAR(9),
CONSTRAINT Customer_PK PRIMARY KEY(CustomerID),
--- to set referential integrity add extra param
ON UPDATE CASCADE
);
```
- altering table
```sql
ALTER TABLE Customer_T 
-- use any of these
ADD col     VARCHAR(20),
DROP col,
ADD CONSTRAINT --- constraint stuff
```
- removing table
```SQL
DROP TABLE Customer_T
```

OK more fun stuff here
```SQL
--- inserting into a table
---- either insert all colums
INSERT INTO Customer_T VALUES (004, 'name', 'street', 'city', 'st', 1234);
---- or define what columns to insert, cols not stated will be null
INSERT INTO Customer_T(CustomerID, CustomerName) VALUES (005, 'cheese');
---- could use select to insert to another table
INSERT INTO CaCustomer_T SELECT * FROM Customer_T WHERE CustomerState = 'CA';
```

```SQL
-- DELETING
DELETE FROM Customer_T WHERE CustomerState = 'HI';
--- Delete all rows
DELETE FROM Customer_T;
```

```SQL
-- update statement
UPDATE Customer_T SET CustomerName = 'steeve'
WHERE CustomerID = 1
```

## Select statements

- query single or many tables
```sql
-- select statement and clauses
SELECT -- list columns and expressions to view
FROM -- tables
WHERE -- boolean conditions
GROUP BY -- categorization of results
HAVING -- what group will be included
ORDER BY -- sorting criteria ASC DESC most likely
```

- misc modifiers for select
```SQL
-- eliminate duplicates
SELECT DISTINCT(column) FROM TableName

-- alias
SELECT column as col FROM TableName

-- like operator, use wildcard to match string
SELECT column FROM TableName
where columnData LIKE '%Table'; -- %indicates any string with any char ending with Table

-- ordering with order by clause
SELECT * from TableName
ORDER BY column DESC -- default is ascending
```

- misc group by clauses
  - to categorize result into groups to be analyzed
  - one of such analysis are **aggregate functions** 
```sql
-- average
SELECT avg(column) FROM TableName;
SELECT round(avg(column), 2) FROM TableName;

-- count
SELECT count(column) FROM TableName;
```

- **HAVING** works like **WHERE** clause but operates on **GROUP BY** clauses

> Under the hood a sql statement will filter in this order
> - FROM table
> - filter Where condition
> - filter Groupby
> - filter Having
> - select columns

EXTRAS `VIEW`
- These are virtual table/ dynamic views (operates similar to variables)
```sql
CREATE VIEW ViewName as (Select * from TableName);
```

---

# lec 8 - Joining table

- relational operation combining many tables with relating columns into a single table
- common columns are normally PK and FK of dependent table
- Types of joins 
  1. EquiJoin - inner inner join joining condition based on equality between common columns, show duplicated column
  ```sql
  SELECT * FROM TableA INNER JOIN TableB
  ON TableA.name = TableB.name;
  ```
  2. Natural join - inner join variation, join column by similar names, and duplicate columns are removed.
  ```sql
  SELECT * FROM TableA NATURAL JOIN TableB;
  ```
  3. Cross join - regular join using the where clause only
  ```sql
  SELECT * FROM TableA a, TableB b
  WHERE a.name = b.name
  ```
- Outer joins - rows not having matching column values are also included
  1. left/right outer join - contains value of the other side even if there are no match
  ```sql
  -- regular left/right outer join
  SELECT * FROM TableA
  LEFT OUTER JOIN TableB
  ON TableA.name = TableB.name
  -- outer join but not including B
  SELECT * FROM TableA
  LEFT OUTER JOIN TableB
  ON TableA.name = TableB.name
  WHERE TableB.id IS NULL
  ```
  2. full outer join/ union join - include all column from each table but if there are no matching column data for the row, it will be null
  ```sql
  SELECT * FROM TableA
  FULL OUTER JOIN TableB -- full outer join
  ON TableA.name == TableB.name
  ```

---

# lec 9 - sub-queries

- query inside another query, can be placed
  - in a condition of the `WHERE` clause
  - as a table in the `FROM` clause
  - within the `HAVING` clause
- sub-queries can also
  - **simple** - executed once for the entire outer query
    - used in `WHERE` and `HAVING`
  - **correlated** - executed once **for each** row returned by the outer query

```sql
-- simple 
SELECT * from Product_t
where price = (SELECT max(price) from Product_t)
-- since max returned only 1 value, outer query is also executed once
```
- `IN` or `ANY` operator, select data from a set
- try to avoid `ALL` and `ANY`
```sql
-- select all customer that have made an order
SELECT * from Customer_T
WHERE CustomerID IN (SELECT distinct(CustomerID) from Order_T)
```

> some JOIN can also be written as a SUB-QUERY
