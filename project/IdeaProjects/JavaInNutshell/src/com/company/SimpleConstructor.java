package com.company;//: SimpleConstructor.java
// Demonstration of a simple constructor

class Rock {
    Rock(int i) {
        System.out.println(
                "Creating Rock number " + i);
    }
    Rock() {
        System.out.println(
                "Creating Rock... ");
    }
}
public class SimpleConstructor {
    public static void main(String[] args) {
        for(int i = 0; i < 10; i++)
            new Rock();
        for(int i = 0; i < 10; i++)
            new Rock(i);
    }
}