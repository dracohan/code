package oschina.cc150;
/**
 * @project: oschina
 * @filename: IT28.java
 * @version: 0.10
 * @author: JM Han
 * @date: 3:20 PM 1/8/2016
 * @comment: calculate the number of 1 in binary format
 * @result: Your test result
 */

public class IT28 {
	public static int getOneNum(int x){
		int r = 0;
		while(x != 0){
			x = x&(x-1);
			r++;
		}
		return r;
	}

	public static void main(String[] args) {
		int n = 20;
		System.out.println("The 1 in number: " + n + " is: " + getOneNum(n));
	}
}
