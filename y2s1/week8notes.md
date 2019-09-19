# Digital Signatures

## Whatis Signature

**Signatures** are used to bind an author to a document. Desireble props are

- **Authentic** suffecient belief that the signer deliberatly signed the doc
- **Unforgeable** Proof that only the signer could have signed the doc, no-one else
- **Non-reuseable** sig is intrinsicly bound to the doc and cannot be moved/reused
- **Unalterable**
- **Non-repudiation** singer cannot deny they didn't sign it

With all things, these props can be attacked/ subverted. We must consider such attacks when designing systems that use signatures

## Whatis Digital Signatures

we have

- **m** message to be signed
- **k** secret key
- **F** signature scheme (func)
- **S** the signature

> S = F(m,k)

Message `m` is signed using the secret key `k`, known only to the signer, which bind the signature `S` to the `m` using a signature scheme `F`

Given `(m,S)` anyone can verify the signature without `k`.
Non-repudiation is acheved through the secrecy of `k`

## Digital Signature with Public Keys

Step-by-Step: **Alice** wishes to sign a message and send it to **Bob**. This process can be divided into 3 steps

- **STEP1** Key Generation
  1. Alice Generate 2 keys
  2. `Apu` is published in a public dict (verifying)
  3. `Apr` is kept secret (signing)
- **STEP2** Signature Verification
  1. Alice chooses `n` random bits `r = {0,1}^n`
  2. Alice hashes the message to get a message digest `d = h(m)`
     - Uses collision resistan hash (CRHF)
  3. Alice generate `S = signatured(d, r, Apr)`
  4. Alice sends `(m, S)`
- **STEP3** Singature Verification:
  1. Bob obtains `Apu` from the public dict
  2. Bob computes `d = h(m)`
  3. Bob run verify `(d, Apu', S)`

### Attack against Digital Signatures

- **Total Break** can recover `Apr` from `Apu` and `(m, S)`
- **Selective Forgery** can forge signetures for a particular message/ class of message
- **Existential Forgery** Possible only in theory (based on currently avaliable resource)

> Signature Replay
>
> Why include `r = {0,1}^n` in the signature
>
> Consider
>
> - Alice send Bob a digital cheque for 100
> - Bob takes cheque to bank
> - Bank varifies valid signature and credid to Bob's acc
>
> What is stopping Bob from cashing it twice (replay attack)
>
> - the random valuer `r` is known as nonce and is used to aboud replay (assure "freshness")
> - Bank keep tracks of all nonce it has seen so far from alice

### Signature based on RSA

**Naive Protocol** based on RSA might be as

- **Key Generation**
  - `n = pq` (p,q are large primes)
  - `de = 1 mox something (n)`
  - `Apu = (n,e)`
  - `Apr = (n,d)`
- **Signature Generation**

- **Signature Verification**

> Notes: Elgamal<br/>
>

#### Problems with Naive RSA Scheme

#### Atack on Naive RSA scheme

### PKCS 1 Signature Scheme(RFC2313)

### EIGamal Signature Scheme

Key Generation

Signature Generation

Signature Verification

> Notes: Elgamal<br/>
> Its rarely used in practice
> - DSA/DSS is more widely used

## Digital Signature Algorithm (DSA)

Key Generation

Signature Generation

Signature Verification

> Notes: DSA<br/>

## Signature based on One-Way-Function

Key Generation

Signature Generation

Signature Verification

> Notes: Signatures Based on One-Way-Functions<br/>

---

## SSL/TLS

### Introducing SSL/TLS

#### TLS Protocol

### Certificates

#### Issues with Certification Authorities

#### Aquiring Certificate

### How it work?

### Certificate Revocation

### Is SSL/TLS perfect?

Ofcourse not, nothing is ever perfect

There are still many attacks on SSL/TLS, even assuming the transport itself is perfect

Many take advantage of the users and the inability of browsers to recommend the correct course of action when `"things arn't right"`
