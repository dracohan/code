package cnblogs;
/**
 * @project: oschina
 * @filename: initSequence.java
 * @version: 0.10
 * @author: JM Han
 * @date: 17:33 2015/11/2
 * @comment: Test Purpose
 * @result:
 */

import static tool.util.*;

class A
{
	public A()
	{
		System.out.println("----------A construct-------------");
	}
	static  void sb()
	{
		System.out.println("----------A.sb() static A function-------------");
	}
	{
		System.out.println("----------A statement-------------");
	}
	static {
		System.out.println("----------A static statement-------------");
	}
}

class B extends A
{
	public B()
	{
		System.out.println("----------B constructor-------------");
	}
	static void sb()
	{
		System.out.println("----------B.sb() static B funstion-------------");
	}
	{
		System.out.println("----------B statement-------------");
	}
	static {
		System.out.println("----------B static statement-------------");
	}
}

public class initSequence
{
	public static void main(String[] args)
	{
		System.out.println("First time new: ");
		B b=new B();
		System.out.println("Second time new: ");
		B b1=new B();
		System.out.println("Call the static functions:");
		A.sb();
		b.sb();
	}
}

