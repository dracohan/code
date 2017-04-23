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
	    System.out.println("Test with fib:");
	    long startTime = System.currentTimeMillis();
	    fib(40);
	    long endTime = System.currentTimeMillis();
	    System.out.println("程序运行时间： " + (endTime - startTime) + "ms");
        System.out.println("Test with fib1:");
        long startTime1 = System.currentTimeMillis();
        fib1(40);
        long endTime1 = System.currentTimeMillis();
        System.out.println("程序运行时间： " + (endTime1 - startTime1) + "ms");
    }


	public static long fib(long n){
		if(n < 2)
			return n;
		long f1 = 0;
		long f2 = 1;
		long res = 0;
		for(long i = 2; i <= n; i++){
			res = f1 + f2;
			f1 = f2;
			f2 = res;
		}
		return res;
	}


    public static long fib1(long n) {
        if (n <= 1)
            return n;
        else
            return fib1(n - 1) + fib1(n - 2);
    }
}
