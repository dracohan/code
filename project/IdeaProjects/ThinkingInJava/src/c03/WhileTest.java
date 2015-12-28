package c03;

/**
 * Created by bwhan on 4/2/15.
 */
//: WhileTest.java
// Demonstrates the while loop
public class WhileTest {
    public static void main(String[] args) {
        double r = 0;
        while(r < 0.99d) {
            r = Math.random();
            System.out.println(r);
        }
    }
} ///:~
