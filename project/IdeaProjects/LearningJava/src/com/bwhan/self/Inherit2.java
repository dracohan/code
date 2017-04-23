package self;

/**
 * Created by Jimmy on 2015/5/29.
 */
class BaseClass{
    int x;

    void printvar(){
        System.out.println("printvar(): x is: " + x);
    }
    void mf1(){
        System.out.println("BaseClass.mf1()");
    }
    void mf1(int i){
        System.out.println("BaseClass.mf1(int)");
    }
    static void mf2(){
        System.out.println("BaseClass.mf2()");
    }
}

class DerivedClass extends BaseClass{
    float x;

    void printvar(){
        System.out.println("printvar(): x is: " + x);
        System.out.println("printvar(): super.x is: " + super.x);
    }
    void mf1(){
        System.out.println("DerivedClass.mf1()");
    }
    void mf4(){
        System.out.println("DerivedClass.mf4()");
    }
}
public class Inherit2 {
    public static void main(String[] args){
        //基类的成员变量
        BaseClass bc = new BaseClass();
        System.out.println("BaseClass.x is: " + bc.x);

        //派生类的成员变量
        DerivedClass dc = new DerivedClass();
        System.out.println("DerivedClass.x is: " + dc.x);
        dc.mf2();
        dc.mf4();

        //派生类的成员变量和super访问的基类成员变量
        dc.printvar();

        //基类的成员变量
        BaseClass bchandler = new DerivedClass();
        System.out.println("BaseClass handler x is: " + bchandler.x);

        bchandler.mf1();
        bchandler.mf1(4);


    }
}

interface A{
	void prt();
}

interface B{
	void prt();
}

