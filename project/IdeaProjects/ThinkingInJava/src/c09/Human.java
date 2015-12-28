package c09;

/**
 * Created by bwhan on 5/4/15.
 */
//: Human.java
// Catching Exception Hierarchies
class Annoyance extends Exception {}
class Sneeze extends Annoyance {}
public class Human {
    public static void main(String[] args) {
        try {
            throw new Sneeze();
        } catch(Sneeze s) {
            System.out.println("Caught Sneeze");
        } catch(Annoyance a) {
            System.out.println("Caught Annoyance");
        }
    }
} ///:~
