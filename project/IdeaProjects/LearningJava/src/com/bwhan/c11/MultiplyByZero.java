package c11;/**
 * @project: LearningJava
 * @filename: MultiplyByZero.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 8:10 2015/7/27
 * @comment: Test Purpose
 * @result:
 */

import static tool.util.prt;

public class MultiplyByZero {
    public static void main(String[] args) {
        int zero = 0;
        try{
            int i = 72 / zero;
        }
        catch (ArithmeticException e) {
            prt("divide by 0");
        }

        double dzero = 0.0;
        double d = 0.0;
        try {
            d = -1.0 / dzero;
        }
        catch (ArithmeticException de){
            prt("divide by dzero");
        }
        finally {
            if(d == Double.NEGATIVE_INFINITY)
                prt("divide by 0.0");
        }
    }
}
