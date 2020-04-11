-- output on
set serveroutput on

-- warm up set up

DECLARE
    v_num   NUMBER;
    v_char  VARCHAR2(20);
    v_date  DATE;
    v_bool  BOOLEAN;
BEGIN
    NULL;
END;

-- 01 print out the value of each variable

DECLARE
    v_num   NUMBER;
    v_char  VARCHAR2(20);
    v_date  DATE;
    v_bool  BOOLean;
BEGIN
    DBMS_OUTPUT.PUT_LINE(nvl(v_num, 3));
    DBMS_OUTPUT.PUT_LINE(NVL(v_char, 'Hello There'));
    DBMS_OUTPUT.PUT_LINE(NVL(v_date, sysdate));
    dbms_output.put_line(nvl(sys.diutil.bool_to_int(v_bool), sys.diutil.bool_to_int(false)));
END;

-- 02 declare variable data and rerun


DECLARE
    v_num   NUMBER := 20;
    v_char  VARCHAR2(20) := 'Goodbye';
    v_date  DATE := to_date('16-jan-1995', 'dd-mm-yyyy'); 
    v_bool  BOOLEAN := true;
BEGIN
    v_num := nvl(v_num, 3); 
    v_char := nvl(v_char, 'Hello There'); 
    v_date := nvl(v_date, sysdate); 
    v_bool := nvl(v_bool, false);
    
    DBMS_OUTPUT.PUT_LINE(v_num);
    DBMS_OUTPUT.PUT_LINE(v_char);
    DBMS_OUTPUT.PUT_LINE(v_date);
    dbms_output.put_line(sys.diutil.bool_to_int(v_bool));
END;

-- add common.log to dupe each printout line
-- 03 set varchar2 to 'O'Connor' run output to both local and common.log

DECLARE
    v_num   NUMBER := 20;
    v_char  VARCHAR2(20) := 'O''Conor';
    v_date  DATE := to_date('16-jan-1995', 'dd-mm-yyyy'); 
    v_bool  BOOLEAN := true;
BEGIN
    v_num := nvl(v_num, 3); 
    v_char := nvl(v_char, 'Hello There'); 
    v_date := nvl(v_date, sysdate); 
    v_bool := nvl(v_bool, false);
    
    DBMS_OUTPUT.PUT_LINE(v_num);
    DBMS_OUTPUT.PUT_LINE(v_char);
    DBMS_OUTPUT.PUT_LINE(v_date);
    dbms_output.put_line(sys.diutil.bool_to_int(v_bool));
    
    common.log('Tut02 - bao on ' || sysdate || ' printing num var: ' || v_num);
    common.log('Tut02 - bao on ' || sysdate || ' printing string var: ' || v_char);
    common.log('Tut02 - bao on ' || sysdate || ' printing date var: ' || v_date);
    common.log('Tut02 - bao on ' || sysdate || ' printing boolean var: ' || sys.diutil.bool_to_int(v_bool));
END;

-- 04 addd subblock declare some variables, and print in the subblock
-- SUB -    print vars from parent block
-- PARENT - print vars from sub and parent
