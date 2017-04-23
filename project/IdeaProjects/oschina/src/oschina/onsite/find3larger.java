package oschina.onsite;
/**
 * @project: oschina
 * @filename: find3larger.java
 * @version: 0.10
 * @author: JM Han
 * @date: 9:26 2015/10/31
 * @comment: 在序列中找出第三个比一个数大的数
 * @result:
 */

import java.util.*;

import static tool.util.printGenericIterator;

public class find3larger {
	public static final int NUM = 3;

	//n, 要找的基准数
	public static void find3larger(int n, List<Integer> lst) {
		TreeSet<Integer> innerlst = new TreeSet<Integer>();

		for (int i = 0; i < lst.size(); i++) {
			int x = lst.get(i);

			if(x <= n)
				continue;

			if (innerlst.size() < NUM) {
				innerlst.add(x);
			} else {
				int max = innerlst.last();
				if (x > max)
					continue;
				else{
					innerlst.add(x);
					innerlst.remove(max);
				}
			}
		}

		if(innerlst.size() == NUM)
			System.out.println("3rd larger item: " + innerlst.last());
		else
			System.out.println("no 3rd larger item exist");
	}

	public static void main(String[] args) {
		Integer[] testArray = new Integer[]{9,7,5,2,18,8,10};
		List<Integer> lst = Arrays.asList(testArray);
		find3larger(2, lst);
	}
}

