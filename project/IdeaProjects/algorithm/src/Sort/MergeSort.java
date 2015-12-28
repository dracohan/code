package Sort;

/**
 * Created by bwhan on 4/28/15.
 */
public class MergeSort {
    public static void mergesort(int[] a){
        int[] tmp = new int[a.length];
        mergesort(a, tmp, 0, a.length - 1);
    }

    static void mergesort(int[] a, int[] tmp, int left, int right){
        if(left < right){
            int center  = (left+right)/2;
            mergesort(a, tmp, left, center);
            mergesort(a, tmp, center + 1,right);
            merge(a, tmp, left, center + 1, right);
        }
    }

    static void merge(int[] a, int[] tmp, int leftPos, int rightPos, int rightEnd){
        int leftEnd = rightPos - 1;
        int tmpPos = leftPos;
        int numElements = rightEnd - leftPos + 1;

        while(leftPos <= leftEnd && rightPos <= rightEnd){
            if(a[leftPos] <= a[rightPos])
                tmp[tmpPos++] = a[leftPos++];
            else
                tmp[tmpPos++] = a[rightPos++];
        }

        while(leftPos <= leftEnd)
            tmp[tmpPos++] = a[leftPos++];
        while(rightPos <= rightEnd)
            tmp[tmpPos++] = a[rightPos++];

        for(int i = 0; i < numElements; i++, rightEnd--)
            a[rightEnd] = tmp[rightEnd];
    }
}
