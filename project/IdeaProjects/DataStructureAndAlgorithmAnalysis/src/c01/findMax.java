package c01;

import java.util.Comparator;

/**
 * @project: DataStructureAndAlgorithmAnalysis
 * @filename: findMax.java
 * @version: 0.10
 * @author: Powell
 * @date: 13:27 2015/9/29
 * @comment: Test Purpose
 * @result:
 */


class CaseInsensitiveCompare implements Comparator<String>{
	public int compare(String lhs, String rhs){
		return lhs.compareToIgnoreCase(rhs);
	}
}

public class findMax {
	public static <AnyType>
	AnyType findMax(AnyType[] arr, Comparator<? super AnyType> cmp){
		int maxIndex = 0;

		for(int i = 1; i< arr.length; i++)
			if(cmp.compare(arr[i], arr[maxIndex]) > 0)
				maxIndex = i;

		return arr[maxIndex];
	}

	public static void main(String[] args) {
		String[] arr = {"ZEBRA", "alligator", "crocodile"};
		System.out.println(findMax(arr, new CaseInsensitiveCompare()));

	}
}
