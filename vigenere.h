//vigenere.h
#ifndef __VIGENERE_H__
#define __VIGENERE_H__

#ifdef __cplusplus
extern "C"
{
#endif

int Vigenere_EncryptText(const char *plainText, const char *keyStr, char *cipherText);
int Vigenere_DecryptText(const char *cipherText, const char *keyStr, char *plainText);


#ifdef __cplusplus
}
#endif



#endif

