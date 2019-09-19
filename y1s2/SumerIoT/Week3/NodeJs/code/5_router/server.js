var http = require("http");
var url = require("url");
// add url module


// pass route as a param for start
function start(route,handle){
    function onRequest(rq,rsp){
        var pathname = url.parse(rq.url).pathname;
        console.log("rq for " +pathname );
        // show the requested url pathname

        route(handle, pathname);
        //use pathname as a param for route()
        
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

