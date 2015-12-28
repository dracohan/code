package c08;

/**
 * @project: ThinkingInJava
 * @filename: MapCreation
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 10:51 AM 7/9/15
 * @comment: Test Purpose
 * @result:
 */
//: MapCreation.java
// Demonstrates time differences in Map creation
import java.util.*;
public class MapCreation {
    public static void main(String[] args) {
        final long REPS = 100000;
        long t1 = System.currentTimeMillis();
        System.out.print("Hashtable");
        for(long i = 0; i < REPS; i++)
            new Hashtable();
        long t2 = System.currentTimeMillis();
        System.out.println(": " + (t2 - t1));
        t1 = System.currentTimeMillis();
        System.out.print("TreeMap");
        for(long i = 0; i < REPS; i++)
            new TreeMap();
        t2 = System.currentTimeMillis();
        System.out.println(": " + (t2 - t1));
        t1 = System.currentTimeMillis();
        System.out.print("HashMap");
        for(long i = 0; i < REPS; i++)
            new HashMap();
        t2 = System.currentTimeMillis();
        System.out.println(": " + (t2 - t1));
    }
} ///:~
