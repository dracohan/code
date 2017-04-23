package oschina.onsite;

import java.util.ArrayList;
import java.util.LinkedList;

class permutaion{
	/*
	 * 输入String s，找出所有的s的每个字符组成的排列组合
	 * 首先获得s的substring的排列组合
	 * 然后将首字符依次插入每一个排列中，得到新的排列组合
	 */
	public static ArrayList<String> getPermutation(String s){
		ArrayList<String> preRes = new ArrayList<String>();

		if(s.length() == 1){
			preRes.add(s);
			return preRes;
		}

		preRes = getPermutation(s.substring(1));

		char c = s.charAt(0);
		ArrayList<String> newRes= new ArrayList<String>();

		for (int i = 0; i < preRes.size(); i++){
			String ss = preRes.get(i);
			LinkedList<String> insertion = getInsertion(ss, c);
			newRes.addAll(insertion);
			insertion = null;
		}

		preRes = null;
		preRes = newRes;
		newRes = null;

		return preRes;
	}

	/*
	 * 返回由String和Char组成的所有排列
	 */
	public static LinkedList<String> getInsertion(String s, char c){
		LinkedList<String> res = new LinkedList<String>();
		int len = s.length();

		res.add(new StringBuilder().append(s).append(c).toString());
		res.add(new StringBuilder().append(c).append(s).toString());

		if(len > 1){
			for(int i = 1; i < len; i++){
				StringBuilder sb1 = new StringBuilder(s.substring(0, i));
				StringBuilder sb2 = new StringBuilder(s.substring(i, len));
				res.add(sb1.append(c).append(sb2).toString());
			}
		}
		return res;
	}

	public static void main(String[] args) {
		String str = "abc";
		ArrayList<String> res = getPermutation(str);
		for(String s:res){
			System.out.println(s);
		}
	}
}
