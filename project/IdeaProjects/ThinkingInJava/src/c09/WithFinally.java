package c09;

/**
 * @project: ThinkingInJava
 * @filename: WithFinally.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 2:10 PM 7/16/15
 * @comment: Finally Guarantees cleanup
 * @result:
 */
class Switch2 {
    boolean state = false;
    boolean read() { return state; }
    void on() { state = true; }
    void off() { state = false; }
}
public class WithFinally {
    static Switch2 sw = new Switch2();
    public static void main(String[] args) {
        try {
            sw.on();
// Code that can throw exceptions...
        } catch(NullPointerException e) {
            System.out.println("NullPointerException");
        } catch(IllegalArgumentException e) {
            System.out.println("IOException");
        } finally {
            sw.off();
        }
    }
} ///:
