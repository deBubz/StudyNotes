# Revision week03 Virtualization

## Objectives

- understanding virtualization
- understanding different types of virtual machine
- Role of Virtualization in Enterprises
- Application level virtualization

## Virtualization

- To utilize the unused resource and make it available as its own independent server to consumers
- VM - slice of physical machine, as an independent web server
- made possible by technology to share computing resources, both hardware and software resources

```md
Any means for many different users to simultaneously interact with a single computing system.

Having each perceiving that they have an entire virtual instance(VM) to themselves
```

### Virtual Machines

Consist of 3 types

- **Process Virtual Machine** `PVM`
  - a platform for the execution of a **single** process
  - Basic software execution, software creates a partition of computing resource to be used for that single software/process/application
  - shares the same os
- **System Virtual Machine (host)** `SVM-host`
  - Hypervisors or VirtualMachineMonitor allows the same hardware to `host` different OS
  - VMM functions include: create/manage instances of SystemVMs, passing hardware access calls from GuestOS to HostOS
  - Each VM can run their own independent instance of machine with any OS
- **System Virtual Machine (native)** `SVM-native`







