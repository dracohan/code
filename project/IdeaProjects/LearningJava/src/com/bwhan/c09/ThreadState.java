package c09;

/**
 * Created by Jimmy on 2015/4/21.
 */
public class ThreadState {
    public static void main(String[] args) {
        Thread[] threads = new Thread[64];
        int num = Thread.enumerate(threads);
        System.out.println("num = " + num);
        for(int i = 0; i < num; i++)
            System.out.println(threads[i] + ":" + threads[i].getState());
    }

}
