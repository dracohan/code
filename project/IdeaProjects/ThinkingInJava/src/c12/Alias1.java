package c12;
/**
 * @project: ThinkingInJava
 * @filename: Alias1.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 9:58 AM 7/28/15
 * @comment: Test Purpose
 * @result:x: 7
 *         y: 7
 *         Incrementing x
 *         x: 8
 *         y: 8
 */

//: Alias1.java
// Aliasing two handles to one object
public class Alias1 {
    int i;
    Alias1(int ii) { i = ii; }
    public static void main(String[] args) {
        Alias1 x = new Alias1(7);
        Alias1 y = x; // Assign the handle
        System.out.println("x: " + x.i);
        System.out.println("y: " + y.i);
        System.out.println("Incrementing x");
        x.i++;
        System.out.println("x: " + x.i);
        System.out.println("y: " + y.i);
    }
} ///:
