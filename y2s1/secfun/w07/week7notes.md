# Week 7

## Authentication

Authentication is a mean where identity is established

**CHALLANGE** `Bob` is to ensure that the party at the end of the channel is `Alice`.
Bob must ensure Alice's id and has actively participated.

**GOAL** To achive this over an **insecure channel** with an active attacker

**PROBLEM** How to make sure the response is not tampered. As an intruder can listen, tamper msg in an **insecure channel**

## **Objectives** of Identification Protocols

- if `Alice` and `Bob` are honest. `A` should be able so succesfully auth herself. (`B` will complete the protocol having verified `A` identity)
- `B` cannot reuse an id exchange with `A` as so to impersonate `A` in conversation with others
- Probability that `E`(attacker) to impersonate `A` is computationally hard
- All above should be **true** even if
  - `E` has seen many auth session between `A` and `B`
  - `E` has authed with either or both of `A` and `B`
  - multiple auth sessions are run simultaneously.

### Basis of identification

- Something you **know**: password, PIN, secret key..
- Something you **have**: magnetic card, smart card, physical key, handheld password generator,...
- Something you **are**:
  - Biometrics: DNA, signatures, voice, retinal, voice
- Biometrics have prolems in real-world situations
  - Key revocation (hard to change)
  - DNA and figerprints are left elsewhere
  - Damage to your "key"

### Example of Authentication

- To **verify id as a precursor to communications**
  - Letting people know the bomb threat really is from the IRA
- To **facilitate access to a resource**
  - Local/remote access to resources (password, OTP)
  - Withdrawal of money from an ATM (key card and PIN)
  - Allow comms through a web server proxy
  - Allow physical access to restricted areas (swipe card)
  - Border crossing (passport)
- To **facilitate resource tracking and billing**
  - Smart Phone access

### Attacks of Authentication

- **Impersonation**: involving selective combination of information from one or more previous or concurrent sessions.
- **Interleaving**: involve sending information from an ongoing auth session back to the originator.
- **Forced Delay**: intercepts a message and relays it at some later point in time (not same as replay)
- **Chosen Text**: attack on challange-response where an adversary chooses as challanges in attempt to extract the secret key

---

## Passwords

Passwords are **simple and weak** method of authentication. They are usually stored hased on the server for extra security. If the server is compromised, the hashes need to be cracked to reveal the password.

### Problems with password

- If authentication is done in an insecure channel, can be breached 21.00
- Password can be **evesdrop and replayed**
  - partialy fixed by seccuring the channel (Diffie-Helman)
  - vulnerable to keyloggers, evesdropper
- Passwords are usually **drawn from a small key space, or re-used**
  - many sites sill limit to 8, 12, 16 chars
  - Dictionary attacks
  - One compromised site => compromises others
  - People are bad at making good passwords

### UNIX /etc/passwd

- Old UNIX password use DES as a hash func
  - truncate password to 8 char (**7 bits/char => 56 bits**)
  - encryppt a **64-bit** block of `0` using truncated password as key
  - output is fetback as input for a total 25 times
  - A **2 byte** salt is used to modify the expansion function, preventing the use od standard DES chips for cracking
- If a login name on `nick` had a salt of `wN` this might generate a lne in `/etc/passwd`
  - `user:password:uid:gid:homedir:shell`
  - `nick:wNX1CiVBBfasd:1001:1001:/home/nick:/bin/sh`

The hash is visible to all users of the system. But now hashed passwords/sats are locked away in a seperate file and is not readable.

### Dictionary Attacks

- Passwords are hard to makeup and remember, most human-generated passwords can be found in a dictionary:
  - pre-compute all password hashes for the dictionary.
  - On recieving a password hash, look up in the precomputed table.
- **Advantages**
  - Re-usable and shareable
  - Won't work on all users, but probably a large portion
  - Extension of dictionary: Rainbow Tables

### Salting

For password `p` and a hash function `h`, rather than using `h(p)` as the password hash, generate a random string `s` and use `h(p || s)`

- string `s` is the salt
- salt are usually stored right next to the password hashes
  - UNIX password use a Public Salt like this
  - salt is random
- this thwarts dictionary attack that rely on massive precomputation
- Once the salt is known, however, brute forc dict maybe run

> Simmilar to MACs.
>
> Password is Hashed and salted, Added a random keyword.

### Brute Forcing Hashes

**Millions** of password per second on CPU

**Billions** of password per sec on GPUs

For password in `[a-z;A-Z;0-9]` and symbols, hashed with `SHA256`, the `Antminer S9` can break a password in an advg of: 8char(1day), 10char(25days)

Brute forcing password hash is embarrassingly parallel: `N` machines gives a factor is `N` speedup

Standard hashing alg (MD5, SHA1, SHA256) are not good enough for passwords
  - hashing algo are designed to run fast
  - Password hashes should idealy be slow to slow down brute force
  - Brute forcing these alg is trivial even with salt

## Mordern Password Hashing

### bcrypt

Is a key derivation function password - highly suggested for websites.

`bcrypt` is simple and clean to impliment for many language(no excuse not to use it, or roll your own hasing scheme).
**Salts** are handled automatically: developers doesn't even need to know they exist.

**Key Stretching**: perform `2c` iteration of a hash, where `c` is a tuneable cost parameter

### scrypt

`bcrypt` aims to make hasking more expensive by using more time. Still vulnerable to hardware attacks, since iterated hashes are relatively easy to implement in hardware.

`scrypt` aims to make password hasing harder by using more space. It makes hardware implementations difficult by using vast amounts of memory
  - generate a large vector of pseudorandom bit-string
  - password derivation function performs random lookup into vector
  - straightforwad implementation requires entire vector to remain in memory
  - complex implementation recreates vector elements (time/ space tradeoff)

Core algorithm used in *Litecoin* to discourage hardware-based mining implementations

## One-Time Password

In **OTP**, each password is used only once, in an attempt to foil eavesdroppers and replay attacks.

- **Many Variation**
  - shared list of OTP
  - challange/response table
  - sequentially update OTP (eg - user creates and uploads `ki+1` when using `ki`)
  - OT-Sequences based on a oneway function (lamport OTP)

### Lamport's One Time Password

- **Setup** (generate a scheme for a max of `n` uses)
  - Alice picksa random key `k` and compute a hash chain (s18)
  - Alice sends `w` to server, set the count `c = n - 1`
- **Authentication**
  - Alice sends `x = h^c (k)` to the server, and decrements the count `c`
  - server verifies that `h(x) = w` and reset `w` to `x`

#### Pros and cons

- **Advantages**
  - No secret stored on the server
  - Prevent replay attacks from evesdropping
- **Disadvantages**
  - A limited number of auths before a new hash chain is setup
  - vulnerable to a pre-play attack if the original secret is compromised

s19

### HTOP

HMAC based OTP algorithm (RFC 4226) and used in end-user product such as the Ggoogle Auth

- **Setup**
  - Client and server agree on a large(> 160bits) secret key `k`
  - Client and server synchronise a `8-byte` counter `c`, which increases over time
- **Authentication**
  - define `HOTP(k, c) = HMAC-SHA-1(k, c) mod 10^d`
  - the client calculates `w = HOTP(k, c)` for the current value of `c`

Authentication usually allows a small "window of error" of `c` values, for users being slow at typing, or unsynced clocks

### TOTP

**Time Based One-Time** algorithm (RFC 6238) and used in end-user products such as Google Auth. Extension oh **HTOP**

- specifies that counter `c` in the previous alg shoud be
  - `(CurrTime - T0) / X`
  - `T0` and `X` are some pre-agreed num of secs
  - e.g `X =30` sec would make the password change every 30 sec.
  - `T0` may be when the user registerd, or `0`

### Challenge-Response Authentication

One proves its id to another by demonstrating knowledge of a secret without revealing the secret itself
  - Done by providing a response to a time-variant challange
  - Response is dependent on both the challenge and the secret

Time variant params are essential to counter replay and interleaving attacks to provide uniqueness and timeless guarantees(eg freshness) and to prevent certain chosen-ciphertext attacks. Some example of time-variant params
    - Nonces
    - Sequence Numbers
    - Timestamp

#### Symetric Crypto

> s23
>
> - `A` sends message `hello`
> - `B` replies with Nonce `r`
> - `A` sends Nonce `r'` and token `Ek (r || r')`

Bob and Alice have shareed secret `k` and have agreed on some keyed encryption or hash algo `Ek`

- Alice initiate comms with Bob
- Bob generate nonce `r` and send to Alice
- Alice generates and send a nonce `r'` and `Ek (r || r')`
- Bob verifies `Ek(r || r')` is what Alice sent

#### Asymetric Crypto

Alice publishes her public key `A` to the world, which Bob has a copy of (and verifies its authenticity at some previous point in time)

- Alice initiate comms with Bob
- Bob generate a nonce `r` and sends it to Alice
- Alice signs the nonce `signA(r)`, and sends the result to Bob
- Bob verifies the signature using Alice's public key
- No secret stored on server

### Zero-knowledge proofs

Zero-KnowledgeProofs are designed to allow a prover to demonstrate knowledge of a secret, while reavealing no info about the secret

- usually consist of many challange-response rounds
- adversaries can cheat with a small probability on a single round
- probability of cheating successfully should decrease exponentally in the num of interactive rounds
- for a large enough rounds, the probability of a succssful cheater is efffectively

> ZKP protocols are usually quite difficlt to comeup with, but have applications in challange-response auth

- **Cut and Choose** Protocol (each round is called an accreditation)
  - `A` cuts something in half
  - `B` picks wich half he wants
  - `A` takes the remaining half
- **Properties** of ZKPs
  - `V` cannot learn anything from the protocol, except that `P` knows something
  - `P` cannot cheat `V`
  - `V` cannot pretend to be `P` to any third party

### Naive HTTP(web server) Auth

- **Basic Authentication**
  - Access is segerated by realms
  - Simple `base64` encoding of `username:password`
  - WWW-Authenticate: basic realm="Control Panek"
- **Digest Authentication**
  - MD5 is used as the hash function

---

## Key Points

- Authenticaiton is **not** Cryptoraphy: Consider System components
- **Passords**: Not gonna change, they provide basis for most forms of authentication
- Protocols are **important**: they can make masquerading harder.
- Authentication methods can be combined
