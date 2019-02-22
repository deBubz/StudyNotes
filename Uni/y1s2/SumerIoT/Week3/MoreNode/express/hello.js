// simple Hello World app with express

const express = require('express');
var app = express(); //obj of express module

// callback func on / endpoint request
app.get('/', function(req,res){
    // send response
    res.send("OI");
});

// make server listen to port 3000
var server = app.listen(3000, function(){});