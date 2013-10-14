//hill.h
#ifndef __HILL_H__
#define __HILL_H__

#ifdef __cplusplus
extern "C"
{
#endif

int Hill_EncryptText(const char *plainText, const char *keyStr, char *cipherText);
int Hill_DecryptText(const char *cipherText, const char *keyStr, char *plainText);


#ifdef __cplusplus
}
#endif



#endif

