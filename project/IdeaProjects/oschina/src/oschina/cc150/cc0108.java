package oschina.cc150;
/**
 * @project: oschina
 * @filename: c008.java
 * @version: 0.10
 * @author: JM Han
 * @date: 21:46 2015/11/21
 * @comment: Test Purpose
 * @result:
 */

import static tool.util.*;

public class cc0108 {
	static boolean checkRotate(String s1, String s2) {
		if (s1.length() != s2.length()) return false;

		for (int i = 0; i < s1.length(); i++) {
			String x = s1.substring(0,i);
			String y = s1.substring(i);

			if(s2.indexOf(y) == 0){
				String p = s2.substring(y.length());
				boolean b = p.equals(x);
				if(b) return true;
			}
		}

		return false;
	}
	public static void main(String[] args) {
		String s1 = "abcdefg";
		String s2 = "fgabcde";

		System.out.println("Result is: " + checkRotate(s1, s2));
	}
}
