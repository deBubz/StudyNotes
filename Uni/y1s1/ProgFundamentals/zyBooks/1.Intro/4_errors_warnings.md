# Errors and Warnings

## Syntax Errors

Simple human arroes such as spelling mistakes or missing symbols can cause __Syntax Errors__.

The Compiler will generate an error message when encountering syntax error.

#### Missing semi-collon
```
Traffic.java:4: ';' expected
      System.out.print("Traffic today")
                                       ^
1 error
```

---

## Unclear Error Mesagges

Compiler error messages are sometimes unclear and misleading. Its the compiler`s "best guess" of what is wrong.

The error message sometimes refer to a line that may past many line after the error message occured. The programmer should look more carefully at the previous lines.

---

## Fixing Errors

Some errors can produce a long list of complicated errors. 

So the _best practice_ is to fix the __First__ error and then re-compile the program. The remaining errors could be real, but it is common that its caused by the first error.

---

## Logic Error

These are errors that might not be detected by the compiler. It is more in the line of error in the code, while the program runs or its not as intended.

---

## Compile frequently

It is __Good Practice__ to compile frequently after several statements so it is easier to fix bugs.
