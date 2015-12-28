package c01;
/**
 * @project: ThinkingInJava
 * @filename: ScopeTest.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 2:17 PM 9/11/15
 * @comment: Test Purpose
 * @result:
 */

public class ScopeTest {
    public static void main(String[] args) {
        int x = 1;
        {
            //int x = 2;
        }
        //System.out.println(Boolean.SIZE);
        System.out.println(Character.BYTES);
        System.out.println(Integer.BYTES);
        System.out.println(Short.BYTES);
        System.out.println(Long.BYTES);
        System.out.println(Float.BYTES);
        System.out.println(Double.BYTES);
    }
}

