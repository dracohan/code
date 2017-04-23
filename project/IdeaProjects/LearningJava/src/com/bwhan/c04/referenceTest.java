package c04;
/**
 * @project: LearningJava
 * @filename: referenceTest.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 11:15 2015/8/22
 * @comment: Test Purpose
 * @result:
 */

interface i{
	void iter();
}

class A{
	int i ;
	A(int x){
		i = x;
	}
}

class B{
	int j;
	B(int x){
		j = x;
	}
}

class C implements i{
	public void iter(){
		System.out.println("C.iter()");
	}
}

class D implements i{
	public void iter(){
		System.out.println("D.iter()");
	}
}
public class referenceTest {
	public static void main(String[] args) {
		A a = new A(1);
		B b = new B(2);

		A aa = a;
		aa.i = 3;
		System.out.println("i is: " + a.i);

		C c = new C();
		i iter = c;
		iter.iter();

		iter = new D();
		iter.iter();

		if(c instanceof i)
			System.out.println("c is type of interface i");
		else
			System.out.println("c is NOT type of interface i");

	}
}
