const mongodb =require('mongodb');
const express =require('express');
const url = require('../../../../cred')

const router = express.Router(); // create router

// GET
router.get('/',async (req,resp)=> {
    const post = await LoadPostCollection();
    resp.send(await post.find({text:{$exists:true}}).toArray()); // OK
})

// ADD
router.post('/', async(req,resp)=>{
    const post = await LoadPostCollection();
    await post.insertOne({
        text: req.body.text,
        createdAt: new Date()
    });
    console.log(`inserting ${post.text}`);
    
    resp.status(200).send();
})

// DELETE
router.delete('/:id', async (req,res)=>{
    const post = await LoadPostCollection();
    await post.deleteOne({_id: new mongodb.ObjectID(req.params.id)});
    console.log("deleting something");
    
    
    res.status(200).send()
})

// connecting asynchronous func
async function LoadPostCollection(){
    const client = await mongodb.MongoClient.connect(url.turtle, {useNewUrlParser:true});
    // return client.db("vue_express").collection('posts');
    return client.db('turtle').collection('sensorreadings'); // return this to do stuff
}

module.exports = router; // export router obj