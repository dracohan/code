package c13;
/**
 * @project: ThinkingInJava
 * @filename: ButtonGroups.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 11:00 AM 8/11/15
 * @comment: Test Purpose
 * @result:
 */

//: ButtonGroups.java
// Uses reflection to create groups of different
// types of AbstractButton.
import javax.swing.*;
import javax.swing.border.*;
import java.lang.reflect.*;
public class ButtonGroups extends JPanel {
    static String[] ids = {
            "June", "Ward", "Beaver",
            "Wally", "Eddie", "Lumpy",
    };
    static JPanel
    makeBPanel(Class bClass, String[] ids) {
        ButtonGroup bg = new ButtonGroup();
        JPanel jp = new JPanel();
        String title = bClass.getName();
        title = title.substring(
                title.lastIndexOf('.') + 1);
        jp.setBorder(new TitledBorder(title));
        for(int i = 0; i < ids.length; i++) {
            AbstractButton ab = new JButton("failed");
            try {
// Get the dynamic constructor method
// that takes a String argument:
                Constructor ctor = bClass.getConstructor(
                        new Class[] { String.class });
// Create a new object:
                ab = (AbstractButton)ctor.newInstance(
                        new Object[]{ids[i]});
            } catch(Exception ex) {
                System.out.println("can't create " +
                        bClass);
            }
            bg.add(ab);
            jp.add(ab);
        }
        return jp;
    }
    public ButtonGroups() {
        add(makeBPanel(JButton.class, ids));
        add(makeBPanel(JToggleButton.class, ids));
        add(makeBPanel(JCheckBox.class, ids));
        add(makeBPanel(JRadioButton.class, ids));
    }
    public static void main(String args[]) {
        Show.inFrame(new ButtonGroups(), 500, 300);
    }
} ///:
