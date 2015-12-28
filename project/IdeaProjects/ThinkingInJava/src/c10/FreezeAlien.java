package c10;

/**
 * @project: ThinkingInJava
 * @filename: FreezeAlien.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 3:08 PM 7/21/15
 * @comment: Test Purpose
 * @result:
 */
//: FreezeAlien.java
// Create a serialized output file
import java.io.*;
public class FreezeAlien {
    public static void main(String[] args)
            throws Exception {
        ObjectOutput out =
                new ObjectOutputStream(
                        new FileOutputStream("file.x"));
        Alien zorcon = new Alien();
        out.writeObject(zorcon);
    }
} ///:
