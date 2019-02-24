const express = require('express');
const mongoose = require('mongoose');
var bodyParser = require('body-parser'); // middleware capture data> convert to json> insert data 

const url = require('../cred.js'); // db connection url

mongoose.Promise =global.Promise;
mongoose.connect(url)
var app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));

// ---------- building Schema
var nSchema = new mongoose.Schema({
    firstname: String,
    lastname: String
})

var user = mongoose.model("user" ,nSchema);


// ---------- GET REQUEST

app.get('/', (rq,res)=>{
    res.sendFile(__dirname +"/index.html"); // maybe try this for the pug file
});

// ----------- POST REQUEST

app.post('/addname', (rq,res)=>{
    var myData = new user(rq.body);
    myData.save().then(item =>{
        res.send("item to the db");
        console.log();
        
        // .catch(err=>{
        //     res.status(400).send("unable to send")
        // })
    })
})


app.listen(3000, ()=>{
    console.log("listening to port 3000");
})
