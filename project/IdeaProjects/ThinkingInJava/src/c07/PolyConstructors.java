package c07;

/**
 * Created by root on 4/20/15.
 */
//: PolyConstructors.java
// Constructors and polymorphism
// don't produce what you might expect.
abstract class Glyph {

    abstract void draw();
    Glyph() {
        System.out.println("Glyph() before draw()");
        draw();
        System.out.println("Glyph() after draw()");
    }
}

class Var{
    Var(){System.out.println("Var.Var()");}
}
class RoundGlyph extends Glyph {
    int radius = 1;
    Var v = new Var();
    RoundGlyph(int r) {
        radius = r;
        System.out.println(
                "RoundGlyph.RoundGlyph(), radius = "
                        + radius);
    }
    void draw() {
        System.out.println(
                "RoundGlyph.draw(), radius = " + radius);
    }
}
public class PolyConstructors {
    public static void main(String[] args) {
        new RoundGlyph(5);
    }
} ///:~
