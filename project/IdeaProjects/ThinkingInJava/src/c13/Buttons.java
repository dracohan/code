package c13;
/**
 * @project: ThinkingInJava
 * @filename: Buttons.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 10:59 AM 8/11/15
 * @comment: Test Purpose
 * @result:
 */

//: Buttons.java
// Various Swing buttons
import javax.swing.*;
import javax.swing.plaf.basic.*;
import javax.swing.border.*;
public class Buttons extends JPanel {
    JButton jb = new JButton("JButton");
    BasicArrowButton
            up = new BasicArrowButton(
            BasicArrowButton.NORTH),
    down = new BasicArrowButton(
            BasicArrowButton.SOUTH),
    right = new BasicArrowButton(
            BasicArrowButton.EAST),
    left = new BasicArrowButton(
            BasicArrowButton.WEST);
    public Buttons() {
        add(jb);
        add(new JToggleButton("JToggleButton"));
        add(new JCheckBox("JCheckBox"));
        add(new JRadioButton("JRadioButton"));
        JPanel jp = new JPanel();
        jp.setBorder(new TitledBorder("Directions"));
        jp.add(up);
        jp.add(down);
        jp.add(left);
        jp.add(right);
        add(jp);
    }
    public static void main(String args[]) {
        Show.inFrame(new Buttons(), 300, 200);
    }
} ///: