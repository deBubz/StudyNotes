If all goes well I will be using some of this code in lectures

Exceptions

set serveroutput on

/*
Change the paramaters to generate errors then see what happens 
*/

declare 
v_value VARCHAR2(35);
begin
v_value := get_param('Email_Constants', 'Fss_Settlement_Report');
dbms_output.put_line('The value is '||v_value);
end;






/*
A = Atomicity
C = Consistancy
I  = Isolation
D = Durability


Log into the database with two sepperate sessions then demonstrate the ACID properties that you can
select * from customer;

*/

rollback;

commit;

update customer
set postcode = 1234
where custno = 'C3340959';

update customer
set custfirstname = 'Wendy'
where custno = 'C3340959';


