package oschina.cc150;
/**
 * @project: oschina
 * @filename: cc007.java
 * @version: 0.10
 * @author: JM Han
 * @date: 21:04 2015/11/21
 * @comment: 如果矩阵的元素为0，清空整个所在的行和列
 * @result:
 */

import static tool.util.*;

public class cc0107 {
	public static void setZeros(int[][] matrix){
		boolean[] rows = new boolean[matrix.length];
		boolean[] cols = new boolean[matrix[0].length];

		for (int i = 0; i < matrix.length; i++){
			for (int j = 0; j < matrix[0].length; j++){
				if (matrix[i][j] == 0){
					rows[i] = true;
					cols[j] = true;
				}
			}
		}

		for (int i = 0; i < matrix.length; i++){
			for (int j = 0; j < matrix[0].length; j++){
				if (rows[i] == true || cols[j] == true){
					matrix[i][j] = 0;
				}
			}
		}

	}
	public static void main(String[] args) {
		int[][] matrix =  {{11,12,13,14,15},
							{21,0,23,24,25},
							{31,32,33,34,35},
							{41,42,43,0,45},
							{51,52,53,54,55}};
		setZeros(matrix);
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++)
				System.out.print(matrix[i][j] + " ");
			System.out.println("\n");
		}
	}
}
