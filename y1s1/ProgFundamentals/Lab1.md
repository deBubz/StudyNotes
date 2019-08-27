# Lab 1

Worksheet 4 Extra

```java
//bubble sort

int n, temp;
int Arr[] = new int[n];
boolean switch = false;

for(i=0; i < Arr.length() ; i++)
{
    for( x = 0; x < Arr.length()-i; x++)
    {
        if(Arr[i+1] >= Arr[i])
        { // swap if 2nd value smaller than 1st
            temp = Arr[i];
            Arr[i] = Arr[i+1];
            Arr[i+1] = temp;

            }
        }

} 
// >> Array will be sorted in ascending order



//Can be faster a bool switch if i remember correcly
```
