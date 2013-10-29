
#include <stdio.h>
#include <string.h>

#include "hill2.h"
#include "hill2_key_maker.h"

static unsigned char hill2_encrypt_key[2][2] = 
{
	{ 129,	77 },
	{	6,	99 }
};

static unsigned char hill2_decrypt_key[2][2] = 
{
	{ 151, 167 },
	{ 146, 189 }
};


#if 0
int main()
{
	#define MAX_LEN 1024
	//char cipherText[MAX_LEN] = "13DE55A875D7AB7E";
	char cipherText[MAX_LEN] = {'\0'};	
	//char plainStr[MAX_LEN]	 = "abcdefghijklmnopqrstuvwxyz0123abcdefghijklmnopqrstuvwxyz0123abcdefghijklmnopqrstuvwxyz01230123456789x";
	char plainStr[MAX_LEN]	 = "www.funshion.com";
	//char plainStr[MAX_LEN]   = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUV";

	int plain_len = strlen(plainStr);
	int cipher_len = Hill2_Encrypt(plainStr, plain_len, hill2_encrypt_key, cipherText, MAX_LEN);
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

	int plain_len2 = Hill2_Decrypt(cipherText, cipher_len, hill2_decrypt_key, plainStr, MAX_LEN);
	fprintf(stdout, "plain2[%d]: %s\n", plain_len2, plainStr);
	for(index=0; index<plain_len2; index++)
	{
		fprintf(stdout, "%02X", (unsigned char)plainStr[index]);
	}
	fprintf(stdout, "\n");

	//hill2_make_keys();
	
}
#endif

