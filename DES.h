#ifndef __DES_H__
#define __DES_H__

#ifdef __cplusplus
extern "C"
{
#endif

int DES_DecryptText(const char *cipherText, const char *keyStr, char *plainStr);

#ifdef __cplusplus
}
#endif

#endif
