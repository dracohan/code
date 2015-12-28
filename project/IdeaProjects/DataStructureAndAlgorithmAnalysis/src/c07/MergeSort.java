package c07;

/**
 * Merge sort.
 * @param an array of Comparable items.
 * O(NLogN)
 **/

public class MergeSort {
    public static <AnyType extends Comparable<? super AnyType>>
    void mergesort(AnyType[] a){
        AnyType[] tmp = (AnyType[])new Comparable[a.length];
        mergesort(a, tmp, 0, a.length - 1);
    }

    public static <AnyType extends Comparable<? super AnyType>>
    void mergesort(AnyType[] a, AnyType[] tmp, int left, int right){
        if(left < right){
            int center  = (left+right)/2;
            mergesort(a, tmp, left, center);
            mergesort(a, tmp, center + 1,right);
            merge(a, tmp, left, center + 1, right);
        }
    }

    public static <AnyType extends Comparable<? super AnyType>>
    void merge(AnyType[] a, AnyType[] tmp, int leftPos, int rightPos, int rightEnd){
        int leftEnd = rightPos - 1;
        int tmpPos = leftPos;
        int numElements = rightEnd - leftPos + 1;

        while(leftPos <= leftEnd && rightPos <= rightEnd){
            if(a[leftPos].compareTo(a[rightPos]) < 0)
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
