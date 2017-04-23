package self;

import static java.lang.Thread.sleep;

/**
 * Created by Jimmy on 2015/4/20.
 */
public class MyThread implements Runnable{
    boolean animate = true;

    public void run() {
        try{
            while(animate) {
                System.out.println("running...");
                sleep(1);
            }
        }
        catch(InterruptedException e){
            System.out.println("exit...");
        }

    }

}
