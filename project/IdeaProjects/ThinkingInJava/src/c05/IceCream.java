package c05;

/**
 * Created by root on 4/10/15.
 */
//: IceCream.java
// Demonstrates "private" keyword
class Sundae {
    private Sundae() {}
    static Sundae makeASundae() {
        return new Sundae();
    }
}
public class IceCream {
    public static void main(String[] args) {
//! Sundae x = new Sundae();
        Sundae x = Sundae.makeASundae();
    }
} ///:~