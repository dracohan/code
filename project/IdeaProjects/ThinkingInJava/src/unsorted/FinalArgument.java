package com.company;

/**
 * Created by bwhan on 2015/2/2.
 */


//: FinalArguments.java
// Using "final" with method arguments
class Gizmo {
    public void spin() {}
}
public class FinalArgument {
    void with(final Gizmo g) {
//! g = new Gizmo(); // Illegal -- g is final
        g.spin();
    }
    void without(Gizmo g) {
        g = new Gizmo(); // OK -- g not final
        g.spin();
    }
    // void f(final int i) { i++; } // Can't change
// You can only read from a final primitive:
    int g(final int i) { return i + 1; }
    public static void main(String[] args) {
        FinalArgument bf = new FinalArgument();
        Gizmo g = new Gizmo();
        bf.without(null);
        bf.with(null);
    }
} ///:~