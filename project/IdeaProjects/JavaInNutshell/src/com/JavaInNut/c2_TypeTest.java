package com.JavaInNut;

/**
 * Created by bwhan on 2015/2/26.
 */
public class c2_TypeTest {
    public static void main(String[] args) {
        //byte只能存-128-127，超过也不会溢出
        byte b1 = 127, b2 = 3;
        byte sum = (byte)(b1 + b2);
        System.out.println("The sum is:" + sum);

        //float和double不相等，两个float值相等时equal
        double d = 6.1E23;
        float f = 6.1f;
        float f1 = 6.1f;
        System.out.println("The float equal double test result is:" + (f == d));
        System.out.println("The float with same value equal test result is:" + (f == f1));

        int i = 13;
        //Java不允许narrow conversion
        //byte b = i;
        //但是你可以强制转化
        byte b = (byte)i;
        //并且转换回来时并不损失精度
        int i1 = b;
        System.out.println("The new i is :" + i1);
        System.out.println("Quotient: " + 7/3.0f);

        //&和|既可以作为逻辑操作符，也可以作为boolean操作符，但同&&和||不同的是他们两边的比较都会被执行
        if(f++ == f1 | f++ == f1)
            System.out.println("Equal!");
        else
            System.out.println("Not equal");

        System.out.println("f:" + f);


    }
}
