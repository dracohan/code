package c10;

/**
 * @project: ThinkingInJava
 * @filename: Redirecting.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 11:11 AM 7/21/15
 * @comment: Test Purpose
 * @result:
 */
//: Redirecting.java
// Demonstrates the use of redirection for
// standard IO in Java 1.1
import java.io.*;
class Redirecting {
    public static void main(String[] args) {
        try {
            BufferedInputStream in =
                    new BufferedInputStream(
                            new FileInputStream(
                                    "Redirecting.java"));
// Produces deprecation message:
            PrintStream out =
                    new PrintStream(
                            new BufferedOutputStream(
                                    new FileOutputStream("test.out")));
            System.setIn(in);
            System.setOut(out);
            System.setErr(out);
            BufferedReader br =
                    new BufferedReader(
            new InputStreamReader(System.in));
            String s;
            while((s = br.readLine()) != null)
                System.out.println(s);
            out.close(); // Remember this!
        } catch(IOException e) {
            e.printStackTrace();
        }
    }
} ///:
