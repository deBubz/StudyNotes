# Part A

## Case Study

Food Delivery Service **Deliveroo** can be accessed either on **deliveroo.com.au** or on their iOs/Android app counterpart. Through their service, customers can order food from nearby participating restaurants to order food to be delivered to them

- after signing up you can browes a selection of restaurants nearby (using the location tracking from the phone) after entering your address in the website (if there is no address presented)
> img - of login/create new form
> 
> img - address form
> 
> img - restaurant selection

- the site will display a selection of restaurants in the area. can be sorted by the type of food, and special offers if there are any
- after selecting the restaurant, customers then can select pick meals offered by the restaurants to be added to the basket.
- after selecting a meal, some meals also provide some additional options that the customers can add into that specific meal to their liking.
- can only order from one restaurant per basket (BR?), if customers want more food from another restaurant, a different order has to be made for the additional restaurant. Any selected option will also be displayed in the basket/order

> optional selection menu

- in Checkout, Customer can then finally review their basket choices, delivery address, payment method, add promocodes. Any of these details can be modified if anything is wrong.

> img - checkout screen
>
> img - change address in checkout
>
> img -change payment in checkout

- comfirm purchase, wait for delivery, the service will also display the status of your order, show that is it being prepped/pickedup/ provide a map for the gps location of the delivery

## Database functions

- account function: check if email exist? ask for password : create new
- Account can also login using fb/googleplay //` may not use this`
- should allow users to store multiple addresses and payment details.
- should store/ read customer's past orders to speed up the customer's order selection if they want the same meal again.
- Should show more db functions

## Data Requirements

User: store user data

Address: user address

Payment-Methods: user payment method

Orders: pending order/ past order

Meals: Meals in a restaurant

Restaurant: restaurant details, should convert this to 

> **NOTE** draw this out, add some attribute names

## Business Rules

write everything out, eliminate/refine

- User BR
  - Users should be able to store multiple payment methods & delivery address
  - Login function (unique email)
- Menu BR
  - Query restaurants by distance
  - query restaurants by cusine type
  - query restaurants by special deals
- Restaurant BR
  - meals should be speparated into categories
  - users should be able to customise their meals
- Ordering BR
  - Each order should only contain meals from 1 restaurant.
  - users should be able to view & edit details such as delivery address & payment method before confirming the order.
  - users should be able to add promotional code to orders
- CartBR
  - Users should be able to order multiple meals per order. (shopping cart)
  - Users should be able to view and edit their cart.

---

Prep

1. Overview
2. DatabaseFunction
   - indexing functionality for rebtal locations/airlines
   - find vehicles at location > filter by features/class
   - find existing emails f users/prevent duplicated users. Email/password
   - calculate total prices of additional charges & car rental rates.
   - total rent cost using the users selection of car, period, options + charges
3. DataRequirements
   - list entities: attributes
   - briefly describe some entities
   - > define what data is stored
4. Business Rules

---
## Time stuff

1.45 analyse mode
2.00 one by one
3.00 prep
3.50 train
5:00 class