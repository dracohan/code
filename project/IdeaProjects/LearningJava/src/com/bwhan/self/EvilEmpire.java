package self;

import java.net.Socket;

/**
 * Created by Jimmy on 2015/5/20.
 */
public class EvilEmpire {
    public static void main(String[] args) throws Exception{
        try{
            Socket s = new Socket("127.0.0.1", 80);
            System.out.println("Connected!");
        }
        catch(SecurityException e){
            System.out.println("SecurityException: could not conmnect.");
        }
    }
}
