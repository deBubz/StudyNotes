# Quiz 2 notes

- [Quiz 2 notes](#quiz-2-notes)
  - [Week 5](#week-5)
    - [Digital Encryption Standard (DES)](#digital-encryption-standard-des)
      - [DESX](#desx)
    - [Advanced Encryptoin Standard (AES)](#advanced-encryptoin-standard-aes)
      - [Rijndael (selected AES)](#rijndael-selected-aes)
    - [Key Distribution](#key-distribution)
      - [Key Distribution Center (KDC)](#key-distribution-center-kdc)
    - [Merkle's Puzzle](#merkles-puzzle)
    - [Diffie-Helman](#diffie-helman)
      - [Hard things in DH](#hard-things-in-dh)
  - [Week 6](#week-6)
    - [Symmetric and Asymmetric](#symmetric-and-asymmetric)
    - [2 common Asymm ciphers](#2-common-asymm-ciphers)
      - [RSA](#rsa)
      - [Elgamal](#elgamal)
    - [Why Asym](#why-asym)
    - [Symmetric v Asymmetric](#symmetric-v-asymmetric)
  - [Week 7](#week-7)
    - [Authentication](#authentication)
    - [Passwords](#passwords)
    - [Password Salt](#password-salt)
    - [Password Hashing](#password-hashing)
    - [One Time Password](#one-time-password)
    - [ZKP](#zkp)
    - [Naive HTTP](#naive-http)
  - [Week 8](#week-8)
    - [Digital Signature](#digital-signature)
    - [DSA](#dsa)
    - [SSL/TSL](#ssltsl)
    - [Certificate Authenticator](#certificate-authenticator)
    - [Online Certification Status Protocol](#online-certification-status-protocol)
    - [SSL Cert Aquisition](#ssl-cert-aquisition)

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
  - potential attack (50% chance) in 50% number of rounds (complete all rounds - 100% protection)

### Key Distribution

- **Key Establishment** process where shared key becomes avail to `=> 2 parties` for subsequent use
- **key Management**: set of process to support key establishment and maintenace of ongoing key relationship between parties.
  - includes `key agreement` and `key transport`

#### Key Distribution Center (KDC)

> Problem with symmetric key net work where `n` parties wants to talk to each other.
>
> it'll require `(n(n-1) / 2)` keys (ALOT of keys)

The solution for this is a Key Distribution Center(KDC) centralize entity that manages keys

KDC Operations:

- `A` notifies `KDC` to talk to `B`
- `KDC` sends to `A`: `E<a> (K<ab>)` where `K<ab>` is random, and `E<b>(K<ab>, "to conn with "A")`
- `A` will then:
  - get `K<ab>` by decrypting `E<a>(K<ab>)`
  - sends `E<b>(K<ab>, "to conn with "A")` to `B`
- `B` gets `K<ab>` by decrypting `E<b>(K<ab>, "to conn with "A")`
- `A` and `B` shares `K<ab>`

> **Problems**
>
> - single point of attack (DoS)
> - no Auth, slow, poor scalability

**Solution**: Diffie-Helman or Merkle's Puzzle

### Merkle's Puzzle

key exchange protocol with out involving a 3rd party. Not used much (cost alot of bandwidth) Operations:

- `A` creates a set of puzzles and send to `B`
- `B` chooses a random puzzle and solve it. (by bruteforce)
- `B` sends result to `A`
- `A` find index of result, `A` and `B` they share a secret/key??

### Diffie-Helman

Key exchange Protocol protocol using math tricks. Current Standard for SSL, smartcards..

- `A` and `B` agrees on large prime `p` and generator `g`
- `A` generates random `a`,(between `1` and `p`) `B` generates random `b`(between `1` and `p`)
- `A` calculates `g^a` and sends to `B`
- `B` calculates `g^b` and sends to `A`
- `A` and `B` will compute and have the shared secret `g^(ab)` = `(g^a)^b` = `(g^b)^a`

Evesdropper will only have `g^a`, `g^b` and `g`. Assuming calculating log its hard, cannot recover `a` and `b`

To generate both `g` and `p`, instead of exchanging the params each time, one will only need to state `RFC3526 1536-bit` to notify which params to use

#### Hard things in DH

- Discrete Log Problem(DLP) (attack with exhaustive search)
- Diffie-Hellman Problem(DHP)

---

## Week 6

### Symmetric and Asymmetric

- **Symmetric**: single key for both encr and decr
- **Asymmetric**: 2 keys, *public* to encrypt (distributed), *private* to decrypt (kept secret)

### 2 common Asymm ciphers

#### RSA

- most popular public key algo
- both publ and priv key are inter changable
- variable key size (512, 1024, 2048)

Operations:

- generate 2 large prime `p` and `q` so `n = pq`
- select `e` which is coprime to `φ (n) = (p - 1)(q - 1)`
- Find ​ `d` ​ such that ​ `ed = 1 (mod φ (n))` ​ using the Euclidean algorithm.
- The public key is​ `(n, e)`​ and the​ private key is `(n, d)`
- the rest can be thrown away

To return a message

- computes `m^e (mod n)` send the result
- reciever gets `m^e` and compute `m^ed ≡ m (mod n)`

#### Elgamal

- less common than RSA, mostly used in PGP

### Why Asym

- to securely establish a connection without using a secured comms channel(free confidential/authed channel)
- use Public Key Infastructure(PKI) to Certify PK

### Symmetric v Asymmetric

- **Sym**
  - **Pro**
    - high throughput(fast)
    - short keys (128, ... 256)
    - used to construct stronger ciphers (PRGs) e.g simple substitutions and permutations in other cipherso
    - all "known" attacks involve exhaustive keysearch
  - **Cons**
    - key must remain secret in 2 party network
    - need to be change frequently( session keys)
    - key management problems in big networks
- **Asym**
  - **Pro**
    - only the priv key needs to be secret
    - administration of keys on a network require presence of only 1 functionally trusted **TTP**
    - only `n` keys required
  - **Cons**
    - slow throughput
    - longer key size (1024, ... 4096)
    - subjected to short-cut attack , known `n` in `n = pq` (so `p` and `q` are often very large primes)

Both are used to complement eachother

> **Asym** crypto is good for key management and signatures
>
> **Symm** crypto is good for encryption and some data inegrity application

still can be broken by:

- virus/ worm (did in 2000)
- chinese lottery (theoretically)

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

**Signature** used to bind an author to a doc. Desirable props:

- **Authentic**
- **Un-forgeable** only the auth can sign
- **Non-reusable** used only for that one doc
- **Non-Repudation** auth can not deny its not theirs

All of these props are considered when designing systems that uses signatures

### DSA

- **m** message to be signed
- **k** secret key
- **F** signature scheme (func)
- **S** the signature

> `S = F(m, k)`

Given `(m, S)` signature is verifiable without `k` (achieve non-repundancy)

**DSA** with public keys

1. Key Gen
2. Signature Generation
3. Signature Verifications

**Attacks** on DSA with public keys

- **Total Break** recovered `A<pr>` and `A<pu>` from `(m, S)`
- **Selective Forgery** forge sigs for a particular msg/class of msg
- **Existential Forgery** only theory

> Preventing **Signature Replay (reuse)**
>
> uses a nonce `r = {0, 1}^n` (random binary length `n`)
>
> used to assure **"freshness"** per transaction

Theres also:

- Signature based on **RSA**, but
  - can be tricked by evesdropper in signing any `m` (by maths tricks) generating a valid `(m, S)`
- **Public Key Cryptography Standard** 1 (PKCS1) uses hash ( much faster than RSA)
- **ElGamal**, whose security is based on the DLP
- Signatures based on **One-Way Func**

> NOTES: DSA
>
> - security of DSA is similar to Elgamal
> - DSA cant be used for encryption
> - Sigs are shorts (aprx 320-b)

### SSL/TSL

- **SSL** Secure Socket Layer (old name)
- **TSL** Transport Socket Layer

They use:

- Asym encryption for auth
- Sym encryption for confidentiality of Messages
- MAC for integrity

> `SSL/TSL` + `http` = `https`
>
> only `ip`, `port` and size of `m` is revealed with `https`

### Certificate Authenticator

Certs comes from **Certificate Authentocators** (CAs).
Which are truted 3rd party orgs whom issue *ditital certs*

Certs are

- Included with browser, OS, other software
- When a server sends a cert to a browser, browser check with a trusted CAs if they signed it.

### Online Certification Status Protocol

The **Online Cert Status Protocol**(OCSP) is for reverting protocols

- browser see a new Cert, makes a request to OCSP url embedded in the cert
- OCSP send a response to signify the new cert is valid
- response signature only contain a part of the data, doesnt include response status.

Possible **MiTM**, intercepting the OCSP response and send `tryLater`. Tricking the browser to think its OK

### SSL Cert Aquisition

1. Generate public/ private keypair for a server
2. Geberate **CertSigningRequest**(CSR) containing domain name, publ key, and other details to send to CA
3. CA confirms detail (domain validation or extension)
4. CA sign and return Cert
5. Installed on server
