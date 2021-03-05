

## programming language 

why `c`

- simple api
- less existing libraries (less bloat but need to implement things from scratch)
- not OO
- efficient in memory usage
  - less instructions
  - access hardware directly such as IO ports

### datatype

> take care of datatypes

- take care of which data type to use
- int can have different size depending on the processor

| Type | size(bit) | Range |
|:---|:---:|:---|
|`signed char` | 8 | -128 to 127 |
|`unsigned char` | 8 | 0 to 255 |
|`signed short` | 16 |  |
|`unsigned short` | 16 |  |
|`signed long` | 32 |  |
|`unsigned long` | 32 |  |
|`signed int` | N |  |
|`unsigned int` | N |  |

> yep you know all this
> 
> int size are N because it depends on the system, 
> commonly 4 byte or 8 byte

- its good to know the rough range of the variable to decide what type is best to use
- conserve space
- embedded often deals with **1bit** items
- `c` dont have 1bit hence char is used in place 
  - `1` and `0`

> we dont use float or double here, due to extra calculation is needed to keep the decimal point

- common practice? to use prefix indicate datatype
- `C` defines the datatypes above as **minimum widths** so compiler wont create long 64bits.
- never assume the exact width
- avoid using `int` due to its unpredictability 

---

## 2's compliment

`signed` twos complement binary
`unsigned` regular binary

> in binary, twos complement for a byte
>
> flip all bits (or + 11111111) then add 1u

- computers cannot subtract
- computers can only add
- 2's compliment allow addition and subtraction

---

## RIMS implicitly defined IO vars

- global vars are common in MCU 
- IO vars are implicitly defined **global** vars
- `A0, A1, ... A7` and `B0, B1, ... B7` each representing a single bit where `A` is the input and `B` is the output
- Theres other 2 global vars `A` and `B` 
```cpp
unsigned char A;  // 8 pin input pins - decimal
unsigned char B;  // 8 pin output pins - decimal
// play around with this, its very flexible
// assigning this will change the pin variables
// vice versa
```
- MISC
  - `B` can be both read and write
  - A is automatically written bu MCU
  - should never be assigned a value should **only read**
  - if `B` is set to value over 255, the output becomes `value - 255`

### c exercises

- [3.1 simple io](./3_1_io.c)
- [3.2 plus 1](./3_2_plus1.c)
- [3.3 overflow](./3_3_overflow.c)
- [3.4 seatbelt](./3_4_airbag.c)

---

## bitwise operations

- & and
- | or
- ^ xor
- ~ not

## bit mask

OH so this is quickly assigning value/ setting the default value regardless of the input

- 0 & is always 0
- 1 | is always 1
- 0 | x is always x
- 1 & x is always x

## shift shift operator

shift bytes left or right by a number of bits

- << left shift
- \>\> right shift