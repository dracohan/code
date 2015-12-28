package c09;

/**
 * Created by bwhan on 5/4/15.
 */
//: NeverCaught.java
// Ignoring RuntimeExceptions
public class NeverCaught {
    static void f() {
        throw new RuntimeException("From f()");
    }
    static void g() {
        f();
    }
    public static void main(String[] args) {
        g();
    }
} ///:~
