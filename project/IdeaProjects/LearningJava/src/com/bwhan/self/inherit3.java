package self;

/**
 * Created by root on 4/14/15.
 */
import static tool.util.*;

class ca{

    private int i = 0;
    protected class cca{
        public cca(){System.out.println("cca construct");}
    }

    cca aa = new cca();

    public ca() {System.out.println("ca construct");
        System.out.println("ca construct1");}
    void ca_func(){System.out.println("ca_func");}

    //overload
    void ca_func(int i){System.out.println("overload1: ca_func(int)");}

    protected void cb_func(){prt("cb_func");}

}

class cb extends ca {
    public cb() {System.out.println("cb construct");}
    void ca_func(){System.out.println("cb_func");
        /*System.out.println(super.i);*/}

    //private void cb_func(){prt("cb_func");}
}



interface ia {
    void ca_func();
}

interface ib extends ia {
    void ca_func(int i);
}

interface ic extends ia, ib {

}
class ica implements ib {
    public void ca_func(){System.out.println("ca_func"); }
    public void ca_func(int i){System.out.println("ca_func"); }
}

public class inherit3 {
    public static void main(String[] args) {
        cb b = new cb();
        b.ca_func();
    }
}
