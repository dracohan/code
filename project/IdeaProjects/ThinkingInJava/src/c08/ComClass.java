package c08;

/**
 * @project: ThinkingInJava
 * @filename: ComClass.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 5:05 PM 7/9/15
 * @comment: A class that implements Comparable
 * @result:
 */
import java.util.*;
public class ComClass implements Comparable {
    private int i;
    public ComClass(int ii) { i = ii; }
    public int compareTo(Object o) {
// Implicitly tests for correct type:
        int argi = ((ComClass)o).i;
        if(i == argi) return 0;
        if(i < argi) return -1;
        return 1;
    }
    public static void print(Object[] a) {
        for(int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }
    public String toString() { return i + ""; }
    public static void main(String[] args) {
        ComClass[] a = new ComClass[20];
        for(int i = 0; i < a.length; i++)
            a[i] = new ComClass(
                    (int)(Math.random() *100));
        print(a);
        Arrays.sort(a);
        print(a);
        int loc = Arrays.binarySearch(a, a[3]);
        System.out.println("Location of " + a[3] +
                " = " + loc);
    }
} ///:
