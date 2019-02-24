const express =require('express');
const bodyParser =require('body-parser');
const cors =require('cors');


//start express
const app = express();

//middle ware
app.use(bodyParser.json());
app.use(cors());

const posts = require('./routes/api/posts')

app.use('/api/posts', posts);   // reroute to posts on /api/posts request

// handle production p3
if(process.env.NODE_ENV === 'production'){
    // use static folder
    app.use(express.static(__dirname + '/public/'));
}
// Handle Single Page Applicaiton
app.get(/.*/, (req, res)=>{
    res.sendFile(__dirname + "/public/index.html")
}) // any route at all NOTE put below everything else at the bottom

 
//for heroku process.env.PORT or port 5000
const port = process.env.PORT || 5000;

app.listen(port,()=> console.log(`server started on port ${port}`));