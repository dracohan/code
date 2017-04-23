package com.company;

//: OrderOfInitialization.java
// Demonstrates initialization order.
// When the constructor is called, to create a
// Tag object, you'll see a message:
class Tag {
    Tag() {
        System.out.println("Default Tag constructor.");
    }
    Tag(int marker) {
        System.out.println("Tag(" + marker + ")");
    }
}
class Card {
    Tag t1 = new Tag(1); // Before constructor
    Card(Tag t) {
// Indicate we're in the constructor:
        System.out.println("Card()");
        t3 = t; // Re-initialize t3
    }
    Tag t2 = new Tag(2); // After constructor
    void f() {
        System.out.println("f()");
    }
    Tag t3 ; // At end
    void g() {
        System.out.println("t3: " + t3);
    }
}
public class OrderOfInitialization {
    public static void main(String[] args) {
        Tag ti = new Tag(1);
        Card t = new Card(ti);
        t.f(); // Shows that construction is done
        Tag n = t.t3;
    }
} ///:~