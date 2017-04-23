package com.company;

public class ArrayDemo {
    public static void main(String args[]){
        int n = 6;
        int score[] = {2,3,4,n};

/*        for(int i = 0; i < 3; i++)
            score[i] = i*2 + 1;*/

        for(int i = 0; i < score.length; i++)
            System.out.println(score[i]);
    }
}
