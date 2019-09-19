# Collision

- [Collision](#collision)
  - [Requirement Notes](#requirement-notes)
  - [Compile/run](#compilerun)
  - [Method](#method)
  - [main()](#main)
  - [TODO](#todo)

Finding 2 disctinct input which have the same output, without any predefined constraint on the input

## Requirement Notes

General approach:

1. Generate array for initial hash value
2. Generate initial message `M`
3. Generate `M'` hash
4. Generate random string `S` and `S'` hash
5. Compare `S'` and `M'` if match found, return number of iterations used
6. No match found save `S'` into array and go return to step 4.

To break the collision free property(hashing method is not collision free), find 2 different msg with the same hash value.
Matching generated hash with initial hash and past generated hash increaonewayse the chance of finding hash value with less number of itterations.

## Compile/run

`gcc -o collision collision.c -lcrypto -ldl -std=c99`

`./collision md5`

## Method

```c
// same in oneway.c
void gen_random (char *s, const int len)
```

```c
// same in oneway.c
int match_digest (char *hash1, char *hash2, int len)
```

```c
// same in oneway.c
void generate_digest(char *mess, char *mess_hash, int len, char *digest_method)

```

```c
void save_to_repo(unsigned char repo[] [3], char repo_msg[] [7], int *repo_index, char *msg, unsigned char * hash)
    // repo[]: hash repo
    // repo_msg[]: message repo
    // repo_index: current count of stored hasm/msg to be increased by 1
    // msg: msg to store in repo_msg[]
    // hash: hash to store in repo[]
```

```c
// Matches the hash with repo
// return index if match, -1 no match
int match_repo (unsigned char repo[] [3], const int repo_index , unsigned char *hash)
    // repo[]: hash repo to look in
    // repo_index: numver of stored hash strings in repo, used in the for loop
    // hash: hash to compare with
```

## main()

1. init variables

    ```c
    int i, match, c, length, j;
    char ch;

    int curr_length = 0, inc_len=1;
    char *hash_algo = argv[1];
    char *mess = NULL;
    char *rand_str = NULL;
    unsigned char mess_hash[3];
    unsigned char rand_hash[3];
    ```

2. generate hash repo `repo[10000][3]` multidimentional array(2d). Array with the size of 10000 storing Arrays size 3
3. generate message repo `repo_msg[10000][7]`
4. `srand(time(NULL))` see oneway.c step 3
5. generate initial message `mess` using `gen_random()`
6. generate hash of `mess` using `generate_digest()` storing the `3` byte long hash in `mess_hash` using the hashing method `hash_algo`(md5)
7. STARTING do this `10000` times or untill a match is found
   1. generate `6` bytes long `rand_str` with `gen_random()`
   2. generate hash from `rand_str`
   3. compare with **initial** and assign result to `match` (possible values: 1 and 0)
   4. if `match == 1` when match found
      - **Implement this**
      - print **initial** string and **generated** string
      - print hash value of generated string in hexadecimal format
      - print number of itteration `printf("dis was ran %d times", j);`
   5. change `match` back to -1
   6. compare with stored hash in `repo` and return index of the matching hash if found
   7. if `match >= 0` when match found (the only case when `match < 0` is when match is not found)
      - **Implement this**
      - print **generated** string and the **stored** string
      - print value of generated string in hex format
      - print number of itteration `printf("dis was ran %d times", j);`
   8. else (`match` is -1)
      - `save_to_repo()` is called, saving generated message and hash into their respective repo.
      - repeat from `7. STARTING`



## TODO

- `match == 1`
- `match >= 0`