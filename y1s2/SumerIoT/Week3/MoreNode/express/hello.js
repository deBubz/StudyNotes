// simple Hello World app with express



const express = require('express');

var app = express(); //obj of express module

app.get('/', function(req,res){
    res.send("Oi There"); // response
});

var server = app.listen(3000, function(){}); // 