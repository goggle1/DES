#include <string.h>

#include "vigenere.h"

/*
     A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
A -A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
B -B C D E F G H I J K L M N O P Q R S T U V W X Y Z A
C-C D E F G H I J K L M N O P Q R S T U V W X Y Z A B
D- D E F G H I J K L M N O P Q R S T U V W X Y Z A B C
E -E F G H I J K L M N O P Q R S T U V W X Y Z A B C D
F -F G H I J K L M N O P Q R S T U V W X Y Z A B C D E
G- G H I J K L M N O P Q R S T U V W X Y Z A B C D E F
H -H I J K L M N O P Q R S T U V W X Y Z A B C D E F G
I- I J K L M N O P Q R S T U V W X Y Z A B C D E F G H
J -J K L M N O P Q R S T U V W X Y Z A B C D E F G H I
K -K L M N O P Q R S T U V W X Y Z A B C D E F G H I J
L -L M N O P Q R S T U V W X Y Z A B C D E F G H I J K
M -M N O P Q R S T U V W X Y Z A B C D E F G H I J K L
N -N O P Q R S T U V W X Y Z A B C D E F G H I J K L M
O -O P Q R S T U V W X Y Z A B C D E F G H I J K L M N
P -P Q R S T U V W X Y Z A B C D E F G H I J K L M N O
Q -Q R S T U V W X Y Z A B C D E F G H I J K L M N O P
R -R S T U V W X Y Z A B C D E F G H I J K L M N O P Q
S -S T U V W X Y Z A B C D E F G H I J K L M N O P Q R
T -T U V W X Y Z A B C D E F G H I J K L M N O P Q R S
U -U V W X Y Z A B C D E F G H I J K L M N O P Q R S T
V -V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
W -W X Y Z A B C D E F G H I J K L M N O P Q R S T U V
X -X Y Z A B C D E F G H I J K L M N O P Q R S T U V W
Y -Y Z A B C D E F G H I J K L M N O P Q R S T U V W X
Z -Z A B C D E F G H I J K L M N O P Q R S T U V W X Y

*/

#define CHARSET_NUM 26

static char cipher_table[CHARSET_NUM][CHARSET_NUM] = 
{
	/*A -*/ { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
	/*B -*/ { 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A' },
	/*C -*/ { 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B' },
	/*D -*/ { 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C' },
	/*E -*/ { 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D' },
	/*F -*/ { 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E' },
	/*G -*/ { 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F' },
	/*H -*/ { 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G' },
	/*I -*/ { 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' },
	/*J-*/ { 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' },
	/*K-*/ { 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' },
	/*L-*/ { 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K' },
	/*M-*/ { 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L' },
	/*N-*/ { 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M' },
	/*O-*/ { 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N' },
	/*P-*/ { 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O' },
	/*Q-*/ { 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' },
	/*R-*/ { 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q' },
	/*S-*/ { 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R' },
	/*T-*/ { 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S' },
	/*U-*/ { 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' },
	/*V-*/ { 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U' },
	/*W-*/ { 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' },
	/*X-*/ { 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W' },
	/*Y-*/ { 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X' },
	/*Z-*/ { 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y' }	
};

int Vigenere_EncryptText(const char *plainText, const char *keyStr, char *cipherText)
{
	int key_len = strlen(keyStr);
	int plain_len = strlen(plainText);
	int plain_index = 0;
	for(plain_index=0; plain_index<plain_len; plain_index+=key_len)
	{
		int robin_len = key_len;
		if(plain_index + key_len > plain_len)
		{
			robin_len = plain_len - plain_index;
		}
		
		int robin_index = 0;
		for(robin_index=0; robin_index<robin_len; robin_index++)
		{
			int row_index = keyStr[robin_index] - 'A';
			int col_index = plainText[plain_index + robin_index] - 'A';
			cipherText[plain_index + robin_index] = cipher_table[row_index][col_index];
		}
	}
	
	return 0;
}

int Vigenere_DecryptText(const char *cipherText, const char *keyStr, char *plainText)
{
	int key_len = strlen(keyStr);
	int cipher_len = strlen(cipherText);
	int cipher_index = 0;
	for(cipher_index=0; cipher_index<cipher_len; cipher_index+=key_len)
	{
		int robin_len = key_len;
		if(cipher_index + key_len > cipher_len)
		{
			robin_len = cipher_len - cipher_index;
		}
		
		int robin_index = 0;
		for(robin_index=0; robin_index<robin_len; robin_index++)
		{
			int row_index = keyStr[robin_index] - 'A';
			/*
			int col_index = 0;
			for(col_index=0; col_index<CHARSET_NUM; col_index++)
			{
				if(cipher_table[row_index][col_index] == cipherText[cipher_index + robin_index])
				{
					plainText[cipher_index + robin_index] = 'A' + col_index;
					break;
				}
			}
			*/
			int col_index = 0;
			col_index = cipherText[cipher_index + robin_index];
			col_index = col_index - 'A';			
			if(col_index >= row_index)
			{
				col_index = col_index - row_index;
			}
			else
			{
				col_index = col_index + 26 - row_index;
			}
			plainText[cipher_index + robin_index] = 'A' + col_index;
		}
	}		

	return 0;
}



