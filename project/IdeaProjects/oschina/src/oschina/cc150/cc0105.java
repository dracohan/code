package oschina.cc150;
/**
 * @project: oschina
 * @filename: c005.java
 * @version: 0.10
 * @author: JM Han
 * @date: 12:58 2015/11/21
 * @comment: Test Purpose
 * @result:
 */

import static tool.util.*;

public class cc0105 {
	static String transform(String s){
		if(s == null || s.isEmpty()) return s;

		int size = countCompress(s);
		if(size >= s.length())
			return s;

		char last = s.charAt(0);
		int count = 1;
		StringBuilder sb = new StringBuilder();
		for(int i = 1; i < s.length(); i++){
			if(s.charAt(i) == last)
				count++;
			else{
				sb.append(last).append(count);
				last = s.charAt(i);
				count = 1;
			}
		}

		sb.append(last).append(count);
		return sb.toString();
	}

	static int countCompress(String s){
		if(s == null || s.isEmpty()) return 0;

		char last = s.charAt(0);
		int size = 0;
		int count = 1;

		for (int i = 1; i < s.length(); i++){
			if(s.charAt(i) == last)
				count++;
			else{
				size += String.valueOf(count).length() + 1;
				count = 1;
				last = s.charAt(i);
			}
		}
		return size += String.valueOf(count).length() + 1;
	}

	public static void main(String[] args) {
		String s = "aaaabcccdeffffg";
		String r = transform(s);
		System.out.println("Result: " + r);
		System.out.println("Length: " + countCompress(s));
		System.out.println("Length: " + s.length());
	}
}
