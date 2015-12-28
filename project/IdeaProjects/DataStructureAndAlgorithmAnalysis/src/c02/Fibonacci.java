package c02;

/**
 * @project: DataStructureAndAlgorithmAnalysis
 * @filename: Fibonacci
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 22:30 2015/7/7
 * @comment: Test Purpose
 * @result:
 */
public class Fibonacci {
    public static void main(String[] args) {
        System.out.println("Test with fib1:");
        long startTime = System.currentTimeMillis();
        System.out.println(fib1(40));
        long endTime = System.currentTimeMillis();
        System.out.println("程序运行时间： " + (endTime - startTime) + "ms");
    }

    public static long fib1(long n) {
        if (n <= 1)
            return n;
        else
            return fib1(n - 1) + fib1(n - 2);
    }
}
