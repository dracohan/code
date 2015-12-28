package c07;

import org.omg.CORBA.Any;

/**
 * HeapSort,因为堆排序需要交换元素，从小到大排序，请用最大堆，从大到小排序，请用最小堆
 * @param an array of Comparable items.
 * O(NLogN)
 **/
public class HeapSort {
    static int leftChild(int i){
        return 2*i + 1;
    }

    public static <AnyType extends Comparable<? super AnyType>>
    void heapsort(AnyType[] a){
        for(int i = a.length/2; i >= 0; i--)
            percDown(a, i, a.length);
        for(int j = a.length - 1; j > 0; j--){
            AnyType tmp = a[0];
            a[0] = a[j];
            a[j] = tmp;
            percDown(a, 0, j);
        }
    }

    public static <AnyType extends Comparable<? super AnyType>>
    void percDown(AnyType[] a, int i, int n){
        int child;
        AnyType tmp;
        for(tmp = a[i]; leftChild(i) < n; i = child){
            child = leftChild(i);
            if(child != n -1 && a[child].compareTo(a[child + 1]) < 0)
                child++;
            if(tmp.compareTo(a[child]) < 0)
                a[i] = a[child];
            else
                break;
        }
        a[i] = tmp;
    }
}
