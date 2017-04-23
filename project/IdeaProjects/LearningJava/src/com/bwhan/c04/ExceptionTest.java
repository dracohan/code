package c04;

import sun.reflect.annotation.ExceptionProxy;

import java.io.IOException;

/**
 * @project: LearningJava
 * @filename: ExceptionTest.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 7:05 2015/8/23
 * @comment: Test Purpose
 * @result:
 */

class MyException extends Exception{

}

public class ExceptionTest {
	static void func1(){
		System.out.println("enter func1");
		try{
			func2();
		}
		catch(Exception e){
			System.out.println("IOException handled in func1");
			e.printStackTrace(System.err);
			//e.getMessage();
		}
		System.out.println("continue func1");
	}
	static void func2() throws IOException{
		System.out.println("enter func2");
		func3();
		System.out.println("continue func2");
	}
	static void func3() throws IOException{
		System.out.println("enter func3");
		func4();
		System.out.println("continue func3");
	}
	static void func4() throws IOException{
		System.out.println("enter func4");
		throw new IOException("My test info");
		//Never reach compile error
		//System.out.println("continue func4");
	}

	static void func5(){
		System.out.println("enter func5");
		System.out.println("continue func5");
	}

	public static void main(String[] args) {
		func1();
		func5();
	}
}
