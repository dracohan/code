package self;
/**
 * @project: LearningJava
 * @filename: StringTest3.java
 * @version: 0.10
 * @author: JM Han
 * @date: 19:27 2015/11/14
 * @comment: Test Purpose
 * @result:
 */

public class StringTest3 {
	public static void main(String[] args) {
		String s = "ab";
		String ss = s.substring(1,2);
		System.out.println(ss);

		int i,j = 1;
		//System.out.println(i);
		System.out.println(j);

		char c = 'a';
		StringBuilder sb = new StringBuilder(c);
		System.out.println(sb.capacity());

		//test the multiline string
		String ms = "ab" +
				"cd" +
				"ef";

	}
}
