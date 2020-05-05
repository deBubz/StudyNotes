# Data Security, Privacy, Availability and Integrity in CloudComputing: Issues and Current Solutions 2016

> Based on [this article](https://pdfs.semanticscholar.org/09fd/5326be429b39d75103ddd6550176c10e0ba3.pdf)

## Abstract

- cloud change the world, moving more data to the cloud accessed through many devices
- issues in storing data in the cloud
  - starting from vm to the cloud storage itself
  - present issues and some solutions that reduces risks
- data beed to be have integrity, confidential and available
- sharing data is a big issue for providers to ensure authorization and authentication

> Issues/ solutions  to cloud storage

## Key words

Data security, Data Confidentiality, Data Privacy, Cloud Computing, Cloud Security

## Intro

- cloud is every where, in all org sizes. cause its faster and cheaper
- not just a technical solution but also a business model
- lets org focus less on infrastructure and more on their business, big market for all sort of communities
- NIST defined cloud standard
- explain cloud's 5 definition of cloud computing
- since it is composed of many technologies services, it comes with many security vulnerability
- Therefore security is extremely important for cloud to keep providing value to both the cloud providers and consumers

## Characteristics of cloud computing

> brief outline, many different processes/tech means many different attack vectors

- self service, resources are partitioned and allocated automatically when requested by customers
- accessed from anywhere on any devicess
- resource pooling, multiple tenants share the same pool of resources and is dynamically allocated when needed
- high level of abstraction on where the data is stored physically
- measured resource consumption for billing

## Service Models

- **SaaS** - provide software ( + architecture ) for customers to use/integrate the software into their business
- **PaaS** - provide a platform for software development and deployment on the cloud
- **IaaS** - includes computing resources such as processing storage/network are provisioned to users to be used how every they want , basicly Virtual Private Servers ( EC2 )

## Deployment Models

> brief outline, ( could be **attack vectors** )

- **private cloud** - infrastructure for a private organization for business operations or used privately
- **community cloud** - infrastructure for many org which forms a community, each community is responsible for their own security policy/requirements
- **public cloud** - open to the public, not exclusive for any org/community.
  - providers may include gov, business/academiv orgs. many of them can be in one cloud and get the service from the same provider
- **hybrid cloud** - combination models of 2 or more above models.
  - this is to create an unifying env, making it easier to manage move data in one single cloud

## **Security Issues**

> Big boy part??

- users are reluctant to adopt because security in cloud is a very big dick topic, combining:
  - tech to secure data
  - **policies**/**requirements** to ensure security in data, service,, and infrastructure
- again **A LOT MORE** `different attack vectors` comparing to traditional computing systems ( physical attacks )
- the onus is now on the cloud provider to protect its customers from any breaches
- **These threats attacks**:
  - data confidentiality
  - data integrity
  - data availability

## Top threats to cloud

> Pick and look into it

- **Data Loss** through malicious attacks, and server issues [3], unintentional deletion by the provider without backups, natural events. Encryption key trouble. Solutions include
  - Strong API access control
  - Encrypt data in transit (MiTM)
  - Analyzing Data protection at run time and design time
  - strong key management practices
  - backups/retention strategies
  - requiring the providers to wipe persistent data before releasing resources back into the pool
- **Data Breaches**
  - any breaches to this env will expose all user/orgs data.
  - from Multitennancy, many user's application could use the same database, hence any break would affect all other users of that database.
  - SaaS can claim they have better security but that could easily be broken through an insider that directly handle user's data.
  - common causes of databreaches includes with 49% of the data breaches are from malware
- **Insider Attacks**
- **Insecure Interface and APIs**
- **Account/Service Hijacking**
- **Data Location**
- **DoS**

## Multitenancy

## Virtualization Security Issues

## Data Integrity issues

## Protecting Data Integrity

## Data Availability

## Data Confidentiality

## Multi Cloud Computing (MMC) issues

## Mobile Cloud Computing

## Done 

- cost of using cloud will always look better than investing in infrastructure
- there are many issues happening as technology matures
- Issues include
  - relating to issues from using the internet
  - network issues
  - application issues
  - storage issues ( storing on remote server ) -> security issues
    - unauth, confidentiality, integrity, availability
