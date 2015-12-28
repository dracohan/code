package c10;

/**
 * @project: ThinkingInJava
 * @filename: ThawAlien.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 3:08 PM 7/21/15
 * @comment: Test Purpose
 * @result:
 */
//: ThawAlien.java
// Try to recover a serialized file without the
// class of object that's stored in that file.

import java.io.*;
public class ThawAlien {
    public static void main(String[] args)
            throws Exception {
        ObjectInputStream in =
                new ObjectInputStream(
                        new FileInputStream("file.x"));
        Object mystery = in.readObject();
        System.out.println(
                mystery.getClass().toString());
    }
} ///:
