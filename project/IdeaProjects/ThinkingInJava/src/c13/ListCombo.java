package c13;
/**
 * @project: ThinkingInJava
 * @filename: ListCombo.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 11:04 AM 8/11/15
 * @comment: Test Purpose
 * @result:
 */

//: ListCombo.java
// List boxes & Combo boxes
import java.awt.*;
        import javax.swing.*;
public class ListCombo extends JPanel {
    public ListCombo() {
        setLayout(new GridLayout(2,1));
        JList list = new JList(ButtonGroups.ids);
        add(new JScrollPane(list));
        JComboBox combo = new JComboBox();
        for(int i = 0; i < 100; i++)
            combo.addItem(Integer.toString(i));
        add(combo);
    }
    public static void main(String args[]) {
        Show.inFrame(new ListCombo(),200,200);
    }
} ///:
