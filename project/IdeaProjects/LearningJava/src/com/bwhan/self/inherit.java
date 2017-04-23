package self;

/**
 * Created by Jimmy on 2015/4/13.
 */
class base{
    int i = 0;
    private int j = 1;
    void prt() {System.out.println("From base: " + i );}
   /* base printEnumeration(){return 1;};*/

}

interface abc {}

public class inherit extends base{
    inherit print() {return this;}
    int i = 1;
    void prt() {
        System.out.println("i From base: " + super.i );
        System.out.println("i From inherit: " + i );
    }

    void printclass(base b){
        ;
    }

    public static void main(String[] args) {
        inherit cl = new inherit();
        base a = new base();
/*        a.j = 2;*/
        cl.prt();
/*        abc a;*/
    }
}
