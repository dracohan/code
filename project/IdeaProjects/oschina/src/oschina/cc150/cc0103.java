package oschina.cc150;
/**
 * @project: oschina
 * @filename: cc003.java
 * @version: 0.10
 * @author: JM Han
 * @date: 15:21 2015/11/20
 * @comment: Test Purpose
 * @result:
 */

import java.lang.reflect.Array;
import java.util.*;


import static tool.util.*;

public class cc0103 {
	static String sort(String s){
		String ns = s.toLowerCase();
		char[] ca = ns.toCharArray();
		Arrays.sort(ca);
		return new String(ca);
	}

	/*
	 * O(nlogn)
	 * O(n)
	 */
	static boolean permutation(String s1, String s2){
		if(s1.length() != s2.length())
			return false;
		return sort(s1).equalsIgnoreCase(sort(s2));
	}

	/*static HashMap<Character, Integer> count(String s){
		HashMap<Character, Integer> hashMap = new HashMap<Character, Integer>();
		for(int i = 0; i < s.length(); i++){
			Character c = s.charAt(i);
			Integer count = hashMap.get(c);
			count = (count == null? 1: count + 1);
			hashMap.put(c, count);
		}
		return hashMap;
	}

	static boolean check(HashMap hashMap1, HashMap hashMap2){
		if(hashMap1.size() != hashMap2.size())
			return false;
		Collection c = hashMap1.entrySet();
		Iterator iter= c.iterator();
		while(iter.hasNext()){
			Map.Entry e = (Map.Entry)iter.next();
			if((Integer)e.getValue() != (Integer)hashMap2.get((Character)e.getKey()))
				return false;
		}
		return true;
	}

	static boolean permutation2(String s1, String s2){
		if(s1.length() != s2.length())
			return false;
		return check(count(s1), count(s2));
	}*/

	static int[] count(String s){
		int[] int_set = new int[256];
		char[] char_set = s.toCharArray();
		for(char c: char_set){
			int_set[c]++;
		}
		return int_set;
	}
	static boolean permutation2(String s1, String s2){
		if(s1.length() != s2.length())
			return false;

		int[] count = new int[256];
		char[] chars = s1.toCharArray();
		for(char c: chars){
			count[c]++;
		}

		for (int i =0; i < s2.length(); i++){
			if(--count[s2.charAt(i)] < 0)
				return false;
		}

		return true;
	}

	public static void main(String[] args) {
		String s1 = "adae ff";
		String s2 = "aade ff";
		System.out.println("The 2 String are from same characters? " + permutation2(s1, s2));
	}
}
