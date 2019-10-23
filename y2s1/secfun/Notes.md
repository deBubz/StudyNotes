# Generic Exam stuff

---

## Week 1

### Aspect of Security(CIA triad)

- **Confidentiality** only the authorized have access
- **Integrity** protect from intentional/accidental data changes
- **Availability** data/system is available when needed
- **Authenticity** proof of a message's origin
- **Non-Repidition**  assured someone cant deny the validity of something
- **Convertness** messace existence secrecy (anonimity)

### Key figgures in sec

- **Cryptography** study of mathematical techniues related to the design of ciphers
- **Encryption** converting original message to an unreadable form
- **Cryptanalysis** Study of breaking ciphers
- **Cryptology** Study of  both cryptography and Cryptanalysis

### Types of Cryptography

- **Classical crypto**
  - Symmetric (same key to encrypt/decrypt)
  - Product Ciphiphers (Transposition, substitution ciphers)
- **Public Key crypto**
  - Asymetric (2 keys, public to encrypt, private to decrypt)
  - must be difficult to derrive the private from the public
  - must be difficult to derrive private keys from chosen plaintext attck ()
- **Cryptographic checksum**
  - hash functions (hmac): mostly used to verify the integrity of information transfered over the net

### Attacks

- Passive: traffic analysis, gaining access to unauthorized assets, release message content
- Active: fabrication, interuption, modification

#### How

- Mathematical
- Statistical: make calculated guesses from what is avaliable
- Methods
  - Brute force
  - Exploitation

---

## Week 2

- Divisibles
- GCD
- Modular Arimethics
- Multiplicative groups
- Eulers phi

---

## Week 3 hash and basic cphers

### Functions (properties)

- `f(x) = y`, `x` is the preimage of `y` for
- the preimage of `y` is expressed as `f^-1({y})`

### Oneway Functions

- Easy to compute `f(x) = y` but hard to find the preimage (`x` given `y`)
- used in **Data Encryption Standard** (DES) `DES(m, k) = c`
  - `m` message, `k` key, `c` cipher

### Hash Functions

- Hash func maps a string of any length to a shorter fixed length string
- used to confirm knowledge without revealing what you know (compares the hash of the secret)
- used to store passwords(with/without salt)
- Some Hash func also uses a key
  - `MAC(h , k)`
  - **MAC** Message Authentication codes
  - **HMAC** Hashed-based Message Authentication codes
- **Props** of hash funcs
  - Preimage resistance: in `f(x) = y` given `y` its hard to find `x`
  - Second preimage resistance: given `x` its hard to find `x'` (not same) such `h(x) = h(x') = y`
  - Collision resistance: hard to find any pair of `x` and `x'` (not the same) such `h(x) = h(x')`
- **One-way hash** has preimage resistance, second preimage resistance
- **Collision resistant** hash is collirion resistant (also has second preimage resistance)

### Attacks on hash

- Bruteforcing, specificly Dictionary attack
- usually attacks preimage resistance

### Detailed Hash functions

- Iterated Hash Func (sl 19) after hashing a block, the resul is used as the `IV` for the next block
  - inclides `MD5`, `SHA-1`

### Keyed hash Func(MAC)

- **MACs** are oneway hash functions using an additional secret key
  - provides message authentication where sender/reciever shares a secret
  - used for integrity, `E` cannot fake a message with a valid **MAC**
- **HMAC** Mac based on non-keyed hash func `h`
- **CBC-MAC** Cipher Block chaining MAC - `sl26`
  - turns message into blocks and repeat using a blockcipher is `XORed`
  - some cbc includes `Blowfish`, `DES`, `3DES`, `MD4`, `MD5`, `SHA-1`

### Ciphers

- Substitution cipher: replace characters in a certain way
  - **Caesar cipher**: each letter shifted by 3 (mod 26)
  - easily broken with frequency analysis
- Homophonic cipher: extension of substitution which target/replace a comon letter with miltiple different chars
  - `e` would substitue with any of `[a, 2, 7, 8, c]`
- Vigenere cipher: `plain + keystream` mod `26`

---

## Week 4 PRNG and BlockCipher

- good source of RNG is essential in cryptography(session keys, nonce, shuffling, challanges)
- PseudoRNG generate what appears random
- CryptographicallySecure PRNG are types of PRNG with props that makes it suitable for crypto
- **Entropy** or **randomness** measure of randomness which is used as the **seed** to generate random numberk
  - sourced from userinput, thermal noise of hd, voltage reading, cpu clock...

### PRNG

- Desireable props
  - repeatability
  - statistical randomness
  - long period/cycle
  - insensitive to seeds
- broken by
  - statistical test to find patterns
  - infering the state of internal registers from the output sequenceo

### PRNG: linear congruential generators

### PRNG: linear feedback shift registers

---

## Week 5

---

## Week 6

---

## Week 7

---

## Week 8
