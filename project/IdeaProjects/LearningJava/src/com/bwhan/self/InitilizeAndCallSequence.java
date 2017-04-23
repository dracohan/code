package LearnJava;

/**
 * Created by Jimmy on 2015/5/28.
 */
import static java.lang.System.*;

class Foo{
    public Foo(){
        System.out.println("Foo constructor without arg.");
    }
    public Foo(Foo f){
        System.out.println("Foo copy constructor.");
    }
}

class Bar{
    public Bar(){
        System.out.println("Bar constructor without arg.");
    }
    public Bar(Bar b){
        System.out.println("Bar copy constructor.");
    }
}

class Base{
    public Base(){
        System.out.println("Base constructor without arg.");
    }
    {
        System.out.println("Just a block in class B");
    }
}

class Derived extends Base{
    public Derived(){
        System.out.println("Derived constructor without arg.");
    }
    public Derived(Foo ff, Bar bb){
        System.out.println("Derived constructor(Foo ff, Bar bb) without arg.");
        m_foo = new Foo(ff);
        m_bar = new Bar(bb);
    }
    public Derived(Bar bb, Foo ff){
        //通过this重载构造函数，则其必须为第一条语句
        this(ff, bb);
        System.out.println("Derived constructor(Bar bb, Foo ff) without arg.");
    }
    {
        System.out.println("Just a block in class Derived");
    }
    private Foo m_foo;
    private Bar m_bar;
}

public class InitilizeAndCallSequence {
    public static void main(String[] args){
        Foo foo = new Foo();
        Bar bar = new Bar();

        System.out.println("##### test start #####");
        System.out.println("test case 1:");
        Derived derived_1 = new Derived();

        System.out.println("test case 2:");
        Derived derived_2 = new Derived(foo, bar);

        System.out.println("test case 3:");
        Derived derived_3 = new Derived(bar, foo);
        System.out.println("##### test end #####");
    }
}




