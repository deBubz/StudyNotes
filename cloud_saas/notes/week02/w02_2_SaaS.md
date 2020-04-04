# Software as a Service

## Software Application
 
Examples:

- Email apps
- Customer Relationship Management
- Human Resource Management
- Finance Management
- Patient record management
- Logistics / Supply Chain Management 
- and more

Typical traditional methods for procuring and using software:

- identify your business requirements for software
- purchasing the license
- installing the software in-house
- deploy patches and upgrades
- report bugs to the vendor

This could be bad because

- upfront capital investment and provisioning
- ongoing investment in the maintenance
    - new software are released everyday

> HENCE, `SaaS` provide and provision for software applications

## SaaS

> What does consuming software means

- software is provided as-a-utility to the consumer
- on-demand, provided by the software/SaaS provider or a third party broker
- deployed, upgraded and maintained by the SaaS provider

> *The capability provided to the consumer is to use the **provider's application* running on a cloud infrastructure.*
> *Applications are accessible from various client devices through interfaces as a browser or a program interface* `NIST definition`

- All users share the same codebase, computing platform
- This allow the SaaS providers to provide the ability to deliver services on a scale that is both economically profitable

### characteristic

- users does not manage/control the underlying computing platform on which the SaaS in executing
- deployed outside of the consumer's network or firewall
- highly standardized, customization limited by the provider

Benefits

- Cost are tied into "operational Usage"
- Fast provisioning of (additional) SaaS Instances

Implications

- limited customisation
- some overheads
  - cost of integrating with in-house applications
  - cost of migration in/out from SaaS
- data security/privacy managed by the provider

### Compare in-house application v SaaS application

- License
  - In-house, licensed with an up-front cost depends on number of users
  - SaaS based on either Time, flat monthly billing, data based or usage
- Usage Constraints
  - SaaS impose restriction such as stored data, file size

### SaaS integration

- Its harder to integrate SaaS mostly because
  - the large existing in-house application
  - concern of data security/privacy
- SaaS can be implemented in varying flavours:
  - complete migration
  - reconfigure the in-house application to work with SaaS
    - SaaS depending on data provided by in-house app
    - in-house app depending on data provided by SaaS

### Integration broker

- responsible for integrating in-house app with SaaS (vice versa)
  - managing and coordinating data dependencies and synchronization between SaaS and the in house app
- **data sink** the app where the corresponding changes from the data source need to be synchronized
- more responsibilities
  - receive data from the data source
  - determine where the corresponding data needs to be sent
  - routing data to the appropriate application data sink
  - transforming the data into the appropriate format

Key elements of the integration broker:

- Metadata layer
- integration broker pipeline

### Integration Broker Pipeline

- perform all the integration activities between the data source and data sink
- comprise of 4 modules
  - **data security** module
  - **data validation and transformation** module
  - **data synchronization** module
  - **routing** module

okok 3 ways the data synchronization can be achieved

- Polling sync mechanism
- push sync mechanism
- pub-sub sync mechanism

### Metadata layer

- specify `how` to perform integration activities
- encompasses the logic to enable integration activities in the form of rules
  - security operations
  - validate/transform operations
  - synchronization operations
  - routing operations

## Examples

- Google Docs
- Dropbox

