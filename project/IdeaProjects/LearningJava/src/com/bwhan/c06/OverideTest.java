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
	int k = 3;
	final void prtb(){
		System.out.println("basic class func read i: " + i);
	}

	void func(){
		System.out.println("B.func()");
	}
}

class D extends B{
	int i = 2;
	int j = 5;
	void prtd(){
		System.out.println("derived class func read i: " + i);
	}


    void func(){
		System.out.println("D.func()");
	}
}

public class OverideTest {
	public static void main(String[] args) {
		B b = new B();
		//基类对象访问基类成员
		System.out.println("basic class i: "+b.i);

		D d = new D();
		//派生类访问派生类成员
		System.out.println("derived class i:"+d.i);
		d.prtb();
		d.prtd();

		//访问继承而来的成员变量
		System.out.println("k from B: " + d.k);

		B bb = new D();
		//转换成了父类型了子类特有的变量就不再可以访问了
		//System.out.println(bb.j);
		//访问基类继承而来的类型也是父类性的值
		System.out.println("read i of derived class with basic class handle: "+bb.i);

		//实际的类型有关
		b.func();
		d.func();
		bb.func();




	}
}
