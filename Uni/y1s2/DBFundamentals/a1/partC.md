# Part C Logical Design


## NOTES

2. Logical Design/ Normalisation
   1. ID and list Functional FD and state which fd is determined based on which BR/Forms of your case study.
      - Use the format `X -> Y`
      - `Determinant -> Dependent`
   2. Use FD to determine highes normal form for each table/relation in previous part.
      - Also Justify your choice
      - Normalise all table till they are BCNF 
      - Document each detail of the nomalzation(or 3rd?)
4. Structure
   1. Revised BR and Assumption
   4. List of FD related to each BR
   5. Normalisation

**NOTE** Normalization step by step

---

## Revised Business Rules and Assumption

1. **User BR**
   - *1.1* Each User should be able to store multiple delivery address in their account.
   - *1.2* Each User should be able to store multiple payment methods in their account wether its a paypal account or through a creditcard.
   - *1.3* Each users will need to have a Unique Email, but for security and privacy reasons an auto generated UniqueID will be used to identify each users instead of the emails.
   - *1.4* When signing up, users will only be asked to enter an email, their name and set up a password for the account.
   - *1.5* When signing up, If the email already exist in the database, the user will be prompt to sign in with a matching password for the account
   - *1.6* Users could become delivery driver to deliver orders if they want to.
   - *1.7* Current Users can refer the Deliveroo service to their friends and families to get a reference discounts on the service.
2. **Restaurants BR**
   - *2.1* The list of restaurants a user could order from is based on the distance
   - *2.2* The list of restaurants should be able to be filtered by cuisine type
3. **Menu BR**
   - *3.1* Each restaurants are able to offer multiple different meals and the meals are speparated into different categories set by the restaurant owner.
   - *3.2* users should be able to customise their meals with more than one options(size, extra toppings) if they wish to.
4. **Ordering BR**
   - *4.1* For logistics reasons and to keep delivery cost low, each order should only contain meals from 1 restaurant.
   -* 4.2* Users should be able to order multiple different meals per order.
   - *4.3* users should be able to view and edit details such as delivery address and payment method before confirming the order.
   - *4.4* If a user did not provide a delivery address/ payment method before ordering, they will be promt to provide them before checking out.
   - *4.5* users should be able to add promotional code for discounts for their order.
   - *4.6* Each order can not have more than one promo code applied.


## Revised ERD **1.5m**

- Here is the new and revises design of the Entity Relation Diagram. Also included below is the list of changes since the previous report.

![ERD](./deliveroo/c_erd.png)

ChangeNotes:

- Changed the naming format of attributes.
- Added a 1 mandatory : 1 optional **Unary** realationship for the User. This is to fit the reviesd BR
 will need to nique Email, but for security and privacy reasons an auto generated UniqueID will be used to identify each users instead of the emails.
     - `UserID → UserEmail`
> Current Users can refer the Deliveroo service to their friends and families to get a reference discounts on the service

## Relation **4m**

This section contain the converted relation from entities in the ERD.

### Customer

**User**

> **USER**(<u>UserID</u>, UserFName, UserLName, UserEmail, UserPassword, RefereeID*)
>
> FK(RefereeID) references USER

**Address**

> **ADDRESS**(<u>AddressID, UserID*</u>, AddrNo, AddrStreetName, AddrCity, AddrPostCode, AddrState)
>
> FK (UserID) references User

**Payment**

> **PAYMENT**(<u>PaymentID, UserID*</u>)
>
> FK (UserID) references USER

**Creditcard** (subtype of Payment)

> **CREDITCARD**(<u> PaymentID, UserID*</u>, CardNum, CardHolderName, CardExp, CardSecCode)
>
> FK (UserID) references USER

**Paypal**

> **PAYPAL**(<u>PaymentID, UserID*</u>, PaypalAcc, PaypalToken)
>
> FK (UserID) references User

### Restaurant Section

**Restaurant**

> RESTAURANT(<u>RestaurantID</u>, RtrCusineType, RtrAddrNumber, RtrStreetName, RtrPost, RtrCity, RtrState, RtrOwnerFname, RtrOwnerLName, RtrContactNo)

**Meal**

> **MEAL** (<u> MealID, RestaurantID*</u>, MealName, MealPrice, MealImage, CategoryID*)
>
> FK (RestaurantID) references RESTAURANT
> 
> FK (CategoryID) references MEALCATEGORY

**MealCategory**

> **MealCategory** (<u>CategoryID</u>, CategoryName)

**Option**

> **OPTION** (<u>OptionID</u>, OptionName, OptionDesc, OptionPrice)

**Order-Meal**

> **ORDERMEAL** (<u>OrderID*, MealID* ,ReastaurantID*</u>, Quantity)
>
> FK (OrderID) references ORDER
>
> FK (MealID) references MEAL
>
> FK (RestaurantID) references RESTAURANT

**Meal-Option**

> **MEALOPTION** (<u>OrderID*, MealID* ,OptionID</u>)
>
> FK (OrderID) references ORDER
>
> FK (MealID) references MEAL
>
> FK (OptionID) references OPTION

### Order Section

**Order**

> ORDER (<u>OrderID, RestaurantID*, UserID*</u>, OrderDate, OrderTime, AddressID*, PaymentID*)
>
> FK (RestaurantID) references RESTAURANT
>
> FK (UserID) references USER
>
> FK (AddressID) references ADDRESS
> 
> FK (PaymentID) references PAYMENT

**Delivery**

> **DELIVERY** (<u>OrderID*, DriverID*</u>, PickupTime, DeliveryTime)
>
> FK (OrderID) references ORDER
>
> FK (DriverID) references USER

**Promotion**

> **PROMOTION** (<u>PromotionID</u>, PromoCode, PromoStartDate, PromoEndDate, DiscAmount, DiscType).

## List of Functional Dependancies related to BR

This secion present Functional Dependancies extracted from business rules. For organisational purposes, 

### User Functional Dependancies

**Regarding Address**

- *1.1* Each User should be able to store multiple delivery address in their account.
  - `UserID → AddressID`
  - `UserID, AddressID → AddressNumber, AddressStreetName, AddressCity, AddressPostCode, AddressState`

**Regarding Payment**

- *1.2* Each User should be able to store multiple payment methods in their account wether its a paypal account or through a creditcard.
  - `UserID → PaymentID(Payment attributes)`
  - `UserID, PaymentID → PayPalAccount, PaypalAccToken`
  - `UserID, PaymentID → CardNumber, CardHolderName, CardExpDate, CardSecNumber`

**Regarding User**

- *1.3* Each users will need to nique Email, but for security and privacy reasons an auto generated UniqueID will be used to identify each users instead of the emails.
- *1.4* When signing up, users will only be asked to enter an email, their name and set up a password for the account.
  - `UserID → UserEmail, UserPassword, UserFName, UserLName`
- *1.5* When signing up, If the email already exist in the database, the user will be prompt to sign in with a matching password for the account
- *1.6* Users could become delivery driver to deliver order if they want to. The time when the food is picked up and the time delivered to ensure the package arrived as promised
  - `DriverID → OrderID, UserID, PickupTime, DeliveredTime`
- *1.7* Current Users can refer the Deliveroo service to their friends and families to get a reference discounts on the service.
  - `RefererID → UserID, UserAttributes`
  - `UserID → RefererID`

### Restaurant Functional Dependancies

- *2.1* The list of restaurants a user could order from is based on the distance
  - `RestaurantID → RtrAddrNo, RtrAddrStreet, RtrAddrCity, RtrAddrPost, RtrAddrState`
- *2.2* The list of restaurants should be able to be filtered by cuisine type
  - `RestaurantID → RtrCusineType`
- *2.3* Restaurants also need to provide the contact details of the owner
  - `RestaurantID - RtrOwnerFname, RtrOwnerLName, RtrContactno`
- *2.4* Restaurants need to provide Price, Name and an image of every single dish they provide.
  - `RestaurantID, MealID → MealName, MealPrice, MealImage`
- *3.1* Each restaurants are able to offer multiple different meals and the meals are speparated into different categories set by the restaurant owner.
  - `RestaurantID → MealID`
  - `MealID → CategoryID`
  - `RestaurantID, MealID → MealName, MealDesc, MealPrice`
- *3.2* users should be able to customise their meals with more than one options(size, extra toppings) if they wish to. Selecting an option may modify the cost of the meal.
  - `OptionID → OptionName, OptionDesc, OptionPrice`
  - `OrerID, MealID → OptionID`

### Order Functional Dependancies

- *4.1* For logistics reasons and to keep delivery cost low, each order should only contain meals from 1 restaurant.
- *4.2* Order records contain the date of the order is made, and its status. Users should also be able to order multiple different meals per order.
  - `OrderID → RestaurantID, UserID`
  - `OrderID, UserID, RestaurantID → MealID, MealQuantity`
  - Note: the meal quantity is to depict the number of a specific meal that the user want to order.
- *4.3* users should be able to view and edit details such as delivery address and payment method before confirming the order.
  - `UserID, OrderID → AddressID(Address attributes), PaymentID(Payment attributes)`
- *4.4* If a user did not provide a delivery address/ payment method before ordering, they will be promt to provide them before checking out.
  - `UserID, OrderID → AddressID, PaymentID`
- *4.5* users should be able to add promotional code for discounts for their order.
- *4.7* Each PromoCode are only applicable in a certain period and the code can either give a percentage or a flat rate discount
  - `PromotionID → PromoStartDate,PromoEndDate, Promocode, PromoDiscountType, PromoDiscountRate`
  - `UserID, OrderID → PromotionID(Promo code attributes)`

### Combining the Functional Dependancies

**User Section**

- `UserID → RefererID, UserEmail, UserPassword, UserFName, UserLName, PaymentID, AddressID`
- `RefererID → UserID, UserFName, UserLName, UserPassword, UserEmail`
- `UserID, AddressID → AddrNumber, AddrStreetName, AddrCity, AddrPostCode, AddrState`
- `UserID, PaymentID → PaypalAccount, PaypalToken, CardNumber, CardHolderName, CardExpDate, CardSecurityNumber`
- `DriverID → UserID, UserFName, UserLastName, UserEmail, UserPassword`

**Restaurant Section**

- `RestaurantID → RtrCusineType, RtrAddrNo, RtrAddrStreet, RtrAddrCity, RtrAddrPost, RtrAddrState, MealID`
- `RestaurantID, MealID → MealName, MealPrice, MealImage`
- `OptionID → OptionName, OptionDesc, OptionPrice`

**Order Section**

- `OrderID → RestaurantID, UserID, OrderDate, OderStatus`
- `OrderID, UserID, RestaurantID → MealID, MealQuantity`
- `OrderID, MealID → OptionID`
- `OrderID, UserID → PromoID, RestaurantID, PaymentID, AddressID`
- `PromotionID → PromoStartDate, PromoEndDate, PromoCode, PromoDiscountType, PromoDiscountRate`

## Normalisation

This section will examine each relations previously converted from the ERD and use the functional dependancies to check if they have reached the 3rd normalization form. A 3rd normal form include these characteristis:

- 1NF: All Attributes must be atomic and not derrived.
- 2NF: Every Non-Key attribute must be defined by the whole key.
- 3NF: No Transitive dependancies

### **User**

> **USER**(<u>UserID</u>, UserFName, UserLName, UserEmail, UserPassword, RefereeID*)
>
> FK(RefereeID) references USER

Normal Form

**Address**

> **ADDRESS**(<u>AddressID, UserID*</u>, AddrNo, AddrStreetName, AddrCity, AddrPostCode, AddrState)
>
> FK (UserID) references User

**Payment**

> **PAYMENT**(<u>PaymentID, UserID*</u>)
>
> FK (UserID) references USER

**Creditcard** (subtype of Payment)

> **CREDITCARD**(<u> PaymentID, UserID*</u>, CardNum, CardHolderName, CardExp, CardSecCode)
>
> FK (UserID) references USER

**Paypal**

> **PAYPAL**(<u>PaymentID, UserID*</u>, PaypalAcc, PaypalToken)
>
> FK (UserID) references User

### Restaurant Section

**Restaurant**

> RESTAURANT(<u>RestaurantID</u>, RtrCusineType, RtrAddrNumber, RtrStreetName, RtrPost, RtrCity, RtrState, RtrOwnerFname, RtrOwnerLName, RtrContactNo)

**Meal**

> **MEAL** (<u> MealID, RestaurantID*</u>, MealName, MealPrice, MealImage, CategoryID*)
>
> FK (RestaurantID) references RESTAURANT
> 
> FK (CategoryID) references MEALCATEGORY

**MealCategory**

> **MealCategory** (<u>CategoryID</u>, CategoryName)

**Option**

> **OPTION** (<u>OptionID</u>, OptionName, OptionDesc, OptionPrice)

**Order-Meal**

> **ORDERMEAL** (<u>OrderID*, MealID* ,ReastaurantID*</u>, Quantity)
>
> FK (OrderID) references ORDER
>
> FK (MealID) references MEAL
>
> FK (RestaurantID) references RESTAURANT

**Meal-Option**

> **MEALOPTION** (<u>OrderID*, MealID* ,OptionID</u>)
>
> FK (OrderID) references ORDER
>
> FK (MealID) references MEAL
>
> FK (OptionID) references OPTION

### Order Section

**Order**

> ORDER (<u>OrderID, RestaurantID*, UserID*</u>, OrderDate, OrderTime, AddressID*, PaymentID*)
>
> FK (RestaurantID) references RESTAURANT
>
> FK (UserID) references USER
>
> FK (AddressID) references ADDRESS
> 
> FK (PaymentID) references PAYMENT

**Delivery**

> **DELIVERY** (<u>OrderID*, DriverID*</u>, PickupTime, DeliveryTime)
>
> FK (OrderID) references ORDER
>
> FK (DriverID) references USER

**Promotion**

> **PROMOTION** (<u>PromotionID</u>, PromoCode, PromoStartDate, PromoEndDate, DiscAmount, DiscType).
## Reflection

- **What did you already know about the content and skills that were presented in this lecture?**
  - I was shown how to design an ERD and work with "SeeQUel"(Specificly SQLServer) in TAFE through their programming/ software dev course. So I would say about 70% of the coursework.
  - TAFE shown me how to a secure DB(atleast against injections) and intergrated it with a MVC webapp. The final project is to build a functional e-commerce site with APIs to get/generate data from the db.
  - This is not a complaint as I understand that this course was made to introduce Db to first year students.
- **What did you learn about the content or skills that were presented in this class?**
  - Using Normalization as an extra step of verifying your db design. Even though it wasnt shown very well ( not the fault of the lecturer and tutor) due to the structure of the course.
  - It took me a while to understand that this is not a following process after completing the ERD but an alternative method of db design process or a verification method for the existing ERD design.
- **How did doing the assignment change your understanding about this subject?**
  - Not much, I would say that this assessment only provided  more much needed practice for normalization and ERD design.
  - Beside that, the assessment shown me the importance of constantly reviewing your design to gradually improve and build it to satisfy given requirements.
- **What connections have you made between this subject and other subjects you have taken?**
  - Not much aside from other subjects such as BRM also using Db in the coursework.
  - This is only my second semester at and so far, I dont think UTS intergrates related subjects very well. e.g big difference in the notation used in BRM and DBFun.
- **What do you suggest for your further improvements in this subject?**
  - A more math like approach, using different smaller bite size usecase to actually apply and practice what is taught in class (building ERD, normalization).
  - Don't just stick with one case study, have several examples for students to practice the processes of normalisation.
  - I understand using the same Hospital use case is to simulate how DB are developed in the real world, but it is very difficult to understand the process if its not applied to different scenarios, They do not need to be big and intricate use case like the Hospital to achieve this
  - I perfer the approach similar to how the SQL tutes are carried out, build queries to get certain data.