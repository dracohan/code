package oschina.IT100;
/**
 * @project: oschina
 * @filename: IT6.java
 * @version: 0.10
 * @author: JM Han
 * @date: 21:46 2015/11/2
 * @comment: 数值: 0,1,2,3,4,5,6,7,8,9
 *           分配: 6,2,1,0,0,0,1,0,0,0
 * @result:
 */

import java.util.ArrayList;
import static tool.util.*;

public class IT6 {
	public static final int NUM = 10;
	ArrayList<Integer> lsta = new ArrayList<Integer>();
	ArrayList<Integer> lstb = new ArrayList<Integer>();
	boolean success;
	public IT6(){
		success = false;
		for (int i = 0; i < NUM; i++){
			lsta.add(i);
			lstb.add(i);
		}
	}
	ArrayList getB(){
		while(success != true){
			setNextB();
		}
		return lstb;
	}
	void setNextB(){
		boolean flag =true;
		for (int i=0; i < NUM; i++){
			int f = getFrequency(i);
			if(lstb.get(i) != f){
				lstb.set(i, f);
				flag = false;
			}
		}
		success = flag;
	}
	int getFrequency(int value){
		int count = 0;
		for(int i = 0; i < NUM; i++){
			if(lstb.get(i) == value)
				count++;
		}
		return count;
	}
	public static void main(String[] args) {
		IT6 test = new IT6();
		ArrayList<Integer> res = test.getB();
		printGenericIterator(test.lsta.iterator());
		System.out.println();
		printGenericIterator(test.lstb.iterator());

	}



}
