# Week 5

Symmetric - samekey for both encr and decr

## Data Encryption Standard (DES)

Is a block cipher operating on **64-bit block** using **56-bit key** (world most heabily analyzed and used cipher)

NSA's modification to DES were though to adding a backdoor

    - Differenctial Cryptanalysis(DC) discovered by IBM (and used in construction of DES) but IBM was gagged by NSA
    - NSA uses DC to strenghten DES, while no-one know it exists

### Attacks on DES

Exhaustive Key Search

- for any `n-bit` block cipher, `j-bit` key, key can be recovered on avg `2^j-i` operations, given snamm numver (` < (j + 4)/n`) of plain/cipher text pairs
- for `DES`, `n = 64`, `j = 56` exhaustive key search is expected to yield key in `2^55` operations

### 2DES

Double Encryption with `DES(2DES)` uses 2 keys

> `2DES<k1,k2>(m) = E<k1> (E<k2> (m))`

- **ITS BAD**: vulnerable meet-in-the-middle attack with known plaintext
- What does this mean?
  - 2DES can be broken in 2^56, using 2^56 memory slot (tine space tradeoff)
  - Not good when there should be 112-bits (56 + 56) of key

### 3DES

- 2 key 3DES uses DES 3 times using 3 key (112bits)
    > `3DES<k1,k2>(m) = E<k1> (E<k2> (E<k1> (m)))`
- 3 key 3DES uses DES 3 times using 3 keys (112bits)
    > `3DES<k1,k2,k3>(m) = E<k1> (E<k2> (E<k3> (m)))`

### DESX

Modification of DES to avoid exhaustive key search:
> `K1` = 56 bits (DES key)
> `K2` = 64 bits (Whitening Key)
> `K3` = 64 bits hash(`K1`, `K2`)
>
> `DESX<k1, k2, k3>(m) = K3 XOR E<k1> (m XOR K2)`

Whitening key gives greater resilience to bruteforce

---

## **Advanced** Encryption Standard (AES)

A competition was helo to replace DES in 1997, and was named Advanced Encryption Standard

Criteria:

- Strength => 3DES with much better efficiency
- Flexible - can be implemented is software, hardware, smartcards
- Simple and Elegant
- Block cipher: 128-bit block (DES uses 64 bit block)
- 128/ 192/ 256 bit keys
- Royalty free world wide
- Security for 30 years
- May protect sensitive data for over 100 years
- Public confidence in the cipher

### AES Finalist

Rijndael

- operates on 128 bit blocks
- Variable key length: 128, 192, 256
- Its an Substition-Permutation network
- Uses a single S-box which acts on a byte input to give a byte output (256 byte lookup table)
    > `S(x) = M(x^-1) + b over GF(2^8)`
- Where `M` is a redefined matrix, `b` a constant, `GF` is chosen Galios Fels( non lineararity comes from `x -> x^-1)
- Construction gives tight differential and linear bounds

### AES overview - Rounds

Number of rounds a variable

- 10 rounds - 128bit keys
- 12 rounds - 192bit keys
- 14 rounds - 256bit keys

Rounds have 50% margin of safety based on current known attacks.
Potential attacks (which require an enormous number of plaintext/ciphertext pairs) are possible on:

- Only 6 rounds for 128bit keys
- only 7 rounds for 192bit keys
- only 9 rounds for 256bit keys

> Safety against possible attacks believed to currently be apprx 100%

---

## Key Distribution

- **Key Establishment**: process whereby a shared key become available to 2 or more parties for subsequent cryptographic use.
- **Key Management**
  - set of processess and mechanism which support key establishment and the maintenance of on-going key relationship between parties, including older keys with newer ones.
  - **Includes**
    - Key agreemant
    - Key transport

### Key Management

Suppose we have a symmetric key network where `A`, `B`, `C` and `D`(4 parties) wants to talk to each other.
For secre comms with `n` parties, we require

`(n(n-1)) / 2` keys

Keys Distribution and management becomes a major issue

### Key Distribution Center(KDC) Naive

- `A` -> `KDC`
  - wants to talk to `B`
- `KDC` -> `A`
  - `KDC` choose random `K<ab>`
  - return `E<ka> (K<ab>)`, `E<kb>(K<ab>, "for talking to alice")`
- `A` decrypt `E<ka> (K<ab>)` to get `K<ab>`
- `A` to `B`
  - `E<kb>(K<ab>, "for talking to Alice")`
- `B` decrypts using `K<b>` to get `K<ab>`
- `A` and `B` now share `K<ab>`

> **Problems**
>
> - Key Distribution Center is a single point of failure(single point of  Attack
> - No Auth
> - Poor scalability (DOS)
> - Slow

### Merkle's Puzzle

**Merkle's puzzles** are a way of doing key exchange between `A` and `B` without the need fo a third party.

`A` creates `N` puzzle `P1`, `P2`... `Pn` of the form `Pi = E<pi>("this puzzle #Xi" , Ki)`

  - `N approx 200`
  - `|Pi|` approx `20bit` (weak)
  - `|ki|` approx `128bit` (strong)
  - `Xi`, `Pi`, and `Ki` are chosen randomly and different for each `i`

`A` sends all puzzle to `B`: `P1`, `P2`, ... `Pn`

`B` chooses a random puzzle `Pj` for some `j` in `{1, 2, .., N}`

- finds `pj` by brute force ( key space search)
- recovers `kj` and `Xk`
- `B` sends `Xj` to `A` unencrypted

`A` looks up the index of `Xj` to find the key `kj` chosen by `B`

`A` and `B` both share key `Kj`

#### Attacking Merkle's Puzzle

On avrg `E` must break half of the puzzle to find which contains `Xj` (and hence obtain `Kj`)

> for `2^20` puzzles, `E` must try `2^19` on average

Each puzzle is encrypted with the `20bit` key `pi`, `E` must stearch, on avg, half of the key space:

> `2^19 . 2^19 x 2^19 = 2^38

So IF `A` and `B` can try 10k keys / sec

- It`ll take about 1 min for each to perform their steps
  - `A` to generate, `B` to break `pj = 2^19` keys
- Plus another min to communicate all the puzzle over ADSL

With comparable resources, it'll take `E` about a year to break

**NOTE** Merkle's puzzle use lots of bandwidth - impractical

### Diffie Hellman Key Exchange

DH key exchange is a protocol for extablishing a cryptographic key using mathematical tricks. Its a worldwide standard for use in SSL, smartcards, etc..

Rough idea

- `A` and `B` agree on some num `g`
- `A` generates a random num `a` sends `g^a` to `B`
- `B` generates a random num `b` and sends `g^b`to `A`
- `A` and `B` can each compute `g^ab`, their shared secret

An evesdropper only has `g^a`, `g^b` and `g`. Assuming that calculating logarithms is hard, cannot recover `a` or `b`
