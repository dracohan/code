package c07;

/*
*
 * Created by root on 4/17/15.

*/



//: Parcel3.java
// Returning a handle to an inner class

//normal class can't be private or protected
//But innner class could
/*private class ABC{

}*/
abstract class Contents1 {
    abstract public int value();
}
interface Destination1 {
    String readLabel();
}
public class Parcel3 {
    private class PContents extends Contents1 {
        private int i = 11;
        public int value() { return i; }

    }
    protected class PDestination
            implements Destination {
        private String label;
        private PDestination(String whereTo) {
            label = whereTo;
        }
        public String readLabel() { return label; }
    }
    public Destination dest(String s) {
        return new PDestination(s);
    }
    public Contents1 cont() {
        return new PContents();
    }
}
class Test {
    public static void main(String[] args) {
        Parcel3 p = new Parcel3();
        Contents1 c = p.cont();
        Destination d = p.dest("Tanzania");
// Illegal -- can't access private class:
//! Parcel3.PContents c = p.new PContents();
    }
} ///:~
