show errors;
set serveroutput on;


----------
-- check output files

select * from all_objects
where object_type = 'DIRECTORY'
and object_name like 'U13363332_DIR';
-- create directory
create directory U13363332_DIR as   '/exports/orcloz';
drop directory U13363332_DIR;
-- grant read and write perms



-- reading and writing to files

-- create a file with name following the format
-- <initials><DDMMYYYY>.dat
-- BH22052020.dat

-- write the following info

-- 					Tutorial 7 Question
-- Date: <DD-Mon-YYYY>						Page 1
-- This file was created by <USER>
-- Today there are 0000xxx transactions in the FSS_TRANSACTIONS table
-- 					*** End of Report ***

-- NOTE
-- date format
-- user form user id
-- transactions num should be 0 padded 10 digits

-- check the unix file


-- OK REVIEW FOR FILE EXAMPLE

---------------------------------------------------------------------------------
--===============================================================================
-- Ricky work through -----------------------------------------------------------

--- ok lets use the parameter table

DECLARE
	v_file_pointer		utl_file.file_type;
	v_utl_dir			VARCHAR2(35)	:= 'U13363332_DIR';		--set your own dir
	v_utl_file_name	    VARCHAR2(35);
	v_page_nr			NUMBER	:= 1;
	v_nr_of_trans		NUMBER;
	v_page_width		NUMBER := 80;
    
    -- function implementation in DECLARE
	-- setup text so its centerd ona 80 char wide page.
	FUNCTION f_center(p_ttext	VARCHAR2)
		RETURN VARCHAR2 IS
		v_text_width	NUMBER;
	BEGIN
		v_text_width := LENGTH(p_ttext)/2;
		return LPAD(p_ttext, (v_page_width/2) + v_text_width, ' ');
	END;
Begin
    -- generate filename
    SELECT 'BH12345.dat' INTO v_utl_File_Name
	FROM dual;
    -- open file pointer
    v_file_pointer := utl_file.fopen(v_utl_dir, v_utl_file_name, 'W');

    -- write the file
	utl_file.put_line(v_file_Pointer, f_center('Tutorial 7 Question'));
	utl_file.put_line(v_file_Pointer, 'Date: ' || to_char(sysdate, 'DD-Mon-YYYY') || LPAD('Page ' || v_page_Nr, 62));
	utl_file.new_line(v_file_Pointer);
	utl_file.put_line(v_file_Pointer, 'This file was created by ' || USER);
	utl_file.new_line(v_file_Pointer);
	utl_file.put_line(v_file_Pointer, 'Today there are ' || LPAD(v_nr_Of_Trans, 10, '0') || ' in the FSS_TRANSACTIONS table');
	utl_file.new_line(v_file_pointer);
	utl_file.put_line(v_file_Pointer, f_center('*** End of Report ***'));
	utl_file.fclose(v_file_pointer);

    -- close file pointer
    utl_file.fclose(v_file_pointer);
EXCEPTION
    -- consider if some other exception occured before the file is oppened
    -- week 7 36:00
    when others then
        utl_file.fclose(v_file_pointer);
END;

-- select * from my_params--
create table my_params(

);

---------------------------------------
--==================================================================
-- Lauries Solution
set serveroutput on;

DECLARE
	v_file_pointer		utl_file.file_type;
	v_utl_dir			VARCHAR2(35)	:= 'LB_DIR';		--set your own dir
	v_utl_file_name	VARCHAR2(35);
	v_page_nr			NUMBER	:= 1;
	v_nr_of_trans		NUMBER;
	v_page_width		NUMBER := 80;

	-- function implementation in DECLARE
	-- setup text so its centerd ona 80 char wide page.
	FUNCTION f_center(p_text	VARCHAR2)
		RETURN VARCHAR2 IS

		v_text_width	NUMBER;

	BEGIN
		v_text_width := LENGTH(p_text)/2;
		return LPAD(p_textm (v_page_width/2) + v_text_width, ' ');
	END;
	-----------------
BEGIN
	-- generate file name
	SELECT 'LB' || to_char(sysdate,'DDMMYYYY') || '.dat' INTO v_utlFileName
	FROM dual;

	SELECT count(*) INTO v_nrOfTrans
	FROM fss_transactions;
	-- create/open file
	v_filePointer := utl_file.fopen(v_utlDir, v_utlFileName, 'W');

	-- writing each line
	utl_file.put_line(v_filePointer, f_centre('Tutorial 7 Question'));
	utl_file.put_line(v_filePointer, 'Date: ' || to_char(sysdate, 'DD-Mon-YYYY') || LPAD('Page ' || v_pageNr, 62));
	utl_file.new_line(v_filePointer);
	utl_file.put_line(v_filePointer, 'This file was created by ' || USER);
	utl_file.new_line(v_filePointer);
	utl_file.put_line(v_filePointer, 'Today there are ' || LPAD(v_nrOfTrans, 10, '0') || ' in the FSS_TRANSACTIONS table');
	utl_file.new_line(v_filePointer);
	utl_file.put_line(v_filePointer, f_centre('*** End of Report ***'));
	utl_file.fclose(v_filePointer);

END;

--------------------------------------------
-- different version using the parameter table

--set serveroutput on;

--DECLARE
--	v_file_pointer		utl_file.file_type;
--	v_utl_dir			VARCHAR2(35)	:= 'LB_DIR';		--set your own dir
--	v_utl_file_name	VARCHAR2(35);
--	v_page_nr			NUMBER	:= 1;
--	v_nr_of_trans		NUMBER;
--	v_page_width		NUMBER := 80;

--	-- function implementation in DECLARE
--	-- setup text so its centerd ona 80 char wide page.
--	FUNCTION f_center(p_text	VARCHAR2)
--		RETURN VARCHAR2 IS

--		v_text_width	NUMBER;

--	BEGIN
--		v_text_width := LENGTH(p_text)/2;
--		return LPAD(p_textm (v_page_width/2) + v_text_width, ' ');
--	END;
--	-----------------
--BEGIN
--	-- generate file name
--	SELECT 'LB' || to_char(sysdate,'DDMMYYYY') || '.dat' INTO v_utlFileName
--	FROM dual;

--	SELECT count(*) INTO v_nrOfTrans
--	FROM fss_transactions;
--	-- create/open file
--	v_filePointer := utl_file.fopen(v_utlDir, v_utlFileName, 'W');

--	-- writing each line
--	utl_file.put_line(v_filePointer, f_centre('Tutorial 7 Question'));
--	utl_file.put_line(v_filePointer, 'Date: ' || to_char(sysdate, 'DD-Mon-YYYY') || LPAD('Page ' || v_pageNr, 62));
--	utl_file.new_line(v_filePointer);
--	utl_file.put_line(v_filePointer, 'This file was created by ' || USER);
--	utl_file.new_line(v_filePointer);
--	utl_file.put_line(v_filePointer, 'Today there are ' || LPAD(v_nrOfTrans, 10, '0') || ' in the FSS_TRANSACTIONS table');
--	utl_file.new_line(v_filePointer);
--	utl_file.put_line(v_filePointer, f_centre('*** End of Report ***'));
--	utl_file.fclose(v_filePointer);

--END;