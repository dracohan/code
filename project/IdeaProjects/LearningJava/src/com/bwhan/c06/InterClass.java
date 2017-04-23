package c06;

/**
 * Created by Jimmy on 2015/6/2.
 */
class A{
    class B{
        void print(){
            System.out.println("wocao");}
    }
}

class C{
    C(int x){
        System.out.println("C class default constructor");
    }
    protected static class D{
        void print(){
            System.out.println("nima");}
    }
}

class E extends C{
    E(){
        super(1);
        System.out.println("E class default constructor");
    }
}

public class InterClass {
    public static class F{
        public static class G{
            public void print(){
                System.out.println("nima");}
        }
    }
    public static void main(String[] args){
        //静态就可以直接引用，否则必须有实例。方法如此，类也如此。
        A a = new A();
        A.B ab = a.new B();
        ab.print();

        C.D cd = new C.D();
        cd.print();

        //继承也一样
        E.D ed = new E.D();
        ed.print();

        //F.G.printEnumeration();

        E e = new E();

    }
}
