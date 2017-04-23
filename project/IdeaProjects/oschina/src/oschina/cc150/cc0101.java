package oschina.cc150;
/**
 * @project: oschina
 * @filename: cc001.java
 * @version: 0.10
 * @author: JM Han
 * @date: 22:56 2015/11/18
 * @comment: ȷ��һ���ַ����������ַ��Ƿ�ȫ����ͬ
 * @result:
 */

import java.util.TreeSet;

public class cc0101 {
	/* ʱ�临�Ӷ�
	 * �ռ临�Ӷ�
	 */
	static boolean isUniqueChars(String s){
		if(s.length() > 256)
			return false;

		TreeSet<Character> treeSet = new TreeSet<Character>();

		for (int i = 0; i < s.length(); i++){
			Character c = s.charAt(i);
			if(false == treeSet.add(c))
				return false;
		}
		return true;
	}

	/* ʱ�临�Ӷ�O(n)
	 * �ռ临�Ӷ�O(1)
	 */
	static boolean isUniqueChars1(String s){
		if(s.length() > 256)
			return false;

		boolean[] char_set= new boolean[256];
		for (int i = 0; i < s.length(); i++){
			int val = s.charAt(i);
			if(char_set[val] == true)
				return false;
			char_set[val] = true;
		}
		return true;
	}

	/* ʱ�临�Ӷ�O(n)
	 * �ռ临�Ӷ�O(1)
	 */
	static boolean isUniqueChars2(String s){
		if(s.length() > 256)
			return false;

		int checker = 0;
		for(int i = 0; i < s.length(); i++){
			int offset = s.charAt(i) - 'a';
			if((checker & (1<<offset)) > 0)
				return false;
			checker |= (1<<offset);
		}
		return true;
	}

	public static void main(String[] args) {
		String s = "abfcdefg";
		System.out.println("String uniqueness check result: " +
							isUniqueChars1(s));
	}
}
