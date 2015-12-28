package com.company;

//: URShift.java
// Test of unsigned right shift
public class URShift {
    public static void main(String[] args) {
        int i = -1;
        System.out.println("Before shift int -1:");
        System.out.println(i);
        i >>>= 10;
        System.out.println("After shift int -1:");
        System.out.println(i);
        long l = -1;
        System.out.println("Before shift long -1:");
        System.out.println(l);
        l >>>= 10;
        System.out.println("After shift long -1:");
        System.out.println(l);
        short s = -1;
        System.out.println("Before shift short -1:");
        System.out.println(s);
        s >>>= 10;
        System.out.println("After shift short -1:");
        System.out.println(s);
        byte b = -1;
        System.out.println("Before shift byte -1:");
        System.out.println(b);
        b >>>= 10;
        System.out.println("After shift byte -1:");
        System.out.println(b);
    }
} ///:~