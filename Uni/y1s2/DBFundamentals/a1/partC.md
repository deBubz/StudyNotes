# Part C Logical Design

## Schema Conversion and Normlisation

## NOTES

1. Logical Design/ Schema Conversion
   - Convert ERD into a set of relational Tables in this format

```md
TableName(<u>Identifyer<ul>, non key attr, fk*)
ForeignKey references OtherTable
```

2. Logical Design/ Normalisation
   1. ID and list Functional FD and state which fd is determined based on which BR/Forms of your case study.
      - Use the format `X -> Y`
      - `Determinant -> Dependent`
   2. Use FD to determine highes normal form for each table/relation in previous part.
      - Also Justify your choice
      - Normalise all table till they are BCNF (or 3rd?)
      - Document each detail of the nomalzation(or 3rd?)
3. Reflecton on your design and Lesson learnt
4. Structure
   1. Revised BR and Assumption
   2. Revised ERD of Part B
   3. Relations
   4. List of FD related to each BR
   5. Normalisation
   6. Reflection

**NOTE** Normalization step by step


---

## Revised Business Rules and Assumption

## Revised ERD **1.5m**

- Add self referencing relationship for ERD

![ERD](./deliveroo/b_erd.PNG)

ChangeNotes:

- Added a 1 mandatory : 1 optional **Unary** realationship for the User. This is to fit the reviesd BR

> Users can refer the Deliveroo service to their friends and families to get a reference discunt on the service

## Relation **4m**

This section contain the converted relation from entities in the ERD.

### Customer

User

> USER(<u>UserID</u>, UserFName, UserLName, UserEmail, UserPassword, RefereeID)
>
> FK(RefereeID) references USER

**NOTE**: reference note

Address

> ADDRESS(<u>AddressID, UserID* </u>, AddrNumber, AddrStreetN, AddrCity, AddrPost, AddrState)
>
> FK (UserID) references User

Payment

> PAYMENT(<u>PaymentID, UserID*</u>)
>
> FK (UserID) references USER

Creditcard

> CREDITCARD(<u> PaymentID*, UserID*</u>, CardNumber, CardHolderName, CardExp, CardSecCode)
>
> FK (UserID) references USER
> 
> FK (PaymentID) references PAYMENT

Paypal

> PAYPAL(<u>PaymentID*, UserID*</u>, PaypalAcc, PaypalToken)
>
> FK (UserID) references User
> 
> FK (PaymentID) references Payment

### Restaurant

Restaurant

> RESTAURANT(<u>RestaurantID</u>, RCuisuneType, RAddrNumber, RStreetName, RPost, RCity, RState, ROwnerFname, ROwnerLName, RContactNo)

Meal

> MEAL (<u> MealID, RestaurantID*</u>, MealName, MealPrice, MealImage, CategoryID)
>
> FK (RestaurantID) references RESTAURANT
> 
> FK (CategoryID) references MeaLCategory

MealCategory

> MealCategory (<u>CategoryID</u>, CategoryName)

Option

> OPTION (<u>OptionID</u>, OptionName, OptionDesc, OptionPrice)

Order-Meal

> ORDERMEAL (<u>OrderID*, MealID* ,ReastaurantID*</u>, Quantity)
>
> FK (OrderID) references ORDER
>
> FK (MealID) references MEAL
>
> FK (RestaurantID) references RESTAURANT

Meal-Option

> MEALOPTION (<u>OrderID*, MealID* ,ReastaurantID*, OptionID</u>)
>
> FK (OrderID) references ORDER
>
> FK (MealID) references MEAL
>
> FK (RestaurantID) references RESTAURAT
>
> FK (OptionID) references OPTION

### Order

Order

> ORDER (<u>OrderID, RestaurantID*, UserID*, OrderDate, OrderTime</u>)
>
> FK (RestaurantID) references RESTAURANT
>
> FK (UserID) references USER
>
> FK (OrderID) references ORDER

Delivery

> DELIVERY (<u>OrderID*, UserID*, </u>, PickupTime, DeliveryTime)
>
> FK (OrderID) references ORDER
>
> FK (UserID) references USER

Promotion

> PROMOTION (<u>PromotionID</u>, PromoCode, PromoStartDate, PromoEndDate, DiscAmount, DiscType).

## List of Functional Dependancies related to BR

## Notmalisation

## Reflection

- **What did you already know about the content and skills that were presented in this lecture?**
  - I was shown how to design an ERD and work with "SeeQUel"(Specificly SQLServer) in TAFE through their programming/ software dev course. So I would say about 70% of the coursework.
  - TAFE shown me how to build a secure DB(atleast against injections) and intergrated it with a MVC webapp. The final project is to build a functional e-commerce site with APIs to get/generate data from the db.
  - This is not a complaint as I understand that this course was made to introduce Db to first year students.
- **What did you learn about the content or skills that were presented in this class?**
  - Using Normalization as an extra step of verifying your db design. Even though it wasnt shown very well ( not the fault of the lecturer and tutor) due to the structure of the course.
  - It took me a while to understand that this is not a following process after completing the ERD but an alternative db design process or a verification method for the existing ERD design.
- **How did doing the assignment change your understanding about this subject?**
  - Not much, I would say that this assessment only provided  more much needed practice for normalization and ERD design.
- **What connections have you made between this subject and other subjects you have taken?**year
  - Not much aside from other subjects such as BRM also using Db in the coursework.
  - This is only my second semester at and so far, I dont think UTS intergrates related subjects very well. e.g big difference in the notation used in BRM and DBFun.
- **What do you suggest for your further improvements in this subject?**
  - A more maths like approach, using different smaller bite size usecase to actually apply and practice what is taught in class (building ERD, normalization).
  - Don't just stick with one case study, have several examples for students to practice the processes of normalisation.
  - I understand using the same Hospital use case is to simulate how DB are developed in the real world, but it is very difficult to understand the process if its not applied to different scenarios, They do not need to be big and intricate use case like the Hospital to achieve this
  - I perfer the approach similar to how the SQL tutes are carried out.