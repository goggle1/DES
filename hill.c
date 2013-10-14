#include <string.h>

#include "hill.h"

#define HILL_N 4

static char encrypt_key[HILL_N][HILL_N] = 
{
	{  8,  6,  9,  5},
	{  6,  9,  5, 10},
	{  5,  8,  4,  9},
	{ 10,  6, 11,  4}
};

static char decrypt_key[HILL_N][HILL_N] = 
{
	{ 23, 20,  5,  1},
	{  2, 11, 18,  1},
	{  2, 20,  6, 25},
	{ 25,  2, 22, 25}
};


int Hill_EncryptText(const char *plainText, const char *keyStr, char *cipherText)
{
	int plain_len = strlen(plainText);
	int plain_index = 0;
	for(plain_index=0; plain_index<plain_len; plain_index+=HILL_N)
	{
		int row_index = 0;
		for(row_index=0; row_index<HILL_N; row_index++)
		{
			int temp = 0;
			temp += encrypt_key[row_index][0] * (plainText[plain_index+0] - 'A');
			temp += encrypt_key[row_index][1] * (plainText[plain_index+1] - 'A');
			temp += encrypt_key[row_index][2] * (plainText[plain_index+2] - 'A');
			temp += encrypt_key[row_index][3] * (plainText[plain_index+3] - 'A');
			temp = temp%26;
			cipherText[plain_index+row_index] = 'A' + temp;
		}		
	}

	return 0;
}


int Hill_DecryptText(const char *cipherText, const char *keyStr, char *plainText)
{
	int cipher_len = strlen(cipherText);
	int cipher_index = 0;
	for(cipher_index=0; cipher_index<cipher_len; cipher_index+=HILL_N)
	{
		int row_index = 0;
		for(row_index=0; row_index<HILL_N; row_index++)
		{
			int temp = 0;
			temp += decrypt_key[row_index][0] * (cipherText[cipher_index+0] - 'A');
			temp += decrypt_key[row_index][1] * (cipherText[cipher_index+1] - 'A');
			temp += decrypt_key[row_index][2] * (cipherText[cipher_index+2] - 'A');
			temp += decrypt_key[row_index][3] * (cipherText[cipher_index+3] - 'A');
			temp = temp%26;
			plainText[cipher_index+row_index] = 'A' + temp;
		}		
	}

	return 0;
}


