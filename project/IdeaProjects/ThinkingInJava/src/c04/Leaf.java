package c04;

/**
 * Created by bwhan on 4/2/15.
 */
//: Leaf.java
// Simple use of the "this" keyword
public class Leaf {
    private int i = 0;
    Leaf increment() {
        i++;
        return this;
    }
    void print() {
        System.out.println("i = " + i);
    }
    public static void main(String[] args) {
        Leaf x = new Leaf();
        x.increment().increment().increment().print();
    }
} ///:~
