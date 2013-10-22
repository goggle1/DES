//hill2.h
#ifndef __HILL2_H__
#define __HILL2_H__

#ifdef __cplusplus
extern "C"
{
#endif

// mod 256
int Hill2_Encrypt(const char *plainText, int plain_len, unsigned char encrypt_key[2][2], char *cipherText, int cipher_len);
int Hill2_Decrypt(const char *cipherText, int cipher_len, unsigned char decrypt_key[2][2], char *plainText, int plain_len);

#ifdef __cplusplus
}
#endif

#endif

