package c04;
/**
 * @project: ThinkingInJava
 * @filename: ArrayInit.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 4:45 PM 9/15/15
 * @comment: Test Purpose
 * @result:
 */

//: ArrayInit.java
// Array initialization
public class ArrayInit {
    public static void main(String[] args) {
        Integer[] a = {
                new Integer(1),
                new Integer(2),
                new Integer(3),
        };
// Java 1.1 only:
        Integer[] b = new Integer[] {
                new Integer(1),
                new Integer(2),
                new Integer(3),
        };
    }
} ///:~