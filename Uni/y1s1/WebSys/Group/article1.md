# Main Characteristics of OOP

## Medium article
According to [the artivle](https://medium.freecodecamp.org/object-oriented-programming-concepts-21bb035f7260), 4 main principle of oop are:

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
