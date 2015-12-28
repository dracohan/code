package c12;
/**
 * @project: ThinkingInJava
 * @filename: Cloning.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 10:12 AM 7/28/15
 * @comment: Test Purpose
 * @result:
 */

//: Cloning.java
// The clone() operation works for only a few
// items in the standard Java library.
import java.util.*;
class Int {
    private int i;
    public Int(int ii) { i = ii; }
    public void increment() { i++; }
    public String toString() {
        return Integer.toString(i);
    }
}
class MyClass {
    Integer i = new Integer(2);

    void g() {
        try {
            clone();
        } catch (CloneNotSupportedException e) {

        }
    }
}

public class Cloning {
    public static void main(String[] args) {
        Vector v = new Vector();
        for(int i = 0; i < 10; i++ )
            v.addElement(new Int(i));
        System.out.println("v: " + v);
        Vector v2 = (Vector)v.clone();
// Increment all v2's elements:
        for(Enumeration e = v2.elements();
            e.hasMoreElements(); )
            ((Int)e.nextElement()).increment();
// See if it changed v's elements:
        System.out.println("v: " + v);

        Integer x = new Integer(1);
        //x.clone();
    }
} ///:
