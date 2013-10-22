<?php

function Hill2_Encrypt($plainText, $plain_len, $encrypt_key, &$cipherText, $cipher_len)
{	
	$cipher_array = array();
	$ret_len = $plain_len;	
	$cal_len = $plain_len;
	
	$x1 = 0;
	$x2 = 0;
	$y1 = 0;
	$y2 = 0;
	$plain_index = 0;
	
	if($plain_len%2 == 1)
	{
		$cal_len = $plain_len - 1;
	}
	
	for($plain_index=0; $plain_index<$cal_len; $plain_index+=2)
	{		
		$x1 = ord($plainText[$plain_index+0]);
		$x2 = ord($plainText[$plain_index+1]);
	
		$y1 = ($x1 * $encrypt_key[0][0] + $x2 * $encrypt_key[1][0])%256;
		$y2 = ($x1 * $encrypt_key[0][1] + $x2 * $encrypt_key[1][1])%256;
				
		array_push($cipher_array, chr($y1), chr($y2));		
	}

	if($plain_len%2 == 1)
	{
		array_push($cipher_array, $plainText[$plain_len-1]);		
	}

	$cipherText = implode('', $cipher_array);
	return $ret_len;
}

/*
function Hill2_Decrypt($cipherText, $cipher_len, $decrypt_key, &$plainText, $plain_len)
{	
	$ret_len = Hill2_Encrypt($cipherText, $cipher_len, $decrypt_key, $plainText, $plain_len);
	return $ret_len;
}
*/
#define Hill2_Decrypt Hill2_Encrypt

$encrypt_key[0] = array(129, 77);
$encrypt_key[1] = array(  6, 99);

$decrypt_key[0] = array(151, 167);
$decrypt_key[1] = array(146, 189);

$plainText = "abcdefghijklmnopqrstuvwxyz0123abcdefghijklmnopqrstuvwxyz0123abcdefghijklmnopqrstuvwxyz01230123456789x";
echo $plainText . "\n";

$cipherText = "";
$cipher_len = Hill2_Encrypt($plainText, strlen($plainText), $encrypt_key, $cipherText, 1024);
print $cipher_len . "\n";
print strlen($cipherText) . "\n";
print $cipherText . "\n\n"; 
for ($i = 0; $i < $cipher_len; $i++)
	printf("%02X", ord($cipherText[$i]));
print "\n";
	
$plainText2 = "";
$plain2_len = Hill2_Encrypt($cipherText, $cipher_len, $decrypt_key, $plainText2, 1024);
echo $plainText2 . "\n";


/*
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

*/

?>