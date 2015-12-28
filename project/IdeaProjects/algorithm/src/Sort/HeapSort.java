package Sort;

/**
 * Created by bwhan on 4/28/15.
 */
public class HeapSort {
    public static void heapsort(int[] a){
        for(int i = a.length/2; i >= 0; i--)
            percDown(a, i, a.length);
        for(int j = a.length - 1; j > 0; j--){
            int tmp = a[0];
            a[0] = a[j];
            a[j] = tmp;
            percDown(a, 0, j);
        }
    }

    static int leftChild(int i){
        return 2*i + 1;
    }

    static void percDown(int[] a, int i, int n){
        int child;
        int tmp;
        for(tmp = a[i]; leftChild(i) < n; i = child){
            child = leftChild(i);
            if(child != n -1 && a[child] < a[child + 1])
                child++;
            if(tmp < a[child])
                a[i] = a[child];
            else
                break;
        }
        a[i] = tmp;
    }
}
