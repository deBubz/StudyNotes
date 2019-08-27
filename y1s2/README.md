# y1s2

## Assessment Planner

### Apps A1 30%

[Guide and Specification](https://drive.google.com/open?id=1LmHmXraxtZgtrqtejtvZ6nPbdOzFVA4e)

- **Topics**: OODesign, Standard Patterns, Lists
- **Due**: 13 May
- **Specs**: 
  - Movie renting kiosk with 2 main parts(Administrative & Catalogue)
  - **Administrative**: Text base menu that can
    - Add/Remove customers
    - Add/Remove movies from catalogue
    - Displays Customer records
    - Display Customers favourite movies & Top-up of customer accounts
  - **Catalogue**:
    - List all movies in the kiosk
    - List the genres of those movies
    - List the availible movies
    - Display/sort movies by avaibility/ genre/ year
    - Also handling renting & returning of movies
  - Each Customer record contains name, chosen ID number, current balance, currently renting + renting history
  - Each movie record contains Title, genre and year.

---

### Database Part2

- Conceptual Data Modelling
- Produce ERD (using crows/textbook notation)
- Provide justification for your design choices while probviding assumptions for the systems
- **Structure of part B** report:
  - **Overview** of the Casestudy (~5 sentences from part A)
  - Revised **Business rules** of part A
  - PartB Conceptual Data Modelling
  - **Justification** of ERD based on Business Rules
    - Correct BR describing entities, relationships  cardinalities between entities. May need to Repeat a BR manytimes.
    - EXAMPLES

```md
BR relating to entity CUSTOMERS
BR1: every customers need to register to the system
BR2: customers should provide their name, addr, and mobile
```

```md
BR related to relationships between CUSTOMER & PRODUCT and their cardinalities
BR4: every customer can buy many products(0:m)
BR7: every product needs to be purchased by at least 1 customer (1:mS)
```

```md
NOTE: as you can see there are m:m relationships between CUSTOMER & PRODUCT there need to be an associative entity

```

---

### BRM Case Study

- **Due** April 29
- Level1
- Level2
- ERD
- Data Dictionary

---

### Networking Server

- **TASK**: Socket programming, python html TCP server
- **Due**:
- **Specification**:
  - Create a socket, bind it to an address/port
  - Send/ recieve http packet
  - learn some basic http header format
  - Server will handle one connection at a time
  - Accept and parse HTTP requests & returns the requested files from the server.
  - The response also needs to contain http response status of the request (200 OK 404 Not found )
- **Running the Server**:
  - 1 basic html in the same dir as the server.
