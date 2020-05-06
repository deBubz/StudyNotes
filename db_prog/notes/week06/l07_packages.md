# Packages

## Whats an ORACLE package

> OO classes perhaps

**Packages** is a grouping or packaging of `PLSQL` code elements.
Packages provide structure to organize your programs, `plsql` elements such as cursors, types and variables.

They can hide logic and data from view, and to define and manipulate 'global' or session-persistent data.

> similar to libraries


### Why Packages

Very useful for any complex application projects

some **advantages**

- easier enhancement and maintenance of applications
  - reusable code
  - logically related functionality can be grouped together
- improved performance (loads into memory once)
- easy to overload weak functionalities in existing packages

## Package concepts

- **Information Hiding**
  - hiding some information from view, specifically to
    - hide complexity and the low level detail
    - security - sensitive data should not be retrieved
- **Public and Private**
  - related to information hiding
  - **public** code and variable are defined in the `package specification`
    - available to any schema that has execute privileges
  - **private** only visible from within the package body
- **package Specification**
  - contains the definition of all the publicly available elements of the package.
  - one large declaration section
  - contains no `plsql` code
  - the `signatures` of all modules are found here
- **Package Body**
  - contains code to implement the modules defined in the package specification
  - may contain elements that are defined only here?? then become private to that the package body can be referenced from within the package
  - where all your code is
- **Initialization**
  - init code that runs the first time the package is "touched"
  - can run code that "init" the state of the package
  - Oracle guarantees it runs only once
- **Session Persistence**
  - When connecting to DB, you establish a session (current until you disconnect)
  - variables are init in package retain value for the duration of the session.
  - This is one way that you can pass values from one app to another.

> diagram slide 8

## Working with package

### Referencing Package Objects

- use dot notation to reference wither package modules or variables
  - `pkg_name.type_name`
  - `pkg_name.variable_name`
  - `pkg_name.subprogram_name`

### Working

- package data consist vars and constants defined at package level
- scope of data is the whole package
- in `plsql` runtime architecture, package data structures persist for the session
-  global scope is single session only
   -  public package data is similar in functionality
   -  and as dangerous as global variables

## Security

- when a package module runs, it does so with the same privilege as the owner of the package ( not the package user )
- gives you the ability to `hide` a table from the user. Access to add/modufy data is done by calling certain modules.
  - values can be checked and data modification can be controlled.
- package allow the creation of private modules which can only be called from other modules within the package. This enforce information hiding 

## Guidelines for writing Packages

## Built in Packages supplied by Oracle

