# Quiz2 Notes

## Project Code stuff (EVP)

- `EVP_CIPHER_CTX` object/interface declaration (same as variable declaration)
- `EVP_CIPHER_CTx_init(&ctx)` Initialize the EVP_CIPHER_CTX object
- `EVP_EncryptInit_ex(&ctx, EVP_aes_128_cbc(), NULL, key, iv)`
  - evp_cipher_ctx object/interface
  - set the cipher/encryption function
  - implementation type, null for default
  - symmetric key (or somesor of key)
  - initial vector (if neccesary/optional can be null)
- `EVP_EncryptUpdate(&ctx, outbuf, &outlen, plaintext, strlen(plaintext))`
  - ctx interface
  - outbuf, outlen output length 16 (first block)
  - plain, strlen() input, input length to encrypt
- `EVP_EncryptFinal_ex(&ctx, outbuf + outlen, &tmplen)`
  - enctypt block which requires padding
  - ctx interface
  - `unsigned char *` outbuff with pointer at 16byte down
  - tmplen length of the encrypted block
  - tmplen + outlen: total length of 2 blocks
- `EVP_CIPHER_CTX_cleanup()`
  - Clean the interface free allocated memory
  - similar to malloc(), free())
  - always called after encr completes so sensitive info does not remain in memory

### Library Docs

```c
#include <openssl/evp.h>
// evp_encryptinit v1.02
// https://www.openssl.org/docs/man1.0.2/man3/EVP_EncryptInit.html

void EVP_CIPHER_CTX_init(EVP_CIPHER_CTX *a);
int EVP_EncryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl, const unsigned char *in, int inl);
int EVP_EncryptFinal_ex(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl);
void EVP_CIPHER_CTX_cleanup (&ctx);
```

## aes_128_cbc

Encryption using The **Advanced Encryption Standard**(Rjaindeal algo), using key size 128 byte (16 char)

block size are 128 byte

**cbc** Cipher Block Chaining mode, The first block (128byte/16char) is encrypted using the provided IV and key.
The ciphertext for that will then also act as the IV for the next block (which uses the same key)

## Symmetric

## Asymmetric
