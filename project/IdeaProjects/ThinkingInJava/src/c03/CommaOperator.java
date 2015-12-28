package c03;

/**
 * Created by bwhan on 4/2/15.
 */
//: CommaOperator.java
public class CommaOperator {
    public static void main(String[] args) {
        for(int i = 1, j = i + 10; i < 5;
            i++, j = i * 2) {
            System.out.println("i= " + i + " j= " + j);
        }
    }
} ///:~