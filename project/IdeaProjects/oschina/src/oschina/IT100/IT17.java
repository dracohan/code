package oschina.IT100;

/**
 * @project: oschina
 * @filename: iT17.java
 * @version: 0.10
 * @author: JM Han
 * @date: 12:54 2015/12/19
 * @comment: find the 1st char that only exist once in string
 * @result:
 */

public class IT17 {
	public static Character findChar(String s){
		int[] int_set = new int[256];
		char[] char_set = s.toCharArray();
		for(char c: char_set){
			int_set[c]++;
		}
		for(char c: char_set){
			if(int_set[c] == 1)
				return c;
		}
		return '\0';
	}
	public static void main(String[] args) {
		System.out.println("The 1st char is: " + findChar("asdertrtdsaf"));
	}
}