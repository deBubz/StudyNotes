// var http = require("http");

// //function abstraction
// http.createServer(function( rq, rsp){
//     rsp.writeHead(200, {"ContentType" : "text/plain"});
//     rsp.write("<h1>HelloThar</h1>");
//     rsp.end();
// }).listen(8888); //localhost:8888

var http = require("http");
var url = require("url");

function start(route){
    function onReq(rq, rsp){
        var pathname = url.parse(rq.url).pathname
        console.log("rq recieved" + pathname);
        
        route(pathname);
        rsp.writeHead(200, {"Content-Type" : "text.plain"});
        rsp.end();
    }
http.createServer(onReq).listen(8888);
}

exports.start = start;
