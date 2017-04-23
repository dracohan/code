package oschina.cc150;
/**
 * @project: oschina
 * @filename: cc006.java
 * @version: 0.10
 * @author: JM Han
 * @date: 13:39 2015/11/21
 * @comment: ��תһ������
 * @result:
 */

import static tool.util.*;

public class cc0106 {
	public static void rotate(int[][] matrix, int n) {
		int low = 0;
		for (int high = n - 1;low < high; low++, high--){
			for (int offset = 0; offset < high - low; offset++) {
				int temp = matrix[low][low + offset];
				//left to top
				matrix[low][low + offset] = matrix[high -offset][low];
				//bottom to left
				matrix[high - offset][low] = matrix[high][high-offset];
				//right to bottom
				matrix[high][high-offset] = matrix[low + offset][high];
				//top to right
				matrix[low + offset][high] = temp;
			}
		}
	}

	public static void main(String[] args) {
		int[][] matrix =  {{11,12,13,14,15},
						   {21,22,23,24,25},
				           {31,32,33,34,35},
				           {41,42,43,44,45},
				           {51,52,53,54,55}};
		rotate(matrix, 5);
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++)
				System.out.print(matrix[i][j] + " ");
			System.out.println("\n");
		}
	}
}
