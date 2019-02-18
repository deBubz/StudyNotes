var http = require("http");
var url = require("url");
// add url module

function start(){
    function onRequest(rq,rsp){
        var pathname = url.parse(rq.url).pathname;
        console.log("rq for " +pathname );
        // show the requested url pathname
        
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

