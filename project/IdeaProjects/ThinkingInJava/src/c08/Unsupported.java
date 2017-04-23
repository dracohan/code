package c08;
/**
 * @project: ThinkingInJava
 * @filename: Unsupported.java
 * @version: 0.10
 * @author: JM Han
 * @date: 10:58 2015/11/18
 * @comment: Test Purpose
 * @result:
 */

import java.util.*;

import static tool.util.printGenericIterator;

public class Unsupported {
	public static void main(String[] args) {

		List<String> b = new ArrayList();
		for(int i = 0; i < 10; i++)
			b.add(Integer.toString(i));
		boolean b1 = b instanceof List;
		System.out.println(b1);
		ListIterator it = b.listIterator();
		it.add("xyz");
		it.add(new Integer(10));
		System.out.println("test");
		printGenericIterator(it);

		String[] s = {
				"one", "two", "three", "four", "five",
				"six", "seven", "eight", "nine", "ten",
		};
		List<String> a = Arrays.asList("abc", "def", "ghi");
		boolean b2 = a instanceof LinkedList;
		System.out.println(b2);
		//iterManipulation(a);
		ListIterator lit = a.listIterator(0);
		System.out.println(lit.next());

		List<Objects> l1 = new ArrayList<Objects>();
		List<String> l2 = new ArrayList<String>();


	}
} ///: