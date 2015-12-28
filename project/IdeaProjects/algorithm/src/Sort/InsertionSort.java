package Sort;

/**
 * Created by bwhan on 4/28/15.
 * Simple insertion sort.
 * O(N^2)
 **/

public class InsertionSort {
    public static void insertionsort(int[] a){
        for(int i = 1; i < a.length; i++){
            int tmp = a[i];
            int j;
            for(j = i;j>0 && tmp < a[j-1];j--){
                    a[j] = a[j-1];
            }
            a[j] = tmp;
        }
    }
}
