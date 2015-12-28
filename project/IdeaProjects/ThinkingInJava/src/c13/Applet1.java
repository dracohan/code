package c13;
/**
 * @project: ThinkingInJava
 * @filename: Applet1.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 1:50 PM 8/6/15
 * @comment: Test Purpose
 * @result:
 */

//: Applet1.java
// Very simple applet
import java.awt.*;
import java.applet.*;
public class Applet1 extends Applet {
    public void paint(Graphics g) {
        g.drawString("First applet", 10, 10);
    }
} ///:~