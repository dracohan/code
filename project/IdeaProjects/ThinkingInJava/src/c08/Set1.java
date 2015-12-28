package c08;

/**
 * Created by bwhan on 5/4/15.
 */
//: Set1.java
// Things you can do with Sets
import java.util.*;
import static tool.util.*;
public class Set1 {
    public static void testVisual(Set a) {
        Collection1.fill(a);
        Collection1.fill(a);
        //TreeSet will be sorted
        a.add("10");
        Collection1.fill(a);
        Collection1.print(a); // No duplicates!
// Add another set to this one:
        a.addAll(a);
        a.add("one");
        a.add("one");
        a.add("one");
        Collection1.print(a);
// Look something up:
        System.out.println("a.contains(\"one\"): " +
                a.contains("one"));

    }
    public static void main(String[] args) {
        testVisual(new HashSet());
        testVisual(new TreeSet());
	    TreeSet ts = new TreeSet();
	    Collection1.fill(ts);
	    Collection1.print(ts);
	    SortedSet ts1 = ts.subSet("3", false ,"5", true);
	    printGenericIterator(ts1.iterator());


    }
} ///:~
