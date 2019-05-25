# A2 Requirements

## OO Requirements Analysis and Specification

- **Due**: 27 May 10pm
- **Tasks**: Produces
  - OO Requirement Analysis and Specification report for a new and improved system
- **Brief marking scheme**
  - 1.0 Intro and Doc Management
  - 9.0 Functional requirement
  - 4.5 Data Requirement
  - 2.0 Non-Functional requirement
  - 0.5 contribution
  - 1.0 presentation quality

## Overview

- Using the updated case study to produce an **OO Requirement Analysis and Specification report**
- the new Customer Onboarding System should address:
  - Epic's goal for a better system.
  - any inefficiencies

To develop the new COS system you should:

- at least **6 User stories**, 2 from users, 4 from Ka-ching's PoV
- Develop a UserStoryMap for the COS? Estimate/Prioritise each User Story.
- **Document, Narrate 4 use case** based on 4 User Stories: 2 from customer, 2 from kaching
- Draw **2 Sequence Diagram**
  - for any one of the user's use case
  - for any of the KaChing's team use case
- Doccument 1 **Class Diagram** covering **all** your user stories & use case
- One **State Transition Diagram** for Customer Obj
- Two User **Interface/Wireframe** for any 2 use case (should be the same use case chosen for the sequence diagram)
- Security & Performance Requirements.
- Include Document management, Introduction, bibliography and contribution.

---

## Structure

### Document Management

- **Revision History**: Table showing changes
- **Intended Audience**: table showing intended audience: lecturer, tutor, group, blah 
- **Reference Documents**: Table showing reference text, mostlikely lecture slides
- **Glossary**: Glossary table for jargon, abbreviations

### Intro
- **Document Purpose**: State the purpose of the report, present a list of business requirements
- **Projecy Purpose**: State the purpose of the project
- **Project Scope**: State the scope of what the project entails, Should Include a basic usecase diagram covering all of your `UseCases`
  - **In Scope** Table Showing usecases in the scope
  - **Out of Scope** Table Shoing use cases out of the scope
- **Assumption**: Assumptions on extra implemented features not presented in the case study

### Functional Requirements

- **User Stories and User Story Map**
  - Provide ALL possible user stories for the new COS (min 2 form user, 2 from staff)
  - user story map, Follow template
  - Each use case must have an ID number included
  - **Use Cases** (use case Narative Table) (2 customer, 2 kaching)
    - **UC1**
    - **UC2**
    - **UC3**
    - **UC4**
  - **Sequence Diagram** Base on presented UseCase Narrative
    - Each Diagram must cleary state corresponding usecase name, should match the mainflow of corresponding usecase narrative.
    - 1 Userhttps://www.owasp.org/index.php/Category:OWASP_Top_Ten_Project
    - 1 Kaching
- **Data Requirements**
  - **Class Diagram**
    - 1 Diagram covoring all user stories and usecase
  - **State Transition Diagram**
    - State Transition Diagram from the lecture, example is not complete, need
      - Event inbetween states that triggers the transition
      - Correct Labeling (verbs)
      - 1 STD (lel) for the `Customer` object covering all related usecases across the whole COS
- **Non-Functional Requirement**
  - **User Interface Requirements**
    - 2 UI wireframe 1 used by the customer, 1 used by kaching staff
  - **Security Requiremtnts**
    - Security Requirement table
  - **Performance Requirements**
    - Performance requirement table
- Bibliography
- Appendices


---

## Case Study: 12 months later

> - takinge avg 10 days to** onboard new custome**r form an initial enquiry through **telephone** registration, ID & payment deets verificatio, **all over the phone**.
> - 3 tier of monthly subscription package
>   - Basic (HD)
>   - Lux   (UDH)
>   - Max   (UHD) for 10 devices
> - ATM, User can only change their subscription through email, OR leaving a call back number and wait to be contacted by KACHING `why`
>   - Competitors can do this on a user dashboard/ online chat
> - Each customer needs:
>   - Name, Addr, email, 100 points of ID (verified **offline** through 3rd party servce provider)
>   - needs to be 18+
>   - Payment (CredCard & EFTPOS) verified through 3rd party
>   - 3rd party offer to intergrate online verification (`APIs duh`)
> - Opt-In choice to recieve marketing/service notification via post/email, while in **phone registration**.
>   - could upgrade to add SMS notification
> - should allow for customers to redeem 3-months promo discount. This is a way to **reward opted-in** customers
> - at the end of registration, KaChing checks if Customers understand the ToS adn reads it out.
> - Let customers update their Payment details on the **dashboard**
