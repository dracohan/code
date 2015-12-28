package c15;
/**
 * @project: ThinkingInJava
 * @filename: WhoAmI.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 9:51 AM 9/1/15
 * @comment: Test Purpose
 * @result:
 */

//: WhoAmI.java
// Finds out your network address when you're
// connected to the Internet.
import java.net.*;
public class WhoAmI {
    public static void main(String[] args)
            throws Exception {
        if(args.length != 1) {
            System.err.println(
                    "Usage: WhoAmI MachineName");
            System.exit(1);
        }
        InetAddress a =
                //InetAddress.getByName(args[0]);
                //InetAddress.getByName(null);
                InetAddress.getByName("127.0.0.1");
        System.out.println(a);
    }
} ///:
