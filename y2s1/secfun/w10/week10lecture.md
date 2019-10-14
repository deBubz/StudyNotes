# Confidentiality and Integrity

## Confidential Policy

**GOAL** prevent unauth discosure of information by: *dealing with iformation flow* and *integrity incidental*

**e.g** Multi-level security models, **Bell_LaPadula Model**

## Bell-LaPadula Model: **step 1**

> - Security Levels arranged in linear ordering
>   - Top secret
>   - Secret
>   - Confidential
>   - Unclassified
> - Level cosist of **security clearance L(s)**
>   - Objects have **sec classification L(o)**

### Step 1 Read

- Info flows up: `Reads up` not allowed, `Read Down` Allowed
- **Simple Security Condition**
  - Subject `s` can read obj `o` if `L(o) <= L(S)` and `s` has permission to read `o`
  - Combines mandatory control (relationship of security levels) and discretionary control (required permission)
  - Sometimes called "no readup" rule

### Step 1 Write

- Info Flows up: `Write Up` allowed `Write Down` not allowed
- `*-Property`
  - Subj `s` can write obj `o` if `L(s) <= L(o)` and `s` has permission to write `o`
  - Combines mandatory control (relationship of security levels) and discretionary control (required permission)
  - Sometimes called "no writedown" rule

### Basic Sec Theorem: step 1

If a system is initially in a secure state, and every transistion of the system satisfies the:

> Simple security condition (step1) and `*-property` (step1)

Then every state of the system is secure.

**Proof** induct on the number of transitions

## Bell-LaPadula Model: step 2

> Expand notion of security level to include categories
>
> Security level is `(clearnace, category set)`. **E.g**
>
> - `(Top secret, {NUC, EUR, ASI})`
> - `(Confidential, {EUR, ASI})`

### Levels and Lattices TODO

### Levels and Ordering

- **Security Levels partially ordered**
  - Any pair of security levels may(or maynot) be related by dom
- **"Dominates" serves the role of greater than in step1**
  - "Greater than" is total ordering though

### Step 2 Read

- Info flows up: `Reads up` not allowed, `Read Down` Allowed
- **Simple Security Condition** (step2)
  - Subject `s` can read obj `o` if `L(s) dom L(o)` and `s` has permission to read `o`
  - Combines mandatory control (relationship of security levels) and discretionary control (required permission)
  - Sometimes called "no readup" rule

### Step 2 Write

- Info flows up: `Write up` allowed, `Write Down` not allowed
- `*-Property` (step2)
  - Subject `s` can write obj `o` if `L(o) dom L(s)` and `s` has permission to write `o`
  - Combines mandatory control (relationship of security levels) and discretionary control (required permission)
  - Sometimes called "no write down" rule

### Basic Sec Theorem: step 2

If a syst is initially in a secure state, and every transition of the system satisfies

> the Simple security condition(step2) and the `*-property`(step2)

Then every system is secure
**Proof** induct on the num of transistion

> In actual *basic security theorem*, discretionary access control treated as third property, abd simple sec property and `*-property` phrased to elimitae disretionary part of the definition - but simpler to express the way done here.

### Problem

- Colonel has `(Secret, {NUC,EUR})` clearance
- Major has `(secret, {EUR})` clearance
- HERE
  - Major can talk to colonel(write up/ read down)
  - Colonel cant talk to major(read up/ write down)
- Absurd?

### Solution

Define max, current levels for subjeccts (`maxlevel(s)` dom `curlevel(s)`)

**e.g**

- treat Major as an obj (Colornel is writing to him/her)
- Colonel has `maxlevel(Secret, {NUC, EUR})`
- Colonel sets `curlevel` to `(Secret, {EUR})
- Now `L(Major)` dom `curlevel(Colonel)` (Col can write to Major without violating no writedowns)

> SO does `L(s)` mean `curlevel(s)` or `maxlevel(s)`
>
> We need a more precise notation

---

## Integrity Policies

> Requirement of policies

### Biba Integrity Model

### Intuition for Integrity Levels

### Biba's Model

### LOCUS and Biba

### Clark-Wilson Integrity Model

### Entities

### Cert Rules 1 and 2

### Enforcement Rules 1 and 2

### Users and Rules

### Logging

### Handling Untrusted Input

### Seperation of Duty in Model

### Comparison to Biba

---

## Key points
