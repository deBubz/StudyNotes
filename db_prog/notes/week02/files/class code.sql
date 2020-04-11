
set serveroutput on

--What does this do?
BEGIN
  NULL;
END;

------------------------

BEGIN
  DBMS_OUTPUT.PUT_Line('This is me at  '||to_char(sysdate, 'DD-Mon-YYYY HH24:MI:SS'));
  Common.log('This is me at  '||to_char(sysdate, 'DD-Mon-YYYY HH24:MI:SS'));
END;

------------------------

select * from dbp_message_log
where 1=1
and student_id = USER
order by 1 desc;

------------------------

declare
  v_message VARCHAR2(255);
  v_date_format VARCHAR2(255) := 'DD-Mon-YYYY HH24:MI:SS';
BEGIN
  v_message := 'This is me at  '||to_char(sysdate, v_date_format);
  DBMS_OUTPUT.PUT_Line(v_message);
  COMMON.log(v_message);
    v_message := 'This is my second go at  '||to_char(sysdate, 'DD-Mon-YYYY HH24:MI:SS');
  DBMS_OUTPUT.PUT_Line(v_message);
  COMMON.log(v_message);
END;

------------------------

delete from dbp_message_log
where student_id = USER;

COMMIT;

