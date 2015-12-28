package c13;
/**
 * @project: ThinkingInJava
 * @filename: FlowLayout1.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 3:10 PM 8/10/15
 * @comment: Test Purpose
 * @result:
 */

//: FlowLayout1.java
// Demonstrating the FlowLayout
import java.awt.*;
import java.applet.*;
public class FlowLayout1 extends Applet {
    public void init() {
        setLayout(new FlowLayout());
        for(int i = 0; i < 20; i++)
            add(new Button("Button " + i));
    }
} ///
