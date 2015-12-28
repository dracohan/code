package c07;

/**
 * Created by root on 4/17/15.
 */
//: Parcel7.java
// An anonymous inner class that calls the
// base-class constructor

public class Parcel7 {
    public Wrapping wrap(int x) {
        int a = 1;
// Base constructor call:
        return new Wrapping(x) {
            public int value() {
                return super.value() * 47;
            }
        }; // Semicolon required
    }
    public static void main(String[] args) {
        Parcel7 p = new Parcel7();
        Wrapping w = p.wrap(10);

    }
} ///:~
