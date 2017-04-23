package web;
/**
 * @project: LearningJava
 * @filename: TestMeo.java
 * @version: 0.10
 * @author: JM Han
 * @date: 16:31 2015/10/19
 * @comment: Test Purpose
 * @result:
 */

import static tool.util.*;

public class TestMeo {

	/**测试基本数据类型以及引用类型参数按值传递
	 * @Description:
	 * @author shaobn
	 * @param args
	 * @Date:2015-9-8 上午7:53:56
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		testInt();
		testStr();
		testPack();
		testObj();
		testObj_2();
	}
	//NO1.测试基本数据类型
	public static void testInt(){
		int num1 = 12;
		System.out.println("Before change::"+num1);
		changeInt(num1);
		System.out.println("After change::"+num1);
	}
	//测试字符串类型
	public static void testStr(){
		String str = "helloworld";
		System.out.println("Before change::"+str);
		changeStr(str);
		System.out.println("After change::"+str);

	}
	//测试包装类型
	public static void testPack(){
		Integer integer = new Integer(42);
		System.out.println("Before change::"+integer);
		changePack(integer);
		System.out.println("After change::"+integer);
	}
	//测试引用类型
	public static void     testObj(){
		Person person = new Person();
		System.out.println("Before change::"+person.age);
		changeObj(person);
		System.out.println("After change::"+person.age);
	}
	//测试引用类型方式二
	public static void     testObj_2(){
		Person person = new Person();
		System.out.println("Before change::"+person.age);
		changeObj_2(person);
		System.out.println("After change::"+person.age);
	}
	public static void    changeInt(int num){
		num = 21;
	}
	public static void     changeStr(String str){
		str = "hellobeijing";
	}
	public static void     changePack(Integer integer){
		integer = new Integer(89);
	}
	public static void     changeObj(Person person){
		person.age = 87;
	}
	public static void     changeObj_2(Person person){
		person = new Person();
		person.age = 78;
	}
}
//引用类型测试类
class Person{
	public  int age = 78;
}
