package c12;
/**
 * @project: ThinkingInJava
 * @filename: Stringer.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 7:25 PM 7/31/15
 * @comment: Test Purpose
 * @result:
 */

//: Stringer.java
public class Stringer {
    static String upcase(String s) {
        return s.toUpperCase();
    }
    public static void main(String[] args) {
        String q = new String("howdy");
        System.out.println(q); // howdy
        String qq = upcase(q);
        System.out.println(qq); // HOWDY
        System.out.println(q); // howdy
    }
} ///:
