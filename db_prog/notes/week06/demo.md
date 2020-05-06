# Demo

```
A1 ReQ
entry module:   rm16_forecast
pkg:            pkg_2020_main
```

create package specification

```sql
create or replace package pk_DEMO as

-- take not of the comments
-- only list PUBLIC function and procedures
procedure propc(p_param varchar20),

end pk_DEMO;

drop package lb_DEMO
```

> ANYTHING defined in the specification is PUBLIC


create package body
```sql
create or replace package body lb_demo as

-- global variables
-- accesible by the whole package
g_package_name varchar(25) := 'lb_demo';

-- define proc/methods 
procedure propc(p_param varchar2) is
    v_proc_name varchar2(25) := 'proc1';
begin
    -- code
end;

end lbl_demo;
```

> Use common.log() instead of put_line

execute
```sql
    lbl_demo.propc('cheese');
```

> Take care of th ORDER OF OPERATION in the package body `single pass compiler`
> ( forward declaration is possible )

> back up your shit

