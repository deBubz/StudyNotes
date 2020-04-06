# Intro to jsp and jsp unit testing

## WebApps v WebServices

- presentation-oriented **web app**
  - **page** based
  - app generates markup files
- service-oriented **web services**
  - **service** based
  - app provide "remote procedure calls/remote methods"
  - application interacts with application

### Web Basics

- request - response 
  - between client - server
  - between machine - machine

## Html to JSP

### JSP

- JavaServerPages
  - allows embedding java code in html
  - executed by the server and return data to the browser as HTML
- Execution Process
  - web browser access URL of JSP page
  - corresponding JSP file is converted into a JAVA class
  - java class is compiled/executed
  - output is sent back to browser
- `Glassfish` server

- architecture sl9
- processing sl10
- syntax sl 11-12

## Intro to JUnit with Java

- **TESTING** the process to check if the app runs according to requirements
- **JUnit**
  - unit test framework
  - ideally integrated with `maven` or `gradle` web apps to enable fully-automated testing
- **JUnit** features
  - open source framework provides
    - annotation to id test methods
    - assertion for testing expected result
    - runners for running tests

## JUnit Basic Usage

there are 4 steps

1. create java class ( in source package )
2. create a test class (Test case) ( in the test package )
3. Create a Test Runner class ( in the etst package )
4. Execute the Test Cases

