
public class Encoder {
	public static void main(String[] args) {
		String plainText = new String("123456"); 
		String encrypt_key = "814d0663";
		String decrypt_key = "97a792bd";
		
		String cipherText = Hill2_Encrypt(plainText, encrypt_key);
		String plainText2 = Hill2_Encrypt(cipherText, decrypt_key);
		
      //输出原文
      System.out.println(plainText);
      //密文
      System.out.println("------------------------------------------------------");
      System.out.println(cipherText);
      //解密后内容
      System.out.println("------------------------------------------------------");
      System.out.println(plainText2);
		
		
		
//        char[] plainText = new char[]{'1', '2', '3'};
//        char[][] encrypt_key = new char[][]{new char[]{129,77}, new char[]{6,99}};
//        char[][] decrypt_key = new char[][]{new char[]{151,167}, new char[]{146,189}};
//        char[] cipherText = new char[3];
//        char[] plainText2 = new char[3];
//        int return_length;
//        
//        //加密
//        return_length = Hill2_Encrypt(plainText, plainText.length, encrypt_key, cipherText, cipherText.length);
//        //解密
//        return_length = Hill2_Decrypt(cipherText, cipherText.length, decrypt_key, plainText2, plainText2.length);
//        
//        //输出原文
//        System.out.println(plainText);
//        //密文
//        System.out.println("------------------------------------------------------");
//        System.out.println(cipherText);
//        //解密后内容
//        System.out.println("------------------------------------------------------");
//        System.out.println(plainText2);
    }
	
	public static String Hill2_Encrypt(String plainText, String encrypt_key) {
		char []plainArray = plainText.toCharArray();
		String str_1 = encrypt_key.substring(0, 2);
		String str_2 = encrypt_key.substring(2, 4);
		String str_3 = encrypt_key.substring(4, 6);
		String str_4 = encrypt_key.substring(6, 8);
		int str_i1 = Integer.parseInt(str_1, 16);
		int str_i2 = Integer.parseInt(str_2, 16);
		int str_i3 = Integer.parseInt(str_3, 16);
		int str_i4 = Integer.parseInt(str_4, 16);
		//System.out.println(str_i1+" "+str_i2+" "+str_i3);
        char[][] keyArray = new char[][]{new char[]{(char)str_i1,(char)str_i2}, new char[]{(char)str_i3,(char)str_i4}};
		char []chipherArray = new char[plainArray.length];
		Hill2_Encrypt(plainArray, plainArray.length, keyArray, chipherArray, chipherArray.length);
		
		return new String(chipherArray);
	}

    public static int Hill2_Encrypt(char[] plainText, int plainLen, char[][] encrypt_key, char[] cipherText, int cipherLen) {
        int ret_len = plainLen;
        int cal_len = plainLen;

        int x1 = 0;
        int x2 = 0;
        int y1 = 0;
        int y2 = 0;
        int plain_index = 0;

        if (plainLen % 2 == 1) {
            cal_len = plainLen - 1;
        }
        for (plain_index = 0; plain_index < cal_len; plain_index += 2) {
            x1 = plainText[plain_index + 0];
            x2 = plainText[plain_index + 1];
            y1 = x1 * encrypt_key[0][0] + x2 * encrypt_key[1][0];
            y2 = x1 * encrypt_key[0][1] + x2 * encrypt_key[1][1];
            cipherText[plain_index + 0] = (char) (y1 % 256);
            cipherText[plain_index + 1] = (char) (y2 % 256);
        }

        if (plainLen % 2 == 1) {
        	cipherText[plainLen - 1] = plainText[plainLen - 1];
        }
        
        return ret_len;
    }
    
    public static int Hill2_Decrypt(char[] cipherText, int cipherLen, char[][] decrypt_key, char[] plainText, int plainLen) {
    	return Hill2_Encrypt(cipherText, cipherLen, decrypt_key, plainText, plainLen);
    }

}
