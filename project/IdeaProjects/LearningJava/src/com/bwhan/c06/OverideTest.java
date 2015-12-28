package c06;

/**
 * @project: LearningJava
 * @filename: OverideTest.java
 * @version: 0.10
 * @author: Han Powell
 * @date: 21:33 2015/9/8
 * @comment: Test Purpose
 * @result:
 */

class B {
	final int i = 1;
	final void prtb(){
		System.out.println("basic class func read i: " + i);
	}

	static void func(){
		System.out.println("B.func()");
	}
}

class D extends B{
	int i = 2;
	void prtd(){
		System.out.println("derived class func read i: " + i);
	}

    static void func(){
		System.out.println("D.func()");
	}
}

public class OverideTest {
	public static void main(String[] args) {
		B b = new B();
		System.out.println("basic class i: "+b.i);

		D d = new D();
		System.out.println("derived class i:"+d.i);
		d.prtb();
		d.prtd();

		B bb = new D();
		System.out.println("read i of derived class with basic class handle: "+bb.i);

		B.func();
		D.func();

	}
}
