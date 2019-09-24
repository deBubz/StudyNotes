# Week 6

- [Week 6](#week-6)
  - [Asymetric-Key Cryptography](#asymetric-key-cryptography)
    - [Public Key Cryptography](#public-key-cryptography)
    - [Asymetric Cipher](#asymetric-cipher)
    - [Why Asymmetric Key](#why-asymmetric-key)
  - [Diffie-Hellman Key Exchange](#diffie-hellman-key-exchange)
    - [Paint Analogy](#paint-analogy)
    - [Hardness of Diffie-Hellman](#hardness-of-diffie-hellman)
    - [Attacks on the Discrete Log Problem](#attacks-on-the-discrete-log-problem)
    - [Selecting g and p for Diffie-Hellman](#selecting-g-and-p-for-diffie-hellman)
    - [Strength of DH](#strength-of-dh)
  - [RSA](#rsa)
    - [Operation](#operation)
    - [RSA Example](#rsa-example)
    - [Security of RSA](#security-of-rsa)
      - [Core Security](#core-security)
    - [Not proven to be "hard"](#not-proven-to-be-%22hard%22)
    - [Factoring Attack](#factoring-attack)
    - [size of Modulus](#size-of-modulus)
  - [Symmetric v Asymmetric](#symmetric-v-asymmetric)
    - [Summary Symmetric Crypto](#summary-symmetric-crypto)
    - [Summary Asymmetric Crypto](#summary-asymmetric-crypto)
  - [Combinding Crypto System](#combinding-crypto-system)
    - [symetric Crypto: Key Length](#symetric-crypto-key-length)
    - [Interesting ways to break symmetric ciphers](#interesting-ways-to-break-symmetric-ciphers)
    - [Asymetric Crypto Key length](#asymetric-crypto-key-length)

## Asymetric-Key Cryptography

- Both **Symmetric** and **Asymmetric** key crypto will exist in parallel and continue to serve the community.
- They complement eaach other: advantage of one can compenstate for the disadvantage of the other
- **Assymetric** key crypto uses 2 seperate keys: Private and public
    > Cipher = `f(K<public>, plain)`
    >
    > plaun = `g(K<private>, cipher)`

### Public Key Cryptography

- public key crypto is a fundamentally/ widely used tech. It is used in many cryprographic alg and cryptosystem.
- Each user has a pair of Cryptograrphic keys: **Public** and **Private**. **Private** is kept secret, **public** maybe widely distributted.
- Messages are encypted with the recipient **public** key, can only be decrypted with correspongind **private** key.
- Keys are related mathematically, but **private** key cannot be easily derrived from the **public** key

### Asymetric Cipher

Also known as public key? and is more computationally intensive

Two most popular algos are

- **RSA**
  - Both **publ** and **priv** are interchangable
  - Variable key size (512, 1024 or 2038 bits)
  - Most popular **publ** key alg
- **ElGamal**
  - Variable key size (512 or 1024 bits)
  - less common in RSA, used in protocols like PGP

### Why Asymmetric Key

Reason why **publ** keys are used is to establish secure comms when there is nowhay to exchange a key beforehand
> Confidential/ authed channel for free?

Must ensure that the publ key belings to the correct party (binding of `id` to key) **Publ** directory may be corrupted.
> **Sol** use a Public Key Infastructure to certify your keys (PKU)

Anyone may encrypt messages that only destinatio device may read, since he knows the private key (`K<private>`)

---

## Diffie-Hellman Key Exchange

### Paint Analogy

### Hardness of Diffie-Hellman

### Attacks on the Discrete Log Problem

### Selecting g and p for Diffie-Hellman

### Strength of DH

---

## RSA

### Operation

### RSA Example

### Security of RSA

#### Core Security

### Not proven to be "hard"

### Factoring Attack

### size of Modulus

---

## Symmetric v Asymmetric

### Summary Symmetric Crypto

- **Advantages**
  - can be designed to have high throughput
  - keys are relatively short (128, ..., 256 bits)
  - can be used as primitives to create other construct as PRNGs
  - can be used to construct stronger ciphers
    - e.g simple subst and permutations can be used to create stronger ciphers
  - All knownn attavks involve **exhaustive** key search
- **Disadvantages**
  - in 2 party networks, key must be secret at both ends
  - Sound practice dictates the key needs to change frequently (each sesh)
  - in large network, `(n/2)` jeys required, can create a massive problem fo key management.

### Summary Asymmetric Crypto

- **Advantages**
  - Only **private** key need to be secret
  - the administration of keys on a network requires the presence of only one functuinally trusted (honest and fair) **TTP**
  - Depends on how its used, **public** and **priv** may be used for a long time (upper bound: Moore's Law)
  - In Large networks, `n` keys are required insted of (n/2) (sl 30)
- **Disadvantages**
  - Throughput rates are slow (typical for all known algos)
  - much larget key size (1024, ... , 4096 bits)
  - Security based on the presumed difficulty of a small set of number-theoretic problems; all known are subject to **short-cut** attacks (knowing prime factorisation of `n`)
  - public key crypto doesnt have as much of an extensive history in the public world, compared to symmetric

## Combinding Crypto System

As mention **Symmetric** and **Asymmetric** cryoti are complementary

- **Assym** crypto can be used to establish keys for subsequent faster **symmetric** crypto (session key)
- `A` and `B` can take advantage of long term benefits of public key crypto by publishing their public key to a directory

> **Asym** crypto is good for key management and signatures
>
> **Symm** crypto is good for encryption and some data inegrity application

### symetric Crypto: Key Length

Security of **Symemetric** cipher is based on

- Str of the algo
- Length of key

Assuming the str of the Algo is perfect, then bruteforce is the best attack

### Interesting ways to break symmetric ciphers

- **Virus/ Word**
  - what if a bot net forced a cipher
  - Melisssa infected apprx 800k PC
  - If wa can cracking DES @ 280k keys (p4 @ 2.8ghz)
  - Melissa-DES bruteforced in 30 hrs
  - 2000 a word did that
  - Newer botnets have many more pcs
- **Chinese Lottery**
  - say 1M key/chips built in to every radio, tv in china
  - Each chip is designed to bruteforce a key sent over the air
  - if 10% of people in china have radio/tv: the 56-bit DES key can be exhausted in 12 min

### Asymetric Crypto Key length

Security of all known **publ** key algo is based on the presumed difficulty of a small set of number-theoretic proiblems

All are subjected to **shortbut attack**. We may find a way to factor easily in the future
> Quantum? DNA?

    1977:   RonRivest (RSA) said 125 digit num would take 4 x 1016 yrs
    2003:   576 bit (177 digit) num factored
    2012:   1061 bit(320 digits) num factored

Designs are being drawn out of optical/ quantum sieving machines that could led to massive optimisations on these nums in the future

