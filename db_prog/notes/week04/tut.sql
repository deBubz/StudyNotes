-- tut 04 homework


-- q01 create a function what returns a fullname from employee
create or replace function empFullName(p_empno in employee.empno%type)
return varchar2 is
    v_fullname  varchar2(35);
begin
    select  decode(gender, 'M', 'Mr', 'F', 'Mrs', 'other') || ' ' || empfirstname || ' ' || emplastname fullname
    into v_fullname
    from employee
    where empno = p_empno;
    
    return nvl(v_fullname, 'error');
end;

-- run this 
SELECT empno, empFullName(empno) name FROM   employee;


---------------------------------
-- q02
create or replace procedure f_weekly_contract (  p_date in date,
                                                p_start out date,
                                                p_end out date) as
begin
    p_start := to_date(trunc(p_date, 'day') + 7, 'dd-mm-yyyy');
    p_end   := to_date(trunc(p_date, 'day') + 13, 'dd-mm-yyyy');
end;

-- testing wrapper
declare
    v_date  date := to_date('06-04-2020','dd-mm-yyyy');
--    v_date  date := sysdate;
    v_start date;
    v_end   date;
begin
    f_weekly_contract(v_date, v_start, v_end);
    dbms_output.put_line(v_start);
    dbms_output.put_line(v_end);
end;

---------------------------------
-- q03 create a function that returns a value from DBP_PARAMETER table given 'category' and 'code' as input params

create or replace function dbp_param_value( p_category in dbp_parameter.category%TYPE,
                                            p_code in dbp_parameter.code%TYPE)
return dbp_parameter.value%type is
    v_value dbp_parameter.value%type;
begin
    select value
    into v_value
    from dbp_parameter
    where category = p_category
    and code = p_code;
    
    return v_value;
end;

------------------
-- q04 extra stuff

