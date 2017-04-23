package self;

/**
 * Created by Jimmy on 2015/5/30.
 */
interface ddd{
    void a();
    void b();
    void c();
    void d();
}

interface eee{
    void a();
    void b();
    void c();
    void d();
}


class InterfaceTest1 implements ddd,eee {
    public void a() {
        System.out.println("a");
    }

    public void b() {
        System.out.println("b");
    }

    public void c() {
        System.out.println("c");
    }

    public void d() {
        System.out.println("d");
    }
}

public class InterfaceTest implements ddd{
    public void a(){
        System.out.println("a");
    }
    public void b(){
        System.out.println("b");
    }
    public void c(){
        System.out.println("c");
    }
    public void d(){
        System.out.println("d");
    }

    public static void main(String[] args){
        InterfaceTest it = new InterfaceTest();
        InterfaceTest1 it1 = new InterfaceTest1();
        ddd dhandler = it;
        dhandler = it1;
        it.a();
        it.b();
        it.c();
        it.d();

    }
}
