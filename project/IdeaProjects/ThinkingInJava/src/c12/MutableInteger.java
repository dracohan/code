package c12;
/**
 * @project: ThinkingInJava
 * @filename: MutableInteger.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 7:00 PM 7/31/15
 * @comment: Test Purpose
 * @result:
 */

//: MutableInteger.java
// A changeable wrapper class
import java.util.*;
class IntValue {
    int n;
    IntValue(int x) { n = x; }
    public String toString() {
        return Integer.toString(n);
    }
}
public class MutableInteger {
    public static void main(String[] args) {
        Vector v = new Vector();
        for(int i = 0; i < 10; i++)
            v.addElement(new IntValue(i));
        System.out.println(v);
        for(int i = 0; i < v.size(); i++)
            ((IntValue)v.elementAt(i)).n++;
        System.out.println(v);
    }
} ///: