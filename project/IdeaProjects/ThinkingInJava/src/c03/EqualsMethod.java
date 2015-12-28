package c03;

import java.util.Objects;

/**
 * @project: ThinkingInJava
 * Created by bwhan on 9/9/15.
 */
//: EqualsMethod.java
class Value{
    int v;
    public Value(){
        v = 1;
    }

    public boolean equals(Object arg){
/*        if(!(arg instanceof Value) || arg == null)
            return false;*/
        Value oarg = (Value)arg;
        return oarg.v == this.v;
    }
}

public class EqualsMethod {
    public static void main(String[] args) {
        Integer n1 = new Integer(47);
        Integer n2 = new Integer(47);
        System.out.println(n1.equals(n2));//true
        System.out.println(n1 == n2); //false

        int n3 = 1;
        int n4 = 1;
        //System.out.println(n3.equals(n4));
        System.out.println(n3 == n4);//true

        //可以看出str1和str2是指向同一个对象的。
        String str1 = "abc";
        String str2 = "abc";
        System.out.println(str1==str2); //true
        System.out.println(str1.equals(str2)); //true

        //用new的方式是生成不同的对象。每一次生成一个。
        String str3 =new String ("abc");
        String str4 =new String ("abc");
        System.out.println(str3==str4); // false
        System.out.println(str3.equals(str4)); // true

        Value v1 = new Value();
        Value v2 = new Value();
        System.out.println(v1==v2); // false
        System.out.println(v1.equals(v2)); // true


    }
} ///:~
