const assert = require('assert');
// const collection = db.collection('sensorreadings');


exports.module = {
    insertDoc: function (db, callback){
        const collection = db.collection('sensorreadings');
        // inserting
        collection.insertMany([
            {a:1},{a:2},{a:3} // insert these 3 args
        ], (err, result)=>{
            assert.equal(err, null);
            assert.equal(3, result.result.n);
            assert.equal(3, result.ops.length);     // ops - contain the docs inserted with the added __id fields
            console.log("Inserted 3 documents into the collection");
            callback(result);
        })
    
    },
    
    findDocs : function (db, callback){    // find all no pring
        const collection = db.collection('sensorreadings');
    
        // find returns cursor object
        collection.find({}).each((err,docs)=>{ //can also do  find().toarray()
            assert.equal(err, null);
            console.log("found these records");
            console.log(docs);
            callback(docs);
            // only find , didnot print
        })
    },
    
    findDocQuery : function(db, callback){    // find matching query
        const collection = db.collection('sensorreadings');
    
        collection.find({a:1}).toArray((err,docs)=>{
            assert.equal(err,null);
            console.log("found these");
            console.log(docs);
            callback(docs);
        });
    },
    
    updateOneDoc : function (db, callback){ // update one with a:1
        const collection = db.collection('sensorreadings');
    
        collection.updateOne( {a:1}, {$set:{b:1}}, (err, result)=>{
            assert.equal(err, null);
            assert.equal(1, result.result.n);
            console.log("updated");
            callback(result);
            console.toArraylog(result);
            
        });
        
    },
    
    removeOneDoc: function (db, callback){ // deleted one
        const collection = db.collection('sensorreadings');
    
        collection.deleteOne({a:3}, (err,result)=>{
            assert.equal(err, null);
            assert.equal(1, result.result.n);
            console.log('removed something');
            callback(result);
            
        })
    },
    
    indexCollection:function (db,callback){  // something index ,increases your performance
        db.collection('sensorreadings').createIndex(
            {"a":1}, null, (err, result)=>{
                console.log(result);
                callback(result);
                
            }
        )
    }
    
    
}

// insert Docs is a function
