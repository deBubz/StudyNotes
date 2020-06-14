set serveroutput on;

-- packages exercise

-- create oacjage spec and body PGK_LECTURE6
-- define/create the following
	-- public module, procedure or func
	-- private module, proc or func
	-- public variable
	-- provate variables

-- create scenarios that will thoroughly test your packages

-- something that works with this

DECLARE
	v_testNum		VARCHAR2(25)	:= '1234';
BEGIN
	IF pgk_lecture6.is_numeric(v_testNum) THEN
		DBMS_output.put_line('(' || v_testNum || ') Test number is numeric');
	ELSE
		DBMS_output.put_line('(' || v_testNum || ') Test number is NOT numeric');
	END IF;


	DBMS_output.put_line('A call to procedure ' || pgk_lecture6.v_package_name);
	DBMS_output.put_line('con cat message value is ' || pgk_lecture6.concat_msg('Laurie', 'class 12345', 25));
END;


-- note
	-- main block of package only execute once. This will be the first time a module in the package is called.
	-- var declared in specification is visible and modifiable
	-- var declared only in the body is only for the body
	-- modules defined in the package spec must be implemented in the package body.

-- maybe add your own procedures to play with it


-----------------------------------------------------------------------
-- package Specification
------------------------------------------------------------------------
CREATE OR REPLACE PACKAGE pgk_lecture6 AS
-- this part be the spec
	FUNCTION is_numeric(p_number VARCHAR2)
		RETURN boolean;

	Function concat_msg(p_string1	varchar2, p_string2 VARCHAR2, p_length NUMBER)
		RETURN VARCHAR2;

	v_package_name	VARCHAR2(35)	:= 'pkg_lecture6';
	v_packageVariable	NUMBER	:= 123.98;
END pgk_lecture6;
/
show errors;
-------------------------------------

-- package body
CREATE OR REPLACE PACKAGE BODY pgk_lecture6 AS

	-- private procedure
	PROCEDURE my_private_proc IS
	BEGIN
		dbms_output.put_line('This is my private procedure');
		dbms_output.put_line('The value of v_packageVariable is '||v_packageVariable);
	EXCEPTION
		WHEN OTHERS THEN
			DBMS_OUTPUT.PUT_LINE('Exception occured in my_private_proc with '||SQLERRM);
	END my_private_proc;

------------------------------------------------
	FUNCTION is_numeric(p_number VARCHAR2)
		RETURN boolean is
		--
		v_myNumber	NUMBER;
		--
	BEGIN
		v_myNumber := TO_NUMBER(p_number);
		RETURN true;
	EXCEPTION
		WHEN VALUE_ERROR THEN
			RETURN false;
	END;

	-- public
	FUNCTION concat_msg(p_string1 VARCHAR2, p_string2 VARCHAR2, p_length NUMBER)
		RETURN VARCHAR2 IS
	BEGIN
		IF LENGTH(p_string1) + LENGTH(p_string2) < p_length
		THEN
			RETURN p_string1 || ' ' || p_string2;
		ELSE
			RETURN NULL;
		END IF;
	END;


    -- init run
    BEGIN
        DBMS_OUTPUT.put_line(' the package is being executed ');
		DBMS_OUTPUT.put_line(' the package variable is ' || v_packageVariable);
        -- use this to init global variables
        select value into v_value from my_parms where category = 'Email_constants' and code='Fss_settlement_Report';
        
--        if v_values is not null Then
--            insert into my_params ()
--            values

END pgk_lecture6;
/


-- no end block??