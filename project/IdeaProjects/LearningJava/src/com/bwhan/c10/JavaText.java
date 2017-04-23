package c10;/**
 * @project: LearningJava
 * @filename: JavaText.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 20:18 2015/7/26
 * @comment: Test Purpose
 * @result:
 */

import java.text.NumberFormat;

import static tool.util.prt;

public class JavaText {
    public static void main(String[] args) {
        double salary = 25000;
        String here =
                NumberFormat.getCurrencyInstance().format(salary);
        prt(here);
    }
}
