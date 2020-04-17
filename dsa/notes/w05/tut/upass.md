# upass week 5

2 task covering some assessment stuff

---

## task 1

describe divide and conquor

Binary search, merge sort, quick sort

## Task 2

1. search unorderd list (linear), assuming the list is an array

```java
// iterative
boolean linear_search(int[] arr, int find) {
    for( int i = 0; i < arr.length; i++ ){
        if(arr[i] == find) return true;
    }
    return false;
}
```

```java
// recursion
boolean liner_search(int[] arr, int find) {
    return linear_search(arr, find, 0, false);
}

boolean liner_search(int[] arr, int find, int index, boolean status) {
    if(status){     // not found
        if(arr[index] == find) return true;
        else if(index => arr.length) {  // index passed the length of 
            return false;
        }
        else {
            return liner_search(arr, find, ++index, status); 
            // still false 
        }
    }
    return true;
}
```

2. factorial value of an interger

```java
int factorial(int n){   // iterative
    int ans = n
    for( int i = n-1; i > 0; i--; ) ans *= i;
    return ans;
}
```

```java 
int factorial( int n ) {    // recursive
    if( n = 1 ) return 1;
    else if (n < 1) return -1; 
    else return factorial(n-1) * n ;
}
```



