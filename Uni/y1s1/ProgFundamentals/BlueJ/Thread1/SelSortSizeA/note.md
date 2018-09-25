# Select Sort Size A

- NOTE: check the methods
- look at the requirements
- check error messages

```java
public static void selSort04(int [] a)
{
    MinMax minmax = new MinMax();

    for(int i = 1 ; i < a.length; i++)
        {
            int minPos = minmax.minPosition(a, i-1, 3);
            swapPositions(a, i-1,minPos);
        }
}
```
