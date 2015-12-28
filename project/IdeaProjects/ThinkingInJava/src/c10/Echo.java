package c10;

/**
 * @project: ThinkingInJava
 * @filename: Echo.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 9:20 AM 7/21/15
 * @comment: Test Purpose
 * @result:
 */
//: Echo.java
// How to read from standard input
import java.io.*;
public class Echo {
    public static void main(String[] args) {
        DataInputStream in =
                new DataInputStream(
                        new BufferedInputStream(System.in));
        String s;
        try {
            while((s = in.readLine()).length() != 0)
                System.out.println(s);
// An empty line terminates the program
        } catch(IOException e) {
            e.printStackTrace();
        }
    }
} ///:
