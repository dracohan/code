package self;

/**
 * @project: LearningJava
 * @filename: test.java
 * @version: 0.10
 * @author: JM Han
 * @date: 16:01 2015/10/19
 * @comment: Test Purpose
 * @result:
 */
public class test {
	public static void main(String[] arg) {
		int x1[]={1,2,3},x2[]={3,2,1};
		swap(x1,x2);//采用swap函数，即直接利用参数引用进行交换
		System.out.print("swap->X1:/t"); printarr(x1);
		System.out.print("swap->X2:/t"); printarr(x2);
		swapArray(x1,x2);//采用swapArray函数，利用对于对象的值的修改进行交换
		System.out.print("swapArr->X1:/t"); printarr(x1);
		System.out.print("swapArr->X2:/t"); printarr(x2);
		Object t;
		t=x1; x1=x2; x2=(int[])t;//在非函数调用中直接利用引用进行交换
		System.out.print("Tswap->X1:/t"); printarr(x1);
		System.out.print("Tswap->X2:/t"); printarr(x2);
	}
	public static void swap(Object x, Object y) {//直接利用参数引用交换
		Object t=x;
		x=y;
		y=t;
	}
	public static void swapArray(int x[], int y[]) {//对引用对象的值进行修改完成交换
		if(x.length!=y.length) return;
		int t[]=x.clone();
		for(int i=0; i<x.length; i++) x[i]=y[i];
		for(int i=0; i<y.length; i++) y[i]=t[i];
	}
	public static void printarr(int x[]) {//打印数组
		for(int i=0; i<x.length; i++) System.out.print(x[i]+"  ");
		System.out.println();
	}
}
