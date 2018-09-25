# Summer OO if

Straight forward Class, have a look carefullly at the whole structure.

__Especially__ the constructor and its requirements

2 If loops to check min max value in the first method

## Constructor

```java
public SummerOOif(int firstNumber)
{
    this.sum = firstNumber;
    this.maximum = firstNumber;
    this.minimum = firstNumber;
    this.count = 1;
}   // const add first number and set it as both max and min value
```

## IfLoops

```java
public void putNumber(int newNumber)
{
    sum = sum + newNumber;
    count = count + 1;
    if(newNumber > this.maximum) // max check
    {
        this.maximum = newNumber;
    }
    if(newNumber > this.maximum) // min check
    {
        this.maximum = newNumber;
    }
}
```
