var http = require("http");

// use http module

function start(){
    function onRequest(rq,rsp){
        console.log("recieved");
        
        rsp.writeHead(200, {"Content-Type": "text/plain"});
        rsp.write("hey");
        rsp.end();
    }

    http.createServer(onRequest).listen(8888);
    console.log("started")

}

exports.start = start;

//exporting start()
//looking index.js

