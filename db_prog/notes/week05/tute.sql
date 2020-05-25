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

-- ==========================================================================================
-- question 2 Tutorial code
-
--drop sequence seq_runlog;
--create sequence seq_runlog start with 1 maxvalue 999999999 increment by 1;
--
--
--select seq_runlog.nextval from DUAL;
--
---- write a procedure that do something
---- if its done in the past hour then then throw an error
--
--
select * from run_log;
--
insert into run_log(runID, ModuleName, RunStartDate, RunEndDate, Outcome, Comments)
values (1, 'test1', sysdate, null, null, 'starting');
--
--set serveroutput on;
--
update run_log set runenddate = sysdate where runid = 1;
--
delete from run_log;

DECLARE
    v_runID               number;
    moduleRun           exception;
    r_run_log           run_log%ROWTYPE;
    c_moduleName       CONSTANT run_log.modulename%TYPE := 'test1';
    c_runBuffer        constant number := 1/24;
BEGIN
    --
    -- log run
    BEGIN
        select * INTO r_run_log
        from run_log
        where upper(modulename) = upper(c_moduleName)
        and runenddate > sysdate -c_runBuffer;

        dbms_output.put_line('has been run before');

        -- raise exception because its already ran
        raise moduleRun;
    EXCEPTION
         WHEN no_data_found THEN
            dbms_output.put_line('not run before ');
            -- if not runbefore start another module
            -- sequence id
            select seq_runlog.nextval into v_runID from dual;
--
            insert into run_log(runID, ModuleName, RunStartDate, RunEndDate, Outcome, Comments)
            values (v_runID, c_modulename, sysdate, null, null, 'starting');

    END;
    dbms_output.put_line(c_moduleName ||' is running');


    -- main code

    v_runid := 100/0;

    -- finish run
    update run_log
    set runenddate = sysdate,
        outcome = 'SUCCESS',
        comments = 'finished running'
    where runid =v_runID;

    dbms_output.put_line(c_moduleName ||' has finished running');

exception
    when moduleRUN then
        dbms_output.put_line(c_moduleName ||' has ben ran before');

    -- when everything failed, log that it failed
    when others then
        update run_log
            set runenddate = sysdate,
            outcome = 'FAILED',
            comments = 'something went wrong'
        where runid =v_runID;


END;


-- ====================================================================================================



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



--------------------------------------------------------------

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