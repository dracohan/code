package c07;


/**
 * Created by bwhan on 4/28/15.
 */
public class SortTest {
    public static void main(String[] args) {
        Integer[] v = {9,3,4,5,1,6,8,2,12,14,22,18,3,11};
        //BubbleSort.bubblesort(v);
        //InsertionSort.insertionSort(v);
        //ShellSort.shellsort(v);
		//SelectionSort.selectionSort(v);
        //HeapSort.heapsort(v);
        QuickSort.quicksort(v);
        //MergeSort.mergesort(v);
        for (int i = 0; i < v.length; i++) {
            System.out.print(v[i] + " ");
        }

    }
}
