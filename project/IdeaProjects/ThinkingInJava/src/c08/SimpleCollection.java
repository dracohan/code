package c08;

/**
 * Created by bwhan on 5/4/15.
 */
//: SimpleCollection.java
// A simple example using the new Collections
import java.util.*;
public class SimpleCollection {
    public static void main(String[] args) {
        Collection c = new ArrayList();
        for(int i = 0; i < 10; i++)
            c.add(Integer.toString(i));
        c.add(Integer.toString(7));
        Iterator it = c.iterator();
        while(it.hasNext())
            System.out.println(it.next());
    }
} ///:~
