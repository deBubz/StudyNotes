-- loops

-- q1 rewrite some if statements
-- statement 1
-- no_revenue := total_sales <= 0;
-- -- statement 2
-- no_revenue := total_sales <= 0;
-- WRONG

-- theres no difference between the 2 answers
-- the elsif block in section 2 is the direct opposite of the initial if statement

--- ans s1
no_revenue := nvl(total_sales, 1) <= 0;
-- this is becouse the if block will return false if total_sales is null

-- ans s2
if total_sales is not null
then
    no_revenue := total_sales <= 0;
end if;

-- q02 write the program that produces a report for total sales on 
-- sat sun and all the weekdays combined
-- data from saturday, sunday and weekday combined
        
DECLARE
    v_day           VARCHAR2(10);
    v_sat           number := 0;
    v_sun           number := 0;
    v_week          number := 0;
    cursor c_1  is  
        select  orddate, qty, prodprice
        from    ordertbl ot, ordline ol, product p
        where   ot.ordno = ol.ordno and
                ol.prodno = p.prodno;
BEGIN
    
    for loopies in c_1 loop
        v_day := trim(to_char(loopies.orddate, 'day'));
        if v_day = 'sunday' then
            v_sun := v_sun + (loopies.prodprice * loopies.qty);
        elsif v_day = 'saturday' then
            v_sat := v_sat + (loopies.prodprice * loopies.qty);
        else
            v_week := v_week + (loopies.prodprice * loopies.qty);
        end if;
    end loop;
    
    dbms_output.put_line(rpad('Sunday', 10, ' ') || rpad('$', 3, ' ') || lpad(v_sat, 10, ' '));
    dbms_output.put_line(rpad('Sunday', 10, ' ') || rpad('$', 3, ' ') || lpad(v_sun, 7, ' '));
    dbms_output.put_line(rpad('Weekday', 10, ' ') || rpad('$', 3, ' ') || lpad(v_week, 10, ' '));
    dbms_output.put_line(lpad('-------------',20, ' '));
    dbms_output.put_line(rpad('Total',12, ' ') || lpad((v_sat + v_sun + v_week), 10, ' '));
END;    


----------
-- 03 fix loop

DECLARE
    v_total NUMBER :=0 ;
BEGIN
    FOR v_counter IN reverse 1..10
    LOOP
        dbms_output.put_line('The counter value is '||v_counter);
        v_total := v_total + v_counter;
    END LOOP;
    dbms_output.put_line('The total is '||v_total);
END;


---------
-- 04 using a cursor for loop - declare cursor
--- select * from ordertbl
-- print the order number and orderdate

declare
    cursor c_ord is select * from ordertbl;
    v_count     number := 1;
begin
    for c in c_ord loop
        dbms_output.put_line(v_count || '. '|| c.ordno || '  ' || c.orddate);
        v_count := v_count + 1;
        exit when v_count > 5;
    end loop;
    null;
end;
    