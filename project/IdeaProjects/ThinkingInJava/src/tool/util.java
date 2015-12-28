package tool;

import java.util.Collection;
import java.util.Enumeration;
import java.util.Iterator;

/**
 * Created by bwhan on 4/28/15.
 */
public class util {
    public static void prt(Object s){
        System.out.println(s);
    }

    public static void printIntArray(int[] a){
        for(int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    public static void printEnumeration(Enumeration e) {
        while(e.hasMoreElements())
            System.out.println(
                    e.nextElement().toString());
    }

    public static <AnyType> void printGenericColection(Collection<AnyType> coll){
        for(AnyType item:coll)
            System.out.println(item);
    }

    public static <AnyType> void printGenericIterator(Iterator<AnyType> itr){
        while(itr.hasNext()){
            System.out.println(itr.next());
        }
    }
}
