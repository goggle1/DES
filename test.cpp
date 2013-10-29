
#include <stdio.h>
#include <string.h>

#include "hill2.h"
#include "base64.h"

static unsigned char encrypt_key[2][2] = 
{
	{ 129,	77 },
	{	6,	99 }
};

static unsigned char decrypt_key[2][2] = 
{
	{ 151, 167 },
	{ 146, 189 }
};

static unsigned char encrypt_key2[2][2] = 
{	
	{  231,  247 },
	{	66,   21 }	
};

static unsigned char decrypt_key2[2][2] = 
{	
	{  145,  245 },
	{  166,   59 }	
};



#if 1
int main()
{
	#define MAX_LEN 1024				
	//0A141E28D93D00000000526F4733
	//char plainStr[MAX_LEN]	 = { 0x0A, 0x14, 0x1E, 0x28, 0xD9, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x52, 0x6F, 0x47, 0x33};	
	char plainStr[MAX_LEN]	 = "hello, funshion";
	char cipherText[MAX_LEN] = {'\0'};
	char base64Text[MAX_LEN] = {'\0'};

	//int plain_len = 14;//strlen(plainStr);
	int plain_len = strlen(plainStr);
	int cipher_len = Hill2_Encrypt(plainStr, plain_len, encrypt_key2, cipherText, MAX_LEN);
	int index=0;
	fprintf(stdout, "plain[%d]: %s\n", plain_len, plainStr);
	for(index=0; index<plain_len; index++)
	{
		fprintf(stdout, "%02X", (unsigned char)plainStr[index]);
	}
	fprintf(stdout, "\n");
	
	fprintf(stdout, "cipher[%d]: \n", cipher_len);
	for(index=0; index<cipher_len; index++)
	{
		fprintf(stdout, "%02X", (unsigned char)cipherText[index]);
	}
	fprintf(stdout, "\n");

	int plain_len2 = Hill2_Decrypt(cipherText, cipher_len, decrypt_key2, plainStr, MAX_LEN);
	fprintf(stdout, "plain2[%d]: %s\n", plain_len2, plainStr);
	for(index=0; index<plain_len2; index++)
	{
		fprintf(stdout, "%02X", (unsigned char)plainStr[index]);
	}
	fprintf(stdout, "\n");


	int base_len = MAX_LEN;
	base64_encode((const unsigned char*)cipherText, cipher_len, (unsigned char*)base64Text, &base_len);
	fprintf(stdout, "base64: %s\n", base64Text);
	
}
#endif

