package oschina.cc150;
/**
 * @project: oschina
 * @filename: cc004.java
 * @version: 0.10
 * @author: JM Han
 * @date: 17:58 2015/11/20
 * @comment: Test Purpose
 * @result:
 */

import static tool.util.*;

public class cc0104 {
	static char[] gen(char[] chars, int length){
		int spaceCount = 0, newLength, i;
		for(i = 0; i < length; i++){
			if(chars[i] == ' ')
				spaceCount++;
		}
		newLength = length + spaceCount*2;
		char[] res = new char[newLength+1];

		res[newLength] = '\0';

		for(int j = length - 1; j >= 0; j--){
			if(chars[j] == ' '){
				res[newLength - 1] = '0';
				res[newLength - 2] = '2';
				res[newLength - 3] = '%';
				newLength = newLength - 3;
			} else{
				res[newLength -1] = chars[j];
				newLength = newLength - 1;
			}
		}
		return res;
	}
	public static void main(String[] args) {
		char[] chars = "John W Smith".toCharArray();
		char[] nchar = gen(chars, chars.length);
		System.out.println(nchar);
	}
}
