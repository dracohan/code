package oschina.cc150;

import java.util.*;

import static tool.util.*;

/**
 * @project: oschina
 * @filename: cc0207.java
 * @version: 0.10
 * @author: JM Han
 * @date: 17:00 2015/11/25
 * @comment: 删除未排序数组的重复元素
 * @result:
 */

public class cc0201 {
	static void deleteDup(List lst){
		HashSet hasSet = new HashSet();
		for (int i = 0; i < lst.size(); i++){
			if(hasSet.contains(lst.get(i)) == false){
				hasSet.add(lst.get(i));
			}else{
				lst.remove(i--);
			}
		}
	}
	public static void main(String[] args) {
		List lst = new LinkedList<Integer>();
		lst.add(9);
		lst.add(8);
		lst.add(7);
		lst.add(6);
		lst.add(5);
		lst.add(4);
		lst.add(3);
		lst.add(2);
		lst.add(0);
		lst.add(7);
		lst.add(6);
		lst.add(1);
		System.out.println("before: ");
		printGenericIterator(lst.iterator());
		System.out.println("\n");
		deleteDup(lst);
		System.out.println("after: ");
		printGenericIterator(lst.iterator());


	}
}
