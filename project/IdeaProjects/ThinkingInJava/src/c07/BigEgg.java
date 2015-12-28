package c07;

/**
 * Created by root on 4/17/15.
 */
//: BigEgg.java
// An inner class cannot be overriden
// like a method
class Egg {
    protected class Yolk {
        public Yolk() {
            System.out.println("Egg.Yolk()");

        }
        void print() {System.out.println("Egg.Tolk.print()");}
    }
    void print() {System.out.println("Egg.print()");}
    private Yolk y;
    public Egg() {
        System.out.println("New Egg()");
 /*       y = new Yolk();

        y.print();*/
    }
}
public class BigEgg extends Egg {
    public class Yolk {
        public Yolk() {
            System.out.println("BigEgg.Yolk()");
        }
    }
    public static void main(String[] args) {
        new BigEgg();
    }
} ///:~
