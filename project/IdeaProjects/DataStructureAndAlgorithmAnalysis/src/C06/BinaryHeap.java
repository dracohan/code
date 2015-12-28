package C06;
/**
 * @project: DataStructureAndAlgorithmAnalysis
 * @filename: BinaryHeap.java
 * @version: 0.10
 * @author: JM Han
 * @date: 21:51 2015/10/24
 * @comment: BinaryHeap
 * @result:
 */

import master.UnderflowException;
import org.omg.CORBA.Any;

import static tool.util.*;

public class BinaryHeap<AnyType extends Comparable<? super AnyType>> {

	public BinaryHeap(){
		this(DEFAULT_CAPACITY);
	}

	public BinaryHeap(int Capacity){
		currentSize = 0;
		array = (AnyType[]) new Comparable[Capacity + 1];
	}

	public BinaryHeap(AnyType[] items){
		currentSize = items.length;
		array = (AnyType[]) new Comparable[(currentSize+2)*11/10];

		int i = 1;
		for(AnyType item:items)
			array[i++] = item;
		buildHeap();
	}

	public void insert(AnyType x){
		//System.out.println("Insert item: "+x);
		if(currentSize == array.length - 1)
			enlargeArray(array.length*2 + 1);
		//优先堆为完全树，放在最后一个元素
		int hole = ++currentSize;
		//从最后一个元素开始上溯，直到寻找到合适的位置，存在hole中
		//将x放在位置0的意思是，当插入最小值时hole为1，如果不设置，则需要单独判断
		for(array[0] = x; x.compareTo(array[hole/2])<0; hole/=2)
			array[hole] = array[hole/2];
		//赋值
		array[hole] = x;
	}

	public AnyType findMin(){
		if(isEmpty())
			throw new UnderflowException();
		return array[1];
	}

	public AnyType deleteMin(){
		if(isEmpty())
			throw new UnderflowException();
		AnyType minItem = findMin();
		array[1] = array[currentSize--];
		percolateDown(1);
		return minItem;
	}

	public boolean isEmpty(){
		return 0 == currentSize;
	}

	public void makeEmpty(){
		currentSize = 0;
	}

	//DEBUG
	//public int getSize(){
	//	return currentSize;
	//}

	//public AnyType getIndex(int i){
	//	return array[i];
	//}

	private static final int DEFAULT_CAPACITY = 10;

	private int currentSize;
	private AnyType[] array;

	private void percolateDown(int hole){
		int child;
		AnyType tmp = array[hole];

		for(;hole*2 <= currentSize; hole = child){
			child = hole*2;
			//和两个儿子中较小的一个比较
			if(child != currentSize &&
					array[child+1].compareTo(array[child])<0)
				child++;
			//如果比儿子小，则把hole放入儿子中，同时在儿子位置继续
			if(array[child].compareTo(tmp)<0)
				array[hole] = array[child];
			else
				break;
		}
		array[hole] = tmp;
	}

	private void buildHeap(){
		for(int i = currentSize/2; i>0; i--)
			//从最后一个儿子开始倒着往前下溯
			percolateDown(i);
	}

	private void enlargeArray(int newSize){
		//System.out.println("Enlarge array size from "+array.length+" to "+newSize);
		AnyType[] old = array;
		array = (AnyType[]) new Comparable[newSize];
		for (int i = 0; i < old.length; i++) {
			array[i] = old[i];
		}
	}

	public static void main(String[] args) {
		int numItems = 10000;
		BinaryHeap<Integer> h = new BinaryHeap<Integer>( );
		int i = 1;

		for( i = 10000; i > 0; i-- )
			h.insert( i );

		//DEBUG
		//System.out.println(h.getSize());
		//for (int j = 0; j < h.getSize(); j++) {
		//	System.out.println("array[" + j + "]: " + h.getIndex(j).toString());
		//}

		//ERROR CHECK
		for( i = 1; i < numItems; i++ )
			if( h.deleteMin( ) != i )
				System.out.println( "Oops! " + i );
	}
}
