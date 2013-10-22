#include <string.h>

#include "hill.h"

#define HILL_2 2


static char hill2_encrypt_key[HILL_2][HILL_2] = 
{
	{ 129,  77 },
	{   6,  99 }
};

static char hill2_decrypt_key[HILL_2][HILL_2] = 
{
	{ 151, 167 },
	{ 146, 189 }
};


#define HILL_4 4

static char hill4_encrypt_key[HILL_4][HILL_4] = 
{
	{  8,  6,  9,  5},
	{  6,  9,  5, 10},
	{  5,  8,  4,  9},
	{ 10,  6, 11,  4}
};

static char hill4_decrypt_key[HILL_4][HILL_4] = 
{
	{ 23, 20,  5,  1},
	{  2, 11, 18,  1},
	{  2, 20,  6, 25},
	{ 25,  2, 22, 25}
};


int Hill2_EncryptText(const char *plainText, char encrypt_key[2][2], char *cipherText)
{
	int plain_len = strlen(plainText);
	int plain_index = 0;
	for(plain_index=0; plain_index<plain_len; plain_index+=2)
	{
		int row_index = 0;
		for(row_index=0; row_index<2; row_index++)
		{
			int temp = 0;
			temp += encrypt_key[row_index][0] * (plainText[plain_index+0]);
			temp += encrypt_key[row_index][1] * (plainText[plain_index+1]);
			temp = temp%256;
			cipherText[plain_index+row_index] = temp;
		}		
	}

	return 0;
}

int Hill2_DecryptText(const char *cipherText, char decrypt_key[2][2], char *plainText)
{
	int cipher_len = strlen(cipherText);
	int cipher_index = 0;
	for(cipher_index=0; cipher_index<cipher_len; cipher_index+=2)
	{
		int row_index = 0;
		for(row_index=0; row_index<2; row_index++)
		{
			int temp = 0;
			temp += decrypt_key[row_index][0] * (cipherText[cipher_index+0]);
			temp += decrypt_key[row_index][1] * (cipherText[cipher_index+1]);			
			temp = temp%256;
			plainText[cipher_index+row_index] = temp;
		}		
	}

	return 0;
}


int Hill4_EncryptText(const char *plainText, const char *keyStr, char *cipherText)
{
	int plain_len = strlen(plainText);
	int plain_index = 0;
	for(plain_index=0; plain_index<plain_len; plain_index+=HILL_4)
	{
		int row_index = 0;
		for(row_index=0; row_index<HILL_4; row_index++)
		{
			int temp = 0;
			temp += hill4_encrypt_key[row_index][0] * (plainText[plain_index+0] - 'A');
			temp += hill4_encrypt_key[row_index][1] * (plainText[plain_index+1] - 'A');
			temp += hill4_encrypt_key[row_index][2] * (plainText[plain_index+2] - 'A');
			temp += hill4_encrypt_key[row_index][3] * (plainText[plain_index+3] - 'A');
			temp = temp%26;
			cipherText[plain_index+row_index] = 'A' + temp;
		}		
	}

	return 0;
}


int Hill4_DecryptText(const char *cipherText, const char *keyStr, char *plainText)
{
	int cipher_len = strlen(cipherText);
	int cipher_index = 0;
	for(cipher_index=0; cipher_index<cipher_len; cipher_index+=HILL_4)
	{
		int row_index = 0;
		for(row_index=0; row_index<HILL_4; row_index++)
		{
			int temp = 0;
			temp += hill4_decrypt_key[row_index][0] * (cipherText[cipher_index+0] - 'A');
			temp += hill4_decrypt_key[row_index][1] * (cipherText[cipher_index+1] - 'A');
			temp += hill4_decrypt_key[row_index][2] * (cipherText[cipher_index+2] - 'A');
			temp += hill4_decrypt_key[row_index][3] * (cipherText[cipher_index+3] - 'A');
			temp = temp%26;
			plainText[cipher_index+row_index] = 'A' + temp;
		}		
	}

	return 0;
}


