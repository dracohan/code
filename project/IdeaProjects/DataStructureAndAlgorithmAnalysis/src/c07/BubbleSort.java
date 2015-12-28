package c07;

/**
 * Created by bwhan on 4/28/15.
 */
public class BubbleSort {
    public static <AnyType extends Comparable<? super AnyType>>
    void bubblesort(AnyType[] a){
	    for (int i = 0; i < a.length; i++)
		    for (int j = i + 1; j < a.length; j++){
			    if(a[i].compareTo(a[j]) > 0){
				    AnyType t = a[i];
				    a[i] = a[j];
				    a[j] = t;
			    }
		    }
    }
}
