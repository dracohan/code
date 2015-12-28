package c14;
/**
 * @project: ThinkingInJava
 * @filename: Continuing.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 9:44 AM 8/17/15
 * @comment: Test Purpose
 * @result:
 */

import java.awt.*;
import java.io.*;

///:Continuing
///////////// Blocking via sleep() ///////////
class Sleeper1 extends Blockable {
    public Sleeper1(Container c) { super(c); }
    public synchronized void run() {
        while(true) {
            i++;
            update();
            try {
                sleep(1000);
            } catch (InterruptedException e){}
        }
    }
}
class Sleeper2 extends Blockable {
    public Sleeper2(Container c) { super(c); }
    public void run() {
        while(true) {
            change();
            try {
                sleep(1000);
            } catch (InterruptedException e){}
        }
    }
    public synchronized void change() {
        i++;
        update();
    }
} ///:Continued

/////////// Blocking via suspend() ///////////
class SuspendResume extends Blockable {
    public SuspendResume(Container c) {
        super(c);
        new Resumer(this);
    }
}
class SuspendResume1 extends SuspendResume {
    public SuspendResume1(Container c) { super(c);}
    public synchronized void run() {
        while(true) {
            i++;
            update();
            suspend(); // Deprecated in Java 1.2
        }
    }
}
class SuspendResume2 extends SuspendResume {
    public SuspendResume2(Container c) { super(c);}
    public void run() {
        while(true) {
            change();
            suspend(); // Deprecated in Java 1.2
        }
    }
    public synchronized void change() {
        i++;
        update();
    }
}
class Resumer extends Thread {
    private SuspendResume sr;
    public Resumer(SuspendResume sr) {
        this.sr = sr;
        start();
    }
    public void run() {
        while(true) {
            try {
                sleep(1000);
            } catch (InterruptedException e){}
            sr.resume(); // Deprecated in Java 1.2
        }
    }
} ///:Continued


/////////// Blocking via wait() ///////////
class WaitNotify1 extends Blockable {
    public WaitNotify1(Container c) { super(c); }
    public synchronized void run() {
        while(true) {
            i++;
            update();
            try {
                wait(1000);
            } catch (InterruptedException e){}
        }
    }
}
class WaitNotify2 extends Blockable {
    public WaitNotify2(Container c) {
        super(c);
        new Notifier(this);
    }
    public synchronized void run() {
        while(true) {
            i++;
            update();
            try {
                wait();
            } catch (InterruptedException e){}
        }
    }
}
class Notifier extends Thread {
    private WaitNotify2 wn2;
    public Notifier(WaitNotify2 wn2) {
        this.wn2 = wn2;
        start();
    }
    public void run() {
        while(true) {
            try {
                sleep(2000);
            } catch (InterruptedException e){}
            synchronized(wn2) {
                wn2.notify();
            }
        }
    }
} ///:Continued

class Sender extends Blockable { // send
    private Writer out;
    public Sender(Container c, Writer out) {
        super(c);
        this.out = out;
    }
    public void run() {
        while(true) {
            for(char c = 'A'; c <= 'z'; c++) {
                try {
                    i++;
                    out.write(c);
                    state.setText("Sender sent: "
                            + (char)c);
                    sleep((int)(3000 * Math.random()));
                } catch (InterruptedException e){}
                catch (IOException e) {}
            }
        }
    }
}
class Receiver extends Blockable {
    private Reader in;
    public Receiver(Container c, Reader in) {
        super(c);
        this.in = in;
    }
    public void run() {
        try {
            while(true) {
                i++; // Show peeker it's alive
// Blocks until characters are there:
                state.setText("Receiver read: "
                        + (char)in.read());
            }
        } catch(IOException e) { e.printStackTrace();}
    }
} ///:Continue


