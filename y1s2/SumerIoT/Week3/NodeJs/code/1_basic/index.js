var http = require("http"); //require http core http package

//anonnymous async func passed as an arg in http.createServer();
// the arg is a request listener with (Incomming Message, ServerResponse)
// listen for requests
http.createServer(function(req, resp){
    resp.writeHead(200, {"ContentType":"text/plain"});

    resp.write("Hey there");

    resp.end();
}).listen(8888);

// create a server at port 8888

// to run in CMD
// node index.js

//With out the annonymous func this basicly is
//http.createServer().listen();