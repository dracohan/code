package Sort;


import static Sort.InsertionSort.insertionsort;

/**
 * Created by bwhan on 4/29/15.
 */
public class QuickSort {
    public static void quicksort(int[] a){
        quicksort(a, 0, a.length - 1);
    }

    static final int median3(int[]a , int left, int right){
        int center = (left + right)/2;
        if(a[center] < a[left]){
            int tmp = a[center];
            a[left] = a[center];
            a[center] = tmp;
        }

        if(a[right] < a[left]){
            int tmp = a[right];
            a[right] = a[left];
            a[left] = tmp;
        }

        if(a[right] < a[center]){
            int tmp = a[right];
            a[right] = a[center];
            a[center] = tmp;
        }

        int temp = a[center];
        a[center] = a[right - 1];
        a[right - 1] = temp;

        return a[right - 1];
    }

    static void quicksort(int[] a, int left, int right){
        if(left + 10 < right){
            int pivot = median3(a, left, right);

            int i = left, j = right - 1;
            for(;;){
                while(a[++i] < pivot){}
                while(pivot < a[--j]){}
                if(i < j){
                    int tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                } else
                    break;
            }

            int tmp = a[i];
            a[i] = a[right - 1];
            a[right - 1] = tmp;

            quicksort(a, left, i - 1);
            quicksort(a, i + 1, right);
        }
        else
            insertionsort(a);
    }
}
