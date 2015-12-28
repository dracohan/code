package c12;
/**
 * @project: ThinkingInJava
 * @filename: Alias2.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 10:00 AM 7/28/15
 * @comment: Test Purpose
 * @result:
 */

import static tool.util.*;

//: Alias2.java
// Method calls implicitly alias their
// arguments.
public class Alias2 {
    int i;
    Alias2(int ii) { i = ii; }
    static void f(final Alias2 handle) {
        handle.i++;
        //handle = new Alias2(2);
    }
    static void g(int i){
        i++;
    }
    public static void main(String[] args) {
        Alias2 x = new Alias2(7);
        System.out.println("x: " + x.i);
        System.out.println("Calling f(x)");
        f(x);
        int y = 2;
        g(y);
        System.out.println("x: " + x.i);
        prt(y);
    }
} ///:~
