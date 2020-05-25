--Turorial 5
SET ServerOutput ON
SET Verify OFF
SET Feedback ON
CLEAR SCREEN
/
DROP SEQUENCE seq_runlog;
CREATE SEQUENCE seq_runlog START WITH 1 MAXVALUE 999999999 INCREMENT BY 1;
/
DROP TABLE RUN_LOG;

-- this is help with creating a solution for question 2, use RUN_LOG to control the code run

-- similar to the assignment requirement ??

-- NOTE
-- to demo multiple exception handlers in the exception section

-- call the procedure with a suburb so that one record is returned with a clean run

-- then change the suburb name by adding x when calling the procedure (bad name)
-- this throw NO_DATA found exception

-- modify the prodecure by removing some handlers to see what happened

-- then put an exeption handler in the calling routing. track to see where the raised exception handled
-- in the procedure?
-- in the caller?
-- or the system bailes out to the OS

-- PURPOSE - to show an exception will `unwind` the caller till it finds a handler

-- Depending where it is, it will catch the exception and print the error, but it could report error in the wrong place

-----




CREATE TABLE RUN_LOG
(
  runID        NUMBER       PRIMARY KEY,
  ModuleName   VARCHAR2(35) NOT NULL,
  RunStartDate DATE         NOT NULL,
  RunEndDate   DATE,
  Outcome      VARCHAR2(25),
  Comments     VARCHAR2(255)
 );






--  question 3


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

select * from DP_MESSAGES;
select * from test_table;

drop procedure child_block;

Create or REPLACE PROCEDURE child_block IS

-- PRAGMA AUTONOMOUS_TRANSACTION;

BEGIN

   Insert Into DP_MESSAGES
   (tutorial_nr, question_nr, message)
   VALUES
   (5, 3, 'Child Block Insert');

   COMMIT;
END child_block;

drop procedure parent_block;

create or replace PROCEDURE parent_block IS
BEGIN

   Insert Into test_table
   (test_value)
   VALUES
   ('Parent block insert at '||sysdate);

   child_block;

   ROLLBACK;

END parent_block;


begin
parent_block;
end;

select * from dp_messages;

select * from test_table;

----------------------------
-- then do Extra Ex

-- what the sql statement in a subblock with its own exception.
-- This demo that we can continue with the procedure by limitimg the amount of code missed out by planting sub blocks within the code

CREATE or replace procedure exec_test(p_suburb VARCHAR2) as
   v_postcode  VARCHAR2(10);
   v_error_message VARCHAR2(255) := 'Exception Encountered. Error is - ';
BEGIN
   -- find and print
   Select postcode INTO v_postcode
   from   dbp_postcode
   where UPPER(locality) = UPPER(p_suburb);
   DBMS_OUTPUT.put_line('Thepostcode is '||v_postcode);

EXCEPTION
   WHEN NO_DATA_FOUND THEN
      DBMS_OUTPUT.put_line('NO_DATA '||v_error_message||SQLERRM);

   WHEN TOO_MANY_ROWS THEN
      DBMS_OUTPUT.put_line('TOO_MANY_ROWS '||v_error_message||SQLERRM);

   WHEN OTHERS THEN
      DBMS_OUTPUT.put_line('Others '||v_error_message||SQLERRM);
END;

-- note explaining the order of the handlers
-- EXCEPTION block will only handle 1 exception,

-- OTHERS need to be at the last as it will be called catching ALL exceptions
-- to simplify debugging handle specific exceptions before others