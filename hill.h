//hill.h
#ifndef __HILL_H__
#define __HILL_H__

#ifdef __cplusplus
extern "C"
{
#endif

// mod 256

int Hill2_EncryptText(const char *plainText, const char *keyStr, char *cipherText);
int Hill2_DecryptText(const char *cipherText, const char *keyStr, char *plainText);


// mod 26
int Hill4_EncryptText(const char *plainText, const char *keyStr, char *cipherText);
int Hill4_DecryptText(const char *cipherText, const char *keyStr, char *plainText);


#ifdef __cplusplus
}
#endif



#endif

