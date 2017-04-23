package self;

/**
 * Created by Jimmy on 2015/4/20.
 */
public class MythreadTest {
    public static void main(String[] args){
        MyThread mt = new MyThread();
        Thread t = new Thread(mt);
        mt.run();
    }
}
