
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hill2.h"
#include "hill2_key_maker.h"

long reciprocal(long value)
{
	long temp = 0;
	int index=0;
	for(index=0; index<256; index++)
	{
		temp = value * index;
		if(temp%256 == 1)
		{
			return index;
		}
	}

	return 0;
}

int hill2_make_keys()
{
	int ret = 0;

	srandom(time(NULL));
	
	while(1)
	{
		long x11 = random()%256;
		long x12 = random()%256;
		long x21 = random()%256;
		long x22 = random()%256;

		long delta = x11 * x22 - x12 * x21;
		delta = delta % 256;
		if(delta == 0)
		{
			continue;
		}
		if(delta < 0)
		{
			delta = delta + 256;
		}

		long recip = reciprocal(delta);
		if(recip == 0)
		{
			//fprintf(stderr, "(%ld)^-1 = %ld \n", delta, recip);
			continue;
		}

		long y11 = (recip*x22)%256;
		long y12 = (recip*(-x12))%256;
		long y21 = (recip*(-x21))%256;
		long y22 = (recip*x11)%256;

		if(y11 < 0)
		{
			y11 = y11 + 256;
		}
		if(y12 < 0)
		{
			y12 = y12 + 256;
		}
		if(y21 < 0)
		{
			y21 = y21 + 256;
		}
		if(y22 < 0)
		{
			y22 = y22 + 256;
		}

		//test it.
		unsigned char encrypt_key[2][2] = { { x11, x12 }, { x21, x22 } };
		unsigned char decrypt_key[2][2] = { { y11, y12 }, { y21, y22 } };

#define MAX_LEN 1024
		char plain_text[MAX_LEN] = "abcdefghijklmnopqrstuvwxyz0123abcdefghijklmnopqrstuvwxyz0123abcdefghijklmnopqrstuvwxyz01230123456789x";
		char cipher_text[MAX_LEN] = { '\0' };
		char plain_text2[MAX_LEN] = { '\0' };
		int plain_len = strlen(plain_text);
		int cipher_len = Hill2_Encrypt(plain_text, plain_len, encrypt_key, cipher_text, MAX_LEN);
		int plain_len2 = Hill2_Decrypt(cipher_text, cipher_len, decrypt_key, plain_text2, MAX_LEN);
		fprintf(stdout, "encrypt key: %3d, %3d, %3d, %3d\n", encrypt_key[0][0], encrypt_key[0][1], encrypt_key[1][0], encrypt_key[1][1]);
		fprintf(stdout, "decrypt key: %3d, %3d, %3d, %3d\n", decrypt_key[0][0], decrypt_key[0][1], decrypt_key[1][0], decrypt_key[1][1]);
		fprintf(stdout, "plain1: %s\n", plain_text);
		fprintf(stdout, "plain2: %s\n", plain_text2);

		ret ++;

		if(ret >= 16)
		{
			break;
		}
		
	}

	return ret;
}

#if 0
encrypt key: 231, 247,  66,  21
decrypt key: 145, 245, 166,  59

encrypt key: 177, 179, 166, 177
decrypt key: 255, 163, 134, 255

encrypt key: 111, 216,  76, 129
decrypt key: 175,  88,  12,  97

encrypt key: 240,  53, 141, 161
decrypt key: 159, 245,  77,  16

encrypt key: 172,   3,  67, 156
decrypt key: 132, 219,  27, 244

encrypt key: 251, 151, 121,  62
decrypt key:  58, 123,  85, 177

encrypt key: 201, 108,  62,  55
decrypt key:  81, 204, 174, 175

encrypt key: 175,  73,  53, 136
decrypt key:  24,  85, 209, 189

encrypt key: 229, 183,  85, 146
decrypt key: 190, 223,  77, 163

encrypt key: 189, 145, 144,  13
decrypt key: 229, 183, 240,  21

encrypt key: 195,  55, 151, 168
decrypt key:  24,  47, 143, 229

encrypt key: 220, 173,  63, 159
decrypt key: 175,  35, 177,  28

encrypt key:  54,  87,  39, 246
decrypt key: 146,  67,  83,  82

encrypt key:  23,  36,  82, 117
decrypt key:  79, 212, 170, 149

encrypt key:   5,  48, 140, 129
decrypt key:  13, 144, 228, 193

encrypt key:  82, 177, 231, 136
decrypt key: 200, 103,  65, 162

#endif


