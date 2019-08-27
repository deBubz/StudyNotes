var server = require("./server.js");
var router = require("./router.js");
var requestHandlers = require("./requestHandlers.js");

var handle = {};
handle["/"] = requestHandlers.start;
handle["/start"] = requestHandlers.start;
handle["/upload"] = requestHandlers.start;

// handle array



// injecting the route() of router
server.start(router.route, handle);

// used start() in server.js
// no need to create http obj in here