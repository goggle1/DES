#ifndef __DES_H__
#define __DES_H__

#ifdef __cplusplus
extern "C"
{
#endif

int DES_DecryptText(char *cipherText, char *keyStr, char *plainStr);

#ifdef __cplusplus
}
#endif

#endif
