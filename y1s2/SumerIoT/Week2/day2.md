# Day2 Day of the DB

## Setting up Metabase

1. Vultr Server: olympus
1. [get metabase](https://computingforgeeks.com/how-to-install-metabase-with-systemd-on-ubuntu-18-04-ubuntu-16-04/)
   - do step 1 AND step 3 (skip 2)
1. if you did the mv command use `cd /apps/java` then `java -jar metabase.jar`

## [MongoNotes](./mongoNotes.md)

## DB firewall

- sudo ufw status to check whats allowed

## Nosql

- "not Only sql"
- non-relational db (not like SqlServer, MySql)
- Good for live webapp data
- e.g MongoDb
- **Advangage over Relational DB**:
  - Flexible data models, No need for schema (wow)
  - Unstrctured, No need to defined columns ( its good to know and understand your data)
  - Scale out/Horizontal Scaling
- **Relational DB advantage:**
  - better for relational data
  - normalization (less redundancy)
  - SQL is pretty good
  - better Data Integrity( better constraint over data)
  - ACID compliance?
- **Types of nosql**
  - `document db` MongoDb, CouchDb
  - `Column Db` Apache Casssandra
  - `Key value Stores` Redis, Couchbase Server
  - `Cache Syst` Redis, Memcache
  - `Graph Db` Neo4J

### Relational v Doc
- RBDMS: defined tables
- Nosql: Json Objects

## got visualiser working
