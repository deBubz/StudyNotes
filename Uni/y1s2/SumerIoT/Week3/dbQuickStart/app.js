const MongoClient = require('mongodb').MongoClient;
const dbFunctions = require('./dbFunctions.js');        // insert docs
// const assert = require('assert');                    // for unit test?
const url = require('../cred.js');                      // hidden url link

// db name information
const dbName = "turtle";
const client = new MongoClient(url);

// db connection
client.connect((err)=>{
    console.log("connected");

    const db = client.db(dbName);
    console.log("aaaand moving on");

    //action then close

    // ----- Single Action -----
    dbFunctions.findDocs(db, ()=>{
        client.close();
    }); console.log(".....");
    

    // ----- Chaining Actionts -----
    // dbFunctions.insertDocs(db,()=>{
    //     dbFunctions.findDocs(db,()=>{
    //         client.close(); // close connection
    //     });
    // });
})




