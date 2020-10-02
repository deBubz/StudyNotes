# Secure software development

- software security
- secure sdlc
- core security training

## Software security

this includes

### Confidentiality

- managing access to software, software data
- only authorized users have access to the software and its data
- **identity** and **access management systems** are used to limit and control access to software and its data
  - id/passwords
  - nFA (multi factor authentication)
  - Biometric
  - Key Fobs
  - Soft token
  - Hard Token
  - Encryption

> probably try to spruce up the security of the project
> - verify token in each locked requests
> - add token timeout? resign

### Integrity

- consistency
- accuracy
- trustworthy
- coding standards and static code analyser can be used to ensure integrity/quality/compliance of software code
- Pen tests can be used to discover vulnerabilities in software

### Availability

- availibility to only authorised
- fail safes & backup
- disaster recovery
- Software availability testing is done to measure the following
  - MBTF(Mean time between failure): avg length of time the software runs before it fails
  - MTTR(Mean time to recovery): avg length of time that is required to repair/restore the service
- Availabilty = (MTBF / (MTBF + MTTR)) x 100

> maybe ask asif where this number comes from
>
> seems like %

## Secure SDLC

- **Planning & Requiements**
  - software sec plan
  - security requirements  
  - quality gates/ bug bars
  - security & privacy risk assessment
- **Architecture & Design**
  - architecture & design spec
  - attack surfac analysis
  - threat modelling
- **Implementation**
  - approved tools usages
  - deprecation of unsafe features/functions
  - static analysis
- **Verification**
  - dynamic analysis
  - fuzz testing
  - attack surface review
- **Release**
  - incident response plan
  - final security review
  - release archive
- **Response**
  - execute response plan

> this seems important enough to remember

## Core security training

- **security design**
  - attack surface reduction
  - defence in depth
  - principle of least privilege
  - secure defaults
- **threat modelling**
  - overview of threat modelling
  - design  implication of a threat model
  - coding constraints based on a threat model
- **secure coding**
  - buffer overruns (c/c++)
  - inter arimetic error (c/c++)
  - xxs (for managed code and webapps)
  - SQL injection (managed code and webapps)
  - weak crypto
- **security testing**
  - differences btween sec testing
  - risk assessment
  - sec testing method
- **privacy**
  - types of privacy sensitive data
  - privacy design best practices
  - risk assessment
  - privacy development testing best