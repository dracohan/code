package oschina.IT100;
/**
 * @project: oschina
 * @filename: IT10.java
 * @version: 0.10
 * @author: JM Han
 * @date: 15:49 2015/11/12
 * @comment: Test Purpose
 * @result:
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class IT10 {
	public static String reverse(String str){
		StringBuilder sb = new StringBuilder();

		String[] fields = str.split("\\s+");
		for(int i = fields.length - 1; i >= 0; i--)
			sb.append(fields[i] + " ");
		return sb.toString();
	}

	public static String reverse2NR(String str){
		return new StringBuilder(str).reverse().toString();
	}

	public static String reverse2R(String str){
		if(str == null || str.length() <= 1)
			return str;

		return reverse2R(str.substring(1)) + str.charAt(0);
	}

	public static String reverse3(String str, String token){
		StringBuilder sb = new StringBuilder();
		String rtoken = new StringBuilder(token).reverse().toString();

		while(str.contains(token)){
			String s = str.substring(0, str.indexOf(token));
			sb.append(s).append(rtoken);
			str = str.substring(str.indexOf(token)+token.length());
		}
		//Ê£ÓàµÄ²¿·ÖString
		sb.append(str);
		return sb.reverse().toString();
	}

	public static void main(String[] args) {
		try {
			System.out.println("Please input some sentence: ");
			InputStream in = System.in;
			InputStreamReader charsIn = new InputStreamReader(in);
			BufferedReader bufferedReader = new BufferedReader(charsIn);
			String str = bufferedReader.readLine();
			String rstr = reverse3(str, "jimmyhan");
			System.out.println(rstr);
		} catch (IOException e){
		}
	}
}
