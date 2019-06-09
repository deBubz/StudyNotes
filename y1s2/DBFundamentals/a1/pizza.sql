/* (Database Fundamentals, Assignment Part D, Spring 2017 */
/* First author's name: Al */
/* First author's email: 113406@UTS.EDU.AU*/
/* Second author's name: Fahimeh */
/* Second author's email: Fahimeh.Ramezani@UTS.EDU.AU*/
/* script name: dbpizza_Revised.SQL */
/* purpose:     Builds PostgreSQL tables for Pizza database */
/* date:        26 Sep 2017 */
/* The URL for the website related to this database is http://www.somewebsite.Com */

DROP TABLE recipe;
DROP TABLE menu;
DROP TABLE items;


CREATE TABLE menu
	(	pizza	varchar(20),
		price	real, 	
		country	varchar(20),		
		base	varchar(20),			
		PRIMARY KEY (pizza)		
);

INSERT INTO menu VALUES ('margarita',6.20,'italy','wf');
INSERT INTO menu VALUES ('napolitana',7.40,'italy','wf');
INSERT INTO menu VALUES ('stagiony',7.80,'italy','wm');


CREATE TABLE items
(	ingredient varchar(12),
	type varchar(8),
	PRIMARY KEY (ingredient)
);

INSERT INTO items VALUES ('cheese','dairy');
INSERT INTO items VALUES ('ham','meat');
INSERT INTO items VALUES ('anchovies','fish');
INSERT INTO items VALUES ('olives','veg');
INSERT INTO items VALUES ('mushroom','veg');
INSERT INTO items VALUES ('spice','spice');



CREATE TABLE recipe
(	pizza varchar(20),
	ingredient varchar(12),
	amount integer,
	PRIMARY KEY (pizza,ingredient),
	FOREIGN KEY (pizza) REFERENCES menu,
	FOREIGN KEY (ingredient) REFERENCES items
);

INSERT INTO recipe VALUES ('margarita','cheese',120);
INSERT INTO recipe VALUES ('margarita','spice',5);
INSERT INTO recipe VALUES ('napolitana','anchovies',100);
INSERT INTO recipe VALUES ('napolitana','olives',75);
INSERT INTO recipe VALUES ('napolitana','spice',10);
INSERT INTO recipe VALUES ('stagiony','ham',75);
INSERT INTO recipe VALUES ('stagiony','mushroom',50);
INSERT INTO recipe VALUES ('stagiony','olives',50);
INSERT INTO recipe VALUES ('stagiony','anchovies',25);
INSERT INTO recipe VALUES ('stagiony','spice',10);




-- 3.a.1: Question: Get all the information of all pizzas stored in the database.
-- 3.a.1: SELECT statement: 

SELECT * FROM menu;

-- 3.a.1: Result Table:

-- pizza    | price | country | base
--------------+-------+---------+------
-- margarita  |   6.2 | italy   | wf
-- napolitana |   7.4 | italy   | wf
-- stagiony   |   7.8 | italy   | wm
--(3 rows)


-- 3.a.2: Question: Get all the information of all ingredient and their types stored in the database.
-- 3.a.2: SELECT statement:

SELECT * FROM items;

-- 3.a.2: Result Table:

-- ingredient | type
--------------+-------
-- cheese     | dairy
-- ham        | meat
-- anchovies  | fish
-- olives     | veg
-- mushroom   | veg
-- spice      | spice
--(6 rows)


-- 3.a.3: Question: Get all the information of all recipes stord in the database.
-- 3.a.3: SELECT statement:

SELECT * FROM recipe;

-- 3.a.3: Result Table:


--   pizza    | ingredient | amount
--------------+------------+--------
-- margarita  | cheese     |    120
-- margarita  | spice      |      5
-- napolitana | anchovies  |    100
-- napolitana | olives     |     75
-- napolitana | spice      |     10
-- stagiony   | ham        |     75
-- stagiony   | mushroom   |     50
-- stagiony   | olives     |     50
-- stagiony   | anchovies  |     25
-- stagiony   | spice      |     10
--(10 rows)



-- 3.b: Question: Get the information of all pizzas, their ingredients and their types.
-- 3.b: SELECT statement:

SELECT * FROM menu NATURAL JOIN recipe;

-- 3.b: Result Table:

--   pizza    | price | country | base | ingredient | amount
--------------+-------+---------+------+------------+--------
-- margarita  |   6.2 | italy   | wf   | cheese     |    120
-- margarita  |   6.2 | italy   | wf   | spice      |      5
-- napolitana |   7.4 | italy   | wf   | anchovies  |    100
-- napolitana |   7.4 | italy   | wf   | olives     |     75
-- napolitana |   7.4 | italy   | wf   | spice      |     10
-- stagiony   |   7.8 | italy   | wm   | ham        |     75
-- stagiony   |   7.8 | italy   | wm   | mushroom   |     50
-- stagiony   |   7.8 | italy   | wm   | olives     |     50
-- stagiony   |   7.8 | italy   | wm   | anchovies  |     25
-- stagiony   |   7.8 | italy   | wm   | spice      |     10
--(10 row)



-- 3.c: Question: Get the average pizza price for each country.
-- 3.c: SELECT statement:

SELECT country, AVG(price) AS Average_Price FROM menu GROUP BY country;

-- 3.c: Result Table:

-- country |  average_price
-----------+------------------
-- italy   | 7.13333336512248
--(1 row)




-- 3.d: Question: Get the information of all pizzas, their ingredients and their types.
-- 3.d: SELECT statement:

SELECT * FROM menu INNER JOIN recipe ON menu.pizza = recipe.pizza;

-- 3.d: Result Table:

--    pizza    | price | country | base |   pizza    | ingredient | amount
--------------+-------+---------+------+------------+------------+--------
-- margarita  |   6.2 | italy   | wf   | margarita  | cheese     |    120
-- margarita  |   6.2 | italy   | wf   | margarita  | spice      |      5
-- napolitana |   7.4 | italy   | wf   | napolitana | anchovies  |    100
-- napolitana |   7.4 | italy   | wf   | napolitana | olives     |     75
-- napolitana |   7.4 | italy   | wf   | napolitana | spice      |     10
-- stagiony   |   7.8 | italy   | wm   | stagiony   | ham        |     75
-- stagiony   |   7.8 | italy   | wm   | stagiony   | mushroom   |     50
-- stagiony   |   7.8 | italy   | wm   | stagiony   | olives     |     50
-- stagiony   |   7.8 | italy   | wm   | stagiony   | anchovies  |     25
-- stagiony   |   7.8 | italy   | wm   | stagiony   | spice      |     10
--(10 rows)



-- 3.e: Question: Get the information of all pizzas, their ingredients and their types.
-- 3.e: SELECT statement:

SELECT * FROM menu,recipe WHERE menu.pizza = recipe.pizza;

-- 3.e: Result Table:

--   pizza    | price | country | base |   pizza    | ingredient | amount
--------------+-------+---------+------+------------+------------+--------
-- margarita  |   6.2 | italy   | wf   | margarita  | cheese     |    120
-- margarita  |   6.2 | italy   | wf   | margarita  | spice      |      5
-- napolitana |   7.4 | italy   | wf   | napolitana | anchovies  |    100
-- napolitana |   7.4 | italy   | wf   | napolitana | olives     |     75
-- napolitana |   7.4 | italy   | wf   | napolitana | spice      |     10
-- stagiony   |   7.8 | italy   | wm   | stagiony   | ham        |     75
-- stagiony   |   7.8 | italy   | wm   | stagiony   | mushroom   |     50
-- stagiony   |   7.8 | italy   | wm   | stagiony   | olives     |     50
-- stagiony   |   7.8 | italy   | wm   | stagiony   | anchovies  |     25
-- stagiony   |   7.8 | italy   | wm   | stagiony   | spice      |     10
--(10 rows)




-- 3.f: Question: Get the name of the cheapest Italian pizza.
-- 3.f: SELECT statement:

SELECT pizza FROM menu WHERE price = (SELECT MIN(price) FROM menu WHERE country = 'italy');

-- 3.f: Result Table:

--   pizza
-------------
-- margarita
--(1 row)


