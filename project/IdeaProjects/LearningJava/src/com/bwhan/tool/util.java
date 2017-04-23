package tool;

import java.util.Collection;
import java.util.Enumeration;
import java.util.Iterator;

/**
 * @project: LearningJava
 * @filename: tool.tool.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 18:52 2015/7/26
 * @comment: Test Purpose
 * @result:
 */
public class util {
    public static void printEnumeration(Enumeration e) {
        while(e.hasMoreElements())
            System.out.println(
                    e.nextElement().toString());
    }

    public static void printIntArray(int[] a){
        for(int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    public static void prt(Object s){
        System.out.println(s);
    }

    public static <AnyType> void printGenericColection(Collection<AnyType> coll){
        for(AnyType item:coll)
            System.out.println(item);
    }

    public static <AnyType> void printGenericIterator(Iterator<AnyType> itr){
        while(itr.hasNext()){
            AnyType item = itr.next();
            System.out.println(item);
        }
    }
}
