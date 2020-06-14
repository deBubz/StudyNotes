# Performance Tuning

## Why Performance tuning

- FESTER??
- Consider in a db environment
  - batch processing
  - data warehousing
- There are many jobs running in either parallel or sequentially
  - jobs depends on eachother
  - tight run windoe

## How sql is processed

- easier to write correct SQL rather than efficient SQL

something **optimizer**  algos

## Optimizer

For all sql, theres more than one way to retrieve required rows.

the DMBS decide which approach is the fastest through **query optimization**

- oracle has 2 approaches to query optimization
  - rule based optimizer
  - cost based optimizer

### Rule Based

- decide based on set of rules and rankings of access paths.
- rule based optimizer not awaare of data bolumes

> perfer index lookup to a full table scan

> cannot differentiate full table scan of a table with 2 rows v 2mil

### Cost Based

- makes decision based on statistical infor relating to the volume and distribution of data within table and indexes.
- generates different execution plan for each table

> statistical info is not generated automaticly. It should be updated regularly so the optimizer can make better decisions

Cost > rule


### Access path query example

> query gives the names of all customers who bought something from sales rep

> slide 10

whats the best order of operation
---

### Access path

- rule based optimizer always use the same path no matter what the table statistic say

> use index if one exist ..

- cost based will calculate the best access plan.
- calculation will be based on the statistics that are stored in the db, for both the table and the index

statistic will need to be updated to reflwct data folime

> table statistics 12, 13

