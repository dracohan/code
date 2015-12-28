package com.company;

class SelfTest {
    public static void main(String[] args) {
        int n = 5;
        if(n == 5)
            System.out.println("Equal 5");
        else if(n ==6)
            System.out.println("Equal 6");
        else
            System.out.println("Un-Equal");

        char c = 0X4e30;
        System.out.println("value: " +
                 (int)c +
                        " character: " + c);

        for(int i = 0; i < 10; i++)
            System.out.println(i);
    }
}
