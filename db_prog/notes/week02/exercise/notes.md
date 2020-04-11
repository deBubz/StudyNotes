# Notes on exercises

printing command will not run unless declared
```sql
-- printing
set serveroutput on
-- always declare once per session
dbms_output.put_line('hello thar');
```

This output will only be seen in the development process.
Will not be shown anywhere in production.
There is another way to **log** your work.

minimum for a block to run

```sql
declare
begin
    null;
end;
```