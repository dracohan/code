package c09;

/**
 * Created by Jimmy on 2015/4/20.
 */
public class Clock extends UpdateApplet{
    public void paint(java.awt.Graphics g){
        g.drawString(new java.util.Date().toString(), 10, 25);
    }
}
