package c02;

/**
 * @project: DataStructureAndAlgorithmAnalysis
 * @filename: Fibonacci
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 21:52 2015/7/7
 * @comment: Bad performance fibonacci
 * @result: 89
 */
public class FibonacciBad {
    public static void main(String[] args) {
        System.out.println(fib(10));
    }

    public static long fib(int n){
        if(n <= 1)
            return n;
        else
            return fib(n -1) + fib(n - 2);
    }
}
