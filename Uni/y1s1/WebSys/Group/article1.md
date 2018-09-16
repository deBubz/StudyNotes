# Main Characteristics of OOP

## Medium article
According to [the artivle](https://medium.freecodecamp.org/object-oriented-programming-concepts-21bb035f7260), 4 main principle of oop are:

---

## Object Oriented OOP

- Object Oriented Programming Is a programming paradigm that involves "objects"

- So what are objects in OOP, To first understand objects we need to know what classes are. 

### Class

- Basic building blocks of OOP you can think that they are __blue prints__. Classes usually contain Fields (which are data/information that the object carry), Constructors(used to initialze an object) and Methods(or functions - actions which the object can do )
- For example in this c# code:

```csharp
public class Cat { // the keyword class is to tell the compiler its a Class youre making
    private string name;    // these are the fields; they store the data of the class when.
    private int age;        // an object of this class is created
    private string owner;

    public Cat() {}
    public Cat(string cName, int cAge, string cOwner){
        this.name = cName;      // this is a constructor and its used when initializing( creating) an object
        this.age = cAge;        // its to assign data into the fields.
        this.owner =cOwner;
    }   

    public void GetOlder(){     // this is a method
        this.age++;             // as you can see when this method is called(used)
    }                           // it will increase the cat's age by 1.
}

```

### Object

---
 ### Encapsulation

- __Encapsulation__:
  - This is achieved when obj keep its data/variables `private` and in-accessable by other objects and classess unless it is specified to be "public".

  ```csharp
  // look at the graph and its the desciptions
  public class Cat{
      private int mood;
      private int hungry;
      private int energy;
      // These uphere are the fields(variables) of the class Cat
      // using the private keyword, these variables can only be accessed/modified by the class it self
      // not by any other external classes.
      private void Meow(){
          Console.print("Meow!!");
      };
      // same with this method(function) it cannot be used by other classes outside of this object.

      public void Sleep(){
          engergy++;
          hungry++;
      }
      // this method however has a public access modifyer, there for it can be accessed by other classes
      // also look at what this method does. the ++ sign means to increase the value of the variable by 1
      // even though these 2 variables are declared private in class Cat.
      // it can be modified by the method Sleep in the SAME class.
  }
  ```

- __Abstraction__:
  - Can be thought as an extension of encapsulation, and is used to simplify big projects.
    - something something
- __Inheritance__:
  - Used to reuse logic, reducing repetition.
  - when
  - Child class can use method from its parents class.
- __Polymorphism__:
    - Extension of Inheritance.
    - Allow child classes to reuse and modify methods from the parent class.

__NOTE__: how to explain this to non programmers. Need to define __Classes__ and __objects__.
