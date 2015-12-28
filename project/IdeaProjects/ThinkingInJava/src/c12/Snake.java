package c12;
/**
 * @project: ThinkingInJava
 * @filename: Snake.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 10:46 AM 7/31/15
 * @comment: Test Purpose
 * @result:
 */

import static tool.util.*;

//: Snake.java
// Tests cloning to see if destination of
// handles are also cloned.
public class Snake implements Cloneable {
    private Snake next;
    private char c;
    private int v;
    // Value of i == number of segments
    Snake(int i, char x) {
        c = x;
        if(--i > 0)
            next = new Snake(i, (char)(x + 1));
    }

    Snake(int i, char x, int y) {
        c = x;
        v = y;
        if(--i > 0)
            next = new Snake(i, (char)(x + 1), y);
    }

    void increment() {
        c++;
        if(next != null)
            next.increment();
    }
    public String toString() {
        String s = ":" + c + "-" + v;
        if(next != null)
            s += next.toString();
        return s;
    }
    public Object clone() {
        Object o = null;
        try {
            o = super.clone();
        } catch (CloneNotSupportedException e) {}
        //*************************************
        //trigger of deep copy
        //if(next != null)
        //    next = (Snake)next.clone();
        //*************************************

        return o;
    }
    public static void main(String[] args) {
        Snake s = new Snake(5, 'a');
        System.out.println("s = " + s);
        Snake s2 = (Snake)s.clone();
        System.out.println("s2 = " + s2);
        s.increment();
        System.out.println(
                "after s.increment, s = " + s);
        System.out.println(
                "after s.increment, s2 = " + s2);

        Snake t = new Snake(3, 'r', 2);
        Snake t1 = (Snake)t.clone();
        prt("t = " + t);
        prt("t1 = " + t1);
        t.increment();
        prt("After t.increment:");
        prt("t = " + t);
        prt("t1 = " + t1);


    }
} ///: