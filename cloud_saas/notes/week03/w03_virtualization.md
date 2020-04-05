# Virtualization and Multitenancy

## Virtualization

### Why

Lets say Company A has a webserver that is on average 50% of the server is utilized.

Let say this is the same with comp B, but then B decided to make the unused server resource available to consumers

- **Virtualization** is the tech that split the webserver to logical units to be provided to consumers
- the logical unit is known as a **virtual server** or **virtual machine**

### What is Virtualization

> *Any means by which many users are able to **simultaneously** **interact** with, as a single computing system,*
> *while each perceiving that they have an entire virtual instances such as "VM" to themselves,*
> *is a form of virtualization* `Shroff 2010`

This technology enable sharing of computing resources such as physical hardware resources, memory, software resources

## Types of Virtual Machines

There are 3 types

### Process Virtual Machine

- PMV provides a platform for the execution of a single program ( process )
- Java Virtual Machine (JVM)
  - One of the most common form
  - Runs as a process on  a underlying shared hardware/os
  - Creates and uses a logically separate slice of resource ( ram ) for itself
- workings of JVM
  - java code is compiled to byte code, which can be executed on top of any JVM
  - JVM has access to a set of OS calls and hardware instruction to translate the byte code to machine language instructions

> jvm diagram slide 10

PVM ( similar to JVM ) creates logical partition of the computing resources and allocate each logical partition to a single process / application

Enables multi processes to run on the same hardware and OS environment, independent of each other

> pvm diagram slide 12

the processes in a pvm **cannot** operate/run their own os. `shares the underlying os`

abstraction of resources provided by GoogleAppEngine is similar to that of pvm

### System Virtual Machine (Host)

- `very different from pvm`
- each `svm - host` **can** run an independent os system instance, independent of other instances ( **system virtual machine** )
- in `svm - host` the instance share the same hardware and the same os ( **host operating system** )
- a `svm - host` can have many **sub-instances** of the same os being run on it ( **guest os** )

> svm-host diagram slide 15

- **Virtual Machine Monitor** or `Hypervisor` enable the system virtual machine instances to share the same hardware and the "host" os
- **VMM** software is installed and runs on the host os, functions include:
  - to **create** and **manage** the instances of system virtual machine
  - passing hardware access calls from GuestOS to HostOS, and converting them ( if required )

### System Virtual Machine (Native)

- `svm-native` **does not have** a host os
  - vmm is installed and executes directly on the shared underlying hardware
  - vmm is responsible for creating and running the vm instances on the underlying shared hardware ( *process is known as native; contrast to the shared host os* )
  - vmm maintains the state of each virtual machine

> svm-native diagram slide 18

## Comparison between the types of Virtual Machines

> slide 19, 20

## Cloud computing and virtualization

os in svm *v* pvm

- **svm** each system vm needs to be able to run a full os (of its own)
- **pvm** the various processes share the same os and cannot execute/run their own os

> The Google App Engine is bases on pvm

host os in svm-host *v* svm-native

- **host** host(base) os is shared across all instances of the vm
- **native** there is no host os

vmm in svm-host *v* svm-native

- **host** executes on top of the host os
- **native** executes on to of the underlying (shared) hardware

> AWS EC2 is based on svm

## Information

### Cloud Computing and virtualization

- virtualization in cloud computing us not limited to just creating vm. Most cloud providers use the virtualization layer to achieve `elastic computing`
- **elastic computing**
  - ability of the cloud provider to allocate resources on demand to the users ( in response to any resource request )
  - more resources/capacity can be made available instantly
  - gives the cloud consumer illusion of "infinite capacity" 
- **key features** for elastic computing
  - automated provisioning
  - elastic operations

### Automated provisioning

- **complete automation** of provisioning vms to consumers. done by an IntelligentProvisioningLayer ( part of the visualization layer )
- automate the selection of the physical server which the vm should be execute and assigned to the requested cloud consumer
- this process is factored by:
  - resource requirement of the consumer
  - available capacity and current utilization of existing physical machines
  - project demand of application running on the existing vm

The process of allocation, configuration and provisioning of vm is **completely automated**

### Elastic operations

- `similar` to elastic provisioning, the provisioning of vm is **completely automated**
- `difference`, the allocation of a given vm to a physical machine is dynamic and may change during the execution of the vm.
- The physical machine which the vm runs on is **dynamically** controlled is factored by
  - collocation- move vm frequently communicating closer to each other
  - fault tolerance - move vm from physical machines that are likely to fail
  - improve utilization of underlying phys machines
- VMs can ve moved do different physical servers at runtime. The process is called `Virtual Machine Migration`

The migration process is governed by the `Elastic operations layer` along with the VMM

### VM migration

Steps involved in a simple VM migration

1. Suspend the running VM
2. Save the VM state
3. Transport the suspended VM to another physical machine
4. Resume state

## Virtualization Applications

Some common applications of virtualization in enterprises:

### Server consolidation

- enterprises have many servers running different applications ( cause `server sprawl` )
- usually these servers are under utilized as each reaquires:
  - initial capital investment, cost in maintenance
- virtualization allows the consolidation of applications running on different under utilized servers across an enterprise
- result in better efficiency in time and cost of managing servers

### Security through the virtualization layer

- maintaining security is significantly more difficult in a `server sprawl` 
- using virtualization, the security mechanisms can be made part of the VMM, rather than being executed on a GuestOS
- its generally easier to detect and stop the suspicious vm with out impacting other users

### Desktop Virtualization

- ( large ) enterprises have a large/fluctuating employee base, comes with a huge cost of maintaining each individual desktops
- `Desktop virtualization` can be used to:
  - minimizing cost of procuring/ maintaining applications on the desktop
  - deploy/run all end user desktops as vm from a central server
  - Desktop as a service ( AWS WorkSpaces )

## Multi-tenancy

- refers to the ability of many users being able to use the same hardware/software
- virt tools ( vmware ) enable infrastructure or hardware level multi-tenancy
- multi-tenancy and PaaS
  - virt software in PaaS enables sharing of both software and hardware to all PaaS Consumers 

### Application Level Virtualization

- refers to the sharing of resources in PaaS and SaaS
- multi-tenancy in SaaS
  - sharing a set of `code` and `db` for holding the functionality and data of multiple enterprises or tenants
  - enables sharing of both `code` and hardware resources among its consumers
- **Challenge** to store each tenant's customized data and present it efficiently to the corresponding tenant on demand.

#### Implementing multi-tenancy in SaaS

`e.g` a form SaaS where each customer could customized what data is present on the form

3 approaches for **data management** in a multi-tenant SaaS

1. separate db for each tenant
   - simple to implements
   - high maintenance cost and security cost for each db
   - *not truly multi-tenant*
2. shared db ( among many tenants ) but a separate schema 
   - schemas are stored on the same db
   - metadata table redirects queries from a given tenant to its schema
   - could be hard to manage at a larger scale ( too many schemas )
3. shared db and shared schema
   - tenant ID is used to identify a tenant data
   - *?a table is created for each new field in the application?*

> - joins between record are carried out in *runtime* to retrieve data for a tenant
> - common approach in PaaS and SaaS