# Part 1 requirement



# Part 2 database

- forecast saved in `local_rm16` using data from `nem_rm16`
- Objects `rm16_day` stores array(48) of interval objects `rm_16_hh`
  - `rm16_hh` stores: int interval range(1 - 48), and consumption volume
  ```sql
  -- clone rm16
  create table local_rm16 as
  select * from nem_rm16;
  ```