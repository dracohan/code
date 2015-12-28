package c01;
/**
 * @project: ThinkingInJava
 * @filename: EqualTest.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 1:06 PM 9/9/15
 * @comment: Test Purpose
 * @result:
 */

public class EqualTest {
    String str1 = "abc";
    String str2 = "abc";
    //System.out.println("aaa"); //true
    //可以看出str1和str2是指向同一个对象的。

    public static void main(String[] args) {
        String str1 = "abc";
        String str2 = "abc";
        System.out.println(str1==str2); //true
        //可以看出str1和str2是指向同一个对象的。

        String str3 =new String ("abc");
        String str4 =new String ("abc");
        System.out.println(str3==str4); // false
    }
}
