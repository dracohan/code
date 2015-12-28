package Sort;

/**
 * Created by bwhan on 4/28/15.
 */
public class BubbleSort {
    public static void bubblesort(int[] a){
        boolean done = false;
        int size = a.length;
        while(!done){
            done = true;
            for(int i = 0; i < size - 1; i++){
                if(a[i] > a[i+1]){
                    done = false;
                    int tmp = a[i+1];
                    a[i+1] = a[i];
                    a[i] = tmp;
                }
            }
            size--;
        }
    }
}
