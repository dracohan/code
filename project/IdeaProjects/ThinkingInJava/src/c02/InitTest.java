package c02;
/**
 * @project: ThinkingInJava
 * @filename: InitTest.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 4:25 PM 9/11/15
 * @comment: Test Purpose
 * @result:
 */

public class InitTest {
    Integer inta;   //will not be initialized
    int     i;      //will be initialized to 0

    public static void main(String[] args) {
        InitTest it = new InitTest();
        System.out.println(it.i);
        System.out.println(it.inta.byteValue());
    }
}
