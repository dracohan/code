package c14;
/**
 * @project: ThinkingInJava
 * @filename: Blocking.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 5:09 PM 8/13/15
 * @comment: Test Purpose
 * @result:
 */

//: Blocking.java
// Demonstrates the various ways a thread
// can be blocked.
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import java.io.*;
//////////// The basic framework ///////////
class Blockable extends Thread {
    private Peeker peeker;
    protected TextField state = new TextField(40);
    protected int i;
    public Blockable(Container c) {
        c.add(state);
        peeker = new Peeker(this, c);
    }
    public synchronized int read() { return i; }
    protected synchronized void update() {
        state.setText(getClass().getName()
                + " state: i = " + i);

    }
    public void stopPeeker() {
// peeker.stop(); Deprecated in Java 1.2
        peeker.terminate(); // The preferred approach
    }
}
class Peeker extends Thread {
    private Blockable b;
    private int session;
    private TextField status = new TextField(40);
    private boolean stop = false;
    public Peeker(Blockable b, Container c) {
        c.add(status);
        this.b = b;
        start();
    }
    public void terminate() { stop = true; }
    public void run() {
        while (!stop) {
            status.setText(b.getClass().getName()
                    + " Peeker " + (++session)
                    + "; value = " + b.read());
            try {
                sleep(100);
            } catch (InterruptedException e){}
        }
    }
} ///:Continue

public class Blocking extends Applet {
    private Button
            start = new Button("Start"),
            stopPeekers = new Button("Stop Peekers");
    private boolean started = false;
    private Blockable[] b;
    private PipedWriter out;
    private PipedReader in;
    public void init() {
        out = new PipedWriter();
        try {
            in = new PipedReader(out);
        } catch(IOException e) {}
        b = new Blockable[] {
                new Sleeper1(this),
                new Sleeper2(this),
                new SuspendResume1(this),
                new SuspendResume2(this),
                new WaitNotify1(this),
                new WaitNotify2(this),
                new Sender(this, out),
                new Receiver(this, in)
        };
        start.addActionListener(new StartL());
        add(start);
        stopPeekers.addActionListener(
                new StopPeekersL());
        add(stopPeekers);
    }
    class StartL implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            if(!started) {
                started = true;
                for(int i = 0; i < b.length; i++)
                    b[i].start();
            }
        }
    }
    class StopPeekersL implements ActionListener {
        public void actionPerformed(ActionEvent e) {
// Demonstration of the preferred
// alternative to Thread.stop():
            for(int i = 0; i < b.length; i++)
                b[i].stopPeeker();
        }
    }
    public static void main(String[] args) {
        Blocking applet = new Blocking();
        Frame aFrame = new Frame("Blocking");
        aFrame.addWindowListener(
                new WindowAdapter() {
                    public void windowClosing(WindowEvent e) {
                        System.exit(0);
                    }
                });
        aFrame.add(applet, BorderLayout.CENTER);
        aFrame.setSize(350,550);
        applet.init();
        applet.start();
        aFrame.setVisible(true);
    }
} ///:
