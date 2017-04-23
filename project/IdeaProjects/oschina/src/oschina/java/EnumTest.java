package oschina.java;
/**
 * @project: oschina
 * @filename: EnumTest.java
 * @version: 0.10
 * @author: JM Han
 * @date: 21:38 2015/11/2
 * @comment: Test Purpose
 * @result:
 */

import static tool.util.*;

public class EnumTest {
	public enum Fruit{
		APPLE, PEAR, PEACH, ORANGE;
	}

	public static void main(String[] args) {
		Fruit f = Fruit.PEACH;
	}
}
