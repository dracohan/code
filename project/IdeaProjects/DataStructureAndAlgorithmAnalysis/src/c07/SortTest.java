package c07;


/**
 * Created by bwhan on 4/28/15.
 */
public class SortTest {
    public static void main(String[] args) {
        Integer[] v = {9,3,4,5,1,6,8,2,12,14,22,18,3,11};
        InsertionSort.insertionSort(v);
        BubbleSort.bubblesort(v);
        //ShellSort.shellsort(v);
        //HeapSort.heapsort(v);
        //MergeSort.mergesort(v);
        //QuickSort.quicksort(v);
        for (int i = 0; i < v.length; i++) {
            System.out.print(v[i] + " ");
        }

    }
}
