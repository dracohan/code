package c11;/**
 * @project: LearningJava
 * @filename: RandomTest.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 8:23 2015/7/27
 * @comment: Test Purpose
 * @result:
 */

import java.util.Random;

import static tool.util.prt;

public class RandomTest {
    public static void main(String[] args) {
        Random rnums = new Random();
        prt(String.valueOf(rnums.nextBoolean()));
        prt(String.valueOf(rnums.nextInt()));
        prt(String.valueOf(rnums.nextLong()));
        prt(String.valueOf(rnums.nextFloat()));
        prt(String.valueOf(rnums.nextDouble()));
        prt(String.valueOf(rnums.nextGaussian()));
    }
}
