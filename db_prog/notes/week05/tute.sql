set serveroutput on;

-- tutorial 5 questions and answers

-- My attempts


-- q01 write a program with an exception section using this template

-- template
DECLARE
	v_orderno		ordertbl.ordno%TYPE;
	v_number			NUMBER;
BEGIN
	SELECT ordno INTO v_orderno
	FROM	ordertb
	WHERE ordno = '01116324';

	v_number := 123/5;
	dbms_output.put_line();

END;

-- use and run and check there is no compulation errors
-- change the code to ther is error
WHERE ordno = 'xx';
v_number := 123/0;

-- write appropriate exception handlers
-- so that the code will operate after the error occur

DECLARE
	v_orderno		ordertbl.ordno%TYPE;
	v_number			NUMBER;
BEGIN
	SELECT ordno INTO v_orderno
	FROM	ordertbl
	WHERE ordno = 'O1116324';
    dbms_output.put_line('found this thing ' || v_orderno);

	v_number := 123/0;
	dbms_output.put_line('result is :' || v_number);

EXCEPTION
    when NO_DATA_FOUND THEN
        dbms_output.put_line('no data found');

    when ZERO_DIVIDE THEN
        dbms_output.put_line('cant divide by 0');

END;


-- q02 create RUN LOG tavble with this table

create table run_log (
	runID				NUMBER			PRIMARY KEY
	ModuleName		VARCHAR2(35)	NOT NULL
	RunStartData	DATE				NOT NULL,
	RunEndDate		DATE,
	Outcome			VARCHAR2(35),
	Comments			VARCHAR2(35)
)

-- write a procedure that do something interesting
-- each time running should check the table

-- your module is allowed to run every hr.
-- if the  model run in the last hour
	-- insert an entry into RUN_LOG recording run start time
-- perform the assined task and exit, recording run_end)date and outcome of the procedure

-- ok so create table for logging (RUN_LOG)
-- run the procedure and record running details into RUN_LOG

-- watch tutorial for this

-- q03 copy to the env

CREATE OR REPLACE PROCEDURE child_block IS
BEGIN
	INSERT INTO dp_messages
		(tutorial_nr, question_nr, message)
	VALUES
		(5, 3, 'Child block insert';
	COMMIT;
END child_block;

/

CREATE OR REPLACE PROCEDURE parent_block IS
BEGIN
	INSERT INTO test_table
		(test_value)
	VALUES
		('Parent block insert at '||sysdate);

	child_block;
	ROLLBACK;
END parent_block;
/

-- run parent_block; and the test table, what do you see
-- what COMMIT in the child_block do?
-- what ROLLBACK in the parent do?

-- modify the child to be an AUTONOMOUS transaction
-- rerun parent
-- do query on the dp_messages table and the test_table, what do you see

-- what did COMMIT in the child_block do?
-- what did ROLLBACK in the parent block do?

