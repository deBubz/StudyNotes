# Linked list is fun

## first/last value should be simple

```java
public int getLast(){
    if(next == null) return thisNumber;
    else return next.getLast();
}
```

## sum and count should be the same

```java
public int getListSize(){
    if(next == null) return 1;
    else return 1 + next.getListSize();
}

public int sum(){
    if(next == null) return thisNumber;
    else return thisNumber + next.sum();
}
```

## Count and replace is the same

```java
public int countElement(int element){
    int count =0;
    if(next != null)
        count = next.countElement(element);

    if(thisNumber == element)
        return 1 + count;
    else return 0 + count;
}

public int replaceAll(int replaceThis, int withThis){
    int count = 0
    if(next != null)
        count = next.replaceAll(replaceAll,withThis);

    if(thisNumber == replaceThis){ 
        thisNumber = withThis;
        return 1+ count;
    }
    else return 0 + count;
}
```

```java
```

```java
```
