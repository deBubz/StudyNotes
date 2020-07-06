# app plan

- Prep services
  - **SecGroup** aukeeb-vpc-secgroup
    - DB private access
    - HTTP, HTTPS (http redir to https using load balancer)
    - ssh public atm, need to change by org to use private ip for development, should not be public
  - **VPC** -  aukeeb-vpc 10.0.0.0/16
    - aukeeb-pub-sub1 10.0.0.0/24  rt1
    - aukeeb-pub-sub2 10.0.1.0/24  rt2

  - **Scaling, LoadBalancer**
    - zones us-east-1a 1f
    - balance on network load traffic
    - instance autoscale min 2 max 8
    - scaling trigger Network output avg up 60% low30%
    - ami-0fcaaa3011af5cc43 t2.micro
  - **RDS**
    - not publicly avail port 3306
    - currently usng dev/test environment
    - db.m5.largee 2cpu 8gbram
    - **U**: aukeebAdmin **PW**: change_3_this7_before1_deployment0
    - backup is automatically enabled
    - **aukeeb-vpc-secgroup**
  - **Notification** aukeebs.aws@gmail.com

> What do with AMI

- Create Application
- Create Environment, take note of the Environment Tier