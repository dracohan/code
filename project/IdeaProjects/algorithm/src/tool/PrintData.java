package tool;

import java.util.Enumeration;

/**
 * Created by bwhan on 4/28/15.
 */
public class PrintData {
    public static void print(Enumeration e) {
        while(e.hasMoreElements())
            System.out.println(
                    e.nextElement().toString());
    }

    public static void printarray(int[] a){
        for(int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
    }
}
