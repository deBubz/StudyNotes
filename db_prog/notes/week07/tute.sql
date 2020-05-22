show errors;
set serveroutput on;

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

---------------------------------------

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