# Week 03 pre work

## Notes Seems like we're moving into the serious part

## Software Architecture v Design Patterns [video](https://youtu.be/lTkL1oIMiaU)

###  Agenda

- Whats software architecture
- Whats its for in the big picture
- Whats architectural patterns
- The various architectural patterns
- Architecture v Design patterns

### Generic

Typical phases of the Software Development

1. Requirement engineering
2. Analysis
3. Design/ Architecture
   - Architectural patterns
   - Quality attributes
   - Messaging Mechanism
   - APIs
4. Development
   - Coding paradigms
   - Design Patterns
   - Tooling
   - Automation
5. Testing
6. Acceptance
7. Deployment
8. Maintenance and Update

> the **design output** is the input of the **development** phase.
> Developers should focus on output of the **design phase** which is the **architecture** of the software.

#### Software architecture

Is composed of 3 main ideas:

- How the defining components of a software system are **organized and assembled**
- How the components **communicates** with each other ( APIs )
- The constraints the system is ruled by. ( qualities attributes, non-functional attributes )

> E.g: Layered Architectural patter, Micro-services pattern...

- The **architectural patterns** ultimately define how small or big components will be.

#### Levels of architectural patterns

- Level 1: high level patterns
  - Monolithic
  - Service-based
  - Distributed
- Level 2:
  - Layered ( N-tier pattern )
    - Monolithic
    - Separation of concern ( MVC? )
  - Micro-services
    - Service based type of pattern
    - Micro services is **NOT** OO ARchitecture
    - **Independently** evolvable and deployable **units**
  - Event-Driven
    - Distributed architecture
    - Event Processing units coordinated in a **Mediator** or **Broker** topology
    - **Asynchronous** nature
  - Service-Oriented Architectural pattern
    - Large, enterprise systems
    - Course grained services
    - Integrating different heterogenous components together
  - Space based architectural system
    - hybrid of Micro services, event driven and cs concepts
    - Inspired by space tuples
    - Distributed caching - in Memory data grid
    - Elastic scalable architectural pattern

| Architectural pattern | Design patterns |
|---|---|
| High-level, universal scope | Lower- level scope |
| how components are **organized and assembled** | How components are **built** |

--- 

### Extra resources

- Software architecture in practice.
- Pattern oriented software architecture.

---

## Agile Architecture: Strategies for Scaling Agile Development

> quite a read [Source](http://www.agilemodeling.com/essays/agileArchitecture.htm)

1. Towards Agile Architecture
2. Architecture throughout the life cycle
3. Who is responsible for architecture
4. Have an "architecture owner" role
5. Agile Architecture at scale
6. Based your architecture on requirements
7. Model your architecture
8. Consider several alternatives
9. remember enterprise constraints
10. Travel Light
11. Prove your architecture with working code
12. Communicate your architecture
13. Think about the future, just wait to act ( defer commitment )
14. Take a multi-view approach
15. How does this works
16. Addressing the myths around agile and architecture




---

## Design patterns samples [website](https://www.oodesign.com/)






