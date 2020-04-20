# UI Development


## web app user interface

> Explain MVC

## web app request & response model

> Networking Request, response model for JSP

## GET and POST requests

- **GET**
  - sends the encoded information string to the wep separated by `?` appended to the URL
  - avoid using `GET` for sensitive information
  - limited `1024` chars in the request string
- **POST**
  - sends the information to the webserver as a separate message in the body of the request

## JSP basics

- **scriptlet** tag - embedded in the html body
  - `<% out.println("Hey") %>`
- **expression** tag - evaluate expressions
  - `<%= "Hey " + 1 %>`
- **declaration** tag - declare variable or method
  - `<%! int add(int a, int b){ return a+b; } %>`

> Have a look at slide 8

## JSP request

- client request page *using the request class*, JSP engine creates a new object represent that "request"
- request object can be used to get that information contained in the request object (parameter, header information, remote address, server name)

`<%= request.getParameter("username")%>`

## JSP web app response

- JSP creates a "response" to each "request" recieved
- Response object contains the data passed from server to client

`<% response.sendRedirect("google.com") %>`

## UI Development Notes

- 