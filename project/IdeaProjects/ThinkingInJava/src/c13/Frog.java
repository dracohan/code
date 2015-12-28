package c13;
/**
 * @project: ThinkingInJava
 * @filename: Frog.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 3:40 PM 8/10/15
 * @comment: Test Purpose
 * @result:
 */

//: Frog.java
// A trivial Java Bean
import java.awt.*;
import java.awt.event.*;
class Spots {}
public class Frog {
    private int jumps;
    private Color color;
    private Spots spots;
    private boolean jmpr;
    public int getJumps() { return jumps; }
    public void setJumps(int newJumps) {
        jumps = newJumps;
    }
    public Color getColor() { return color; }
    public void setColor(Color newColor) {
        color = newColor;
    }
    public Spots getSpots() { return spots; }
    public void setSpots(Spots newSpots) {
        spots = newSpots;
    }
    public boolean isJumper() { return jmpr; }
    public void setJumper(boolean j) { jmpr = j; }
    public void addActionListener(
            ActionListener l) {
//...
    }
    public void removeActionListener(
            ActionListener l) {
// ...
    }
    public void addKeyListener(KeyListener l) {
// ...
    }
    public void removeKeyListener(KeyListener l) {
// ...
    }
    // An "ordinary" public method:
    public void croak() {
        System.out.println("Ribbet!");
    }
} ///: