# Application Data

## Data

Data are generally organisms, place, time, thing, event, mechanism... which are stored in databases/data warehouse to be distributed to data markets

## Application Data

Some thing about MVC
translating data from user story to database

## Bean

This seems like a model class for data objects

they re called javabeans need to implement `java.io.Serializable` interface

## JSP and Beans Scope

this show how to use beans in JSP, seems very convoluted using it in the tags

- 3 main beans methods in jsp
    - `<jsp:useBean ... />
    - `<jsp:getProperty ... />
    - `<jsp:setProperty ... />

2 ways of using beans in jsp

```jsp
<jsp:useBean id="book" class="mypackage.Book" scope="">
    <jsp:setProperty name="book" property="title" value="JavaBook">    
    <jsp:setProperty name="book" property="author" value="Steven steve">
    <jsp:setProperty name="book" property="price" value="200">    
</jsp:useBean>
<!-- very self explanatory -->
<jsp:getProperty name="book" property="title"/>
```

```jsp
<%
    mypackage.Book = new mypackage.Book(title, auth, price);
    book.setTitle(new_title);
    out.println(book.getTitle());
%>
```

> NOTE: bean **scope**
> - only available for JSP page
> - request avail while request is active
> - stored session in a variable
> - available for the current application 


## Session

- web servers do not keep track of clients interactions ( a lot of resource cost )
- **session** is an implicit object in JSP which can be used to remember interaction data from clients
- Keep data in the session obj while the session is active, which is used in
  - user login access between pages, shopping card data

## Cookie

- small piece of data stored on the client-side
- webserver can assign a unique session id
- used to identify a client when communicating with a server
- some browser may not support cookies
