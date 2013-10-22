#include "hill2.h"

int Hill2_Encrypt(const char *plainText, int plain_len, unsigned char encrypt_key[2][2], char *cipherText, int cipher_len)
{	
	int ret_len = plain_len;	
	int cal_len = plain_len;
	
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	int plain_index = 0;
	
	if(plain_len%2 == 1)
	{
		cal_len = plain_len - 1;
	}
	for(plain_index=0; plain_index<cal_len; plain_index+=2)
	{
		x1 = plainText[plain_index+0];
		x2 = plainText[plain_index+1];
		y1 = x1 * encrypt_key[0][0] + x2 * encrypt_key[1][0];
		y2 = x1 * encrypt_key[0][1] + x2 * encrypt_key[1][1];
		cipherText[plain_index+0] = y1%256;	
		cipherText[plain_index+1] = y2%256;	
	}

	if(plain_len%2 == 1)
	{
		cipherText[plain_len-1] = plainText[plain_len-1];
	}
	return ret_len;
}

int Hill2_Decrypt(const char *cipherText, int cipher_len, unsigned char decrypt_key[2][2], char *plainText, int plain_len)
{	
	int ret_len = Hill2_Encrypt(cipherText, cipher_len, decrypt_key, plainText, plain_len);
	return ret_len;
}


