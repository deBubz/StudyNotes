# Week 01 Revisions of content

## Pre read stuff

- Generic understanding for cloud computing and cloud services
  - **Taxonomy Service Models**: SaaS, PaaS IaaS
  - **Deployment Models**: private cloud, community cloud, public cloud, hybrid cloud
- **Essential key functions of cloud services**:
  - On demand Self service
  - Broad network access
  - Resource pooling
  - rapid elasticity
  - measured service

## Class Overview / Objectives

- Overview of cloud computing
  - key characteristics
  - key business/economic parameter that drive the growth of Cloud
  - basic history ( maybe skip this )
- IaaS Overview
  - what is IaaS
  - generic architecture of IaaS service provisioning
  - Brief intro of AWS ( ec2 and storage options )

<!-- --- -->

## Cloud Computing

### History

- Gradually the philosophy for engineering computing software to be more **Process oriented**
  - programs are broken down to individual process that acted upon shared data

### Understanding Cloud Computing

- **Availability** Cloud service provider pooled resources to be made quickly available to customers upon request, through the internet
- **Elasticity** resources are dynamic, automatically made available when needed
- **Virtualization** the whole server (pooled resources) are able to be partitioned to virtual server to be used by consumers, using tech such as hypervisors
- **Measured service** cost are based on time and amount of resource used. Significantly reduces start up upfront cost and save on low usage.
- **Automated** request deployment and de-provisioning are automatically handled by the provider

<!-- --- -->

## IaaS

> **NIST**
>
> *"The capability provided to the consumer is to provision processing, storage, networks, and other fundamental computing resources,*
> *where the consumer is able to deploy and run arbitrary software, which can include OS and applications"*

- Infrastructure includes: WebServers, Application Servers, Database Servers, Memory
- Each infrastructure varies in processing speed, capacity, latency and cost
- **Key factors**
  - Resource provisioning on demand
  - Let consumer deploy and run arbitrary software, without configuring the underlying cloud infrastructure

### Provisioning process

- IaaS provisioning carried out by the IaaS stack. The layers of the stack are
  - **co-location layer** - basic requirement to deliver IaaS ( power, bandwidth, cooling )
  - **hardware layer**
  - **virtualization layer** - finding the physical machine to run on, partition resource, maintain snapshot of usage
  - **service layer** - interface for consumers 

## AWS Introductions


- **Amazon Elastic Compute Cloud** ( EC2 ) - basic VPS
- **Amazon Simple Storage Services** ( S3 ) non structured storage ( videos, images ) with objects stored as buckets
- **Amazon Relational Database Service** relational DB with automatic backups
- **Amazon Cloud front service**
- **Amazon Simple Queued Services** ( SQS )
- **Amazon Glacier** storage as archives, backups. perfered fore infrequently accessed data, less accessed, but has more storage
- **Amazon Cloud watch** monitor performance of AWS resources
