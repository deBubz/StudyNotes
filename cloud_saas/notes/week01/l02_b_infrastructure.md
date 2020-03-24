# Infrastructure as a service

## Objectives

- Understand Computing Infrastructure in Enterprises
- Understand/Define Infrastructure as a Service ( IaaS )
- Understanding generic architecture of IaaS provisioning
- Intro to AWS

---

## Computing Infrastructure in Enterprises

These Includes:

- WebServers
- Application servers
- Database Servers
- Memory

> These varies in processing speed, capacity, latency and cost

- so *Enterprise Applications* have a specific hardware requirements, **different applications need different requirements**
- cost of procuring, maintaining and re-registering IT infrastructure
  - equipment cost
  - hiring and managing skilled staff
  - real-estate ( for the physical hardware )
- So it makes more sense to hire these applications. Which is provided by **cloud** in the form of **IaaS**

> **NIST**
>
> *"The capability provided to the consumer is to provision processing, storage, networks, and other fundamental computing resources,*
> *where the consumer is able to deploy and run arbitrary software, which can include OS and applications"*

## IaaS

- **Key factors**
  - *Provisioning* resources on demand
  - Able for consumer to *deploy and run* arbitrary software
  - Consumer *does not manage* the underlying cloud infrastructure.
- **Implications**
  - no upfront investment, real-estate expenses
  - no administrative or maintenance expenses for the cloud consumer
  - charged as resource used

## Generic architecture of IaaS **provisioning process**

IaaS provisioning process is carried out by the IaaS stack. The layers of the stacks are:

### Co-Location Layer

Provide basic requirements needed to deliver IaaS

- Electrical Power
- Bandwidth
- Cooling
- Real Estate

### Hardware Layer

- Physical hardware that is provisioned "virtually" to the cloud consumers ( data centers )
- Maximize the hardware capacity to give the cloud the illusion of infinite capacity

### Virtualization Layer

- enables IaaS service provisioning:
- responsible for
  - finding appropriate physical machine that host the consumer request
  - partition and allocate resource for consumer
  - maintain the snapshot of resource usage

### Service Layer

The interface the IaaS consumer interacts with to get the provisioned resources

---

## AWS

You know what this is. Some components AWS offer:

- **Amazon Elastic Compute Cloud** ( EC2 )
  - Virtual Machines to cloud consumer, choose as their requirement
  - 3 pricing models: On-demand( by the hr ), reserved ( upfront, subscription ), spot instances ( bid )
- **Amazon Simple Storage Services** ( S3 )
  - non structured storage for data such as images, videos
  - objects are stored as buckets assigned a unique key, associated with an amazon user
- **Amazon Relational Database Service**
  - Relational DB ( MySQL, Oracle, MS SQL server, PostGreSQL, AMZAurora, Maria DB )
  - carry out backups regularly in intervals
  - with the advantage of the ability to scale up/down of the RDS instance on demand
- **Amazon Cloud front service**
- **Amazon Simple Queued Services** ( SQS )
- **Amazon Glacier**
  - Storage service useful for data archiving and backup
  - used to data that is infrequently accessed, longer query time, a lot more storage
- **Amazon Cloud watch**
  - Monitor performance of AWS resources
  - define your own metric from your servers to monitor
