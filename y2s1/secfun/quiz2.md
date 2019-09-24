# Quiz 2 notes

## Week 5

### Digital Encryption Standard (DES)

- Block cipher operating on 64-b block using 56-b key
- **2DES** 2 keys, run DES twice with 2 different keys
- **3DES** 2 keys, run DES 3 times, first(key 1), seccond(key 2), third (key 1)
- **3DES** 3 keys, run DES 3 times, first(key 1), seccond(key 2), third (key 3)

> 2DES 2 key `2DES<k1,k2>(m) = E<k1> (E<k2> (m))`
>
> 3DES 2 key `3DES<k1,k2>(m) = E<k1> (E<k2> (E<k1> (m)))`
>
> 3DES 3 key `3DES<k1,k2,k3>(m) = E<k1> (E<k2> (E<k3> (m)))`

Breakable with exhaustive Key search in `2^n-1` where `n` is the keylength.

- DES - broken in `2^55` (Exhaustive)
- 2DES - broken in `n^56` (meet-in-the-middle) while supposedly should be 2^112
- 3DES broken  in `n^112` (meet in the middle)

#### DESX

Modification of **DES** to avoid exhaustive key search, where the *whitening key* gives better resilience to bruteforce

> `K1` = 56 bits (DES key)
>
> `K2` = 64 bits (Whitening Key)
>
> `K3` = 64 bits hash(`K1`, `K2`)
>
> `DESX<k1, k2, k3>(m) = K3 XOR E<k1> (m XOR K2)`

### Advanced Encryptoin Standard (AES)

Replacement encryption standard for DES. Which contains the properties

- Strength => 3DES with much better efficiency
- Flexible (implementable in software, hardware, smartcards)
- Simple and Elegant
- Block cipher: 128-bit block (DES uses 64 bit block)
- variable key length (128, 192, 256 bit)
- Royalty free world wide
- Security for 30 years

#### Rijndael (selected AES)

- operates on 128 bit block
- variable key length (128, 192, 256 bit)
- Substitution-permutation network
- Encryption rounds variable according to key length
  - **10** rounds - 128-b keys
  - **12** rounds - 192-b keys
  - **14** rounds - 256-b keys
  - potential attack (50% chance) in 50% number of rounds

### Key Distribution

- **Key Establishment**
- **key Management**

#### KDC

### Merkle's Puzzle

---

## Week 6

### Symmetric

### Asymetric

### Diffie-Helman key Exchange

### RSA

### Symmetric & Asymmetric Exchange

---


## Week 7

### Authentication

### Passwords

### Password Salt

### Password Hashing

### One Time Password

### ZKP

### Naive HTTP

---

## Week 8

### Digital Signature

### DSA

### SSL/TSL

### Certificate Authenticator

### Online Certification Status Protocol


