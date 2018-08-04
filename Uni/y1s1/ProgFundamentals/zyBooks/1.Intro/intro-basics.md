# Hello

## Generic Intro to Programming

Computer programs contain specific instructions executing one at a time.

Basic instruction types:

- __Input__ gets data
- __Process__ process data
- __Output__ returns data

Program refer to data as __Variables__

```java
//variables
int a = 3;
String b = "Hello";
```

Picture a cooking recipe, it is similar to how a program is structured. The _Ingredient list_ are __Variables.__ The _step by step instructions_ are __Commands__.

__Algorithm__ Set of computational instructions to solve a problem.

---

## First program

A simple Java Program  below have:

- Program starts in the __main()__ method, executing statesments within the `Braces { }`.
- Each statement has to end with a `semi-colon ;`.
- __int wage__ creates a integer variable and assigned with 20.
- __print__ and __println__ output string values.

```java
public class Salary
{
   public static void main (String [] args)
   {
       int wage = 10; //variable
       System.out.print("Salary is ");System.out.println(wage * 40 * 50);
   }
}
```

---

## Basic Input

You can use the `Scanner` package to get input from the keyboard in Java.

So steps:

1. Import the package with.
    - `import java.util.Scanner`
2. Create a Scanner object to use it.
    - `Scanner scanner = new Scanner(System.in);`
3. Use the `nextInt()` method to get and assign the int to `wage`.
    -`wage = scanner.nextInt();`l

```java
import java.util.Scanner;

public class Salary {
    public static void main(String[] args) {
        int wage;

        //create scanner obj
        Scanner scanner = new Scanner(System.in);
        //asign int input to wage
        wage = scanner.nextInt();

        // blah blah output
    }
}
```

---

## Basic Output: Text

Use `System.out.print("text");` or `System.out.println(variable)` to print out variables.
Text in `double quotes " "` is known as __string literal.__

__NOTE__: `println()` starts a newline after output

```java
public class Print{
    public static void main(String[] args){
        System.out.print("Hello");
        System.out.print("World");
    }
}
// HelloWorld
```

```java
public class PrintLine{
    public static void main(String[] args){
        System.out.println("Hello");
        System.out.println("World");
    }
}
/*
Hello
World
*/
```
