-- assuming has params table for assessment
select * from my_params;

select * from local_rm16;
-- copy structure v_nem_rm16
drop table local_rm16;
create table local_rm16 as (select * from v_nem_rm16 where rownum < 1);

select * from ordertbl;

-- cursors
-- q1 define cursor
-- print details reflecting the result
-- cursor open correctly | failed curosr return [] rows
-- last row of cursor contains the values
-- [ list value of cursor ]

declare
    cursor cur_order is select ordno, orddate, ordname from ordertbl where rownum <= 5;
    rec_order      cur_order%rowtype;
     vcount   number := 1;
     vmax     number := 5;
begin

    -- open cursor
    if not cur_order%isopen then
        open cur_order;
    else
        dbms_output.put_line('already open');
        null;
    end if;

    -- print cursor status
    dbms_output.put_line('cursor status:  ' || SYS.diutil.bool_to_int(cur_order%isopen));

    loop
        fetch cur_order into rec_order;
--        exit when cur_order%rowcount = vmax + 1;
        exit when cur_order%notfound;

        dbms_output.put_line(
            cur_order%rowcount || '. orderno: ' || rec_order.ordno
            || ', date: ' || to_char(rec_order.orddate, 'DD-MON-YYYY')
        );
    end loop;

    close cur_order;
    dbms_output.put_line('cursor status:  ' || SYS.diutil.bool_to_int(cur_order%isopen));

EXCEPTION
    when others then
        if cur_order%isopen then
            close cur_order;
        end if;
end;

------------------------------
-- theyll read your logs for the assessment criteria
-- write good logs
------------------------------


---------------------------------------------------------------------------
-- collections
-- big as question 3


-- set up
DROP TABLE Tut8_print;
CREATE TABLE Tut8_print
(
    line_nr   NUMBER,
    Line_text VARCHAR2(255)
);
DROP SEQUENCE line_nr;
CREATE SEQUENCE line_nr START WITH 1 INCREMENT BY 1;

-- misc helper

select * from tut8_print;
select * from fss_terminal;
select * from fss_transactions;


--

declare
    -- create record type
    type t_fss_term is record(
        vr_terminal fss_terminal%rowtype,       -- a row of fss_term
        vr_transaction_amt number               -- total transaction amount


    -- record to hold row
    v_fss_term      t_fss_term;

    cursor c_terms is
        select terminalID, terminalType, samid, terminalstatus, merchantid
        from fss_terminal;

    -- create array
    type t_terminal_array is the table of t_fss_term index by binary_integer;
    -- whats the size of this array, no fixed size is a linked list
    -- undefined length

    -- should put these in package body so the packagee modules has access to them
    v1_term_list                t_terminal_array;

    -- collections start
    v_index_base    constatnt   number:=1;
    v_counter                   number := v_index_base;

    -- using the 3rd coll record
    v_termcount                 number:= 3;
    v_dummyString               varchar2(255);

begin
    -- opem curs
    open c_terms;
        fetch c_terms into v1_terminal_list(v_counter).vr_terminal;

        exit when c_terms%notfound;

        c_counter := v_counter + 1;
    loop

    end loop;
    null;
end;





-- note not done yet, review later
-- lets do read write and then packages





















