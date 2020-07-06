# misc notes

## What we did

- week 3+
    - aws edu creation
    - creating **ec2**
    - creating **ami** based on the ec2 instance
- week 5
    - **elastic beanstalk** and type of environment tiers
    - creating custom ebs 
- week 6
    - customise ebs environment
      - single instance v high avail environment
      - adding **load balancer** and **autoscaling group**
      - types of load balancers
      - customizing instance types and AMI for creating EC2 Instances
      - customizing **network/ db** params for EB health monitoring
    - vpc, subnet, launching Eb application
- week 7
    - aws storage service block v obj v file
    - understanding EBS, EFS, S3
    - Storage - s3 and ebs

## What I need

### part 1

- Design doc outline the architecture diagram justifying the inclusion of each AWS services
- Outline the any assumptions made from the design on the app
- DIAGRAMS

### part 2

> either use Beanstalk to config your App or configure and deploy each application component individualy

USING

- AWS bean stalk
- EC2 
- **LAST** create custom AMI
- custom security group allowing HTTP and SSH
- Load balancer
- `Auto scaling (min: 2 max: 8) scaling trigger on network output traffic with upper 60% lower 30%`
- RDS (relational database) multi zones deployed
- `Custom virtual private cloud VPC (2 subnets in different avail zones). with puplic subnets`
- `Same custom key pairs`
- Set email notif for EBS

## Docs

- labs
- https://docs.aws.amazon.com/elasticbeanstalk/latest/dg/GettingStarted.html
- https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/CHAP_Tutorials.WebServerDB.CreateWebServer.html
- https://docs.aws.amazon.com/autoscaling/ec2/userguide/as-register-lbs-with-asg.html#as-register-lbs-console
- https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/install-LAMP.html


----

# Current Plan

- Note week 3, 5, 6, 7 lab content
- build based on requirements
- note the document

---

# lab review notes

## Week 3 Ec2, AMI

- Just basic creation of an AMI of an existing instance containing all its configs
- do last

## Week 5 elasic beanstalk

### EBS

- to deply scaling web app
- ebs components:
  - **application** "folder" for components including environment versions and env
  - **environment** collection of all the AWS resource used to execute on run 
    - each env runs 1 single app

> Application > application version > environment

work flow

> create app > upload app > launch/ manage environment

architecture slide 9

### EC2

- tech stack running on ec2 is dependent on the container type
- a host manager runs on each EC2 instance and it:
  - deploying the app
  - aggregating event + metric for retrieval via the console, API or CLI
  - motinoring application log

### Sec group

- determine whats allowed to reach (ingress) and leave (egress) the instance
- EBS default security group defaults traffic from the **load balancer** from http(80) and https(443)


### Auto scaling

- **ElasicBeans** app may be a collection of EC2 that are used to deliver the app
- have built in mechanism for auto scaling of EC2 instance + managing:
  - Group size: min max no of instance
  - Scaling policies
  - Load Balancing
  - Health Checks

### Storage options

- Relational Database Service 
- use MySQL for LAMP stack


### Creating EBS steps

1. Creating EB application
2. Creating EB environment

--------------

## Week 6 EB customization

How can EB be modified, select **configure more options** to customize env before creation:

What can be customized

| Param             |                                           |
|:------------------|:-----------------------------------------:|
| Instances         | Specify number of EC2 in EB and sec group |
| modify capacity   |               Auto Scaling                |
| LoadBal           | Criteria and mechanism for Load Balancing |
| network           |            specify VPN for EC2            |
| Db                |     use existing DB snapshot / engine     |
| software          |  store logs in S3 - send to cloud watch   |
| modify monitoring |      what cloud watch metric to use       |

### Single instance v High Avail Env

**Single** no load balancer low cost

> Need High Availability Instances

**Multiple** instences to achieve fault tollerance and high availability

- Need to specify AutoScalingGroup
- for *scalability* use Multiple Abailability Zones

> Samples sl 10 - 14

### Auto Scaling Group


### Select Instance type, AMI used to create instance

- **type** determines ec2 types of EC2 to run on
- useful type for e-shop **General Purpose Instances** - scale out workload - webserver, dev environment

### AMI

- EBS select default AMI based on the region, platform, instance type you use
- Creating custom AMI will:
  - improve provisioning times for instances launched in your env, if you need software not part of the standard AMI

> 20 - AMI
>
> 21 - EC2 sec group
>
> 22 - load balancer

### Load Balancers

- LB have
  - Listener: check connection request and forward it to an instance
  - HealthCheck: periodically check the registered EC2 instance
- LB types:
  1. **Classic** elastic LB previous gen LB, route HTTP, HTTPS, or TCP port to different instance of same port `THIS`
  2. **Network** network layer LB, route TCP to different ports
  3. **Application** app layer lb, route HTTP, HTTPS to different ports `maybe THIS`

### Customising Network Params

- **VPC** Isolated virtual network in the AWS cloud
  - isolated from other viritual networks in AWS cloud
  - can launch AWS resource into your vpc
  - can add many subnets in each Avail Zone in VPC
- **Subnet** smaller network section withon VPC, reside within a Availability Zone

> 31 diagram
>
> 32 Customizing VPC

- Avail Zones to set server zone in the world 
  - composed of Regions(geographic area) and Avail Zones(isolated location in regions)
  - Each zone is isolated, but Avail zones are connected trhoguh low-latency links

> sl 34

### Customising DB 

- do this by:
  - specify snapshot used to create the database, type of DB(MySQL)
  - class of DB instance, size of DB instance
  - Credentials of the RDS instance
  - Availability of the RDS instance

### Customising Health Monitoring prams

- Health reporting: for cloudwatch metrices
- Health event streaming to Cloudwatch: stream env health events to CloudWatch

> Maybe do this and note your assumptions

### Cloud Formation

- Maybe useful to save/transfer configs to the client

## LAB

- VPC, creating EB using custom VPC
- Customize ASG, create EB using ASG
- Go Cloud Formation console and see it making changes to AWS EBS

---

## w07 RDS

- **Block** raw, organised as arr of unrelated blocks
- **File** unrelated datablocks
- **Object** virtual containers that encapsulate data, attr, metadata and obj id, has API to access data `THIS`

Characteristics

- **Durability** aversion to dataloss
- **Avail** expected downtime
- **Sec** ssec for at-rest / intransit data
- **Cost**
- **Scalability** upward flexability
- **Performance** 
- **Integration** interact using API

> Find how how do RDS backup

> Find what Object Stoarange type S3

### Project Data Assumption

- Main bulk of data storage is User data, Order Data
- Inventory data will be a small percentage, according to the client

S3 one zone IA

- Access is mainly to handle Account Autherization, Session Keys, Shopping cart items, Order Records, show Items

> Have to use Block Storage for MySQL

### LAB

#### Elastic Block Store

- Launch, create volume
- Attatch EBS to EC2
- Connect EC2 and make it usable
- Download files from S3 to EBS
- Create EBS snapshot, create from snapshot
- Detatch from EC2


