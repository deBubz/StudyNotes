// require statement
const express = require('express');

// object express
var app = express();

app.set('view engine', 'jade');
app.get('/',function(req,res)
{
});
var server=app.listen(3000,function()
{
});