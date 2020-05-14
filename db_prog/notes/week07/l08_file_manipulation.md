# File Manipulation

> important for writing `xml` files for assessment

## What is UTL_FIle package

by Oracle

allows `PLSQL` read/write os system text files

DBA must specify the dir you write to `/export/orcloz`

on **rerun** server in unix that folder is default

> DB is in the `db` server we dont have access to it
>
> use the folder `/oralab/loz` in your rerun server

The file path is common to all users, make sure to give your file a unique name

## Setup

prior to O9i, the DBA had to set the `UTL_FILE_DIR` param in the DB init file

A dir was set as the set destination for all `UTL_FILE` operations

a big problem is each user had the same destination dir. leading to poor security since each user has the same access to the same folder

### create dir

use the `create directory` command, where the `directory` is an object you create to give you access to the new directory, users will have access to system files within that dir

```sql
drop directory <student_no> DIR;
create directory <student_no> DIR as '/exports/orcloz';     -- use this destination
grant read on <student_no>_dir to public;                   -- not required for creator, used by dba
```

each user now can control the destination of the `UTL_FILE` source, you can have more than 1 dir

> this is usually reserved for DBA, but try it inclass

to use `UTL_FILE` you will need to know what env you're working in, then ensure that the correct params are set

`select * from all_objects where object_type = 'DIRECTORY'`

## How to use

1. create var type `utl_file.file_type` (file pointer)
2. decalre file
3. open in either read/write mode
4. write into file or read from file
5. close the file

```sql
DECLARE
    v_file  utl_file.file_type;                                             -- step 1
    v_date varchar2(20) := to_char(sysdate);
BEGIN
    v_file := utl_file.fopen ('<student_no>_dir', 'laurie.test', 'A');      -- step 2
    utl_file.put_line(v_file, 'test print at ', v_date);                    -- step 3
    utl_file.put_line(v_file, 'Test print at '|| lpad('laurie',15));
    utl_file.fclose(v_file);                                                -- step 4
END;
```

- **read** - if file dont exist, system will throw an exception for you to handle
- **write** - if file dont exist, system will create a new file. *else* system will delete the content and reset the pointer for input
- **append** - if file dont exist, create new file. *else* pointer starts at end of file

# What it offers
# FOCUS
### open
### write
### read
### exceptions



