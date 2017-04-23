package oschina.cc150;

import data.list.linkedlist;

/**
 * @project: oschina
 * @filename: cc0205.java
 * @version: 0.10
 * @author: JM Han
 * @date: 12:50 2015/12/6
 * @comment: 计算两个数字相加
 * @result:
 */

public class cc0205 {
	public static linkedlist res = new linkedlist();

	public static linkedlist addLists(linkedlist lst1, linkedlist lst2, int carry){
		while (lst1.size()!=0 && lst2.size()!=0){
			int v1 = 0; int v2 = 0;	int v3 = 0;
			v1 = lst1.getNode(0).data;
			v2 = lst2.getNode(0).data;
			v3 = v1 + v2 + carry;
			carry = v3/10;
			if(carry != 0) v3 = v3%10;
			res.add(v3);
			lst1.removeHead();
			lst2.removeHead();
		}

		//没加完情况下有进位
		if(carry == 0 && (lst1.size() != 0 || lst2.size() != 0)){
			if(lst1.size() != 0){
				for (int i = 0; i < lst1.size(); i++)
					res.add(lst1.getNode(i).data);
			}
			if(lst2.size() != 0){
				for (int i = 0; i < lst2.size(); i++)
					res.add(lst2.getNode(i).data);
			}
		} else if(carry != 0 && (lst1.size() != 0 || lst2.size() != 0)){
			linkedlist mres = new linkedlist();
			mres.add(carry);
			if(lst1.size() != 0){
				addLists(mres, lst1, 0);
			}
			if(lst2.size() != 0){
				addLists(mres, lst2, 0);
			}
		} else if(carry != 0){
			res.add(carry);
		}
		return res;
	}

	public static void main(String[] args) {
		linkedlist lst1 = new linkedlist();
		lst1.add(7);
		lst1.add(1);
		lst1.add(6);
		lst1.print();
		linkedlist lst2= new linkedlist();
		lst2.add(5);
		lst2.add(9);
		lst2.add(3);
		lst2.add(9);
		lst2.add(9);
		lst2.print();

		linkedlist res = addLists(lst1, lst2, 0);
		res.print();
	}
}
