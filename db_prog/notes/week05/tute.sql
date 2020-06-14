et serveroutput on;

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

	when OTHERS THEN
		  dbms_output.put_line('ERROR THROWN ' || SQLERRM);
		  ROLLBACK;

END;


-- q02 create RUN LOG tavble with this table

drop table run_log;
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

select * from run_table;

drop table run_log;
create table run_log (
	runID				NUMBER			PRIMARY KEY,
	ModuleName		VARCHAR2(35)	NOT NULL,
	RunStartDate	DATE				NOT NULL,
	RunEndDate		DATE,
	Outcome			VARCHAR2(35),
	Comments			VARCHAR2(35)
);

-- sequence
drop sequence seq_runlog;
create sequence seq_runlog start with 1 maxvalue 999999999 increment by 1;


--- table editing
-- test running
insert into run_log(runID, ModuleName, RunStartDate, RunEndDate, Outcome, Comments)
values (1, 'test1', sysdate, null, null, 'starting');

-- test finished runnign
update run_log set runenddate = sysdate where runid = 1;    -- had coded runid


-- update
update run_log set runenddate = sysdate where runid = 1;

-- remove all
delete from run_log;

select * from run_log;

set serveroutput on;


call mainProg();

--- check run code
create or replace procedure mainProg is
    v_runID         NUMBER;

    moduleRUN       EXCEPTION;
    pragma exception_init(moduleRun, -60);

    c_module_name   constant    run_log.ModuleName%TYPE := 'test1';
    c_run_buffer    constant    number := 1/24;     -- used to check if ran in the last hour
BEGIN
    --
    -- log run
    testshouldrun(c_module_name, c_run_buffer, v_runID);

    -- main code
    dbms_output.put_line('running some code');
    null;
    -- finish running succesfullt
    update run_log
    set runenddate = sysdate,
        outcome = 'SUCCESS',
        comments = 'Finished running'
    where runid = v_runID;
EXCEPTION
    when moduleRUN then
        dbms_output.put_line(c_module_name || ' has been run before');
--    when others then
--        dbms_output.put_line('something happened');
--
--        update run_log
--        set runenddate = sysdate,
--            outcome = 'FAILED',
--            comments = 'failed execution '
--        where runid = v_runID;
END;
/

-- if you wanna use this is a speperate module
create or replace procedure testShouldRun (
    p_modulename    run_log.modulename%type,
    p_run_buffer    number,
    p_runID         out number
) is
    r_run_log       run_log%ROWTYPE;
    -- moduleRun exception is unknown
    moduleRun exception;

begin
    select * into r_run_log     -- to check if ran in the last hour
    from run_log
    where upper(modulename) = upper(p_modulename)
    and runenddate > sysdate - p_run_buffer
    and outcome != 'FAILED';        -- if no data found, it ran in the past hr

    dbms_output.put_line('> ran already before');

        -- stop running when its ran before
    dbms_output.put_line('> raising');
    raise moduleRUN;

        -- need to handle this
exception
    when NO_DATA_FOUND then
        dbms_output.put_line('> no data - not ran before or already ran'); -- then add a log to start running
        -- set id
        select SEQ_RUNLOG.nextval into p_runid from dual;
        insert into run_log(runID, ModuleName, RunStartDate, RunEndDate, Outcome, Comments)
        values (p_runid, p_modulename, sysdate, null, null, 'starting');
end;




-- *****************************************************************************
--------------------------------------------------------------------------------

-- misc information

--assessmetn

-- msg log table

select * from dbp_message_log where student_id = user;

-- should not use db_admin.nem16 just use nem_rm16 table

-- forcast 48 entries for 14 days for
select tni, fr, frmp from v_nem_rm16;

-- forecast statement type

-- initialize what should init
-- what functions should i do
-- do everything at once?? seems bad

-- seperate generate and print??


-- design document
-- schema of the data, erd
-- describe module, what it does, parameter table, log table
-- technical guide to help another person build the system
-- table of contents, headers, page numbers


-- sql avg for 1hh of 1day
select tni, lr, frmp, hh, avg(volume)
from v_nem_rm16
where to_char(day, 'Day') = to_char(to_date('19-MAY-2020', 'DD-MON-YYYY'), 'Day')
and tni = 'NBFW'
and lr = 'ENGYAUST'
and frmp = 'CITIP'
-- and hh = 1
group by tni, lr, frmp, hh

-- can i do this to generate 48 entries for 1 day

-- need a holiday flag, if no holiday. normal operation, check against the forcasting day



-- question 3

-- question 3
 drop table DP_MESSAGES;
 CREATE TABLE DP_MESSAGES
 (
   Tutorial_nr      VARCHAR2(35),
   Question_nr      VARCHAR2(10),
   message          VARCHAR2(255));


Drop Table Test_Table;
Create table test_table
(
  test_value     VARCHAR2(255)
);

select * from test_table;
select * from dp_messages;

drop procedure child_block;
drop procedure parent_block;

CREATE OR REPLACE PROCEDURE child_block IS
    -- add autonomous transaction
    -- only commit an autonomous transaction in the current scope
    pragma autonomous_transaction;
BEGIN
	INSERT INTO dp_messages
		(tutorial_nr, question_nr, message)
	VALUES
		(5, 3, 'Child block insert autonomous');
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

-- running

call parent_block();

-- no pragma, since it inserted into seperate tables
-- it'll commit both??
-- run parent_block; and the test table, what do you see
-- what COMMIT in the child_block do?
-- what ROLLBACK in the parent do?

-- modify the child to be an AUTONOMOUS transaction
-- rerun parent
-- do query on the dp_messages table and the test_table, what do you see

-- what did COMMIT in the child_block do?
-- what did ROLLBACK in the parent block do?s
