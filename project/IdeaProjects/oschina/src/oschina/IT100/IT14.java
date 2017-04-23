package oschina.IT100;

/**
 * @project: oschina
 * @filename: IT13.java
 * @version: 0.10
 * @author: JM Han
 * @date: 12:08 PM 12/15/2015
 * @comment: find two number in an incredent list whose sum is given
 * @result:
 */

public class IT14 {
	public static boolean findTwo(int[] arr, int sum){
		int i = 0;
		int j = arr.length - 1;
		boolean flag = true;
		while(flag && (i < j)){
			if((arr[i] + arr[j]) < sum){
				i++;
			} else if ((arr[i] + arr[j]) > sum){
				j--;
			} else{
				System.out.println("i: " + i + " j: " + j);
				flag = false;
			}
		}
		return flag;
	}

	public static void main(String[] args) {
		int[] array = {1,3,4,5,13,17,18};
		findTwo(array, 25);
	}
}
