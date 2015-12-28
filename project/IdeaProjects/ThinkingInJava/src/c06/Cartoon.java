package c06;

/**
 * Created by root on 4/13/15.
 */
//: Cartoon.java
// Constructor calls during inheritance
class Art {
    Art() {
        System.out.println("Art constructor");
    }
}
class Drawing extends Art {
    Drawing() {
        System.out.println("Drawing constructor");
    }
}
public class Cartoon extends Drawing {
    Cartoon() {
        System.out.println("Cartoon constructor");
    }
    public static void main(String[] args) {
        Cartoon x = new Cartoon();
    }
} ///:~
