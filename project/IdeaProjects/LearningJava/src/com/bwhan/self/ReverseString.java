package self;/**
 * @project: ThinkingInJava
 * @filename: ReverseString.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 11:08 AM 7/27/15
 * @comment: Test Purpose
 * @result:
 */

import java.util.Scanner;
import static tool.util.*;


public class ReverseString {
    public static void main(String[] args) {
        prt("Please input a number:");
        Scanner scanner = new Scanner(System.in);
        Long l = scanner.nextLong();

        StringBuffer sb = new StringBuffer(l.toString());
        prt("The input number is:" + sb.toString());
        prt("The reverse number is:" + sb.reverse());
    }

}
