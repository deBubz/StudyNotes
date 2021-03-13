

## time order behavior

- output depends on the order of which output occurs
  - what happens when an input changed
- `c` not designed for time-ordered behavior involving i/o values, it use **sequential instructions computation model**
- good for capturing algos that transform input to output (**data processing behavior**)

```c
// exteded carousel, harder to understand 
// bc sequential instruction model not made dor capturing time behavior
#include "RIMS.h"
void main()
{
    B = 0;
    while(1) {
        while(!A1 && !A0);
        if(A1) B = 0;   // reset count
        else {          // count pulse
            B = B +1;
            While (A0); 
        }
    } 
}
```

---

## state machine 

- computation model for **capturing** time ordered behavior(many types exist)
- common features:
  - set of i/o
  - set of **states** with actions (the circle)
  - set of **transitions** with conditions (arrow lines)
- system described by SM as 
  - at anytime, the system is in a state (**current state**)
  - upon starting, system transition to the initial state and execute the action (**tick**)
- for state machine to be precisely defined, transition should have **mutually exclusive conditions
  - only 1 condition could be true at anytime
  - which state will the system choose if the multiple conditions are true
  - **non deterministic** state machine

---

## Implementing SM in `c`

- since microprocessors have `c` compilers and not SM compulers
  - necessary to implement SM in `c`

example of [latch](./latch.c)
    
![latch](latch.png)

good SM practices
- initializing input in `main`
- include `default` in `switch` even if not needed for safety purposes
  - incase your SM ran into trouble and is stuck in a state

[carousel SM](./carousel.c)

![carousel](./carousel.png)

[light toggle sm](./light_toggle.c)

![light toggle](./light_toggle.png)

---

## Variables, statements and conditions in SMs


