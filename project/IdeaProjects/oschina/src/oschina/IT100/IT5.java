package oschina.IT100;
/**
 * @project: oschina
 * @filename: IT5.java
 * @version: 0.10
 * @author: JM Han
 * @date: 10:52 2015/11/2
 * @comment: 输入n 个整数，输出其中最小的k 个。
 * @comment: 例如输入8, 7, 6, 5, 4, 3, 2, 1这8 个数字，则最小的3 个数字为3, 2, 1。
 * @result:
 */

import java.util.*;
import static tool.util.*;

public class IT5 {
	public static final int NUM = 3;
	public static void find3least(List<Integer> lst){
		TreeSet<Integer> innerlst = new TreeSet<Integer>();
		for (int i = 0; i < lst.size(); i++) {
			int x = lst.get(i);
			if(innerlst.size() < NUM) {
				innerlst.add(x);
			} else {
				int max = innerlst.last();
				if(x < max){
					innerlst.add(x);
					innerlst.remove(max);
				}
			}
		}
		if(innerlst.size() != 0){
			printGenericIterator(innerlst.iterator());
		}
	}

	public static void main(String[] args) {
		Integer[] testArray = new Integer[]{8, 7, 6, 5, 4, 3, 2, 1};
		List<Integer> lst = Arrays.asList(testArray);
		Integer[] arra = lst.toArray(new Integer[0]);
		for(Integer i:arra)
			System.out.print(i+" ");
		System.out.println();
		find3least(lst);
	}
}
