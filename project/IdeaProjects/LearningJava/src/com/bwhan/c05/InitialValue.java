package c05;

/**
 * Created by Jimmy on 2015/4/11.
 */

//: InitialValues.java
// Shows default initial values
class Measurement {
    boolean t;
    char c;
    byte b;
    short s;
    int i=9 ;
    long l;
    float f;
    double d;
    static int k;
    {
        t = true;
        k = 9;
    }

    {
        i = 10;
    }
    void print() {
        double g;
        i = i + 1;
        //g = g+ 1;
        System.out.println(
                "Data type Inital value\n" +
                        "boolean " + t + "\n" +
                        "char " + c + "\n" +
                        "byte " + b + "\n" +
                        "short " + s + "\n" +
                        "int " + i + "\n" +
                        "long " + l + "\n" +
                        "float " + f + "\n" +
                        "double " + d + "/n" +
                        "static int " + k);
    }
}
public class InitialValue {
    final static  int i = 0;
    public static void printfuck(){System.out.println("fuck!");}
    public static void main(String[] args) {
        Measurement d = new Measurement();
        //i = 1;
        d.print();
        printfuck();
/* In this case you could also say:
new Measurement().printEnumeration();
*/
    }
} ///:~
