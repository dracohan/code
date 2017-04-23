package c07;


import static c07.InsertionSort.insertionSort;

/**
 * Quick sort.
 * O(NLogN)
 **/

public class QuickSort {
	public static int partition(Integer[] a, int low, int high){
		int pivot = a[low];
		while(low < high){
			while(low < high && a[high] > pivot) --high;
			a[low] = a[high];
			while(low < high && a[low] < pivot) ++low;
			a[high] = a[low];
		}
		//
		a[low] = pivot;
		return low;
	}

	public static void quicksort(Integer[] a){
		quicksort(a, 0, a.length - 1);
	}


	private static void quicksort(Integer[] a, int low, int high){
		int loc = 0;
		if(low < high){
			loc = partition(a, low, high);
			System.out.println("排序中:");
			for(int i = low; i <= high; i++){
				System.out.print(a[i] + " " + (i==high? "\n" : ""));
			}
			quicksort(a, low, loc - 1);
			quicksort(a, loc + 1, high);
		}
	}

	public static void main(String[] args){
		Integer[] a = {7,8,1,2,3,4,5,6};

		System.out.println("排序前:");
		for(int i = 0; i < a.length; i++){
			System.out.print(a[i] + " " + (i==a.length - 1? "\n" : ""));
		}
		quicksort(a, 0, a.length -1);
		System.out.println("排序后:");
		for(int i = 0; i < a.length; i++){
			System.out.print(a[i]+ " "+ (i==a.length - 1? "\n" : ""));
		}
	}
}
