# sample a1 dissect

## Format

- abstract
- keywords
- brief overview of topic
- summary of existing topic
- findings & reflections

## Attacks/Issues Covered

1. User Distrust in Information Processing Measures
2. Cloud Attacks??
   - Wrapping attack
   - malware injection
   - Flooding (just say DoS/DDoS)
3. Data Leak
4. Account/Service Hijacking
5. VM escape
6. Auth and Access Control

## Solutions??

1. TTP handle the data transactions, transactions use the public key infrastructure
   - brings up the issues of how the keys are managed
   - CyberSec/Networking issue
   - attacks integrity
2. 

## Notes

### abstract

### keywords


### brief overview of topic

- describe the concept of cloud computing its pros and cons, how it functions and why it is so widely addopted
- 2 main security threats, internal/external
  - these vector of attack comes from users, vendors and third party vendors
- main defensive mechanism "virtualization" but itself is not immune to bugs, and incorrect configuration
- issues regarding privacy and compliance with the law also effect security  (​ Hashizume et al. 2013)
- main concern is regarding the  migration of confidential data into the cloud environment.

### summary of existing topic

- **2.1** distrust in information processing measures
  - current deployment model base on the provider trustworthiness, security mostly handled by the provider
  - multilayered security in each different layer of the infrastructure
  - **SOL** a Trusted Third Party(TTP) service is used to mitigate the problem of distrust in the **information processing measure**
    - trusted by both party
    - handle data transaction  (Zissis & Lekkas 2012) `????`
    - method based on technology, legal, financial an structural manner
    - PublicKeyInfrastructure (PKI)
    - describe the what is used to ensure a secure and trustworthy information processing method
- **2.2** cloud services attacks `vague`
  - important to retain customer's trust and usage
  - **Attacks**
    - **wrapping attack** - for SimpleObjectAccessProtocol(SOAP) messages
      - similar to MiTM acting as an imposter (Zunnurhain & Vrbsky 2011)
      - **SOL** Certificates and RSA
    - **malware injection attack** -  MiTM intercepting auth req/res, adds delay metadata spoofing
      - **SOL** incorporate hardware into verification
        - using FileAllocationTable(FAT) like system for verification
        - verify users current state (Zunnurhain & Vrbsky 2011)
    - **flooding attack** DDOS using request to attack the server load
      - **SOL** allocate each server to a specific task using hypervisers to schedule requests
      - also check validity of requests
    - attack on user accounts through the automated billing system, use more validation to check identity before charging
- **2.3** data leak
  - while handling data ( moving, storing, auditing, processing )
  - **SOL** digital signatures, homomorphic encryption, generic encryption
  - describe how and what the countermeasure assist security
- **2.4** account or server hijacking
  - social engineering, bad credentials
    - **SOL** access management guidance - from the CloudSecurityAlliance (CSA)
    - describe CSA
    - another **SOL** dynamic credentials based on user location or number of exchanged packets
- **2.5** VM escape
  - harm the vm by attempting take control of the physical server
  - **SOL** `HyperSafe` prevent modification of write protected memory pages
    - use TrustedCloudComputingPlatform(TCCP) 
- **2.6** auth and access control(AAC) issues
  - single sign on (SSO) policy
  - Multi factor Auth
  - Intrusion Detection System (ISD)

### findings & reflections

> state that while most issue have some sort of solution addressing the issue.
> There are no single perfect solution for any of them, not ever

- **2.1** distrust
  - **3.1** - TTP describe what PKI theoretically ensures
    - Not guaranteed complete trust as its accessing sensitive information
    - then identify vulnerabilities
    - TTP prone to malicious, distrustful practices by a single breach.
    - third party access to clients data, operate with out client monitor
    - could exacerbate distrust
    - `divert from main point` network security
    - auth and digital signature mechanism to confirm ID.
      - requires TTP
    - inappropriate TTP behavior could hard the networking security
    - **SOL** combining TTP with a secret sharing protocol
- **2.2** cloud attacks
  - **3.2** technology makes it harder to address these issues
    - **Wrapping**
      - expired certs, renewing certs is costly
      - cloud firms may neglect certs
      - need discipline in ensuring security
    - **Insufficient Accountability**
      - addresses identity spoofing/take over
      - need more auth `bad point`
- **2.3** data leak
  - challenging even with some countermeasures, FragmentationRedundancyScattering(RFS) only partially handle leakage
    - bad config lead do data leak
    - homomorphic encryption - bad/broken encryption algos
- **2.4** account or server hijacking
  - promote good practices for credentials
  - providers can force customer to adhere to good practices
- **2.5** VM escape
  - `HyperSafe` could be outdated, platform dependant
  - need to be regularly maintained `this is trash`
- **2.6** Auth and Access Control Issues
