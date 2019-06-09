


var http = require("http");

function onRequest(req, resp){
    console.log("Request recieved");

    resp.writeHead(200, {"Content-Type": "text/plain"});
    resp.write("Oi");
    resp.end();
}

http.createServer(onRequest).listen(8888);


console.log("Server Started");

// the console log is for track what happened
// the "Request Recieved" in STDOUT appearing 2 time cause
// browser will try to request the favicon @ localhose:88888/favicon.ico
// when you request local:8888
