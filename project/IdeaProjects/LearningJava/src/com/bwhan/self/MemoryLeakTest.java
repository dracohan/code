package self;
/**
 * @project: ThinkingInJava
 * @filename: MemoryLeakTest.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 2:36 PM 9/11/15
 * @comment: Test Purpose
 * @result:
 */

import java.util.Vector;
import static tool.util.*;



public class MemoryLeakTest {
    public static void main(String[] args) {
        Vector v = new Vector(10);
        for (int i = 1; i<20; i++){
            Integer o = i*2;
            v.add(o);
            o = null;
        }

        printEnumeration(v.elements());
    }
}
