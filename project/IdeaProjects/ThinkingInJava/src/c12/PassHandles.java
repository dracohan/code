package c12;

/**
 * @project: ThinkingInJava
 * @filename: PassHandles.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 9:54 AM 7/28/15
 * @comment: Test Purpose
 * @result:
 */

import static c10.AnalyzeSentence.*;

//: PassHandles.java
// Passing handles around
public class PassHandles {
    static void f(PassHandles h) {
        System.out.println("h inside f(): " + h);
    }
    static void g(int x){x= x + 1;}
    public static void main(String[] args) {
        PassHandles p = new PassHandles();
        System.out.println("p inside main(): " + p);
        f(p);
        int y = 2;
        g(y);
        prt("y: " + y);
    }
} ///:
