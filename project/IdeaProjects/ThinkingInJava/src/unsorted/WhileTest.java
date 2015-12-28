package com.company;

import java.util.*;

//: WhileTest.java
// Demonstrates the while loop
public class WhileTest {
    public static void main(String[] args) {
        double r = 0;
        Random rand = new Random();
        while(r < 0.99d) {
            r = Math.random();
            System.out.println("From Math: " + r);
            r = rand.nextDouble();
            System.out.println("From Random: " + r);
        }
    }
} ///:~