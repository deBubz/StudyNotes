# NodeJS

## Notes from the Nodejs for Beginers PDF

Node is **server side** JS

Dissecting a WebApp, It needs

- **HTTP Server** to serve webpages
- Server needs to handle different requests. Need **Routers** to map requests to handlers
- To handle requests to the server that has been `routed`, we need **Requests Handler**
- Router also need to treat POST data and give it to the request handlers in a better form. we need **Request Data Handing**
- Need to display content when the URL is requested. we need **View Logic** request handler to send content to users browser
- need **Upload Handling** to handle uploading

[Setting a Basic Http Server](./basic/index.js)

## Async funcdions

The speacialty of NodeJS is the ability to run its code asyncronously(simultaniously) through the Annonymous func

for this 

``` js
db.query("SELECT * FROM hugetable", function(rows){
    var result = rows;
});
console.log("Hello");
```

Provbided that db.query() is a part of the asynchronous library. It sends the query to the db, but instead of waiting for returning data, it remembers to execure the annonymous func that passed to the query().

then It execure the `console.log()` > then enter an event loop. NodeJs will loop over and over if there are no more tasks, waiting for new events. `e.g db query, http requests`

### So 

HTTP server needs a funcion it can call **incomming requests**. [To Understand more `felix geisendoerfer-Understanding nodeJs`]()

To prove code loop after creating the server do [this](./code/3_loopTest/index.js)

## Request Handling

look at the **callback** func onRequest()

When the callback fires and `onRequest()` triggered, 2 objects are passed into it `request` and `response`

- `resp.writeHead()` send a HTTP status 200 and the content type in the HTTP response header.
- `resp.write()` sent text into the body
- `resp.end()` finishes the response

> `request` object is not used atm

## Place for **Server Module**

this is to organise the application.

- `index.js` is often used to **bootstrap** and start your app by using other modules.

> like the http module in
>
> `const http = require("http");`

`http` is one of Node's core module, and we can acess it by requiring/ assigning it into a local variable. Its common practice to use the Module's name as the var, but you can use anything.

### Back to server.js

to turning `server.js` into a real module, we need to `export` the parts we want to use in other modules

[server.js](./code/4_servModule/server.js)

[index.js](./code/4_servModule/index.js)

## Routing Requests

- basicly making http request points at different part of the app using a `router` (redirecting requests)

### To **Route** requests

- Need to give the requested URL extra GET and POST params into the router.
- The router then will need to decide which to execute
- All the info we need is availible in the `request` object > a param in the callback func `onRequest()`.
- To interperate this we need more Node modules, `url` and `querystring`

> `url` - provide methods to extract different parth of th URL

> `querrystring` used to parse the querystring for request params. AND parse body of POST request

back to

[server.js](./code/5_router/server.js)

The app can now distingquish request based on the requested URL path. We can now map request to the *RqHandlers* based on the URL path using the *router*

[router.js](./code/5_router/router.js)

Using **dependancy Injection** to **loosely couple** the `server` and the `router` see [Martin Fowler - DI](#)

editing the [server.js](./code/5_router/server.js)

Extends the `start()` to pass the `route` func to be used by parameter

**THEN** add the `route` module into `index.js`, injecting the `route()` of route **module** into the server

[index.js](./code/5_router/index.js)

## THEORY BIT pp20

### Execution in the kingdom of verbs

`functional programming`

*Passing functions* is a part of **Software design**

> In the `index.js` we could pass the `router obj` into the `server` AND the `server` could just called and use it.

**BUT** the `server` only need the *action*, to get something done, NOT the whole `router` Object.

read [Steve Yegge - Execution in the Kingdom of nouns]()

### Routing to *REAL* request Handler

What we did above is not enough.

**ROUTING** means we need to handle request to different URL differently. ITs better to seperate `business logic` for request to `/start` with request to `/upload`

NOW creating new placeholder mdodule

[requestHolders](./code/5_router/requestHandlers.js)

This is to let us write the `rq handlers` into the `router`. DI should only be uses to make the module loosely coupled. so *how should we route the handlers??*

### Back to index.js

Its decided to pass the `requestHandlers` as an obj and inject it into the `route()` for loose coupling

[index.js](./code/5_router/index.js)

the handler array is to map different URL to differnt handlers

[server.js](./code/5_router/server.js) would also need to be changed to use it the extra parameter.

[router.js](./code/5_router/router.js) would also need to be changed