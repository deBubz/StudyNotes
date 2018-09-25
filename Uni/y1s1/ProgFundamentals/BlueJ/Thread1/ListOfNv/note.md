# list of NV

The same as ListOf 4v2 but use an Array with undefined length instea

Watchout for minPos()
```java
public int minPos()
{
    int mostWantedHolder = 0; // hold index
    for(int i = 1; i < list.length; i++)
    {
        if(list[mostWantedHolder] > list[i]) // if current index( 0 at default) is larger => change Index
        {
            mostWantedHolder = i;
        }
    }
    return mostWantedHolder;
} 
```
