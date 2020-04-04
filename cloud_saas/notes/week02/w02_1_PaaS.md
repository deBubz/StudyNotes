# PaaS

## Understanding Computing Platform

There are many formal definition of *Computing Platform*.
It is a *combination* of **hardware/software** resources used for application developments.

Its other uses are

- to **build** new software
- to **enhance** existing software
- to **execute** software

Stacks of the computing platform

- Software Development framework ( .NET, JDK )
- IDE to assist in development
- OS
- Hardware

## Platform as a Service

Platform as a Service ( PaaS ) are commonly used to refer Computing Platforms.
Which are **provided over the internet** to cloud consumers via **web interface**

> *"The capability provided to the consumer is to **create and deploy applications** using*
> *programming languages, libraries, and tools supported by the provider"* `NIST definition`

Implications to the **cloud consumer**:

- doesn't need to pay upfront expenses for the computing platform
- exposed to the *software framework* only via an interface
  - no need to worry about the underlying cloud structure
  - visibility over the provided framework only
- not responsible for ongoing maintenance/upgrade of the platform
- has control/ownership of the developed application

### PaaS Components

PaaS just as other cloud products contain these layers

- End users
- Interface
- Virtualization Layer
- Software Resource
- Hardware Resource

**PaaS also provides** access to all the required resources for building applications such as:
  
- IDEs
- Collaboration tools
- Unit testing, stress testing, integration testing, prep-production testing...

**Pricing** is based on:

- The amount of code?
- Number of Licenses required or used
- Number of application deployed, resource usage

**Implications** for PaaS:

- Your code and data resides Externally
  - **Stored** by the PaaS Provider
  - PaaS provider **may use** an IaaS Provider
- Accessibility ( code, data an application ) is governed by the provider
- Not all lang, dev features or runtime features are supported
- Problems with changing PaaS provider due to compatibility between compilers ( propriety )
  - Apex compiler from Force.com something about propriety Compilers

## Google Apps Engine

- PaaS to develop apps and deploy on the google cloud
- Only the provided Framework is exposed to the user
  - provides local app development
  - PhP, Python, NodeJs, .NET, Go
- **Architecture** Slide 14
- **Key elements**
  - GoogleFileSystem
  - GoogleDataStore, CloudFireStore
  - GoogleWebServers
  - MemoryStore

### GoogleFileSystem

- Proprietary distributed file system
- Stores data in a **fault tolerant** manner.
  - 64 mb chunks are replicated across many servers in the GFS
- Used for many google based products, services

### GoogleDataStore

- Scalable storage service for data
- Data  is stored as Data objects 
- NoSql like Mongo, contains their own proprietary query language
- Theres also **Google FireStore** new version of GDS

### GoogleCloudSql

- Fully Managed Database service for relational databases integrated within the Google Cloud platform
  - Can pick either MySql or PostgreSQL

### MemoryStore

- Distributed RAM cache for GWS
- `GET` and `WRITE` request to **MemoryStore** are much faster than to **CloudStore** or **GDS**
- used to cached application data for easy access across many web servers ( HTTP session )

### Deployed applications

- Apps are made available online as soon as its deployed.
  - unlike `IaaS` where VMs need to be explicitly provisioned
  - users cannot specify configuration and number of vms in Google PaaS
- GAE apps are *load balanced* automatically
  - unlike IaaS where users need to setup their own load balancers

### Constraints

- Resources free for deployed app are free within a limit
- Some constraints are increased by buying premium

## Force.com

- Originally used to host their SaaS application, a CustomerRelationshipManagement app
- now offering both **PaaS** for application development, deployment and hosting
- Provides a very simple UI for application development. Drag and drop.

### force.com properties

- users share a stack of resources ( db )
- different users of the Force platform see customized views, generates on the fly, they do not maintain customized views for users
- force provided clear **separation** in **shared db** between:
  - core data and functionality ( pre-defined )
  - user data and functionality ( custom )
- both above are stored as metadata

### force.com functionalities

- users ( tenants ) see customized (tenant-specific) view of the application ( depends on the user defined logic/data )
- `polymorphic abstraction` process determine which user is requesting data and passes this to the runtime engine
  - **runtime engine** access
    - core app metadata
    - custom metadata of the user
  - then generates custom views for the corresponding user
- user can manipulate both core and customized data without impacting each other

## Readings

Theres a lot but these seems alright



