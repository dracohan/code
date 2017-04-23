package oschina.IT100;
/**
 * @project: oschina
 * @filename: IT26.java
 * @version: 0.10
 * @author: JM Han
 * @date: 5:23 PM 1/5/2016
 * @comment: Rotate characters of a String
 * @result: After rotate 3 of 12345678 is: 45678123
 */

public class IT26 {
	public static String rotateString(String s, int n){
		StringBuilder sxb = new StringBuilder(s.substring(0, n));
		StringBuilder syb = new StringBuilder(s.substring(n));
		StringBuilder srb = sxb.reverse().append(syb.reverse());
		return srb.reverse().toString();
	}
	public static void main(String[] args) {
		String src = "12345678"; int n = 8;
		System.out.println("After rotate " + n + "character of " + src + " is: " + rotateString(src, n));
	}
}
