# Cloud SaaS Tutorial Overview


## Week 3 Intro to AWS and EC2

- **OK** Create aws account
- **OK** Launch an EC2 instance
- **OK** Create a custom Amazon Machine Image and launch an EC2

## Week 5 Elastic BeanStalk

- **OK** Create Elastic BeanStalk environment (using presets)
- **OK** Customize health monitoring your EB environment
- **OK** Create a custom EB env using custom code

## Week 6 Customize EBS

- Create a custom VPC and 2 subnets in the VPC. Then launch a new EB environment using the custom VPC and subnets
- Customize the AutoScalingGroup and launch a new EB environment using ASG
- Go to the Cloud Formation console and see it making changes to EB environment

## Week 7 AWS Storage Services

- using SimpleStorageService(S3)
  - create s3 bucket
  - change bucket permission
  - upload files into bucket
  - change obj permissions
  - access the object using the object URL
  - enable versioning on buckets
  - enable S3 bucket lifecycle rule
  - make a static website using S3 bucket
- using ElasticBookStore (EBS)
  - launch 2 EC2 instances
  - create EBS volume
  - attach EBS volume to EC2 instance
  - connect to EC2 instance and make Volume Usable
  - Download Files from S3 bucket to EBS volumes
  - Create EBS volume snapshot
  - Create a new volume from a snapshot
  - Attach the new EBS volume to EC2 instance
  - Detach EBS from EC2

---

From this point on  is PaaS stuff, might be useful looking at the lectures

## Week 8

- Create app on salesforce using case study
- All files on drive folder, create the app through the following task
  - identify **object required** for the app, draw a rough sketch of the data model
  - define the **objects** and their **relationships**
  - identify the **validation** rules and define them
  - identify the need for **page layout** and define them
- Steps Involved
  1. Create **position** object (posID, posTitle, description, startDate, endDate )
     - validation rule on closing date
  2. Create **applicant** object (fName, lName, addr, dob, firstDgree, secDgree)
     - define layout
  4. Create **application** object
     - master-detail relation with **Application** obj and
     - look-up relation with **Position** obj

## Week 9

## Week 10