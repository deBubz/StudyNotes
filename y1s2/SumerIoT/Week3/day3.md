# Day3 Node and MongoDb

## More node

Going Through [this](https://www.guru99.com/node-js-tutorial.html)

### 1. Intro

Whats nodeKS

- runtime environment used for server side web dev
- event-driven architecture and non-blockin I/O API designed to optimize apps throughput and scalability for realtime **webapps**

Why Node

- can work in real-time and have a 2-way comms stream. Either the client or server can start the communication.

FEATURES

- Asynchronous event driven IO > better concurrent request handing

### 3. modules( create, publish, extend, manage)

node moduels are logic encapsulation of code in a single unit (class?)

Creating npm modules

see [folder](./create/additions.js)

`exports` used to ensure functionality in the file can be accessed bt others

EXTENDING modiles

It is also possible to exten or inherit one module from another.

### 5. express

bleh MEAN stack applications. look at [this](./express/hello.js) for a basic hello world app

WHAT ARE ROUTES?

Routing means determining the way an application respond to client requests to a specific end point

> http://localhost:3000/   `app.get('/')`
>
> http://localhost:3000/Books
>
> http://localhost:3000/Students

Each route will be able to handle different functions, which will be executed when the route is mathced

General Syntax for route `app.METHOD(PATH, HANDLER)` see [this](./express/hello.js)

- `app` is an express obj/ instance
- `METHOD` HTTP request method (GET, POST, PUT, DELETE)
- `path` duh `'/'` and  `'/Books'`, like above
- `HANDLER` is execute when the route is matched

More Routes [Example](./express/moreRoutes.js)

#### New Framework Pug(Jade)

middle man to render html (why did i never use this). look at the [template](./express/index.html) and [server be](./express/moreRoutes.js)

> There seem to be an issue with rendering the view. the file cannot be located
> Might try with a new npm flile that has all the json stuff

### 6. NodeJs MongoDb

Files

- [app.js](./mongo/app.js)

Need `mongoose`(for schema) and `mongodb` npm pakages

So this works??

---

I want to interact with the db