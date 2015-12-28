package c08;

/**
 * @project: ThinkingInJava
 * @filename: AlphaCompare
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 5:02 PM 7/9/15
 * @comment: Using Comparator to perform an alphabetic sort
 * @result:
 */
import java.util.*;
public class AlphaCompare implements Comparator {
    public int compare(Object o1, Object o2) {
// Assume it's used only for Strings...
        String s1 = ((String)o1).toLowerCase();
        String s2 = ((String)o2).toLowerCase();
        return s1.compareTo(s2);
    }
    public static void main(String[] args) {
        String[] s = Array1.randStrings(4, 10);
        Array1.print(s);
        AlphaCompare ac = new AlphaCompare();
        Arrays.sort(s, ac);
        Array1.print(s);
// Must use the Comparator to search, also:
        int loc = Arrays.binarySearch(s, s[3], ac);
        System.out.println("Location of " + s[3] +
                " = " + loc);
    }
} ///:

