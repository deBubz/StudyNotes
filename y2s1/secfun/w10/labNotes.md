# SSL & X509 certs

## Objective

Gain first-hand exp on applications of crypto to get familiar with the concept in the PublicKey encr and the PublicKey Infastructure(PKI)

## TASKS

1. Become a CA
2. Copy conf file from `/usr/lib/ssl/openssl.cnf`
	- `cp /usr/lib/ssl/openssl.cnf .` 
3. Set up dir 
	- `mkdir crl certs newcerts`
	- `touch index.txt`
	- `echo '01' > serial`
4. Generate self-signed cert for the CA
	- `openssl req -new -x509 -keyout ca.key -out ca.crt -config openssl.cnf`
5. Use these details
	```
	Country Name (2 letter code) [AU]:AU
	State or Province Name (full name) [Some-State]:NSW
	Locality Name (eg, city) []:SYD
	Organization Name (eg, company) [Internet Widgits Pty Ltd]:UTS
	Organizational Unit Name (eg, section) []:FEIT
	Common Name (e.g. server FQDN or YOUR name) []:netsec.com.au
	Email Address []:root@netsec.com.au
	```
> To read the modulus, private exponents...
>
> run `openssl rsa -in ca.key -text`
