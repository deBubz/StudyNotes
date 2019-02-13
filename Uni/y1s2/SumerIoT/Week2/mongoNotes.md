# MongDb Notes

# One
[Sauce](https://youtu.be/pWbMrx5rVBE)

## starting 

- 4:20 skip installation process
- create folder /mongo/data/db  /mongo/log
- bash into /mongo/bin
  - `mongod --directoryperdb --dbpath <path to data/db> --logpath <pathto /log> --logappend --rest --install`
  - run as a service
  - `net start MongoDB` Start running in background
  - `mongo` start mongoshell
  - show dbs
 
- `use <dbname>` create and set what youre using
- `db` check what db is being used

### db.createUser()

> also see doccumentation

```mongo
db.createUser({
    user:"";
    pwd:"";
    roles:[ see doccumentation]
});

// return status success, fail
```

### db.createCollection('colection name');

- similar to RDMS tables
- returs status
- `show collections` show all? or current

 ### db.collectionName.insert()

- insert data/doccument {name:"something" , field2:"data"}
- returns statis `nInserted`
- `db.collName.find()` returns all doccuments
- change args into array[] to insatall multiple
- `db.collectionName.insert().pretty()` make it nice

### db.collectionName.update(param1 find, param2 update/replace)

- can use to add/edit information in doccuments
- do `update({findParam: "new"}, {name:"aa", field2:"cc"})` 
- **NOTE**: need to fill all current data or it will be replaced with the param2

- to add information use `{$set:{newField:"new"}}` as the 2nd params (can be multiple fields)

- to increment numeric val `{$inc:{field: 5}}` @ param2 (+5 to field)

- remove field `{$unset:{field:1}}`

- can use to insert if not found with param3 `db.collectionName.update(param1 find, param2 update/replace, {upsert:true})`

- rename field `{$rename:{"currField":"newfield"}}`

### db.collectionName.remove(param1 find)

- duh
- will delet all docs that matches the param
- add param 2 `{justone:true}` to det just one

### db.collectionName.find()
 
- no param = find all
- params = return all docs that match
- find A and B add to param `{$or:[{first doc},{seccond doc}}`

- e.g `db.collectionName.find({age:{$gt:40}})` find docs with the field age greather than 40
  - `$gte` greather or eaqual
  - `$lte` less than or equal

- `db.collectionName.find({"address.city":"sydney"})` find docs containing objects with field city = sydney
-`db.collectionName.find(membership:"mem1")` find docs containing membership array containing "mem1"

### db.collectionName.find().sort()

- `db.collectionName.find().sort(fieldName:1)` 1 for accending -1 for decending

### db.collectionName.find().count()

- ez

### db.collectionName.find().limit() 

top 4

### db.collectionName.find().forEach()

- for each collection, execute params for each doccument

----

## 