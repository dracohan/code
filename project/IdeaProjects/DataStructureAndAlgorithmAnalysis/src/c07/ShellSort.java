package c07;

/**
 * Shellsort, using Shell's (poor) increments.
 * @param an array of Comparable items.
 * O(N^8/7)
 **/
public class ShellSort {
    public static <AnyType extends Comparable<? super AnyType>>
    void shellsort(AnyType[] a) {
        for(int gap = a.length/2; gap > 0; gap /= 2)
            for(int i = gap; i < a.length; i++){
                AnyType tmp = a[i];
                int j = i;
                for(; j >= gap && tmp.compareTo(a[j-gap]) < 0; j -= gap)
                    a[j] = a[j - gap];
                a[j] = tmp;
            }
    }
}
