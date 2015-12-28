package c04;

/**
 * Created by bwhan on 4/2/15.
 */
//: SimpleConstructor.java
// Demonstration of a simple constructor
class Rock {
    Rock() { // This is the constructor
        System.out.println("Creating Rock");
    }
}
public class SimpleConstructor {
    public static void main(String[] args) {
        for(int i = 0; i < 10; i++)
            new Rock();
    }
} ///:~
