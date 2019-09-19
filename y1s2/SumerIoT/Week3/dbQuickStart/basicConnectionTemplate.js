const MongoClient = require('mongodb').MongoClient;
const assert = require('assert');       // for unit test?
const url = require('../cred.js');      // hidden url link

const dbName = "turtle";

const client = new MongoClient(url);

client.connect((err)=>{
    console.log("connected");

    const db = client.db(dbName);
    console.log("aaaand Its gone");
     client.close(); // close connection
})