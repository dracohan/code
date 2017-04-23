package other;

//: AutoInc.java
// Demonstrates the ++ and -- operators
public class AutoInc {
    public static void main(String[] args) {
        int i = 1;
        prt("i : " + i);
        prt("++i : " + ++i); // Pre-increment
        prt("i++ : " + i++); // Post-increment
        prt("i : " + i);
        prt("--i : " + --i); // Pre-decrement
        prt("i-- : " + i--); // Post-decrement
        prt("i : " + i);
        int x = 1, y = 2;
        if(x == y)
            System.out.println("Equal");
        else
            System.out.println("NOT Equal");
    }
    static void prt(String s) {
        System.out.println(s);
    }
} ///:~