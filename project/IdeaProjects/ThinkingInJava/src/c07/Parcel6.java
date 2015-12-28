package c07;

/**
 * Created by root on 4/17/15.
 */
//: Parcel6.java
// A method that returns an anonymous inner class

public class Parcel6 {
    public Contents cont() {
        return new Contents() {
            private int i = 11;
            public int value() { return i; }
        }; // Semicolon required in this case
    }
    public static void main(String[] args) {
        Parcel6 p = new Parcel6();
        Contents c = p.cont();
    }
} ///:~
