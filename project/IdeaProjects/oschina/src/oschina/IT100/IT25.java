package oschina.IT100;

import java.util.Scanner;

/**
 * @project: oschina
 * @filename: IT25.java
 * @version: 0.10
 * @author: JM Han
 * @date: 10:05 AM 1/4/2016
 * @comment: Find the continous number of max length
 * @result: Please input the String:
 * 123dfasdf123123asdfasdf33333333333333asdfsdf221asdf2323
 * The max continuous number is: 33333333333333
 */

public class IT25 {
	public static String contiNumMax(String s){
		char[] chars = s.toCharArray();
		int length = chars.length;
		int len = 0; int maxLen = 0;
		String r = "";

		for(int i = 0; i < length; i++){
			char c = chars[i];
			if(c > '0' && c < '9'){
				len++;
			} else{
				if(len > maxLen){
					maxLen = len;
					r = s.substring(i - len, i);
				}
				//has to reset len to re-calculate
				len = 0;
			}
		}
		return r;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Please input the String: ");
		System.out.println("The max continuous number is: " + contiNumMax(sc.next()));
	}
}
