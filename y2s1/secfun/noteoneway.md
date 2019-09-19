# OneWay

- [OneWay](#oneway)
  - [Requirement Notes](#requirement-notes)
  - [Compile/run](#compilerun)
  - [MethodsList](#methodslist)
  - [main method flow](#main-method-flow)
  - [TODO](#todo)

Given a function output, you cannot matching input unless trying many and getting lucky

## Requirement Notes

**OBJ**  hit a target hash value by generating the hash for all possible combinations of different strings and matching it with the target hash value. General approach

1. Start with string length 1
2. Generates all possible combinations of strings for current length using the characterset, generate hash and compare it with target hash
3. If Match, stop execution and return number of itterations
4. No Match for current string length, increase by one and go step `(2)`

The method generates strings ina systematic manner

## Compile/run

`gcc -o oneway oneway.c -lcrypto -ldl -std=c99`

`./oneway md5`

## MethodsList

```c
// generate random string of length
void gen_random(char *s, const int len)
    // char *s  where the random string is stored
    // int len  byte length of the random string
```

Ignore `gen_str()`

```c
// generate next string of length len int str
// return 0 ok, 1 end of string set for length len
int gen_str (int len, char *str)

// check whether last string for length n
int check_last(char *str, int len)

// raise as *ch will never be z
void raise (char *ch)
```

Ignore `generate_digest()`
```c
// generate digest for the message mess using hash algo digest_method
// saves the first len bytes in mess_hash
void generate_digest (char *mess, char *mess_hash, int len, char *digest_method)
    // mess: string message to be hashed
    // mess_hash: stored hased string
    // len: byte length of mess hash
    // digest_method: hashing method - see how to run assesment requirement
```

```c
// compare the first n bytes between hash1 and hash2
int match_digest (char *hash1, char *hash2, int len)
    // hash1, hash2: 2 char[] to be compares
    // count of bytes to be compared
```

## main method flow

Assuming your code is not edited yet

1. init variables

   ```c
   int i, count, match, c;
   char ch;
   int curr_length = 0; inc_len = 1;

   // pointers
   char *hash_algo = NULL;
   char *mess = NULL;
   char rand_str = NULL;

   unsigned char mess_hash[3];
   unsigned char rand_hash[3];
   ```

2. pick hash_algo `md5` from input. See how the program is run on the assessment requirement.
3. `srand(time(NULL))` start RNG using the CPU speed time as seed, doesnt return anything??
4. alocate 7bytes for `mess`
5. `gen_random(mess, 6)`, generate random string `mess` length `6`
6. generate hash `generate_digest()`
7. starting generate strings to bruteforce the hash `while(1)` loop will keep running till a match is found
8. Initializing random string starting with length 1
9. `get_str(len, string)` get next string with len bytes
10. find hash of generated string `generate_digest()` to check
11. check 2 hash if match `match_digest`
12. if matched break `while()` loop and end, if not repeat 9-11 untill match found
13. result is printed

NOTE: should run this several times and get average

## TODO

- match_digest(hash1, hash2, len)
- gen_random(s, len)