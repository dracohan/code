package Sort;

/**
 * Created by bwhan on 4/28/15.
 */
public class ShellSort {
    public static void shellsort(int[] a) {
        for(int gap = a.length/2; gap > 0; gap /= 2)
            for(int i = gap; i < a.length; i++){
                int tmp = a[i];
                int j = i;

                for(; j >= gap && tmp < a[j-gap]; j -= gap)
                    a[j] = a[j - gap];
                a[j] = tmp;
            }
    }
}
