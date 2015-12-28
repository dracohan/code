package Sort;

import static Sort.QuickSort.quicksort;

/**
 * Created by bwhan on 4/28/15.
 */
public class SortTest {
    public static void main(String[] args) {
        int[] v = {9,3,4,5,1,6,8,2,12,14,22,18,3,11};
        //insertionsort(v);
        //bubblesort(v);
        //shellsort(v);
        //heapsort(v);
        //mergesort(v);
        quicksort(v);
        tool.PrintData.printarray(v);

    }
}
