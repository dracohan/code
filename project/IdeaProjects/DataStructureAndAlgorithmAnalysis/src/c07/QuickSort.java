package c07;


import static c07.InsertionSort.insertionSort;

/**
 * Quick sort.
 * @param an array of Comparable items.
 * O(NLogN)
 **/

public class QuickSort {
    public static <AnyType extends Comparable<? super AnyType>>
    void quicksort(AnyType[] a){
        quicksort(a, 0, a.length - 1);
    }

    private static <AnyType extends Comparable<? super AnyType>>
    AnyType median3(AnyType[]a , int left, int right){
        int center = (left + right)/2;
        if(a[center].compareTo(a[left]) < 0){
            AnyType tmp = a[center];
            a[left] = a[center];
            a[center] = tmp;
        }

        if(a[right].compareTo(a[left]) < 0){
            AnyType tmp = a[right];
            a[right] = a[left];
            a[left] = tmp;
        }

        if(a[right].compareTo(a[center]) < 0){
            AnyType tmp = a[right];
            a[right] = a[center];
            a[center] = tmp;
        }

        AnyType temp = a[center];
        a[center] = a[right - 1];
        a[right - 1] = temp;

        return a[right - 1];
    }

    static <AnyType extends Comparable<? super AnyType>>
    void quicksort(AnyType[] a, int left, int right){
        if(left + 10 < right){
            AnyType pivot = median3(a, left, right);

            int i = left, j = right - 1;
            for(;;){
                while(a[++i].compareTo(pivot) < 0 ){}
                while(pivot.compareTo(a[--j]) < 0){}
                if(i < j){
                    AnyType tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                } else
                    break;
            }

            AnyType tmp = a[i];
            a[i] = a[right - 1];
            a[right - 1] = tmp;

            quicksort(a, left, i - 1);
            quicksort(a, i + 1, right);
        }
        else
            insertionSort(a);
    }
}
