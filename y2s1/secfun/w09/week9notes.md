# Security protocols

> a number of public/private keys are used to achieve Perfect Forward Secrecy

> Often uses session keys 

## Perfect Forward Secrecy

A protocol has **perfect forward secrecy** if disclosure of long-term does not compromise previous (short term) sessions

- **Ephemeral** keys have this (generated during DiffieH)
- Encrypting everything directly with **RSA** does not have this

Protocols are vulnerable to **known key attack** if disclosure of past session keys allow attackers to comprimise future session key (includes actively impersonating)

### MiTM

Suppose `A` and `B` performs DH key exchange, but `E` owns the communication channel and can intercepts traffic without the knowledge of `A` and `B`

> `E` now can replace what is sent with its own keys

- shared for `A` and `E` is `g^ax mod p`
- shared for `B` and `E` is `g^bx mod p`

## Needham-Schroeder Protocol

**Needham-Shroeder** protocol facilitate key exchange using a trusted third party (TTP).
`A` and `B` want ti setup a session key for communication. All parties shares key with `T`, the TTP

1. `A` sends `T` request to talk to `B` `(A, B, r<a>)` where `r<a>` is a nonce
2. `T` sends `A` a session key, ticket to give `B`:  `E<KAT> (r<a>, B, k<AB>, E<KAT>(k<AB>, A))`
3. `A` sends `B` the ticket: `E<KBT>(k<AB>, A), E<KAB>(S<A>)`
4. `B` challengs `A` with `E<KAB> (S<A> -1, r<b>)` where `r<b>` is a nonce
5. `A` responds to `B` challange `E<KAB> (r<B> -1)

**Problem** what if `E` got a hand of `k<AT>` somehow??

**Problem** `B` cant guarantee `k<AB>` is fresh. Old session keys are valuable as they dont expire

> 1. suppose `E` manage to get `k<AT>`
> 2. `E` can read all and impersonate `A`
> 3. `A` needs to revoke her key, the only party can make this have an affect is `T`
> 4. **Key revocation is a major problem**

`needham-Schroeder`'s problen is that is assumes all users of the system are good, and the goal is to keep bad parties from getting in.

> not using pub/priv key
>
> only symmetric

### Kerberos

**kerberos** is a protocol which builds on **Needham-Shroeder** protocol. It allows noedes with in the insecure network to prove identity to each other.

## Public Key Management using Certitification Authorities

public key cert binds a public key to its owner:

1. `A` sneds her public key to the `CA` (or `T`)
2. `CA` produces a cert for `A`
3. `A` sends her public key and cert to `B`
4. `B` verifies the cert using `A`'s public key
5. `B` sends encrypted message to `A` using key

- Everyone must be able to berify the `CA`'s publlic key so its shipped with OS, browsers...
- `CA` is a trusted party: it has the ability to issue signatures to whomever
## Public Key Certificate Generation

1. `A` generates public/private keypair
2. `A` sends the public key to the `CA`
3. `CA` challanges `A` to see if she knows the `private` key
4. if success `CA` generates a certificat and sends to `A`

**Important** notes:

1. `CA` will never learns `A`'s private key
2. Important for forward secrecy
3. A compromise of the `CA` can still lead to people pretending to be `A`

## Certificate Revocation

`A`'s cert may need to be revoked. in cases;

- Her private key is stolen or otherwise compromised
- She changes jobs (or trustworthiness)

This is a `major` problem with the `CA` system

- may require daily cert-validation information (slow and cumbersome)
- Use experation date field
- User of a cert revocation list (CRL) which is circulated (e.g bad credit cards)

## Trust Model

- **Symmetric keys** (kdc)
  - TTP must be online (used every session)
  - TTP is a juicy tarket(known passwords)
  - no forward secrecy
- **Assymetric keys**
  - TTP is offline (only used in generation)
  - TTP only knows public key
  - TTP has forward secrecy
  - Not as fast (e.g SSL/TLS, PGP)

---

## Secret Splitting

**Problem**: you the CEO, responsible to keep the secret of the company

You can tell your trusted employees but

- They could defect to the opposition
- They could fall to rubber hose cryptanalysis

How can the secret be split among multiple parties such that each piece by itself is useless

### Secret Splitting with XOR

Suppose `T` wants to protect `m`

1. generate random string `r`, same length as `m`
2. computes `s = m xor r`
3. gives `A` the `r` and `B` the `s`

Each piece `r`, `s` are called shadow of `m`. To reconstruct `m`.
`A` and `B` can XOR the shadows together

> `s xor r = m`

if `r` is random, then the system is perfectly secure (OTP)

Scheme may be extended to `n` people by generating `n - 1` random string `r1`, `r2`,..., `rn-1`.
Gives the first `r1`, seccond `r2` upto `rn-1`, gives the person `r1 xor r2 ... xor rn-1 xor m`

So **secret splitting** aims to enhance reliability without increasing risk through distributing trust

**Issues** with XOR

- System is adjudicated by `T`
  - `T` can hand out rubbish and say it's the secret
  - `T` can say its splitting the secret 4 way, but only split with 2
  - `m` is malleable, by flipping bits in anypart, then the recovered message changes
  - All parties are required to recover `m` (bus factor = 1??)

## Secret Sharing

**Problem** you are responsible for a small country's nuclear weapons

- ensure that no single lunatic can launch a missle
- Ensure that no pair of lunatics launch a missle
- You want at least of 3 of 5 officers to be mad to launch

> (3,5) threshold scheme

### Secret sharing with Shamir's

Shamir's secret sharing is an algo for dividing a secret into `m` pieces where only `n` are required to reconstruct the secret

A polinomial of degree `n` can be uniquely defined by plotting `n + 1` on that polinomial

### Shamir's (t, n) threshold scheme

---

## Commitment Protocols

### Bit Commitment

**Problem**

- `A` wants to sell `B` info regarding police informants
- `A` doent trust `B` enough to tell him rats befor getting paid first
- `B` things its a setup, wont pay begore getting the names

- **Commitment**
  - `B` generates random string `r`, sends it to `A`
  - `A` generates randonn key `k`, sends `B` the `E<k> (r || m)`
- **Relevation**
  - `A` sends `B` the key `k`
  - `B` decrypts `m` with `k` and verifies `r`
- **Discussion**
  - `r` is needed for freshness, and stop `A` from finding colliding messages with `E<k1>(m1) = E<k2>(m2)`. `A` needs to commit when recievs `r`
  - `B` does not know `k` untill relevation, cannot bruteforce the message space

### Bit Commitment with Hash Functions

- **Commitment**
  - `A` generates random string `r`, computes `x = h(r || s || m)` (`x` called a blob)
  - `A` sends `B` the `(r, x)`
- **Relevation**
  - `A` sends `B` the remaining data of `(s, m)`
  - `B` verifies that `h(r || s || m)` is the same as the recieved `x`
- **Discussion**
  - `B` does not hae to send any messages
  - `A` sends a message to commit, message to reveal
  - `s` is kept secret so `B` cant brute force the message space

hmmm

## Fair Coin Flipping

**Problem**: `A` and `B` are arguing who plays white in chess

They want to **flip a coin** to resolve the situation. BUT `A` dont trust `B` to flip and vice versa

To **flip a coin** fairly:

1. `A` commits to bit `b` using a commitment scheme
2. `B` tries to guess `b`
3. `A` will reveal the bit if `B` guesssed correctly, `B` wins otherwise `A` winso

**security** of this algo lies on the security of the commitment scheme

Partivularly, the blob of the commitment scheme shouldnt give away anything about the messages inside(such as low-order bits)

### Fair Coin Flipping using Public Key Crypto

require a commutative public key crypto, example **ElGamal** so that

> `E<A>(E<b>(m)) = E<b>(E<A>)(m)`

To perform fair flip

1. `A` and `B` generate key pairs `a`, `b`
2. `A` generates two random number `r<t>` and `r<h>`
3. `A` sends `B` the `m1 = E<a>(heads, r<h>)` and `m2 = E<a>(tails, r<t>)` in random order
4. `B` selects one of `A`'s messages and send it back  `E<b>(x)`
5. `A` decrypts `B`'s message and sends it back `D<a>(E<b>(x))`
6. now `B` is left holding `E<b>(m1)` or `E<b>(m2)`: he can decrypt this and send it back to `A`
7. `A` verifies that `B` response matches up with her `r<t>` or `r<h>`

Overal

- The algo is self-enforcing: either party can detect the other cheating, without requiring a TTP
- `B` learns the result of the flip bedore `A`, cant change the result but may delat it (flipping the coin into a well)
- Coin flipping has use in sessio keygen, as neither party can influence the result of each flip. **e.g** in DiffieH, one party selects an exponent after the first

## Mental Poker

**Problem** `A` and `B` wants to play poker over email, They dont trust each other to deal hands fairly

> Use a **Commutative public key crypto system**
>
> 1. `A` and `B` generates keypairs `a`, `b`
> 2. `A` encrypts 52 message `m1 = (ace-spades, r1)` , ... using her public key and sends these blobs `x1`, `x2`, ... to `B`
> 3. `B` picks 5 however he pleases (random or not), encrypts them with his public key, sends them back to `A`
> 4. `A` decrypts the messages with its public key, sends back to `B`
> 5. `B` decrypts message: its hand
> 6. At the end, `A` and `B` may reaveal their keys to ensure no one cheated

### Attacks against the Poker Scheme

Cryptosystems (esp if based on number theory) tend to leak small amt of info, if not used in conjuction with hash func

**e.g** in RSA, if the num representing the card is a quardratic residue ( square num modulo the RSA modulus), then the encryption of the card is also a quadratic residue. *Could be used by the dealer to "mark" certain cards*

what why
