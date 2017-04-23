package com.company;

//: Arrays.java
// Arrays of primitives.
public class Arrays {
    public static void main(String[] args) {
        int[] a1 = { 1, 2, 3, 4, 5 };
        int[] a2;
        a2 = a1;
        for(int i = 0; i < a2.length; i++)
            a2[i]++;
        for(int i = 0; i <= a1.length; i++)
            prt("a1[" + i + "] = " + a1[i]);
        if(a1 == a2)
            prt("==");
        else if(a1 != a2)
            prt("!=");
        else
            prt("nothing");
    }
    static void prt(String s) {
        System.out.println(s);
    }
} ///:~