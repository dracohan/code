package c02;

/**
 * @project: DataStructureAndAlgorithmAnalysis
 * @filename: FibonacciBetter
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 23:29 2015/7/8
 * @comment: Test Purpose
 * @result:
 */
public class FibonacciBetter {
    public static void main(String[] args) {
        System.out.println(fib(10));
    }

    public static long fib(long n) {
        //通过研究fibonacci序列的规律：
        if (n ==0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        //如果n为奇数，则fib(n)为fib((n+1)/2)^2 + fib((n-1)/2)^2
        //比如，fib(9) = fib(5)^2 + fib(4)^2
        if (n % 2 == 1)
            return fib((n+1)/2)*fib((n+1)/2) + fib((n-1)/2)*fib((n-1)/2);
        //如果n为偶数，则fib(n)为fib(n/2)^2 + fib((n-2)/2)^2 + fib(n/2-1)*fib(n/2) + fib(n/2-2)*fib(n/2-1)
        //比如，fib(10) = fib(5)^2 + fib(4)^2 + fib(4)*fib(5) + fib(3)*fib(4)
        else
            return fib(n/2)*fib(n/2) + fib((n-2)/2)*fib((n-2)/2) + fib(n/2-1)*fib(n/2) + fib(n/2-2)*fib(n/2-1);
    }
}
