# r0 code planning

## feature focuses

> somewhat ordered by my perceived difficulty 

1. Owner account management
   - just cause I haven't figgure out Auth
2. Kennel Management (main bulk of work)
3. Dog Management - simple CRUD 
4. Date Management - simple CRUD? (kinda not sure how this will work)
5. Gift Management - simple CRUD
6. Security management

## wireframes

this is currently based on my understanding of the app.
pls have a look and comment on it

> add the doc here

> maybe also use this to plan out the route names

landing page (auth/ no auth)
sign in (auth)

acc management (auth)
update account details (auth)
    dog management
        add dog
        remove dog
    payment management
        add payment
        remove payment

kennel
dates (show upcomming dates/ popup to redirect to kennel if no dates)
    

## Tech stuff

MVC

view React (material-ui)
controller Express (rest api + stuff)
model MongoDB (mongoose)

auth with JWT or context api (stay away from redux)


ci/cd CodeShip, Github Actions, Gitlab, Heroku (pick 1?)

testing using Jest, react-testing-library

build with webpack

## dev branchs

master - deployment branch
https://stackoverflow.com/questions/38864405/how-to-restrict-access-to-master-branch-on-git


dev - development branch

either
feat/{feature name}

---

# Task

## DevOps pipeline platform 

### GitLab

> can self host

https://youtu.be/gxWS0Tmvo-4

- pipeline jobs are defined in yaml (could also be used in github actions)
- the logging looks nice


### Jenkins

> can self host

- ran using 
- theres its own documentation/syntax to go through and learn
- but syntax seems very similar to yaml so this shouldnt be a problem

### codeship

lets play with this a bit

### Gitlab Actions

### Heroku