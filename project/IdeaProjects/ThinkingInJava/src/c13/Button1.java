package c13;
/**
 * @project: ThinkingInJava
 * @filename: Button1.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 1:43 PM 8/10/15
 * @comment: Test Purpose
 * @result:
 */

//: Button1.java
// Putting buttons on an applet
import java.awt.*;
import java.applet.*;
public class Button1 extends Applet {
    Button
            b1 = new Button("Button 1"),
            b2 = new Button("Button 2");
    public void init() {
        add(b1);
        add(b2);
    }
} ///:
