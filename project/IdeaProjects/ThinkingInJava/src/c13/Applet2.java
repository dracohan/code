package c13;
/**
 * @project: ThinkingInJava
 * @filename: Applet2.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 2:00 PM 8/6/15
 * @comment: Test Purpose
 * @result:
 */

// Easy graphics
import java.awt.*;
import java.applet.*;
public class Applet2 extends Applet {
    public void paint(Graphics g) {
        g.drawString("Second applet", 0, 15);
        g.draw3DRect(0, 0, 100, 50, true);
    }
} ///:
