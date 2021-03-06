

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

## Hex

- better to write binary or hex rather than int value
- 0-255 doesnt clearly show intent, should write `B = b11111111`
- but `c` doesnt support binary, it supports **hexidecimal**
- Base 16 number with the range `[0-9A-F]` (4 bit).

in `c`
- hex constant preceed by `0x`
  - `1111 1111` == `0xFF`
  - `1010 1010` == `0XAA`

> hex can give a better desired bit pattern

### hex exercises

- [4.2 hex](./4_3_hex.c)
- [4.4 more hex](./4_4_more_hex.c)
- [4.6 7segment system](./4_6_segment.c)

---

## bitwise operations

similar to logical operators
- & and
- | or
- ^ xor - exactly one
- ~ not

### bit mask

- Masks are constant pattern of 0/1

OH so this is setting the default value regardless of the input

- 0 & is always 0
- 1 | is always 1
- 0 | x is always x
- 1 & x is always x

```c
B = A | 0x01; // Sets B to A, except forces B0 to 1
B = A | 0x04; // Sets B to A, except forces B2 to 1
B = A & 0xF7; // Sets B to A, except that B3 is cleared to 0
B = A | 0xF0; // Sets B7..B4 to 1111, and B3..B0 to A3..A0
B = A & 0x0F; // Sets B7..B4 to 0000, and B3..B0 to A3..A0 
B = B | 0x0F; // Keeps B7..B4 the same, forces B3..B0 to 1s
B = B & 0xF0; // Keeps B7..B4 the same, forces B3..B0 to 0s
```

> avoid using bitwise operations on single bit var

- [5_5 mask and bitwise operators](./5_5_bit_mask.c)

## shift shift operator

shift bytes left or right by a number of bits

- << left shift
- \>\> right shift

```c
B = A << 1;  // Sets B7 to A6, B6 to A5, ..., B1 to A0, and B0 to 0 
B = A >> 4;  // Sets B7..B4 to 0000, and B3..B0 to A7..A4
B = B << 1;  // Sets B7 to B6, B6 to B5, ..., and B0 to 0
```

4 bit addition using shift
```c
#include "RIMS.h"

void main()
{
  unsigned char sound1 = 0;
  unsigned char sound2 = 0;

  while (1) { 
    sound1 = A & 0x0F; // 0000A3A2A1A0
    sound2 = A >> 4;   // A7A6A5A4A3A2A1A0 --> 0000A7A6A5A4

    // splitting each half then add
    B = sound1 + sound2;
  }
}
```

> be careful of loosing data when shifting bits

- [6_2_shifting](./6_2_shiftng.c)
- [6_3_parkinglot](./6_3_parkinglot.c)

---

## Bit access functions

Return a value where `Kth` bit is of an `unsigned char x` is 0
```c
x | (0x01 << k)
// shift 1 into K position
// or to guarantee it to be always 1
```

function setting bit to a value
```c
// x: 8-bit value
// k: bit position to set, range is 0-7
// b: set bit to this, either 1 or 0
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
  return (b ?  (x | (0x01 << k))  :  (x & ~(0x01 << k)) );
}
```

function return bit at a position
```c
unsigned char GetBit(unsigned char x, unsigned char k) {
  return ((x & (0x01 << k)) != 0)
}
```

- useful for the parking lot question incase each pin is not assigned to an individual Variable - **rewrite code later**

> `inline` keyword
> - tell the compiler to replace the function to where it is called
> - default by most compiler optimizations

---

## Rounding, overflow

rounding
- be careful using expressions with integer divisions, fractions are truncated
- problem can be partially addressed by doing division as late as possible

overflow
- opposite of rounding
- the way to address overflow is to divide earlier
  > what
- another way is temporarily cast it to a larger type



