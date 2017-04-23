package LearnJava;
/**
 * Created by Jimmy on 2015/4/16.
 */
import java.lang.String;

class Value{
    int v;
    String s;

    public Value(){
        v = 1;
        s = "";
    }

    //覆盖equals方法
    public boolean equals(Object arg){
        if(!(arg instanceof Value) || arg == null)
            return false;
        //必须将Object转化为Value，否则不能访问v和s字段
        Value oarg = (Value)arg;
        return oarg.v == this.v && oarg.s == this.s;
    }
}
public class equal {

    public static void main(String[] args) {

        int i = 1;
        int j = 1;
        String s = "a";
        String ss = "a";
        Value v1 = new Value();
        Value v2 = new Value();

        if (i == j)
            System.out.println("int with same value ==");
        else
            System.out.println("int with same value not ==");

        if (s.equals(ss))
            System.out.println("String with same value equals");
        else
            System.out.println("String with same value not equals");

        if (v1 == v2)
            System.out.println("class ==");
        else
            System.out.println("class not ==");

        if (v1.equals(v2))
            System.out.println("class equal");
        else
            System.out.println("class not equal");
    }
}
