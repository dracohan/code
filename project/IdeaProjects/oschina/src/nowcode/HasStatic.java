package nowcode;
/**
 * @project: oschina
 * @filename: HasStatic.java
 * @version: 0.10
 * @author: JM Han
 * @date: 16:42 2015/11/2
 * @comment: Test Purpose
 * @result:
 */

import static tool.util.*;

public class HasStatic {
	private static  int x = 100;

	public static void main(String[] args) {
		HasStatic hs1 = new HasStatic();
		hs1.x++;

		HasStatic hs2 = new HasStatic();
		hs2.x++;
		hs1 = new HasStatic();
		hs1.x++;
		HasStatic.x--;
		System.out.println("x=" + x);
	}
}
