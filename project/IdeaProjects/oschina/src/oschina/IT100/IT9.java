package oschina.IT100;
/**
 * @project: oschina
 * @filename: IT9.java
 * @version: 0.10
 * @author: JM Han
 * @date: 8:40 2015/11/5
 * @comment: Verify whether array is a post transversal of BSTree
 * @result:
 */

public class IT9 {
	static boolean verify(int start, int end, int[] a){
		//= represent only one element on sub-tree, return true
		//> represent left tree don't exist, return true
		if(start >= end)
			return true;

		int i; int j;
		for(i = start; a[i] < a[end]; i++);
		for(j = i; a[j] > a[end]; j++);

		//left tree + right tree should tranverse the whole list, or return false
		if(j != end)
			return false;

		//check the 2 parts(smaller and bigger)
		boolean right = verify(start, i-1, a);
		boolean left = verify(i, j - 1, a);

		//both left and right tree meet criteria, return true
		if(right && left)
			return true;
		//else return false
		return false;
	}

	public static void main(String[] args) {
		//int[] a = new int[]{4,8,6,12,16,14,10};
		//int[] a = new int[]{4,8,6,12,16,11,10};
		//int[] a = new int[]{4,8,6,9,11,12,10};
		int[] a = new int[]{6,5,8,5,7};
		boolean res = verify(0, a.length-1, a);
		String isn = res?"is":"isn't";
		System.out.println("Array " + isn + " a tree of postorder tranversal");
	}
}
