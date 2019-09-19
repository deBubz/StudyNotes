# Digital Signatures

- [Digital Signatures](#digital-signatures)
  - [Whatis Signature](#whatis-signature)
  - [Whatis Digital Signatures](#whatis-digital-signatures)
  - [Digital Signature with Public Keys](#digital-signature-with-public-keys)
    - [Attack against Digital Signatures](#attack-against-digital-signatures)
    - [Signature based on RSA](#signature-based-on-rsa)
    - [PKCS 1 Signature Scheme(RFC2313)](#pkcs-1-signature-schemerfc2313)
    - [EIGamal Signature Scheme](#eigamal-signature-scheme)
  - [Digital Signature Algorithm (DSA)](#digital-signature-algorithm-dsa)
  - [Signature based on One-Way-Function](#signature-based-on-one-way-function)
  - [SSL/TLS](#ssltls)
    - [Introducing SSL/TLS](#introducing-ssltls)
      - [TLS Protocol](#tls-protocol)
    - [Where are the Certificates from?](#where-are-the-certificates-from)
      - [Aquiring Certificate](#aquiring-certificate)
    - [How it work](#how-it-work)
    - [Certificate Revocation](#certificate-revocation)
    - [Is SSL/TLS perfect](#is-ssltls-perfect)

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
  - `de = 1 mox φ(n)`
  - `Apu = (n,e)`
  - `Apr = (n,d)`
- **Signature Generation**
  - Assume `m is in Zn`
  - `S = m^d mod n` RSA decryption
- **Signature Verification**
  - `m = S^e mod n` RSA encryption

> **Problems with Naive RSA scheme**
>
> Eve can trick Alice into signing any `m`
>
> Based on RSA **homomorpic prop**:
>
> if `s1 = md1 (mod n)` and `s2 = md2 (md n)`<br>
> then `s1s2 = (m1m2)d mod n

> **Problems with Naive RSA scheme**
>
> 1. Eve wants Alice to sign hidden `m`
> 2. Eve picks random `r in Zn`
> 3. Eve computes `m' = m r^e (mod n)`
> 4. Eve ask alice to sign `m'`
> 5. Alice returns `s' = (m')d(mod n)`
> 6. Eve computes `s = s'/r (mod n)`
>
> The pair `(m,s)` is a valid message signature pair. Eve tricked alice into signing hidden `m`

### PKCS 1 Signature Scheme(RFC2313)

Or **Public Key Cryptography Standard #1**

When naive RSA signature scheme has message recovery, the verification actually returns the message. **PKCS#1** is a hash(much faster than naive RSA)

- Signature Generation
  1. `n = pq` (1024-bit modulus)
  2. Alice calculates `d = h(m)` (160-bit hash)
  3. Define Encryption blocks:
  4. Alice calc `S = EB^d (mod n)`
  5. Alice sends `(S, m)`
- Signature Verification
  - `S = EB^d (mod n)`
  - Bob calc `S^e mod n = EB (mod n)`
  - Bob check the first 864 bits are valid
  - Bob checks last 160 bits are valid (i.e `= h(m)`)

### EIGamal Signature Scheme

**ElGamal** is an alternative signature scheme, whose security is based on the discrete Log Problem. LET:

- `H` collision-resistant hash func
- `p` large prime number
- `g` randomly chosen int `< p`, from group Zn

- **Key Generation**
  - choose large prime `p` and generator `g` in `Zn`
  - choose secret key `x` where `1 < x < p - 2
  - compute `y = g^x (mod p)
    - Public Key `y`
    - Privatekey `x`
- **Signature Generation**
  - choose ramdom `k` where `1 < k < p-1` and `gcd(k, p-1) = 1`
  - compute `r = g^k (mod p)`
  - computes `s = (H(m) - xr)k^-1 (mod p-1)`
  - if `(s == 0)` redo
  - `(r, s)` is the digital signature of `m`
- **Signature Verification**
  - verify `0 < r < p` and `0 < s < p-1
  - check signature ` g^(H(m)) = y^r r^s (mod p)
  - If everything checks out, sig is correct

> Notes: Elgamal<br/>
> Its rarely used in practice
> - DSA/DSS is more widely used
> - If a weak generator `g` is chosen, selective forgery is possible
> - `k` must be random for each sig. If the same `k` is used twice, then the pk `x` can be recovered

## Digital Signature Algorithm (DSA)

DSA was selected by NIST as the **Digital Signatue standard** (DSS)

> **Parameter** selection
>
> - choose a hash `H`. Previously `SHA-1` not `SHA-2` is perfered
> - choose key len `N` and `L`
> - choose `N` bit prime `q`
> - choose `L` bit prime mod `p` such that `p-1` is a multiple of `q`
> - choose `g in Zn` of mulplicative order modulo `p` is `q`
>   - i.e `g = h(p-1/q) (mod p) != 1` for some arbitrary `h(1 < h < p -1)`

- **Key Generation**
  - Secret key `x` chosen randomly in `0 < x < q`
  - compute public key `y = g^x (mod p)`
    - Also provide `p`, `q` and `g` params as part of public key
- **Signature Generation**
  - pick random `k in Zn` where `1 < k < q` (must be unique per msg)
  - calc `r = (g^k (mod p)) (mod q)` where r != 0
  - calc `s = k-h(H(m) + xr+ (mod q)` where s != 0
  - Signature is `(r, s)`
- **Signature Verification**
  - verify `0 < r < q` and `0 < s < q`
  - calc `w = s^-1 (mod q)`
  - calc `u1 = H(m) . w (mod q)`
  - calc `v = (g^u1 . y)

> Notes: DSA
>
> Security analysis of **DSA** is very similar to **ELGamal**
>
> DSA is standard for signature because
>
> - DSA can't be used for encryption (ELGamal can)
> - Signatures are shot (approx 320-b)
> - Patent issues
>
> Security of DSA is based on the security of subgroup `g`.
> Its not known if a sub-exponential alg exists in the size of the subgroup for discrete log. DSA sig verification can be speed up by (x2) by using simultaneous exponentiation

## Signature based on One-Way-Function

**Lamport onet-time sig** scheme is a digital sig scheme based on the one-way hash func

- **Key Generation**
  - for a `n-bit` msg, generate `2n x m` bit numbers
  - public key is `vi^j = H(xi^j)` for all `i`, `j`
  - private key is all of `xi ^j`
- **Signature Generation**
  - for a mesg `M = m1, m2, ... mn`
  - Signature is `s = (x1^m1, ... xn ^(mn))`
    - ie we select block x1^0 if bit `1` of `m` is `0`, otherwise `x1^1`
- **Signature Verification**
  - test for all `i: H(xi^(mi)) = vi^(mi)`

> Notes: Signatures Based on One-Way-Functions
>
> - Only sender knows the value of `x` that produce the sig
> - the public key is very long and must be unique for every message
> - the message itself expands by a factor of `m` (each bit expands to a `m-bit` block). Since `m` must be large to reduce the likelihood of attack, the message expansion is considerable
> - Lamport sig are believed to be quantum-res, unlike ELGamal or RSA  based schemes

---

## SSL/TLS

In standard `HTTP`, everything goes across the line in plaintext (insecure). This leave connection vulneraable to:

- Message tampering
- Evesdropping on connection
- MiTM attacks

Plus other numerous flaws in the underlying TCP/IP protocols

### Introducing SSL/TLS

**Transport Layer Security**(TLS) with its predecessor **Secure Socket Layer**(SSL) are cryptographic protocol for secure comms. They use:

- Asymetric crypto for authentication
- Symetric encryption for confidentiality of messages
- MAC for integrity

HTTP sits on top of that to produce HTTPS. The only leaked info is the **IP addr** and the connected **TCP port**. As well as the size of the sending/recieving message.

#### TLS Protocol

- **Client** -> **Server** (SSL version, avail ciphers, other info)
- **Server** -> **Client** (SSl version, selected ciphers, cert)

Client authenticate the server ( message sent should be signed by cert)

Client (possibly in conjunction to server, depending on cipher) creates the pre-master secret for the session, encrypts using server's cert, sends to sender.

*Optional* Server may auth the client using the client's **cert**. All msg from this point are encrypted.

### Where are the Certificates from?

A **Certificate Authority**(CA) is a trusted third party that issues digtal certs.

- Certificates for CAs are shipped with the OS, browser and other software
- Each time a server sents a cert to a browser, the browser will check to see if one of the CAs it trust has signed the cert.

**Who** are these **CA**: Small number of multinational comps with a significant barrier to entry.

> **Issues** with **CAs**
>
> - Do we actually **trust** them?
>   - Many have poor security practices and arn't willing to cooporate witht eh govt
>   - Small number of root CA allow others CA to sign on their behalf
>   - 2011, Fraudulant certs obtained from *Comodo* were used for MiTM attacks in Iran, they can MiTM any sites at will.
> - Sell based on ridiculous **"features"**
>   - Cost of 128-b and 256-b certs are commonly different, eventhough no extra work is done in 256
> - Saying **"this site is secured by SSL"** gives a false sense of confidence.
>   - Easy for scammers to get their own SSL cert for a domain they own.

#### Aquiring Certificate

- **Domain Validation** CA determines you own the domain by one of:
  - Having you respond to an email sent to admin@, postmaster@ ...
  - Having you publish a certain DNS TXT record
  - And more...
- **Extended Validation cert**
  - CA verifies you pass a set of identity verification criteria
  - Cost more than a normal cert
  - Puts a green bar at the top of your browser
  - **NOTE** still don't stop a faked normal cert from intercepting traffic.

### How it work

1. Generate public/private keypair for your server
2. Generate a **Certificate Signing Request**(CSR), containing domain name, PK, and other relevant details, and send this to a CA.
3. CA confirms any necessary details (domain validation or exteded validation)
4. CA signs the cert and sends it back
5. Install the Cert on your server

### Certificate Revocation

Method to revoke SSl certs, **Online Certification Status Protocol**(OCSP)

- Wheen a browser sees a new SSL cert, it makes a request to the OCSP URL embedded in the CA signing certificate.
- OCSP server sends a signed response indicating whether the cert is still valid.
- The signature on the response only covers some of the response data, and doesn't include the response status. Hence a MITM can send back any response status

Outcome of this is that attacers can intercpet an OCSP req and send a `tryLater` response status. All browser think this is fine and avoid raising an issue.

### Is SSL/TLS perfect

Ofcourse not, nothing is ever perfect

There are still many attacks on SSL/TLS, even assuming the transport itself is perfect

Many take advantage of the users and the inability of browsers to recommend the correct course of action when `"things arn't right"`
