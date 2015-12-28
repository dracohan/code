package c13;
/**
 * @project: ThinkingInJava
 * @filename: GridLayout1.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 3:12 PM 8/10/15
 * @comment: Test Purpose
 * @result:
 */

//: GridLayout1.java
// Demonstrating the GridLayout
import java.awt.*;
import java.applet.*;
public class GridLayout1 extends Applet {
    public void init() {
        setLayout(new GridLayout(7,3));
        for(int i = 0; i < 20; i++)
            add(new Button("Button " + i));
    }
} ///:
