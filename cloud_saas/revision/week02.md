# Revision week02

## Overview

- **PaaS**
  - understanding PaaS
  - Overview Google Cloud Engine as PaaS
  - Architecture of Google Cloud Engine
- **SaaS**
  - understanding SaaS
  - integrating applications with SaaS

<!-- --- -->

## PaaS

- Platform as a Service provide a a platform to create and deploy platform for applications
- PaaS includes the software framework, IDE, OS, and Hardware provided to users through the internet
- **implications** of PaaS
  - code and data stored by the provider
  - accessibility is governed by the provider
  - issue with changing provider through the use of proprietary code, framework, compilers
- PaaS **constraints** limited resources based on different level of premium
- Deployed applications are made available online as soon as it is deployed

### Google Apps Engine

- PaaS to develop and deploy apps on the Google Cloud / ecosystem
- Key Elements
  - **GoogleFileSystem**
    - proprietary distributed file system, stores data in a **fault tolerrant** manner
    - used in many google based products, services
  - **GoogleDataStore**
    - NoSql scalable data storage using their own proprietary query language
    - replacing by **CloudFireStore**
  - **GoogleCloudSQL**
    - SQL data storage for the google cloud platform
  - **MemoryStore**
    - Distributed RAM for google cloud products to handle `GET` and `WRITE` requests

### Force.com

- PaaS service offering platform for development, deployment and hosting
- simple drag and drop interface
- **Properties**
  - user shares the same stack of resource to generated views for users
  - provide clear separation of stored data for **core** and **customized** data and functionalities 
    - stored as metadata
- **Functionalities** 
  - users `tenants` see customized `tenant-specific` view of the application
  - `polymorphic abstraction` determines which user is requesting data
  - user can manipulate core and customized data with out impacting each other


<!-- --- -->

## SaaS

- Software Apps includes: Email Apps, Finance management, HR management, Customer Resource management...
- Traditional software procurement are lengthy and includes:
  - Identify what is needed, purchasing license and installing software
  - it is costly and time consuming

Typical Software

- utility to consumers provided on demand via provider or third party broker
- maintained by the provider

### Understanding SaaS

> **NIST**
>
> *The capability provided to the consumer is to use the **provider's application* running on a cloud infrastructure.*
> *Applications are accessible from various client devices through interfaces as a browser or a program interface*

- **characteristics**
  - user does not manage/control the software platform is running on
  - deployed outside of the consumer's network. Customization is limited by provider
  - cost tied to usage
- **implications**
  - limited customization and security depends on the provider
  - extra cost includes migration in/out of SaaS

### Integration Broker

- middle ware handling integration between data source and data sync. Comprize of 4 modules:
  - **Data security**
  - **Data validation & transformation**
  - **Data Sync**
    - Polling Sync Mechanism
    - Push Sync Mechanism
    - PubSub sync Mechanism
  - **Data Routing**
- MetaData Layer
  - Specify how to perform integration activities, which encompasses rules for **operations** for the modules
