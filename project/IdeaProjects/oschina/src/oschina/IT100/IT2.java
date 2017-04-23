package oschina.IT100;
/**
 * @project: oschina
 * @filename: IT2.java
 * @version: 0.10
 * @author: JM Han
 * @date: 17:08 2015/10/20
 * @comment: design a stack that has min function which could return the min element at anytime
 * @result:
 */

import java.util.Stack;

class MinStack{
	Stack<Integer> stacks, mins;
	MinStack(){
		stacks = new Stack<Integer>();
		mins   = new Stack<Integer>();
	}
	void push(Integer x){
		stacks.push(x);
		//use <= instead of < for duplicate element
		if(mins.isEmpty() || x <= mins.peek())
			mins.push(x);
	}
	void pop(){
		Integer x = stacks.pop();
		if(x == mins.peek())
			mins.pop();
	}
	Integer peek(){
		return stacks.peek();
	}
	Integer getMin(){
		return mins.peek();
	}
}

public class IT2 {
	public static void main(String[] args) {
		MinStack minStack = new MinStack();
		minStack.push(6);
		minStack.push(2);
		minStack.push(3);
		minStack.push(1);
		minStack.push(1);
		minStack.push(5);
		minStack.push(8);
		System.out.println("Content of stack: \n" + minStack.stacks);
		System.out.println("min value of stack: \n" + minStack.getMin());
		System.out.println("Content of mins: \n" + minStack.mins);
		minStack.pop();
		minStack.pop();
		minStack.pop();
		System.out.println("Content of mins: \n" + minStack.mins);
		System.out.println("min value of stack: \n" + minStack.getMin());
	}
}
