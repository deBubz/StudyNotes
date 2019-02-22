// More routes stuff

const express = require('express');
var app = express(); //obj of express module

app.route('/Node').get(function(req,res){
    res.send("NODE TUTORIAL");
});
// app.route('/Ang').get(function(req,res){
//     res.send("Angular TUTORIAL");
// });
app.get('/Angular', function (req, res) {
    res.send("Ang"); 
 });


//----- pug stuff ------
// app.set('views','.views')
app.set('view engine', 'pug');


// why is this different
app.get('/', function (req, res) {
//    res.send("fml"); 
    res.render(__dirname+"/index",             //render index.html
        {
            title:'main page',      // set template val
            message:'hey ther boi'
        })
});

// make server listen to port 3000
var server = app.listen(3000, function(){
    console.log("Listening at 3000");
    
});