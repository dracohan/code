package c04;
/**
 * @project: LearningJava
 * @filename: breakTestr.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 21:35 2015/8/22
 * @comment: Test Purpose
 * @result:
 */

public class breakTestr {
	public static void main(String[] args) {
		int i = 0, j = 0;
		LableOne:
			while(i < 10){
				i++;
				System.out.println("i: " + i);
				LableTwo:
					while(j < 10){
						j++;
						System.out.println("j: " + j);
					}
					break LableOne;
			}
		System.out.println("Let's continue");



	}
}
