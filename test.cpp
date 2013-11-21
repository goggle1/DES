
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

static unsigned char encrypt_key_token[2][2] = 
{
	{ 129,  77 },
	{   6,  99 }
};

static unsigned char decrypt_key_token[2][2] = 
{	
	{ 151, 167 },
	{ 146, 189 }	
};


#if 0
int main()
{
	#define MAX_LEN 1024				
	//0A141E28D93D00000000526F4733
	//char plainStr[MAX_LEN]	 = { 0x0A, 0x14, 0x1E, 0x28, 0xD9, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x52, 0x6F, 0x47, 0x33};	
	//char plainStr[MAX_LEN]	 = "user=360&client_ip=192.168.160.203&timestamp=1383621431";
	char plainStr[MAX_LEN]	 = "[{\"mediaid\":\"106203\",\"cid\":";
	//"124c067507a4b484c48fa51633326993\",\"hashid\":\"b5606d8cb3a57995262f0dc8d9a18395978fce37\",\"fileformat\":\"mp4\",\"timelength\":\"2640456\",\"clarity\":\"tv\",\"byterate\":\"327680\",\"dub_one\":\"chi\",\"dub_two\":\"\",\"publishflag\":\"published\",\"forpc\":\"1\",\"number\":\"1\",\"description\":\"\u7b2c1\u96c6\"},{\"mediaid\":\"106203\",\"cid\":\"124c067507a4b484c48fa51633326993\",\"hashid\":\"67e201ecee87c9fc68080685f183f789d40eb5fd\",\"fileformat\":\"mp4\",\"timelength\":\"2640456\",\"clarity\":\"dvd\",\"byterate\":\"491520\",\"dub_one\":\"chi\",\"dub_two\":\"\",\"publishflag\":"published","forpc":"1","number":"1","description":"\u7b2c1\u96c6"},{"mediaid":"106203","cid":"124c067507a4b484c48fa51633326993","hashid":"82ab8193f396b1ad7245745b27a0e81c8f0b4e4f","fileformat":"mp4","timelength":"2640456","clarity":"high-dvd","byterate":"737280","dub_one":"chi","dub_two":"","publishflag":"published","forpc":"1","number":"1","description":"\u7b2c1\u96c6"}]"
	
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

#else

int main()
{
	#define MAX_LEN 1024	

	char base64_cipher[MAX_LEN] = "wXfoR/Jr";
	int  base64_cipher_len = strlen(base64_cipher);	
	char base64_plain[MAX_LEN] = "";
	int  base64_plain_len = MAX_LEN;
	base64_decode((const unsigned char *)base64_cipher, base64_cipher_len, (unsigned char *)base64_plain, &base64_plain_len);
	int index=0;
	fprintf(stdout, "base64_cipher[%d]: %s\n", base64_cipher_len, base64_cipher);
	for(index=0; index<base64_plain_len; index++)
	{
		fprintf(stdout, "%02X", (unsigned char)base64_plain[index]);
	}
	fprintf(stdout, "\n");

	char hill2_plain[MAX_LEN] = "";
	int  hill2_plain_len = MAX_LEN;
	int plain_len2 = Hill2_Decrypt(base64_plain, base64_plain_len, decrypt_key2, hill2_plain, MAX_LEN);
	fprintf(stdout, "plain2[%d]: %s\n", plain_len2, hill2_plain);	
	
}
#endif

