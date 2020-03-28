# Software Architecture and Design

## Software Application Architecture - MVC

### Architecture 

> Fundamental concept or properties of a system in its environment embodied in its
> elements, relationships, and the principles of its design and evolution.

- SWA properties
  - Systems ( software )
  - Concepts or properties
  - Elements or components
  - Environment
  - Relationship
  - Design Principles
  - Evolution

### Agile architecture

> Basically another flavour of the swa

- contains: **Application** architecture and **Data** architecture
- Pros
  - No upfront detailed architecture but at different levels
  - Project overall high lvl architecture.
  - releases part of the project related to the current/ upcomming release in hand
  - Iteration levels is poart of the release architecture
- Each level specifies the software **application**, **data** and **hardware infrastructure**
- Each iteration takes the vertical slice of the **whole project** not one at a time

### Architecture Design

- Early stage of the system design process
- Represents the link between spec(requirement or user stories) and design process
- often Carried out parallel with some specification activities
- Involves identifying major system components and their communication

**Abstraction**:

- `small` architecture is concerned with the the architecture of **individual programs**
  - cover the way that an individual program is decomposed to components
- `large` architecture is concerned with the architecture of **complex enterprise systems** which includes:
  - other systems, programs, program components.
  - Enterprise systems are distributed over different computers, maybe **owned/managed** by different companies
- Architecture can also be expressed using different **software programming abstraction paradigm** such as:
  - OO, serviced oriented, relational/ non-relational 

**Decisions**:

- Architectural design is a creative process, hence it varies depending on the **system type** being developed
- There are **common decisions** span all design process and these decision can affect the **non-functional characteristics**. Including
  - performance
  - security
  - safety
  - availability
  - maintainability

**Patterns**:

> **Pattern** means representing, sharing and reusing knowledge.

- An architectural pattern is a stylized **description of good design practice**
- Pattern should **not** include info about when they are (and not) useful
- Patterns maybe represented using textual, tabular, and graphical description
  - MVC
  - Layered architecture
  - Repository architecture
  - Client-server architecture
  - Pipe and filter architecture
  - Service-oriented architecture

### Architecture view

- involves stakeholders solving concerns
- Views type
  - Logical view
  - Process View
  - Development View
  - Physical View
  - Usability View

## Design

- This is a `creative` task in which you identify software components and their relationship ( based on the **requirements** )
- design specifies the architecture details

### Interface Design ( View )

- Ways to enable interaction between the user and the system
- UI components and UI flow
- Online, Offline, devices, special people design...

> Have a look at the User Journey map on slide 17

### Logical Flow Design ( Controller )

- Control the flow of the application function or service execution
- Returning the response (data from Model) to a request

### Data Design ( Model )

- Represent domain specific data and business logic
- Maps the data from between the object model classes and db
- get and store model object state in the database.

### Backend DB

- Map the object design to relational database entities
- Identify entity attributes, relationship between entities (ERD)
- convert erd to physical db tables

### Object design

main task is to

- Identify object classes
- Identify object class attributes
- Identify object class methods
- Object class association
- Object class inheritance or hierarchy

Obj design Mvc includes

- `View` Encapsulate connection between actors and usecase
- `Conctoller` performs behaviors associated with inner workings of usecases
- `Model` Mostly correspond to conceptual data model classes

---

## Summary

| Agile | Traditional |
|---|---|
| Adaptive | Complex |
| starts high lvl early | Too much upfront detail |
| Evolves iteratively as the project progresses | Large architecture and design documents | 
| Just-in-time details | Illusion of complete requirements |

### Challenges

- Everything is flexible
- Database issues
- Techinical debt

### Conclusion

- SWA provides a high level blueprint of a software application components
- design provide additional detail of the component (classes, db) identified in the architecture.
- Architecture and design are done using some design patterns ( MVC )
- Architecture can defined for both a small/large set of applications





