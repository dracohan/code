package c07;

/**
 * Simple insertion sort.
 * @param an array of Comparable items.
 * O(N^2)
 **/
class InsertionSort {
    public static <AnyType extends Comparable<? super AnyType>>
    void insertionSort(AnyType[] a) {
        for (int p = 1; p < a.length; p++) {
            AnyType tmp = a[p];
            int j;
            for (j = p; j > 0 && tmp.compareTo(a[j-1]) < 0; j--)
                a[j] = a[j - 1];
            a[j] = tmp;
        }
    }
}