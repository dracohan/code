package c02;

import java.util.Comparator;

/**
 * @project: DataStructureAndAlgorithmAnalysis
 * @filename: BinarySearch
 * @version: 0.10
 *           0.20 use generic
 * @author: Jimmy Han
 * @date: 22:57 2015/7/7
 *        21:33 2015/09/29
 * @comment: Test Purpose
 * @result:
 */
public class BinarySearch<AnyType> {
    public static final int NOT_FOUND = -1;

    public static void main(String[] args) {
        Integer[] a = {1, 2, 7, 9, 9, 12, 15, 24, 30};
        System.out.println(binarySearch(a, 7));
        System.out.println(binarySearch(a, 7, 1, 6));
    }

    /**
     * Performs the standard binary search. Normal
     * @return index where item is found, or -1 if not found
     */
    public static <AnyType extends Comparable<? super AnyType>>
    int binarySearch(AnyType[] a, AnyType x){
        int low = 0, high = a.length - 1;

        while(low <= high){
            int mid = (low + high)/2;

            if(a[mid].compareTo(x) < 0)
                low = mid + 1;
            else if(a[mid].compareTo(x) > 0)
                high = mid - 1;
            else
                return mid;
        }

        return NOT_FOUND;
    }

    /**
     * Performs the standard binary search. Recursively.
     * @return index where item is found, or -1 if not found
     */
    public static <AnyType extends Comparable<? super AnyType>>
    int binarySearch(AnyType[] a, AnyType x, int beginidx, int endidx){
        if(a[beginidx].compareTo(x) > 0 || a[endidx].compareTo(x) < 0)
            return -1;

        int mididx = (beginidx + endidx)/2;

        if(a[mididx].compareTo(x) < 0)
            return binarySearch(a, x, mididx + 1, endidx);
        else if(a[mididx].compareTo(x) > 0)
            return binarySearch(a, x, beginidx, mididx - 1);
        else
            return mididx;

    }
}

