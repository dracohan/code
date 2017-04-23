package c09;

/**
 * Created by Jimmy on 2015/6/30.
 */
public class ThreadTest {
    public static void main(String[] args){
        new Thread(){
            public void run(){System.out.println("Hello World!");}
        }.start();
    }
}
