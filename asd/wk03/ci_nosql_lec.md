# CI/CD and NoSQL

## Continuous Integration

- **CI** is the process of automating the **build** and **testing** of code everytime a team member commits changes to version control
- **CI** encourages code/tests sharing by mergin changes to shared repository after every small task of code completion
- commiting code triger the build system to grab the latest code from the repo to build and test
- **CI** became best practice because devs often work in isolation, and its **vital** to integrate their changes with their teams codebase.
- Waiting a long time before integrating code creates many **merge conflicts**, difficult bugs, diverging code strategies and dupplicated effort

> everytime code is pushed to rep, CI server build test and return result

## Continuous Delivery/Deployment

- **CD** is to process to **build**, **test**, **configure** and deploy from a build to a production environment
- Multiple testing/ staging env creates a **Release Pipeline** to automate the creation of infrastructure and deployment if a new project.
- Successive env support progressively longer running-activities of integration, load, and user acceptance testing.
- **CI** starts the **CD** process and the pipeline stages each successive enironment to the next upon successful completion of tests

> without **CD**, software release cycles were a bottleneck for dev and ops teams in the past.
> Manual processes leads to unreliabler releases that produces delays and errors.

## NoSQL DB

- NonRelational and NonSQL
- Stored as
  - Document Databases( mongo - JSON )
  - Key-Value store ( redis )
  - wide-column stores ( cassandra, hbase )
  - graph store ( neo4j, hypergraphdb )
- benefits
  - more scalable
  - superior performance ?? *questionable*

### Examples

Document Database

> json format

each json doc has a key attatched to it

Key-Value pair

| key   | value |
|:------|:-----:|
| bob   | 12345 |
| jane  | 23456 |
| alice | 34567 |

Wider Column

Graph

