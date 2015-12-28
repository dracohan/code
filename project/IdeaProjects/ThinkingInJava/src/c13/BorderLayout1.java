package c13;
/**
 * @project: ThinkingInJava
 * @filename: BorderLayout1.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 3:11 PM 8/10/15
 * @comment: Test Purpose
 * @result:
 */

//: BorderLayout1.java
// Demonstrating the BorderLayout
import java.awt.*;
import java.applet.*;
public class BorderLayout1 extends Applet {
    public void init() {
        int i = 0;
        setLayout(new BorderLayout());
        add("North", new Button("Button " + i++));
        add("South", new Button("Button " + i++));
        add("East", new Button("Button " + i++));
        add("West", new Button("Button " + i++));
        add("Center", new Button("Button " + i++));
    }
} ///: