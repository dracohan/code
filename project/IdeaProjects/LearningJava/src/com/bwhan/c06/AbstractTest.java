package c06;

import java.util.Objects;

/**
 * @project: LearningJava
 * @filename: AbstractTest.java
 * @version: 0.10
 * @author: Powell
 * @date: 22:58 2015/9/8
 * @comment: Test Purpose
 * @result:
 */

abstract class InitialValue{
	abstract  void prt();
}

class extendsclass extends InitialValue{
	@Override
	void prt(){
		System.out.println("wawa");
	}
}

class myc{
	static void printa(){
		System.out.println("shit");
	}
}
public class AbstractTest {


	public static void main(String[] args) {
		extendsclass ist = new extendsclass();
		ist.prt();

		String[] strArr = new String[5];
		Object[] objArr = new Object[5];
		//1, compile error
		//strArr[0] = new myc();
		//2, OK, myc is Object
		objArr[0] = new myc();

		objArr = strArr;
		//ArrayStoreEception in array alias, compiler cant detect the type mismatch
		objArr[1] = new myc();



	}
}
